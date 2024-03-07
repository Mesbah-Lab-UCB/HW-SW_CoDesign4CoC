function [out] = scale_inputs(filename, in)

dnn = load(filename);
input_min = dnn.input_min;
input_max = dnn.input_max;
in_range = input_max - input_min;

out = 2*(in - input_min)./(in_range) - 1;

end