classdef FxpDNN
    properties
        inputs
        outputs
        input_min
        input_max
        output_min
        output_max
        codegen_path = './fxp_codegen';
    end
    
    methods
        
        function [self] = set_codegen_path(self, cgpath)
            self.codegen_path = cgpath;
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
        end
        
        function [out, self] = getControlInput(self, in)
            
            pathStr = path;
            onPath = contains(pathStr, self.codegen_path, 'IgnoreCase', ispc);
            if ~onPath
                addpath(self.codegen_path)
            end
            
            in_range = self.input_max - self.input_min;
            out_range = self.output_max - self.output_min;
            
            x = in;
            xs = 2*(x - self.input_min)./(in_range) - 1;
            
            [out1, out2] = plasma_nn_wrapper_wrapper_fixpt_mex('plasma_nn_wrapper_wrapper_fixpt', xs(1), xs(2), xs(3));
            
            us = [out1; out2];
            u = (us+1)/2 .* (out_range) + self.output_min;
            
            out = u;
        end
    end 
end