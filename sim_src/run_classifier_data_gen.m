close all; clear; clc;

%% add package paths
addpath(genpath('./config'), genpath('./utils'),genpath('../Model_ID'),genpath('./hdlcoder_fullDNN'))
casadipath = '~/casadi-linux-matlab-v3.5.5';
% casadipath = '~/casadi-osx-matlabR2015a-v3.5.5';
s = pathsep;
pathStr = path;
onPath = contains(pathStr, casadipath(3:end), 'IgnoreCase', ispc);
if ~onPath
    addpath(casadipath)
end

%% user inputs
save_date = '2023_09_14';
save_file = ['./saved/workspace_HW_classifier_data_gen', save_date, '.mat'];     % filename to save data for future use; leave empty if no save is desired
font_size = 15;     % font size for plotting
line_width = 2;     % line width for plotting
dnn_trn_file = './saved/dnn_trn_data_5000samp.mat'; % file which stores the dnn training data (if not generating training data)
rng(520)

set(0, 'DefaultLineLineWidth', line_width);
set(0, 'DefaultAxesFontSize', font_size);


%% initialize DNN
L = 3;

H_opts = 2:10;
fxp_wl_opts = 10:32;
% loop_opt_opts = {'LoopNone', 'StreamLoops', 'UnrollLoops'};
% feas = zeros(length(10:32),length(loop_opt_opts));
loop_opt = 'LoopNone';
feas = zeros(length(H_opts), length(fxp_wl_opts));

for h = 1:length(H_opts)
    for fwl = 1:length(fxp_wl_opts)
%         for lo = 1:length(loop_opt_opts)
        dnn = DNN();
        dnn = dnn.set_data(dnn_trn_file);
        disp('Building Neural Network...')
        dnn = dnn.build_neural_network(H_opts(h),L,'relu');
        disp('Training Neural Network...')
        dnn = dnn.train_neural_network();

        % generate MATLAB Function of neural network
        % NOTE: remember to scale inputs/outputs when using this function!!
        rmpath(casadipath)
        genFunction(dnn.net, './hdlcoder_fullDNN/plasma_nn.m', 'MatrixOnly', 'yes')
        addpath(casadipath)

        %% test run of a hw controller
        sf.input_min = dnn.input_min;
        sf.input_max = dnn.input_max;
        sf.output_min = dnn.output_min;
        sf.output_max = dnn.output_max;

        hw_params = struct();
        hw_params.fxp_word_length = fxp_wl_opts(fwl);
        hw_params.loopOpt = loop_opt;

        try
            remove_codegen_project();

            hw_ctrl = HWController('plasma_nn_wrapper', 'test_fullDNN', sf);
            hw_ctrl = hw_ctrl.buildController(hw_params);
            feas(h, fwl) = 1;
        catch e
            disp('Potential error occurred during HW code generation')
            disp(e)
            feas(h, fwl) = 0;
        end
%         end
    end
end


%% save data
if ~isempty(save_file)
    save(save_file)
end

%% remove package paths
rmpath(genpath('./config'), genpath('./utils'),genpath('../Model_ID'),genpath('./hdlcoder_fullDNN'))
