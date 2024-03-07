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

void b_custom_mex_logger(const emlrtStack *sp, uint32_T idx_in,
                         const real_T val_in[2]);

void buffers_free(void);

void buffers_init(const emlrtStack *sp);

void c_custom_mex_logger(const emlrtStack *sp, uint32_T idx_in,
                         const real_T val_in[3]);

void customCoderEnableLog_free(void);

void customCoderEnableLog_init(const emlrtStack *sp);

void custom_mex_logger(const emlrtStack *sp, uint32_T idx_in, real_T val_in);

void d_custom_mex_logger(const emlrtStack *sp, uint32_T idx_in,
                         const real_T val_in_xoffset[3],
                         const real_T val_in_gain[3], real_T val_in_ymin);

void e_custom_mex_logger(const emlrtStack *sp, uint32_T idx_in,
                         real_T val_in_ymin, const real_T val_in_gain[2],
                         const real_T val_in_xoffset[2]);

void f_custom_mex_logger(const emlrtStack *sp, emxArray_struct0_T *data,
                         emxArray_struct1_T *bufferInfo);

void indexMapper_free(void);

void indexMapper_init(const emlrtStack *sp);

void pInit_not_empty_init(void);
