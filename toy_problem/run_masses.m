close all; clear; clc;

%% add package paths
addpath(genpath('./config'), genpath('./utils'))
% casadipath = '~/casadi-linux-matlab-v3.5.5';
casadipath = '~/casadi-osx-matlabR2015a-v3.5.5'; % add the path to CasADi according to your own system configuration
s = pathsep;
pathStr = path;
onPath = contains(pathStr, casadipath(3:end), 'IgnoreCase', ispc);
if ~onPath
    addpath(casadipath)
end

%% user inputs
Nsim = 100; % simulation horizon
font_size = 15;     % font size for plotting
line_width = 3;     % line width for plotting
set(0, 'DefaultLineLineWidth', line_width);
set(0, 'DefaultAxesFontSize', font_size);

%% load problem data
prob_info = two_masses_load_problem_info(Nsim);

%% set up controller
c = NominalMPC(prob_info);
c = c.get_mpc();
[c, res, feas] = c.solve_mpc(); % do test run

%% initialize simulation
sim = Simulation(Nsim, prob_info);
% run simulation
[sim, sim_data] = sim.run_closed_loop(c, []);
disp('sim_data fields:')
disp(fieldnames(sim_data))

%% plot
Nplot = 100;
ctime = sim_data.ctime;
fprintf('Total Runtime: %.4f s\n', sum(ctime))
fprintf('Average Runtime: %.4f s\n', mean(ctime))

% plot the states and inputs
figure()
subplot(211)
plot((0:Nplot)*prob_info.ts, sim_data.Xsim(1,1:Nplot+1))
ylim([-2,2])
ylabel('x_1')

subplot(212)
stairs((0:Nplot-1)*prob_info.ts, sim_data.Usim(1,1:Nplot))
ylabel('u_1')
ylim([-0.6,0.6])
xlabel('Time (seconds)')

% plot a histogram of stage costs
figure()
histogram(sim_data.Jsim)

disp('done.')