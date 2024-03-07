classdef Simulation
    properties
        Nsim
        sim_params
        rand_seed = 42
    end
    methods
        function self = Simulation(Nsim, sim_params)
            % constructor for Simulation object
            self.Nsim = Nsim;
            self.sim_params = sim_params;
            if isfield(self.sim_params, 'rand_seed')
                self.rand_seed = self.sim_params.rand_seed;
            end
        end

        function [self, sim_data] = run_closed_loop(self, c, model, observer, CEM, multistage, varargin)

            % define default values for name-value pair arguments
            rand_seed2 = 0;
            gp_update = false;
            if nargin > 6
                n = length(varargin);
                nkwargs = floor(n/2);
                for i = 1:nkwargs
                    name = varargin{2*i-1};
                    value = varargin{2*i};
                    switch lower(name)
                        case 'rand_seed2'
                            rand_seed2 = value;
                        case 'gp_update'
                            gp_update = value;
                        otherwise
                            warning('Undefined name-value pair...')
                    end
                end
            end
            % check controller type
            mpc_controller = false;
            hw_controller = false;
            fxpdnn = false;
            if isa(c,'MPC')
                mpc_controller = true;
                disp('Using a MPC.')
            elseif isa(c,'DNN')
                disp('Using an approximate controller.')
            elseif isa(c, 'HWController')
                hw_controller = true;
                disp('Using an approximate controller on hardware.')
            elseif isa (c,'FxpDNN')
                fxpdnn = true;
                disp('Using an approximate controller.')
            else
                error('Unsupported controller type.')
            end
            % extract relevant information from sim_params
            nu = self.sim_params.nu;
            nx = self.sim_params.nx;
            ny = self.sim_params.ny;
            nyc = self.sim_params.nyc;
            nv = self.sim_params.nv;
            nw = self.sim_params.nw;

            x0 = self.sim_params.x0;
            myref = self.sim_params.myref;
            ts = self.sim_params.ts;

            if isfield(self.sim_params, 'u_min')
                u_min = self.sim_params.u_min;
            else
                u_min = self.sim_params.ctrl_params.u_min;
            end
            if isfield(self.sim_params, 'u_max')
                u_max = self.sim_params.u_max;
            else
                u_max = self.sim_params.ctrl_params.u_max;
            end

            v_min = self.sim_params.v_min;
            v_max = self.sim_params.v_max;
            w_min = self.sim_params.w_min;
            w_max = self.sim_params.w_max;
            
            if multistage
                Wset = self.sim_params.ctrl_params.Wset;
            end

            % check if a plant model was provided
            plant_provided = false;
            if isfield(self.sim_params, 'fp')
                plant_provided = true;
                disp('Using user-provided plant...')
                fp = self.sim_params.fp;
                hp = self.sim_params.hp;
            end
            if ~plant_provided
                error('no plant provided')
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
            Xhat = zeros(size(Xsim));  % state estimation
            if multistage
                Ypred = cell(self.Nsim,1);
                Wpred = cell(self.Nsim,1);
            else
                Ypred = zeros(ny,self.sim_params.Np,self.Nsim);
            end

            ctime = zeros(1,self.Nsim);   % computation time
            Jsim = zeros(1,self.Nsim);    % cost/optimal objective value (controller)
            Yrefsim = zeros(nyc,self.Nsim+1);  % output reference/target (as sent to controller)
            Feas = zeros(1,self.Nsim);

            if CEM
                CEMsim = zeros(1,self.Nsim+1);
                CEMadd = self.sim_params.CEMadd;
                CEM_stop_time = self.Nsim+1;
            end

            % set initial states and reset controller for consistency
            Xsim(:,1) = x0;
            Xhat(:,1) = Xsim(:,1);
            if ~isempty(observer)
                observer.xhat = Xhat(:,0);
            end
            if plant_provided
                Ysim(:,1) = full(hp(Xhat(:,1),Vsim(:,1)));
            else
                Ysim(:,1) = 37;
            end
            if mpc_controller
                c.reset_initial_guesses();
            end

            % loop over simulation time
            CEM_stop_trigger = false;
            for k = 1:self.Nsim
                startTime = tic;

                Yrefsim(:,k) = myref(k*ts);
                if mpc_controller
                    if CEM
                        if multistage
                            % multistage version
                            c.set_parameters({Xhat(:,k), Yrefsim(:,k), CEMsim(:,k), Wset}, false);
                        else
                            % economic version
                            c.set_parameters({Xhat(:,k), Yrefsim(:,k), CEMsim(:,k)}, false);
                        end
                    else
                        % tbd
                        error('Unsupported controller')
    %                     c.set_parameters({Xhat(:,k), Yrefsim(:,k), Ysim(:,k)}, false);
                    end
                    [c, res, feas] = c.solve_mpc();
                    Feas(k) = feas;
                    Uopt = res.U;
                    Jopt = res.J;
                    if multistage
                        Ypred{k} = res.Y;
                        Wpred{k} = res.wPred;
                    end
                else
                    Jopt = NaN;
                    if CEM
                        in_vec = [Xhat(:,k); CEMsim(:,k)];
                    else
                        in_vec = [Xhat(:,k); Yrefsim(:,k)];
                    end
                    if hw_controller || fxpdnn
                        [Uopt, c] = c.getControlInput(in_vec);     
                    else
                        if isempty(c.netca)
                            Uopt = c.net(in_vec);
                        else
                            Uopt = full(c.netca(in_vec));
                        end
                    end
                    Uopt = max(min(Uopt,u_max),u_min);
                end

                ctime(k) = toc(startTime);
                if mpc_controller
                    if ~feas
                        fprintf('Was not feasible on iteration %d of simulation\n',k)
                    end
                end

                Usim(:,k) = Uopt;
                Jsim(k) = Jopt;

                % send optimal input to plant/real system
                if plant_provided
                    Xsim(:,k+1) = full(fp(Xsim(:,k),Usim(:,k),Wsim(:,k)));
                    Ysim(:,k+1) = full(hp(Xsim(:,k+1),Vsim(:,k+1)));
                end
                if CEM
                    CEMsim(:,k+1) = CEMsim(:,k) + full(CEMadd(Ysim(:,k)));
                    if ~CEM_stop_trigger && CEMsim(:,k+1) > Yrefsim(:,k)
                        CEM_stop_time = k+1;
                        CEM_stop_trigger = true;
                    end
                    if CEM_stop_time > self.Nsim
                        CEM_stop_time = self.Nsim
                    end
                    if CEM_stop_trigger
                        break
                    end
                end


                % get estimates
                if ~isempty(observer)
                    xhat = observer.update_observer(Usim(:,k), Ysim(:,k+1));
                    Xhat(:,k+1) = xhat;
                else
                    Xhat(:,k+1) = Xsim(:,k+1);
                end
            end

            Yrefsim(:,k+1) = myref((k+1)*ts);
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
            sim_data.feas = Feas;
            if multistage
                sim_data.wPred = Wpred;
            end
            if CEM
                sim_data.CEMsim = CEMsim;
                sim_data.CEM_stop_time = CEM_stop_time;
            end
        end
    end
end
