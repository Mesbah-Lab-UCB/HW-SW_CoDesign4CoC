function [out] = unscale_outputs(filename, in)

dnn = load(filename);
output_min = dnn.output_min;
output_max = dnn.output_max;
out_range = output_max - output_min;

out = (in+1)/2 .* out_range + output_min;

end