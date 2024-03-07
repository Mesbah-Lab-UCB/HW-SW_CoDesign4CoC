close all; clear; clc;
set(0, 'DefaultLineLineWidth', 2);
set(0, 'DefaultAxesFontSize', 15);

%% add package paths
addpath(genpath('./config'), genpath('./utils'))
casadipath = '~/casadi-linux-matlab-v3.5.5';
% casadipath = '~/casadi-osx-matlabR2015a-v3.5.5';
s = pathsep;
pathStr = path;
onPath = contains(pathStr, casadipath(3:end), 'IgnoreCase', ispc);
if ~onPath
    addpath(casadipath)
end

%% user inputs
Nsim = 100;
Nrep = 100;
font_size = 15;     % font size for plotting
line_width = 3;     % line width for plotting
set(0, 'DefaultLineLineWidth', line_width);
set(0, 'DefaultAxesFontSize', font_size);

%% load problem data
prob_info = two_masses_load_problem_info(Nsim);
prob_info.rand_seed = 42;

%% set up controllers
% assume that the controllers are located in subfolders; these are blank
% containers for the simulation
mpc = MPC(prob_info); addpath('MPC/codegen/mex/mpc');
empc = EMPCController(); addpath('EMPC/codegen/mex/empc')
dnn = DNN(); addpath('DNN/codegen/mex/dnn');

%% set up Simulations
sim1 = Simulation(Nsim, prob_info);
sim2 = Simulation(Nsim, prob_info);
sim3 = Simulation(Nsim, prob_info);

%% run closed-loop simulations

[sim1, sim_data1] = sim1.run_closed_loop(mpc, [], 'mex_exist', true);
[sim2, sim_data2] = sim2.run_closed_loop(empc, [], 'mex_exist', true);
[sim3, sim_data3] = sim3.run_closed_loop(dnn, [], 'mex_exist', true);

for i = 2:Nrep
    prob_info.rand_seed = 42*i;
    
    sim1 = sim1.set_prob_info(prob_info);
    sim2 = sim2.set_prob_info(prob_info);
    sim3 = sim3.set_prob_info(prob_info);
    
    [sim1, sim_data1a] = sim1.run_closed_loop(mpc, [], 'mex_exist', true);
    [sim2, sim_data2a] = sim2.run_closed_loop(empc, [], 'mex_exist', true);
    [sim3, sim_data3a] = sim3.run_closed_loop(dnn, [], 'mex_exist', true);
    
    sim_data1 = Simulation.combine_sim_data(sim_data1, sim_data1a);
    sim_data2 = Simulation.combine_sim_data(sim_data2, sim_data2a);
    sim_data3 = Simulation.combine_sim_data(sim_data3, sim_data3a);
end

%% view computation time stats (as evaluated using tic/toc)
fprintf('MPC ctime stats:\n')
print_ctime_stats(sim_data1);
fprintf('EMPC ctime stats:\n')
print_ctime_stats(sim_data2);
fprintf('DNN-C ctime stats:\n')
print_ctime_stats(sim_data3);

%% save sim_datas
sim_data_mpc = sim_data1;
sim_data_empc = sim_data2;
sim_data_dnn = sim_data3;
save('./saved_sim_data.mat', 'sim_data_mpc', 'sim_data_empc', 'sim_data_dnn')

%% plot trajectories/profiles
Nplot = (Nsim+1)*Nrep-1;
Nplotu = Nsim*Nrep-1;

figure()
subplot(211)
hold on
stairs((0:Nplot)*prob_info.ts, sim_data1.Xsim(1,1:Nplot+1), 'b-', 'DisplayName', 'MPC')
stairs((0:Nplot)*prob_info.ts, sim_data2.Xsim(1,1:Nplot+1), 'm--', 'DisplayName', 'EMPC')
stairs((0:Nplot)*prob_info.ts, sim_data3.Xsim(1,1:Nplot+1), 'g:', 'DisplayName', 'DNN')
ylim([-4.5,4.5])
ylabel('x_1')
legend()

subplot(212)
hold on
stairs((0:Nplotu)*prob_info.ts, sim_data1.Usim(1,1:Nplotu+1), 'b-', 'DisplayName', 'MPC')
stairs((0:Nplotu)*prob_info.ts, sim_data2.Usim(1,1:Nplotu+1), 'm--', 'DisplayName', 'EMPC')
stairs((0:Nplotu)*prob_info.ts, sim_data3.Usim(1,1:Nplotu+1), 'g:', 'DisplayName', 'DNN')
ylabel('u_1')
ylim([-0.6,0.6])
xlabel('Time (seconds)')

