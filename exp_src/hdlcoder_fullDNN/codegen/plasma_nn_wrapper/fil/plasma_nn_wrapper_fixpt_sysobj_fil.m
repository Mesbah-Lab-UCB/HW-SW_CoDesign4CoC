% Auto generated wrapper function for FPGA-in-the-Loop System object

% Generated by MATLAB 9.10 and HDL Coder 3.18

function [y1_1,y1_2] = plasma_nn_wrapper_fixpt_sysobj_fil(x1_1,x1_2,x1_3)

% Declare persistent variables
persistent fil_sys_obj;

if isempty(fil_sys_obj)
   % Instantiate FPGA-in-the-Loop System object
   fil_sys_obj = class_plasma_nn_wrapper_fixpt_sysobj;
end

[y1_1,y1_2] = step(fil_sys_obj,x1_1,x1_2,x1_3);

