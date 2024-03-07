close all; clear; clc;
addpath(genpath('./config'), genpath('./utils'))

%% user inputs
Nsim = 100;
font_size = 15;     % font size for plotting
line_width = 3;     % line width for plotting
set(0, 'DefaultLineLineWidth', line_width);
set(0, 'DefaultAxesFontSize', font_size);

%% load problem data
prob_info = two_masses_load_problem_info(Nsim);

%% set up exact controller
c = MPCController(prob_info.sys, prob_info.Np);

%% initialize simulation
loop = ClosedLoop(c, prob_info.sys);
data = loop.simulate(prob_info.x0, Nsim);

%% set up explicit controller
ec = c.toExplicit();

% test explicit controller simulation
loop = ClosedLoop(ec, prob_info.sys);
data_ec = loop.simulate(prob_info.x0, Nsim);

%% plot
Nplot = 100;

figure()
subplot(311)
plot((0:Nplot)*prob_info.ts, data.X(1,1:Nplot+1))
hold on
plot((0:Nplot)*prob_info.ts, data_ec.X(1,1:Nplot+1), ':')
ylim([-2,2])
ylabel('x_1')

subplot(312)
plot((0:Nplot)*prob_info.ts, data.X(2,1:Nplot+1))
hold on
plot((0:Nplot)*prob_info.ts, data_ec.X(2,1:Nplot+1), ':')
ylim([-2,2])
ylabel('x_2')

subplot(313)
stairs((0:Nplot-1)*prob_info.ts, data.U(1,1:Nplot))
hold on
stairs((0:Nplot-1)*prob_info.ts, data_ec.U(1,1:Nplot), ':')
ylabel('u_1')
ylim([-0.6,0.6])
xlabel('Time (seconds)')

figure()
histogram(data.cost)
hold on
histogram(data_ec.cost)

%% end
rmpath(genpath('./config'), genpath('./utils'))
