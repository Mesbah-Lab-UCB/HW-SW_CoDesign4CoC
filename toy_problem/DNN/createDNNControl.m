clear; clc; close all
addpath(genpath('../config'), genpath('../utils'))

%% run two_masses_casadi.m to obtain implicit controller
two_masses_casadi_reduced()

%% get/create problem info
Nsim = 100;
prob_info = two_masses_load_problem_info(Nsim);

%% get training data for DNN
Nsamp = 5000;
gen_data = false;
tdata_filename = './training_data_unscaled.mat';
if gen_data
    data = generateTrainingData(c, Nsim, prob_info, Nsamp);
    save(tdata_filename, 'data')
else
    load(tdata_filename, 'data')
end

%% create DNN controller
cdnn = DNN();
inputs = data.inputs;
outputs = data.outputs;
cdnn = cdnn.load_data(inputs, outputs, data);

activation_function = 'relu';

Hs = 3:5;
Ls = 2:4;
mses = zeros(length(Hs), length(Ls));
for i = 1:length(Hs)
    for j = 1:length(Ls)
        m = [];
        for n = 1:5
            cdnn = cdnn.build_neural_network(Hs(i),Ls(j),activation_function);
            [cdnn, mse] = cdnn.train_neural_network();
            m = [m; mse];
        end
        mses(i,j) = mean(m);
    end
end

[min_val, min_idx] = min(mses,[], 'all','linear');
[r,c] = ind2sub([length(Hs),length(Ls)],min_idx);

H = Hs(r);
L = Ls(c);

% H = 5;
% L = 2;
cdnn = cdnn.build_neural_network(H,L,activation_function);
[cdnn, mse] = cdnn.train_neural_network();

cdnn = cdnn.create_casadi_function(true);

%%
rmpath(genpath('../config'), genpath('../utils'))
