function localRunTest_plasma_nn_wrapper_fixpt
   fxptPath = '/home/kimberlychan/Desktop/DNN_Generality/matlab/codegen0_H5_L3_wL20_LoopNone/codegen/plasma_nn_wrapper/fixpt';
addpath(fxptPath);
cleanupObj = onCleanup(@() rmpath(fxptPath));

   test_fullDNN_fil;
end

