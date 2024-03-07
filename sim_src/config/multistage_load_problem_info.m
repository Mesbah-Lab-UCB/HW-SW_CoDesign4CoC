function [ctrl_params, sim_params, varargout] = multistage_load_problem_info(varargin)

    %% set default values
    % control-relevant parameter defaults
    ctrl_model_file = 'APPJmodel_2021_06_08_15h57m55s_n4sid_alldata.mat';
    Np = 5;    % prediction horizon
    N_robust = 2;   % robust horizon
    case_idx = [-1, 0, 1]; % multiplier of the additive uncertainty
    Kcem = 0.5;
    Tref = 43.0;   % degC
    y_min = [20; 0]; % [T, I], [degC, arb. units]
    y_max = [45; 80]; 
    u_min = [1.5; 1.5]; % [P, q], [W, SLM]
    u_max = [5.0; 5.0];
    w_bound = [0.5; 1.0];
    
    % plant/simulation environment parameter defaults
    plant_model_file = 'APPJmodel_2021_06_08_15h57m55s_n4sid_50split.mat';
    ts = 0.5; % seconds
    CEMsp = 1.5;   % min
    Kcem_p = Kcem;
    Tref_p = Tref;
    Tmax = y_max(1); % degC
    x0 = [34, 7.74]; % [T, I], [degC, arb. units]
    rand_seed = 520;
    
    
    if nargin > 1
        for i = 1:2:length(varargin)
            name = varargin{i};
            value = varargin{i+1};
            switch name
                case 'ctrl_model_file'
                    ctrl_model_file = value;                    
                case 'prediction_horizon'
                    Np = value;
                case 'robust_horizon'
                    N_robust = value;
                case 'Kcem'
                    Kcem = value;
                case 'Tref'
                    Tref = value;
                case 'y_min'
                    y_min = value;
                case 'y_max'
                    y_max = value;
                case 'u_min'
                    u_min = value;
                case 'u_max'
                    u_max = value;
                case 'w_bound'
                    w_bound = value;
                case 'plant_model_file'
                    plant_model_file = value;
                case 'sampling_time'
                    ts = value;
                case 'CEMsp'
                    CEMsp = value;
                case 'Kcem_p'
                    Kcem_p = value;
                case 'Tref_p'
                    Tref_p = value;
                case 'Tmax'
                    Tmax = value;
                case 'rand_seed'
                    rand_seed = value;
                otherwise
                    warning(['Name "', name, '" not recognized. Value not assigned'])
            end
        end
    end

    %% load system matrices from Data model ID
    modelp = load(plant_model_file); % 2021 data (n4sid)
    model = load(ctrl_model_file); % 2021 data (n4sid)
    
    A = model.A;
    B = model.B;
    C = model.C;
    yss = model.yss'; % [Ts; I]
    uss = model.uss'; % [P; q]
    disp('Linear Model to be used for CONTROL:')
    disp('A: '); disp(A)
    disp('B: '); disp(B)
    disp('C: '); disp(C)
    disp('yss: '); disp(yss)

    Ap = modelp.A;
    Bp = modelp.B;
    Cp = modelp.C;
    yssp = modelp.yss; % [Ts; I]
    ussp = modelp.uss; % [P; q]
    disp('Linear Model to be used for the PLANT:')
    disp('A: '); disp(Ap)
    disp('B: '); disp(Bp)
    disp('C: '); disp(Cp)
    disp('yss: '); disp(yssp)

    x0 = x0 - yssp;
    myref = @(t) myRef_CEM(t, ts, CEMsp); % reference signal
    
    [~, nx] = size(A); % number of states
    [~, nu] = size(B); % number of inputs (P, q)
    [ny, ~] = size(C); % number of outputs (Ts, I)
    nyc = 1;         % number of controlled outputs
    nw = nx;         % process noise
    nv = ny;         % measurement noise

    %% load/set MPC info
    % constraint bounds in deviation variables for controller
    u_min = u_min - uss;
    u_max = u_max - uss;
    x_min = y_min - yss;
    x_max = y_max - yss;
    y_min = x_min;
    y_max = x_max;
    % Discrete uncertainty set
    Wset = [-w_bound, zeros(nw,1), w_bound];

    % initial variable guesses for solver
    u_init = (u_min+u_max)/2;
    x_init = (x_min+x_max)/2;
    y_init = (y_min+y_max)/2;
    
    %% create casadi functions for problem
    import casadi.*
    % casadi symbols
    x = SX.sym('x', nx);
    u = SX.sym('u', nu);
    w = SX.sym('w', nw);
    wp = SX.sym('wp', nw); % predicted uncertainty
    v = SX.sym('v', nv);

    % dynamics function (state evolution model for controller)
    xnext = A*x + B*u + wp;
    f = Function('f', {x,u,wp}, {xnext});

    % output equation (for control model)
    y = C*x;
    h = Function('h', {x}, {y});

    % controlled output equation
    ymeas = SX.sym('ymeas', ny);
    yc = ymeas(1);
    r = Function('r', {ymeas}, {yc});

    % dynamics function (state evolution model for plant)
    xnextp = A*x + B*u + w;
    fp = Function('fp', {x,u,w}, {xnextp});

    % output equation (for plant)
    yp = C*x + v;
    hp = Function('hp', {x,v}, {yp});

    % CEM output (for plant)
    CEM = Kcem_p^(Tref_p-(x(1)+yssp(1)))*ts/60;
    CEMadd = Function('CEMadd', {x}, {CEM});

    % stage cost (nonlinear CEM cost)
    lstg = Kcem^(Tref-(x(1)+wp(1)+yss(1)))*ts/60;
    lstage = Function('lstage', {x,wp}, {lstg});
    
    warm_start = 1;
    
    %% additional simulation parameters
    % measurement noise bounds
    v_min = 0*-0.01*ones(nv,1);
    v_max = 0*0.01*ones(nv,1);
    % process noise bounds
    w_min = -1*ones(nw,1);
    w_max = 1*ones(nw,1);
    
    %% pack away problem info
    ctrl_params = struct;
    ctrl_params.Np = Np;
    ctrl_params.N_robust = N_robust;
    ctrl_params.case_idx = case_idx;
    ctrl_params.Wset = Wset;
    
    ctrl_params.nu = nu;
    ctrl_params.nx = nx;
    ctrl_params.ny = ny;
    ctrl_params.nyc = nyc;
    ctrl_params.nw = nw;
    ctrl_params.u_min = u_min;
    ctrl_params.u_max = u_max;
    ctrl_params.x_min = x_min;
    ctrl_params.x_max = x_max;
    ctrl_params.y_min = y_min;
    ctrl_params.y_max = y_max;
    
    ctrl_params.u_init = u_init;
    ctrl_params.x_init = x_init;
    ctrl_params.y_init = y_init;

    ctrl_params.f = f;
    ctrl_params.h = h;
    ctrl_params.r = r;
    ctrl_params.lstage = lstage;
    ctrl_params.warm_start = warm_start;
    
    ctrl_params.yss = yss;
    ctrl_params.uss = uss;
    
    sim_params = struct;
    sim_params.myref = myref;
    sim_params.ts = ts;
    sim_params.x0 = x0;
    sim_params.rand_seed = rand_seed;
    
    sim_params.nu = nu;
    sim_params.nx = nx;
    sim_params.ny = ny;
    sim_params.nyc = nyc;
    sim_params.nv = nv;
    sim_params.nw = nw;
    
    sim_params.v_min = v_min;
    sim_params.v_max = v_max;
    sim_params.w_min = w_min;
    sim_params.w_max = w_max;

    sim_params.fp = fp;
    sim_params.hp = hp;
    sim_params.CEMadd = CEMadd;
    sim_params.Tmax = Tmax;

    sim_params.yss = yssp;
    sim_params.uss = ussp;
    
    sim_params.ctrl_params = ctrl_params;
    
    varargout{1} = struct;
end