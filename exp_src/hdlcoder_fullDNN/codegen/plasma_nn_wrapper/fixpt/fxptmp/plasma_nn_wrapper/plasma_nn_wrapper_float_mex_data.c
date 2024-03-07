#include "plasma_nn_wrapper_float_mex_data.h"
#include "rt_nonfinite.h"

emlrtLocationLoggingDataType emlrtLocationLoggingDataTables[70];

emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,
    false,
    131610U,
    NULL,
    "plasma_nn_wrapper_float_mex",
    NULL,
    false,
    {2045744189U, 2170104910U, 2743257031U, 4284093946U},
    NULL};

emlrtRSInfo j_emlrtRSI = {1, "plasma_nn",
                          "/home/kimberlychan/Desktop/DNN_Generality/matlab/"
                          "hdlcoder_fullDNN/plasma_nn.m"};

emlrtRSInfo o_emlrtRSI = {
    28, "repmat",
    "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/repmat.m"};

emlrtRTEInfo b_emlrtRTEI = {58, 23, "assertValidSizeArg",
                            "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/"
                            "+internal/assertValidSizeArg.m"};

covrtInstance emlrtCoverageInstance;
