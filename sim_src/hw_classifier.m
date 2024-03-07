clear; clc;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% this file trains the hardware classifier
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% NOTE: Must be run with higher release of MATLAB if hyperparameter
% optimization is set to true. Newer versions of MATLAB will include a version 
% of fitcnet that can perform hyperparameter optimization with BO
hp_opt = false;
save_date = '2023_09_14'
if hp_opt
    save_file = ['./saved/workspace_HW_classifier_', save_date, '.mat'];     % filename to save data for future use; leave empty if no save is desired
else
    save_file = ['./saved/workspace_HW_classifier_', save_date, '_noBO.mat'];
end

%% load and extract the saved feasibility data
data1 = load('./saved/workspace_HW_classifier_data_gen_2023_09_14.mat', ...
    'feas', 'fxp_wl_opts', 'H_opts', 'L', 'loop_opt');
out1 = data1.feas;
fxp_wl_opts = data1.fxp_wl_opts;
loop_opt = data1.loop_opt;
H_opts = data1.H_opts;

[XX, ~] = meshgrid(1:length(H_opts), 1:length(fxp_wl_opts));

[r,c] = size(XX);
WordLength = [];
Nodes = [];
Feasible = [];
for i = 1:c
    for j = 1:r
        WordLength = [WordLength; fxp_wl_opts(j)];
        Nodes = [Nodes; H_opts(i)];
        Feasible = [Feasible; out1(i,j)];
    end
end
% create a table with the extracted feasibility data for ease of passing to the CV partition and training
data = table(Nodes, WordLength, Feasible);

% create cross-validation (CV) partition for training the classifier
rng("default") % For reproducibility of the partition
c = cvpartition(data.Feasible,"Holdout",0.20);
trainingIndices = training(c); % Indices for the training set
testIndices = test(c); % Indices for the test set
dataTrain = data(trainingIndices,:);
dataTest = data(testIndices,:);

% train a neural network-based classifier
rng("default") % For reproducibility
if hp_opt
    Mdl = fitcnet(dataTrain, "Feasible", "OptimizeHyperparameters", "auto", ...
        "HyperparameterOptimizationOptions", ...
        struct("AcquisitionFunctionName", "expected-improvement-plus", ...
        "MaxObjectiveEvaluations", 100))
else
    Mdl = fitcnet(dataTrain, "Feasible")
end

% compute the accuracy of the classifier
modelAccuracy = 1 - loss(Mdl, dataTest, "Feasible", ...
    "LossFun", "classiferror")
% plot a confusion matrix to view the accuracy of the classifier
confusionchart(dataTest.Feasible, predict(Mdl,dataTest))

fitcnet_out = predict(Mdl, dataTest);

%% create casadi function for faster evaluation
% extract model/classifier information
act_fun = Mdl.Activations;
H = Mdl.LayerSizes;
out_act_fun = Mdl.OutputLayerActivation;

import casadi.*
in = SX.sym('in', 2);

L = length(Mdl.LayerWeights);
x = Mdl.LayerWeights{1} * in + Mdl.LayerBiases{1};
x = max(x, 0);
for l = 1:L-2
    x = Mdl.LayerWeights{l} * x + Mdl.LayerBiases{l};
    x = max(x, 0);
end
x = Mdl.LayerWeights{end} * x + Mdl.LayerBiases{end};
out = x / (sum1(exp(x))); % softmax step

cas_classifier = Function('cas_classifier', {in}, {out});

in_test = [dataTest.Nodes, dataTest.WordLength];
cas_out = cas_classifier(in_test');
[~,idx] = max(full(cas_out));

% check the CasADi implementation to make sure it matches
fitcnet_out == idx'-1

% plot a confusion matrix for quick visual comparison
figure()
confusionchart(dataTest.Feasible, idx'-1)

%% save workspace data
if ~isempty(save_file)
    save(save_file)
end