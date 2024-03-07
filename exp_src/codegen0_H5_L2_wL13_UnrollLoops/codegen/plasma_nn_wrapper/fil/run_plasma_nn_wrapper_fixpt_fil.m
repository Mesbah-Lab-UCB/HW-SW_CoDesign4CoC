function run_plasma_nn_wrapper_fixpt_fil
% Program FPGA
disp('### Programming FPGA ');
filProgramFPGA('Xilinx Vivado','/home/kimberlychan/Desktop/DNN_Generality/matlab/codegen0_H5_L2_wL13_UnrollLoops/codegen/plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil/plasma_nn_wrapper_fixpt_fil.bit',2);

disp('### Waiting for FPGA initialization ');
pause(3);
% Clear persistent variables before simulation
l_clearPersistentVariable;

% Clear persistent variables after simulation
onCleanupObj = onCleanup(@() l_clearPersistentVariable);

% Add current working directory to search path
savedPathVar = addpath(pwd);
restorePathObj = onCleanup(@() path(savedPathVar));

% Run generated test bench
disp('### Simulating generated test bench ');
% Exercise the compiled version of plasma_nn_wrapper_wrapper_fixpt_fil in the generated test bench.
% To debug the test bench with the original function "plasma_nn_wrapper_wrapper_fixpt_fil",
% replace the next line with "test_fullDNN_fil"
coder.runTest('localRunTest_plasma_nn_wrapper_fixpt','plasma_nn_wrapper_wrapper_fixpt_fil');
% To recompile MATLAB function "plasma_nn_wrapper_wrapper_fixpt_fil",
% run the re-compilation function "localRecompile_plasma_nn_wrapper_wrapper_fixpt_fil".
disp('### Finished Simulation');

end

function l_clearPersistentVariable
% Clear reference DUT function
clear plasma_nn_wrapper_fixpt;

% Clear FPGA-in-the-Loop System object wrapper function
clear plasma_nn_wrapper_fixpt_sysobj_fil;

% Clear FPGA-in-the-Loop function
clear plasma_nn_wrapper_fixpt_fil;

% Clear generated MEX function
clear plasma_nn_wrapper_wrapper_fixpt_fil_mex

end

