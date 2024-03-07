function prob_info = economic_load_problem_info(varargin)
    import casadi.*
    ts = 0.5; % sampling time (0.5 for 2021 data)
    rand_seed = 520;
    Kcem = 0.5;
    Tref = 43.0;

    Np = 10;      % Prediction horizon (ensure it is the same as DNN)

    %% load system matrices from Data model ID
    % modelp = load('APPJmodel_2021_06_08_15h57m55s_n4sid_50split.mat'); % 2021 data (n4sid)
    % model = load('APPJmodel_2021_06_08_15h57m55s_n4sid_alldata.mat'); % 2021 data (n4sid)
    model = load('APPJmodel_2022_07_07_12h02m37s.mat') % 2022 data (n4sid)

    A = model.A;
    B = model.B;
    C = model.C;
    xss = model.yss'; % [Ts; I]
    uss = model.uss'; % [P; q]
    disp('Linear Model to be used for CONTROL:')
    disp('A: '); disp(A)
    disp('B: '); disp(B)
    disp('C: '); disp(C)
    disp('xss: '); disp(xss)

    % Ap = modelp.A;
    % Bp = modelp.B;
    % Cp = modelp.C;
    % xssp = modelp.yss; % [Ts; I]
    % ussp = modelp.uss; % [P; q]
    % disp('Linear Model to be used for the PLANT:')
    % disp('A: '); disp(Ap)
    % disp('B: '); disp(Bp)
    % disp('C: '); disp(Cp)
    % disp('xss: '); disp(xssp)

    x0 = zeros(2,1);%[36-xssp(1);0] % initial state
    myref = @(t) myRef_CEM(t, ts); % reference signal

    [~, nx] = size(A); % number of states
    [~, nu] = size(B); % number of inputs (q, P)
    [ny, ~] = size(C); % number of outputs (Ts, I)
    nyc = 1;         % number of controlled outputs
    nd = 0;        % offset-free disturbances
    nw = nx;         % process noise
    nv = ny;         % measurement noise

    %% load/set MPC info
    % constraint bounds
    u_min = [1.5; 1.5] - uss;
    u_max = [5.0; 5.0] - uss;
    x_min = [25.0; 0.0] - xss;
    x_max = [45.0; 80.0] - xss;
    y_min = x_min;
    y_max = x_max;
    v_min = 0*-0.01*ones(nv,1);
    v_max = 0*0.01*ones(nv,1);
    w_min = 0*-0.02/ts*ones(nw,1);
    w_max = 0*0.02/ts*ones(nw,1);

    % initial variable guesses
    u_init = (u_min+u_max)/2;
    x_init = (x_min+x_max)/2;
    y_init = (y_min+y_max)/2;

    %% create casadi functions for problem
    % casadi symbols
    x = SX.sym('x', nx);
    u = SX.sym('u', nu);
    w = SX.sym('w', nw);
    v = SX.sym('v', nv);
    yref = SX.sym('yref', nyc);

    % dynamics function (prediction model)
    xnext = A*x + B*u;
    f = Function('f', {x,u}, {xnext});

    % output equation (for control model)
    y = C*x;
    h = Function('h', {x}, {y});

    % controlled output equation
    ymeas = SX.sym('ymeas', ny);
    yc = ymeas(1);
    r = Function('r', {ymeas}, {yc});

    % % plant model
    % xnextp = A*x + B*u + w;
    % fp = Function('fp', {x,u,w}, {xnextp});
    %
    % % output equation (for plant)
    % yp = C*x + v;
    % hp = Function('hp', {x,v}, {yp});

    % % CEM output (for plant)
    % CEM = Kcem^(Tref-(x(1)+xssp(1)))*ts/60;
    % CEMadd = Function('CEMadd', {x}, {CEM});

    % stage cost (nonlinear CEM cost)
    lstg = Kcem^(Tref-(x(1)+xss(1)))*ts/60;
    lstage = Function('lstage', {x}, {lstg});

    warm_start = 1;

    %% pack away problem info
    prob_info = struct;
    prob_info.Np = Np;
    prob_info.myref = myref;
    prob_info.ts = ts;
    prob_info.x0 = x0;
    prob_info.rand_seed = rand_seed;

    prob_info.nu = nu;
    prob_info.nx = nx;
    prob_info.ny = ny;
    prob_info.nyc = nyc;
    prob_info.nv = nv;
    prob_info.nw = nw;
    prob_info.nd = nd;

    prob_info.u_min = u_min;
    prob_info.u_max = u_max;
    prob_info.x_min = x_min;
    prob_info.x_max = x_max;
    prob_info.y_min = y_min;
    prob_info.y_max = y_max;
    prob_info.v_min = v_min;
    prob_info.v_max = v_max;
    prob_info.w_min = w_min;
    prob_info.w_max = w_max;

    prob_info.u_init = u_init;
    prob_info.x_init = x_init;
    prob_info.y_init = y_init;

    prob_info.f = f;
    prob_info.h = h;
    prob_info.r = r;
    % prob_info.fp = fp;
    % prob_info.hp = hp;
    % prob_info.CEMadd = CEMadd;
    prob_info.lstage = lstage;
    prob_info.warm_start = warm_start;

    % prob_info.xssp = xssp;
    % prob_info.ussp = ussp;
    prob_info.xss = xss;
    prob_info.uss = uss;
end
