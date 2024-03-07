function prob_info = masses_load_problem_info(Nsim, varargin)

    rand('state',0); % make
    k = 1;          % spring constant 
    lam = 0;        % damping constant 
    a = -2*k;
    b = -2*lam;
    c = k;
    d = lam;
    
    n = 12; % state dimension
    m = 3; % input dimension

    Acts = [zeros(n/2) eye(n/2);
        [a,c,0,0,0,0,b,d,0,0,0,0;
         c,a,c,0,0,0,d,b,d,0,0,0;
         0,c,a,c,0,0,0,d,b,d,0,0;
         0,0,c,a,c,0,0,0,d,b,d,0;
         0,0,0,c,a,c,0,0,0,d,b,d;
         0,0,0,0,c,a,0,0,0,0,d,b]];

    Bcts = [zeros(n/2,m);
        [1, 0, 0;
        -1, 0, 0;
         0, 1, 0;
         0, 0, 1;
         0,-1, 0;
         0, 0,-1]];

    % convert to discrete-time system
    ts = 0.5;       % sampling time
    A = expm(ts*Acts);
    B = (Acts\(expm(ts*Acts)-eye(n)))*Bcts;
    sys = LTISystem('A', A, 'B', B, 'Ts', ts);

    % objective matrices
    Q = eye(n);
    R = eye(m);
    sys.x.penalty = QuadFunction(Q);
    sys.u.penalty = QuadFunction(R);

    % state and control limits
    Xmax = 4; Umax = 0.5;
    xmin = -Xmax*ones(n,1);
    xmax = Xmax*ones(n,1);
    umin = -Umax*ones(m,1);
    umax = Umax*ones(m,1);
    sys.x.min = xmin;
    sys.x.max = xmax;
    sys.u.min = umin;
    sys.u.max = umax;

    % process noise trajectory
    nsteps = Nsim;
    w = 2*rand(n,nsteps)-1; w(1:n/2,:) = 0; w = 0.5*w;
    W = (1/12)*diag([0;0;0;0;0;0;1;1;1;1;1;1]);
    Wsim = w;

    % initial state
    x0 = zeros(n,1);
    x0(1) = 1.0;

    % fast MPC parameters
    T = 30;                % time horizon

    %% create casadi functions for problem
    % casadi symbols
    import casadi.*
    x = SX.sym('x', n);
    u = SX.sym('u', m);
    w = SX.sym('w', n);
    v = SX.sym('v', n);

    % dynamics function (prediction model)
    xnext = A*x + B*u;
    f = Function('f', {x,u}, {xnext});

    % output equation (for control model)
    y = x;
    h = Function('h', {x}, {y});

    % plant model
    xnextp = A*x + B*u + w;
    fp = Function('fp', {x,u,w}, {xnextp});

    % output equation (for plant)
    yp = x + v;
    hp = Function('hp', {x,v}, {yp});

    % stage cost
    lstg = x'*Q*x+u'*R*u;
    lstage = Function('lstage', {x,u}, {lstg});    
    
    %% pack away problem info
    prob_info = struct;
    prob_info.Np = T;
%     prob_info.myref = myref;
    prob_info.ts = ts;
    prob_info.x0 = x0;
    prob_info.rand_seed = 0;
    prob_info.Wsim = Wsim;
    prob_info.sys = sys;
    prob_info.Q = Q;
    prob_info.R = R;

    prob_info.nu = m;
    prob_info.nx = n;
    prob_info.ny = n;
    prob_info.nyc = n;
%     prob_info.nv = nv;
%     prob_info.nw = nw;
%     prob_info.nd = nd;
    
    prob_info.u_min = umin;
    prob_info.u_max = umax;
    prob_info.x_min = xmin;
    prob_info.x_max = xmax;
    prob_info.y_min = xmin;
    prob_info.y_max = xmax;
%     prob_info.v_min = v_min;
%     prob_info.v_max = v_max;
%     prob_info.w_min = w_min;
%     prob_info.w_max = w_max;

    prob_info.u_init = zeros(m,1);
    prob_info.x_init = zeros(n,1);
    prob_info.y_init = zeros(n,1);

    prob_info.f = f;
    prob_info.h = h;
    prob_info.fp = fp;
    prob_info.hp = hp;
    prob_info.lstage = lstage;
    prob_info.warm_start = true;
    
    prob_info.xssp = zeros(n,1);
    prob_info.ussp = zeros(m,1);
    prob_info.xss = zeros(n,1);
    prob_info.uss = zeros(m,1);
    
end