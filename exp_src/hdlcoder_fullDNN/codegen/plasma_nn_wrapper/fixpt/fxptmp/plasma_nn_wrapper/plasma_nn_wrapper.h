#pragma once

#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void plasma_nn_wrapper(const emlrtStack *sp, real_T x1_1, real_T x1_2,
                       real_T x1_3, real_T *y1_1, real_T *y1_2);
