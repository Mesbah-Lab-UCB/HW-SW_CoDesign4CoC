#pragma once

#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void customFetchLoggedData_mexFunction(int32_T nlhs, mxArray *plhs[4],
                                       int32_T nrhs);

void forcePushIntoCloud_mexFunction(int32_T nlhs, int32_T nrhs);

void logStmts_mexFunction(int32_T nlhs, int32_T nrhs);

MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS(void);

void plasma_nn_wrapper_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T nrhs,
                                   const mxArray *prhs[3]);
