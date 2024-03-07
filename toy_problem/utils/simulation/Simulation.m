classdef Simulation
    % Simulation Class:
    % This class is used to run closed-loop simulations on controlled
    % systems.
    properties
        Nsim            % simulation horizon (how many iterations to simulate for)
        prob_info       % struct containing information on the system (details in constructor)
        rand_seed = 42  % random seed for initializing random number generators
    end
    methods
        function self = Simulation(Nsim, prob_info)
            % constructor for Simulation object
            % a Simulation requires two arguments to initialize the object.
            % Inputs:
            % -------
            % Nsim          (int) the simulation horizon in number of 
            %               iterations to simulate for
            % prob_info     (struct) problem information, requires the
            %               dimensions of the system (e.g., nx - the number
            %               of states, nu - the number of inputs, ny - the
            %               number of outputs, etc.); bounds/constraints on
            %               the system (e.g., u_min/u_max - bounds on the
            %               manipulated variable/inputs, etc.); plant
            %               dynamics (i.e., equations that describe the
            %               state evolution x_{k+1}=f(x_{k},u_{k},w_{k})
            %               and/or output equation
            %               y_{k}=h(x_{k},u_{k},v_{k}))
            % Outputs:
            % --------
            % self          an initialized Simulation object
            
            self.Nsim = Nsim;
            self.prob_info = prob_info;
            if isfield(self.prob_info, 'rand_seed')
                self.rand_seed = self.prob_info.rand_seed;
            end
        end
        
        function [self] = set_prob_info(self, prob_info)
            self.prob_info = prob_info;
            if isfield(self.prob_info, 'rand_seed')
                self.rand_seed = self.prob_info.rand_seed;
            end
        end

        function [self, sim_data] = run_closed_loop(self, c, observer, varargin)

            % define default values for name-value pair arguments
            rand_seed2 = 0;
            mex_exist = false;
            if nargin > 3
                n = length(varargin);
                nkwargs = floor(n/2);
                for i = 1:nkwargs
                    name = varargin{2*i-1};
                    value = varargin{2*i};
                    switch lower(name)
                        case 'rand_seed2'
                            disp('set rand_seed2')
                            rand_seed2 = value;
                        case 'mex_exist'
                            disp('set mex_exist')
                            mex_exist = value;
                        otherwise
                            warning('Undefined name-value pair...')
                    end
                end
            end
            % check controller type
            mpc_controller = false;
            mpt_controller = false;
            explicit_controller = false;
            dnn_controller = false;
            if isa(c,'MPC')
                mpc_controller = true;
                disp('Using CasADi-based MPC.')
            elseif isa(c, 'MPCController')
                mpt_controller = true;
                disp('Using MPT-based MPC.')
            elseif isa(c, 'EMPCController')
                explicit_controller = true;
            elseif isa(c, 'DNN')
                dnn_controller = true;
            else
                error('Unsupported controller type.')
            end
            % extract relevant information from prob_info
            nu = self.prob_info.nu;
            nx = self.prob_info.nx;
            ny = self.prob_info.ny;
            nyc = self.prob_info.nyc;
            nv = self.prob_info.nv;
            nw = self.prob_info.nw;

            x0 = self.prob_info.x0;
            
            u_min = self.prob_info.u_min;
            u_max = self.prob_info.u_max;
            
            v_min = self.prob_info.v_min;
            v_max = self.prob_info.v_max;
            w_min = self.prob_info.w_min;
            w_max = self.prob_info.w_max;

            % check if a plant model was provided
            plant_provided = false;
            if isfield(self.prob_info, 'fp')
                plant_provided = true;
                disp('Using user-provided plant...')
                fp = self.prob_info.fp;
                hp = self.prob_info.hp;
            end
            if ~plant_provided
                error('no plant provided')
            end
            
            % get stage cost function
            if isfield(self.prob_info, 'lstage')
                lstage = self.prob_info.lstage;
            end

            % set random seed (for reproducible results)
            rng(self.rand_seed+rand_seed2)
            % generate noise/disturbance variables
            Vsim = v_min + (v_max-v_min) .* rand(nv,self.Nsim+1);
            Wsim = w_min + (w_max-w_min) .* rand(nw,self.Nsim+1);

            % instantiate container variables for storing simulation data
            Xsim = zeros(nx,self.Nsim+1); % state trajectories (plant)
            Ysim = zeros(ny,self.Nsim+1); % output trajectories (plant)
            Usim = zeros(nu,self.Nsim);   % input trajectories (plant)
            Xhat = zeros(size(Xsim));     % state estimation (observer/plant)
            Ypred = zeros(ny,self.prob_info.Np,self.Nsim); % predicted states (controller)

            ctime = zeros(1,self.Nsim);   % computation time
            Jsim = zeros(1,self.Nsim);    % stage cost (simulation)
            Jpred = zeros(1,self.Nsim);    % cost/optimal objective value (controller)
            Yrefsim = zeros(nyc,self.Nsim+1);  % output reference/target (as sent to controller)
            Feas = zeros(1,self.Nsim);

            % set initial states and reset controller for consistency
            Xsim(:,1) = x0;
            Xhat(:,1) = Xsim(:,1);
            if ~isempty(observer)
                observer.xhat = Xhat(:,0);
            end
            if plant_provided
                Ysim(:,1) = full(hp(Xhat(:,1),Vsim(:,1)));
            else
                Ysim(:,1) = 0;
            end
            if mpc_controller
                c.reset_initial_guesses();
            end

            % loop over simulation time
            for k = 1:self.Nsim
                startTime = tic;
                
                if mpc_controller
                    if mex_exist
                        try
                            Uopt = mpc_mex('mpc_implicit', Xhat(:,k));
                        catch
                            disp("Infeasible! Setting optimal input as previous value...")
                            Uopt = Usim(:,k-1);
                        end
                    else
                        c.set_parameters({Xhat(:,k)}, false);
                        [c, res, feas] = c.solve_mpc();
                        Feas(k) = feas;
                        Uopt = res.U;
                        Jopt = res.J;
                        Jpred(k) = Jopt;
                    end
                elseif mpt_controller
                    if mex_exist
                        Uopt = mpc_mex(Xhat(:,k));
                    else
                        Uopt = c.evaluate(Xhat(:,k));
                    end
                elseif explicit_controller
                    if mex_exist
                        Uopt = empc_mex(Xhat(:,k)');
                    else
                        Uopt = c.evaluate(Xhat(:,k)');
                    end
                elseif dnn_controller
                    if mex_exist
                        Uopt = dnn_mex(Xhat(:,k));
                    else
                        [Uopt, c] = c.getControlInput(Xhat(:,k));
                    end
                else
                    error('Unsupported controller')
                end
                Uopt = min(max(Uopt,u_min),u_max);

                ctime(k) = toc(startTime);
                if mpc_controller && ~mex_exist
                    if ~feas
                        fprintf('Was not feasible on iteration %d of simulation\n',k)
                    end
                end

                Usim(:,k) = Uopt;
                Jsim(k) = full(lstage(Xsim(:,k),Usim(:,k)));

                % send optimal input to plant/real system
                if plant_provided
                    Xsim(:,k+1) = full(fp(Xsim(:,k),Usim(:,k),Wsim(:,k)));
                    Ysim(:,k+1) = full(hp(Xsim(:,k+1),Vsim(:,k+1)));
                end

                % get estimates
                if ~isempty(observer)
                    xhat = observer.update_observer(Usim(:,k), Ysim(:,k+1));
                    Xhat(:,k+1) = xhat;
                else
                    Xhat(:,k+1) = Xsim(:,k+1);
                end
            end
            
            % create dictionary of simulation data
            sim_data = struct();
            sim_data.Xsim = Xsim;
            sim_data.Ysim = Ysim;
            sim_data.Usim = Usim;
            sim_data.Jsim = Jsim;
            sim_data.Wsim = Wsim;
            sim_data.Vsim = Vsim;
            sim_data.Yrefsim = Yrefsim;
            sim_data.ctime = ctime;
            sim_data.Xhat = Xhat;
            sim_data.Ypred = Ypred;
            sim_data.Jpred = Jpred;
            sim_data.feas = Feas;
        end
    end
    methods(Static)
        function [sim_data] = combine_sim_data(sim_data1, sim_data2)
            
            fn1 = fieldnames(sim_data1);
            
            sim_data = struct();
            for i = 1:length(fn1)
                f = fn1{i};
                if isfield(sim_data2, f)
                    sim_data.(f) = [sim_data1.(f) sim_data2.(f)];
                end
            end
        end
    end
end
