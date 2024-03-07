function localRunTest_plasma_nn_wrapper_fixpt
   fxptPath = '/home/kimberlychan/Desktop/DNN_Generality/matlab_v3/hdlcoder_fullDNN/codegen/plasma_nn_wrapper/fixpt';
addpath(fxptPath);
cleanupObj = onCleanup(@() rmpath(fxptPath));

   test_fullDNN_fil;
end

