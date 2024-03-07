classdef DNN < handle
    properties
        inputs
        outputs
        input_min
        input_max
        output_min
        output_max
        net
        netca
        W
        b
    end

    methods
        function [self] = collect_training_data_open_loop(self, c, Nsamp, sim_params)
            nx = c.prob_info.nx;
            nu = c.prob_info.nu;
            nyc = c.prob_info.nyc;
            x_min = c.prob_info.x_min;
            x_max = c.prob_info.x_max;
            if strcmp(c.mpc_type, 'economic') || strcmp(c.mpc_type, 'multistage')
                myref = sim_params.myref;
                if strcmp(c.mpc_type, 'multistage')
                    Wset = c.prob_info.Wset;
                end
            end
            rng(rand_seed)

            % generate a set of feasible inputs and outputs for training
            % (open loop generation)
            input_data = zeros(nx+nyc,Nsamp);
            output_data = zeros(nu,Nsamp);
            for i = 1:Nsamp
                c.reset_initial_guesses();

                if strcmp(c.mpc_type, 'economic') || strcmp(c.mpc_type, 'multistage')
                    rand_x = x_min + (x_max-x_min) .* rand(nx,1);
                    rand_cem0 = myref(0) * rand(nyc,1);

                    if strcmp(c.mpc_type, 'multistage')
                        c.set_parameters({rand_x, myref(0), rand_cem0, Wset}, false);
                    else
                        c.set_parameters({rand_x, myref(0), rand_cem0}, false);
                    end
                    input_data(:,i) = [rand_x; rand_cem0];
                else
                    error('Controller type not supported!')
                end
                [c, res, ~] = c.solve_mpc();
                output_data(:,i) = res.U;
            end

            % scale to [-1,1]
            self.input_min = min(input_data,[],2);
            self.input_max = max(input_data,[],2);
            self.output_min = min(output_data,[],2);
            self.output_max = max(output_data,[],2);
            in_range = self.input_max - self.input_min;
            out_range = self.output_max - self.output_min;
            self.inputs = 2*(input_data - self.input_min)./(in_range) - 1;
            self.outputs = 2*(output_data - self.output_min)./(out_range) - 1;
        end
        
        function [self] = collect_training_data_closed_loop(self, c, Nsamp, Nsim, sim_params)
            nx = sim_params.nx;
            ny = sim_params.ny;
            nu = sim_params.nu;
            nyc = sim_params.nyc;
            nw = sim_params.nw;
            nv = sim_params.nv;
            x_min = c.prob_info.x_min;
            x_max = c.prob_info.x_max;
            w_min = sim_params.w_min;
            w_max = sim_params.w_max;
            fp = sim_params.fp;
            hp = sim_params.hp;
            rand_seed = sim_params.rand_seed;
            if strcmp(c.mpc_type, 'economic') || strcmp(c.mpc_type, 'multistage')
                myref = sim_params.myref;
                if strcmp(c.mpc_type, 'multistage')
                    Wset = c.prob_info.Wset;
                end
            else
                error('MPC type not supported.')
            end
            rng(rand_seed)

            Ncl = ceil(Nsamp/Nsim);

            CL_training_data = cell(Ncl);
            for i = 1:Ncl
                % initialize container variables to store simulation data
                States = zeros(nx,Nsim+1);
                Outputs = zeros(ny,Nsim+1);
                Inputs = zeros(nu,Nsim);
                Disturbances = zeros(nw,Nsim);
                Objective = zeros(1,Nsim);
                Reference = zeros(nyc,Nsim);

                if strcmp(c.mpc_type, 'economic') || strcmp(c.mpc_type, 'multistage')
                    CEMadd = sim_params.CEMadd;
                    CEM = zeros(1,Nsim+1);
                else
                    error('Unsupported MPC type')
                end

                % randomly initialize an initial state(s) and reference
                % point
                Xcl = x_min + (x_max - x_min) .* rand(nx,1);
                if strcmp(c.mpc_type, 'economic') || strcmp(c.mpc_type, 'multistage')
                    CEM(:,1) = 0.0;
                end

                States(:,1) = Xcl;
                c.reset_initial_guesses();
                for k = 1:Nsim
                    if mod(k, 60) == 0
                        sprintf('CL# %d, Time Step %d', i, k)
                    end

                    Reference(:,k) = myref(k);

                    if strcmp(c.mpc_type, 'economic')
                        c.set_parameters({States(:,k), Reference(:,k), CEM(:,k)}, false);
                    elseif strcmp(c.mpc_type, 'multistage')
                        c.set_parameters({States(:,k), Reference(:,k), CEM(:,k), Wset}, false);
                    else
                        error('Unsupported MPC type.')
                    end
                    [c, res, ~] = c.solve_mpc();
                    Inputs(:,k) = res.U;
                    Objective(:,k) = res.J;

                    Disturbances(:,k) = w_min + (w_max - w_min) .* rand(nw,1);
                    States(:,k+1) = full(fp(States(:,k),Inputs(:,k),Disturbances(:,k)));
                    Outputs(:,k+1) = full(hp(States(:,k),zeros(nv,1)));

                    if strcmp(c.mpc_type, 'economic') || strcmp(c.mpc_type, 'multistage')
                        CEM(:,k+1) = CEM(:,k) + full(CEMadd(Outputs(:,k)));
                    end
                end
                % store data
                data_struct = struct;
                data_struct.States = States;
                data_struct.Outputs = Outputs;
                data_struct.Inputs = Inputs;
                data_struct.Disturbances = Disturbances;
                data_struct.Objective = Objective;
                data_struct.Reference = Reference;
                if strcmp(c.mpc_type, 'economic') || strcmp(c.mpc_type, 'multistage')
                    data_struct.CEM = CEM;
                end
                CL_training_data{i} = data_struct;
            end

            % gather training data
            input_data = [];
            output_data = [];
            for i = 1:length(CL_training_data)
                data_struct = CL_training_data{i};
                if strcmp(c.mpc_type, 'economic') || strcmp(c.mpc_type, 'multistage')
                    input_data = [input_data, [data_struct.States(:,1:end-1); data_struct.CEM(:,1:end-1)]];
                else
                    input_data = [input_data, [data_struct.States(:,1:end-1); data_struct.Reference]];
                    error('Unsupported MPC type')
                end
                output_data = [output_data, data_struct.Inputs];
            end

            % crop data to desired number of samples
            input_data = input_data(:,1:Nsamp);
            output_data = output_data(:,1:Nsamp);

            % scale to [-1,1]
            self.input_min = min(input_data,[],2);
            self.input_max = max(input_data,[],2);
            self.output_min = min(output_data,[],2);
            self.output_max = max(output_data,[],2);
            in_range = self.input_max - self.input_min;
            out_range = self.output_max - self.output_min;
            self.inputs = 2*(input_data - self.input_min)./(in_range) - 1;
            self.outputs = 2*(output_data - self.output_min)./(out_range) - 1;
        end

        function [self] = load_data(self, X, Y, scale_factors)
            self.inputs = X;
            self.outputs = Y;
            self.input_min = scale_factors.input_min;
            self.input_max = scale_factors.input_max;
            self.output_min = scale_factors.output_min;
            self.output_max = scale_factors.output_max;
        end

        function [self] = build_neural_network(self,H,L,activation,varargin)
            self.net = feedforwardnet(H*ones(1,L));
            switch lower(activation)
                case 'relu'
                    act_fcn = 'poslin';
                case 'tanh'
                    act_fcn = 'tansig';
                otherwise
                    warn('No activation function specified. Using ReLU (poslin).')
                    act_fcn = 'poslin';
            end
            for l = 1:L
                self.net.layers{l}.transferFcn = act_fcn;
            end
            if nargin > 4
                trn_fcn = varargin{1};
                trn_params = varargin{2};
                self.net.trainFcn = trn_fcn;
                self.net.trainParam = trn_params;
            end
            self.net.trainParam.showWindow = false;
            self.net = configure(self.net, self.inputs, self.outputs);
        end

        function [self, varargout] = train_neural_network(self,varargin)
            self.net = train(self.net, self.inputs, self.outputs);
            y = self.net(self.inputs);
            mse = perform(self.net,y,self.outputs);
            disp(mse)
            varargout{1} = mse;
        end

        function [self] = create_casadi_function(self, test)
            import casadi.*
            [n_in, ~] = size(self.inputs);
            % extract weights and biases from neural network
            L = self.net.numLayers-1; % numLayers gives number of hidden layers + output layer
            self.W = cell(L+1,1);
            self.b = cell(L+1,1);
            self.W{1} = self.net.IW{1};
            self.b{1} = self.net.b{1};
            for i = 1:L
                self.W{i+1} = self.net.LW{i+1,i};
                self.b{i+1} = self.net.b{i+1};
            end
            in_range = self.input_max - self.input_min;
            out_range = self.output_max - self.output_min;

            x = SX.sym('x', n_in);
            xs = 2*(x - self.input_min)./(in_range) - 1;
            z = max(self.W{1}*xs + self.b{1}, 0);
            for k = 1:L-1
                z = max(self.W{k+1}*z+self.b{k+1},0);
            end
            us = self.W{L+1}*z+self.b{L+1};
            u = (us+1)/2 .* (out_range) + self.output_min;

            self.netca = Function('netca', {x}, {u});

            if test
                % test for same function
                input = self.inputs(:,1);
                input_s = 2*(input-self.input_min)./(in_range)-1;
                output_s = self.net(input_s);
                output = (output_s+1)/2 .* (out_range) + self.output_min;
                disp(abs(full(self.netca(self.inputs(:,1))) - output) <= 1e-10)
            end
        end

        function [self] = set_data(self, filename)
            % function to set the data for the DNN given a filename
            loaded = load(filename);
            self.inputs = loaded.inputs;
            self.outputs = loaded.outputs;
            self.input_min = loaded.input_min;
            self.input_max = loaded.input_max;
            self.output_min = loaded.output_min;
            self.output_max = loaded.output_max;
            if isfield(loaded, 'net')
                self.net = loaded.net;
            else
                warning('Warning: no trained neural network found; you must build and train the neural network!')
            end
        end
        
        function [self] = save_trained_dnn_info(self, filename)
            inputs = self.inputs;
            outputs = self.outputs;
            input_min = self.input_min;
            input_max = self.input_max;
            output_min = self.output_min;
            output_max = self.output_max;
            net = self.net;
            save(filename, 'inputs', 'outputs', ...
                'input_min', 'input_max', ...
                'output_min', 'output_max', ...
                'net')
        end

        function [out, self] = getControlInput(self, in)

            % out = full(self.netca(in));
            L = self.net.numLayers-1; % numLayers gives number of hidden layers + output layer
            in_range = self.input_max - self.input_min;
            out_range = self.output_max - self.output_min;

            x = in;
            xs = 2*(x - self.input_min)./(in_range) - 1;
            % z = max(self.W{1}*xs + self.b{1}, 0);
            % for k = 1:L-1
            %     z = max(self.W{k+1}*z+self.b{k+1},0);
            % end
            % us = self.W{L+1}*z+self.b{L+1};
            us = self.net(xs);
            u = (us+1)/2 .* (out_range) + self.output_min;

            out = u;
        end
    end
end