figure()
subplot(131)
rectangle('Position', [-4,-4,8,8], 'LineStyle', '--', 'LineWidth', line_width);
hold on
subplot(132)
rectangle('Position', [-4,-4,8,8], 'LineStyle', '--', 'LineWidth', line_width);
hold on
subplot(133)
rectangle('Position', [-4,-4,8,8], 'LineStyle', '--', 'LineWidth', line_width);
hold on
for i = 1:Nrep
%     figure()
%     hold on
%     rectangle('Position', [-4,-4,8,8], 'LineStyle', '--', 'LineWidth', line_width);
    if i == 1
        subplot(131)
        lh = plot(sim_data1.Xsim(1,(i-1)*Nsim+1:i*Nsim+1), sim_data1.Xsim(2,(i-1)*Nsim+1:i*Nsim+1), 'bx-', 'DisplayName', 'MPC', 'MarkerIndices', [Nsim+1], 'MarkerSize', 10, 'MarkerEdgeColor', 'r', 'MarkerFaceColor', 'r');
        set(lh, 'Color', [lh.Color, 0.25], 'LineWidth', 1)
        subplot(132)
        lh = plot(sim_data2.Xsim(1,(i-1)*Nsim+1:i*Nsim+1), sim_data2.Xsim(2,(i-1)*Nsim+1:i*Nsim+1), 'mx-', 'DisplayName', 'EMPC', 'MarkerIndices', [Nsim+1], 'MarkerSize', 10, 'MarkerEdgeColor', 'r', 'MarkerFaceColor', 'r');
        set(lh, 'Color', [lh.Color, 0.25], 'LineWidth', 1)
        subplot(133)
        lh = plot(sim_data3.Xsim(1,(i-1)*Nsim+1:i*Nsim+1), sim_data3.Xsim(2,(i-1)*Nsim+1:i*Nsim+1), 'gx-', 'DisplayName', 'DNN', 'MarkerIndices', [Nsim+1], 'MarkerSize', 10, 'MarkerEdgeColor', 'r', 'MarkerFaceColor', 'r');
        set(lh, 'Color', [lh.Color, 0.25], 'LineWidth', 1)
    else
        subplot(131)
        lh = plot(sim_data1.Xsim(1,(i-1)*Nsim+1:i*Nsim+1), sim_data1.Xsim(2,(i-1)*Nsim+1:i*Nsim+1), 'bx-', 'MarkerIndices', [Nsim+1], 'MarkerSize', 10, 'MarkerEdgeColor', 'r', 'MarkerFaceColor', 'r');
        subplot(132)
        set(lh, 'Color', [lh.Color, 0.5], 'LineWidth', 1)
        lh = plot(sim_data2.Xsim(1,(i-1)*Nsim+1:i*Nsim+1), sim_data2.Xsim(2,(i-1)*Nsim+1:i*Nsim+1), 'mx-', 'MarkerIndices', [Nsim+1], 'MarkerSize', 10, 'MarkerEdgeColor', 'r', 'MarkerFaceColor', 'r');
        set(lh, 'Color', [lh.Color, 0.5], 'LineWidth', 1)
        subplot(133)
        lh = plot(sim_data3.Xsim(1,(i-1)*Nsim+1:i*Nsim+1), sim_data3.Xsim(2,(i-1)*Nsim+1:i*Nsim+1), 'gx-', 'MarkerIndices', [Nsim+1], 'MarkerSize', 10, 'MarkerEdgeColor', 'r', 'MarkerFaceColor', 'r');
        set(lh, 'Color', [lh.Color, 0.5], 'LineWidth', 1)
    end
end
subplot(131)
xlabel('x_1'); ylabel('x_2'); xlim([-4.5,4.5]); ylim([-4.5,4.5])
subplot(132)
xlabel('x_1'); ylabel('x_2'); xlim([-4.5,4.5]); ylim([-4.5,4.5])
subplot(133)
xlabel('x_1'); ylabel('x_2'); xlim([-4.5,4.5]); ylim([-4.5,4.5])
% legend({'MPC', 'EMPC', 'DNN'},'Location', 'southeast')

figure()
subplot(311)
hold on
histogram(sim_data1.Jsim)
xline(mean(sim_data1.Jsim), '--k', num2str(mean(sim_data1.Jsim)))
title('MPC')
subplot(312)
histogram(sim_data2.Jsim)
xline(mean(sim_data2.Jsim), '--k', num2str(mean(sim_data2.Jsim)))
title('EMPC')
subplot(313)
histogram(sim_data3.Jsim)
xline(mean(sim_data3.Jsim), '--k', num2str(mean(sim_data3.Jsim)))
title('DNN')

%% removed added paths
rmpath(genpath('./utils'), genpath('./config'))
rmpath('./MPC/codegen/mex/mpc')
rmpath('./EMPC/codegen/mex/empc')
rmpath('./DNN/codegen/mex/dnn')

disp('done.')



%% helper functions
function print_ctime_stats(sim_data)
    ctime = sim_data.ctime;
    fprintf('Total Runtime: %.3e s\n', sum(ctime))
    fprintf('Average Runtime: %.3e s\n', mean(ctime))
    fprintf('Maximum Runtime: %.3e s\n', max(ctime))
    fprintf('Minimum Runtime: %.3e s\n', min(ctime))
    fprintf('Standard Deviation: %.3e s\n', std(ctime))
end