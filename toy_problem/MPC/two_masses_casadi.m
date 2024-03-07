clear; clc;

import casadi.*

k = 1;          % spring constant 
lam = 0;        % damping constant 
a = -2*k;
b = -2*lam;
c = k;
d = lam;

n = 4; % state dimension
m = 1; % input dimension

Acts = [zeros(n/2) eye(n/2);
    [a,c,b,d;
     c,a,d,b]];
Bcts = [zeros(n/2,m);
    [1;
    -1]];

% convert to discrete-time system
ts = 0.5;       % sampling time
A = expm(ts*Acts);
B = (Acts\(expm(ts*Acts)-eye(n)))*Bcts;

% objective matrices
Q = eye(n);
R = eye(m);

% state and control limits
Xmax = 4; Umax = 0.5;
xmin = -Xmax*ones(n,1);
xmax = Xmax*ones(n,1);
umin = -Umax*ones(m,1);
umax = Umax*ones(m,1);

% initial state
x0 = zeros(n,1);
x0(1) = 0.0;

N = 30;  % prediction horizon

% Declare model variables
x = SX.sym('x', n);
u = SX.sym('u', m);
w = SX.sym('w', n);
v = SX.sym('v', n);

% dynamics function (prediction model)
xnext = A*x + B*u;
f = Function('f', {x,u}, {xnext});

% output equation (for controller)
y = x;
h = Function('h', {x}, {y});

% stage cost
lstg = x'*Q*x+u'*R*u;
lstage = Function('lstage', {x,u}, {lstg});

% Start with an empty NLP
w = {};
w0 = [];
lbw = [];
ubw = [];
J = 0;
g = {};
lbg = [];
ubg = [];

% "Lift" initial conditions
X0 = MX.sym('X0', n);
w = {w{:}, X0}; % decision variable
lbw = [lbw; x0]; % lower bound on variable
ubw = [ubw; x0]; % upper bound on variable
w0 = [w0; x0]; % initial guess of variable

% Formulate the NLP
Xk = X0;
for k=0:N-1
    % New NLP variable for the control
    Uk = MX.sym(['U_' num2str(k)],m);
    w = {w{:}, Uk};
    lbw = [lbw; umin];
    ubw = [ubw;  umax];
    w0 = [w0;  zeros(m,1)];

    % Integrate till the end of the interval
    Xk_end = f(Xk,Uk);
    J = J + lstage(Xk,Uk);

    % New NLP variable for state at end of interval
    Xk = MX.sym(['X_' num2str(k+1)], n);
    w = {w{:}, Xk};
    lbw = [lbw; xmin];
    ubw = [ubw;  xmax];
    w0 = [w0; zeros(n,1)];

    % Add equality constraint
    g = {g{:}, Xk_end-Xk};
    lbg = [lbg; zeros(n,1)];
    ubg = [ubg; zeros(n,1)];
end

% Create a solver
prob = struct('f', J, 'x', vertcat(w{:}), 'g', vertcat(g{:}));
options = struct('print_time',false, ...
    'error_on_fail', false, ...
    'print_iter', false);
solver = qpsol('solver', 'qrqp', prob, options);

s0 = MX.sym('s0',n);

lbw_sym = MX(lbw);
ubw_sym = MX(ubw);
lbw_sym(1:n) = s0;
ubw_sym(1:n) = s0;

sol_sym = solver('x0', w0, 'lbx', lbw_sym, 'ubx', ubw_sym,...
            'lbg', lbg, 'ubg', ubg);

% Mapping from initial state to control action
function_name = 'mpc_implicit';
% opts = struct('record_time', true, 'error_on_fail', false);
mpc_implicit = Function(function_name,{s0},{sol_sym.x(n+1)});

%% generate code
opts = struct('main', true, ...
    'mex', true, ...
    'with_header', true);
mpc_implicit.generate('mpc.c',opts);

mex mpc.c -largeArrayDims -outdir codegen/mex/mpc/ -output mpc_mex

addpath('codegen/mex/mpc')
disp(mpc_mex('mpc_implicit', [0.0,0.1,0.0,0.1]))
disp(mpc_mex('mpc_implicit', [-1.77,-2.3,3.4,3.67]))

%% remove added paths
rmpath('codegen/mex/mpc')

