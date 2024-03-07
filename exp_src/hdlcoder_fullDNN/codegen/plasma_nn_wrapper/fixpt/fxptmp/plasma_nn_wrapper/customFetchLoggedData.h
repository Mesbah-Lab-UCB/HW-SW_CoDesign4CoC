#pragma once

#include "plasma_nn_wrapper_float_mex_types.h"
#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void customFetchLoggedData(const emlrtStack *sp, emxArray_struct0_T *data,
                           emxArray_struct1_T *dataInfo,
                           char_T dataExprIdMapping[690],
                           real_T *numLoggedExpr);
