% Auto generated function to simulate the generated HDL code using FPGA-in-the-Loop
% 
% Generated by MATLAB 9.10 and HDL Coder 3.18

function [ref_y1_1,ref_y1_2] = plasma_nn_wrapper_fixpt_fil(x1_1,x1_2,x1_3)

coder.extrinsic('plasma_nn_wrapper_fixpt_sysobj_fil');
coder.extrinsic('hdlverifier.assert');
coder.extrinsic('hdlverifier.Delay');
coder.extrinsic('step');

% Declare persistent variables
persistent initialized;

% Initialize persistent variables
if isempty(initialized)
   initialized = true;
end

% Call the original MATLAB function to get reference signal
[ref_y1_1,ref_y1_2] = plasma_nn_wrapper_fixpt(x1_1,x1_2,x1_3);

% Run FPGA-in-the-Loop
[y1_1,y1_2] = plasma_nn_wrapper_fixpt_sysobj_fil(x1_1,x1_2,x1_3);

% Verify the FPGA-in-the-Loop output
hdlverifier.assert(y1_1,ref_y1_1,'y1_1');
hdlverifier.assert(y1_2,ref_y1_2,'y1_2');

