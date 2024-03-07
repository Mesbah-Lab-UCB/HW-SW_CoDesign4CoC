#pragma once

#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void customFetchLoggedData_api(int32_T nlhs, const mxArray *plhs[4]);

void forcePushIntoCloud_api(void);

void logStmts_api(void);

void plasma_nn_wrapper_api(const mxArray *const prhs[3], int32_T nlhs,
                           const mxArray *plhs[2]);
