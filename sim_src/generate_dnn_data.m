function [save_file] = generate_dnn_data(Nsamp, varargin)
% function to collect data for training a neural network to approximate a
% MPC

    %% add package paths
    addpath(genpath('./config'), genpath('./utils'),genpath('../Model_ID'),genpath('./hdlcoder_fullDNN'))
    casadipath = '~/casadi-linux-matlab-v3.5.5';
    addpath(casadipath)

    open_loop_data = false;
    Nsim = 100;
    dnn = DNN();
    save_file = './saved/dnn_trn_data.mat';
    exp_runs = false;
    if nargin > 1
        for i = 1:2:length(varargin)
            name = varargin{i};
            value = varargin{i+1};
            switch name
                case 'open_loop_data'
                    open_loop_data = value;
                case 'Nsim'
                    if open_loop_data
                        warning('Nsim not needed!')
                    else
                        Nsim = value;
                    end
                case 'dnn_obj'
                    dnn = value;
                case 'save_file'
                    if isempty(value)
                        warning('Save file for DNN training data not specified! Using the default ./saved/dnn_trn_data.mat')
                        save_file = './saved/dnn_trn_data.mat';
                    else
                        save_file = value;
                    end
                case 'exp_runs'
                    exp_runs = value;
                otherwise
                    warning('Name-Value pair does not exist.')
            end
        end
    end

    %% load problem data
    if exp_runs
        prob_info = multistage_load_problem_info_exp();
    else
        prob_info = multistage_load_problem_info();
    end

    %% set up controller
    c = MultistageMPC(prob_info);
    c = c.get_mpc();

    %% collect training data
    disp('Collecting training data...')
    if open_loop_data
        dnn = dnn.collect_training_data_open_loop(c, Nsamp);
    else
        dnn = dnn.collect_training_data_closed_loop(c, Nsamp, Nsim);
    end

    inputs = dnn.inputs;
    outputs = dnn.outputs;
    input_min = dnn.input_min;
    input_max = dnn.input_max;
    output_min = dnn.output_min;
    output_max = dnn.output_max;

    save(save_file, 'inputs', 'outputs', 'input_min', 'input_max', 'output_min', 'output_max')

    %% remove package paths
    rmpath(genpath('./config'), genpath('./utils'),genpath('../Model_ID'),genpath('./hdlcoder_fullDNN'))
end
