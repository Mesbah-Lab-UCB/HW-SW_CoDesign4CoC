classdef HWController < handle
    properties
        dut_fname
        tb_fname
        scale_factors
        fxptcfg
        hdlcfg
        fm
        in_fxpt_p
        fil_sys_obj
        codegen_dir = './hdlcoder_fullDNN/codegen';
    end
    methods
        function [self] = HWController(dut_fname, tb_fname, scale_factors)
            self.dut_fname = dut_fname;
            self.tb_fname = tb_fname;
            self.scale_factors = scale_factors;
        end

        function [self] = buildController(self, params)
            [self.fxptcfg, self.hdlcfg] = self.run_codegen(params, self.codegen_dir);
            % get fixed point conversion info
            self.fm = eval(self.fxptcfg.fimath);
            codegendir = self.fxptcfg.CodegenDirectory;
            a = load([codegendir '/' self.dut_fname '/fixpt/' self.dut_fname '_fixpt_args.mat']);
            inputArgs = a.values.inputArgs;

            for i = 1:length(inputArgs)
                fitype = inputArgs{i}.NumericType;
                self.in_fxpt_p{i} = fi(0, fitype, self.fm);
            end

            addpath(genpath([codegendir '/' self.dut_fname '/fil']))
            % instantiate FIL system object
            self.fil_sys_obj = eval(['class_' self.dut_fname '_fixpt_sysobj']);
        end

        function [self] = loadController(self, params)
            [self.fxptcfg, self.hdlcfg] = self.run_config_gen(params);
            % get fixed point conversion info
            self.fm = eval(self.fxptcfg.fimath);
            codegendir = self.codegen_dir;
            a = load([codegendir '/' self.dut_fname '/fixpt/' self.dut_fname '_fixpt_args.mat']);
            inputArgs = a.values.inputArgs;

            for i = 1:length(inputArgs)
                fitype = inputArgs{i}.NumericType;
                self.in_fxpt_p{i} = fi(0, fitype, self.fm);
            end

            addpath(genpath([codegendir '/' self.dut_fname '/fil']))
            % instantiate FIL system object
            self.fil_sys_obj = eval(['class_' self.dut_fname '_fixpt_sysobj']);
            self.fil_sys_obj.programFPGA();
        end

        function [out, self] = getControlInput(self, in)

            in = self.scale_inputs(in, self.scale_factors);
            assert(length(self.in_fxpt_p) == length(in))
            % convert to fixed point
            for i = 1:length(in)
                fxp_in{i} = cast(in(i), 'like', self.in_fxpt_p{i});
            end

            
            for i = 3
                [to1, to2] = step(self.fil_sys_obj, fxp_in{1}, fxp_in{2}, fxp_in{3});
            end
            out = [double(to1); double(to2)];
            out = self.unscale_outputs(out, self.scale_factors);
        end

        function [self] = setCodegenDir(self, name)
            % function to set the codegen directory
            self.codegen_dir = [name '/codegen'];
        end
    end

    methods(Static)
        function [fxptcfg, hdlcfg] = run_codegen(params, codegen_dir)
            % wrapper function to call external function which runs the
            % code generation
            [fxptcfg, hdlcfg] = generateHDLCode(params, codegen_dir);
        end
        function [fxptcfg, hdlcfg] = run_config_gen(params)
            % wrapper function to call external function which generates the
            % configuration objects used previously
            [fxptcfg, hdlcfg] = generateConfigs(params);
        end
        function [out] = scale_inputs(in, scale_factors)
            % function to scale the inputs of the dnn
            in_range = scale_factors.input_max - scale_factors.input_min;
            out = 2*(in - scale_factors.input_min)./(in_range) - 1;
        end
        function [out] = unscale_outputs(in, scale_factors)
            % function to unscale the outputs of the dnn
            out_range = scale_factors.output_max - scale_factors.output_min;
            out = (in+1)/2 .* out_range + scale_factors.output_min;
        end
    end

end
