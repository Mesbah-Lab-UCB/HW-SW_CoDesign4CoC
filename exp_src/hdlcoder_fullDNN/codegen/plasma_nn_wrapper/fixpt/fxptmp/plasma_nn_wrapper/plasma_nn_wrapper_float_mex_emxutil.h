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

void emxCopyStruct_struct0_T(const emlrtStack *sp, struct0_T *dst,
                             const struct0_T *src,
                             const emlrtRTEInfo *srcLocation);

void emxCopy_char_T_1x0(emxArray_char_T_1x0 *dst,
                        const emxArray_char_T_1x0 *src);

void emxCopy_char_T_1x6(emxArray_char_T_1x6 *dst,
                        const emxArray_char_T_1x6 *src);

void emxCopy_real_T_1x2(emxArray_real_T_1x2 *dst,
                        const emxArray_real_T_1x2 *src);

void emxCopy_uint8_T(const emlrtStack *sp, emxArray_uint8_T **dst,
                     emxArray_uint8_T *const *src,
                     const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_boolean_T(const emlrtStack *sp,
                                 emxArray_boolean_T *emxArray, int32_T oldNumel,
                                 const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_struct0_T(const emlrtStack *sp,
                                 emxArray_struct0_T *emxArray, int32_T oldNumel,
                                 const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_struct1_T(const emlrtStack *sp,
                                 emxArray_struct1_T *emxArray, int32_T oldNumel,
                                 const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_uint8_T(const emlrtStack *sp, emxArray_uint8_T *emxArray,
                               int32_T oldNumel,
                               const emlrtRTEInfo *srcLocation);

void emxExpand_struct0_T(const emlrtStack *sp, emxArray_struct0_T *emxArray,
                         int32_T fromIndex, int32_T toIndex,
                         const emlrtRTEInfo *srcLocation);

void emxExpand_struct1_T(emxArray_struct1_T *emxArray, int32_T fromIndex,
                         int32_T toIndex);

void emxFreeStruct_struct0_T(struct0_T *pStruct);

void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);

void emxFree_struct0_T(emxArray_struct0_T **pEmxArray);

void emxFree_struct1_T(emxArray_struct1_T **pEmxArray);

void emxFree_uint8_T(emxArray_uint8_T **pEmxArray);

void emxInitStruct_struct0_T(const emlrtStack *sp, struct0_T *pStruct,
                             const emlrtRTEInfo *srcLocation, boolean_T doPush);

void emxInitStruct_struct1_T(struct1_T *pStruct);

void emxInit_boolean_T(const emlrtStack *sp, emxArray_boolean_T **pEmxArray,
                       int32_T numDimensions, const emlrtRTEInfo *srcLocation,
                       boolean_T doPush);

void emxInit_struct0_T(const emlrtStack *sp, emxArray_struct0_T **pEmxArray,
                       int32_T numDimensions, const emlrtRTEInfo *srcLocation,
                       boolean_T doPush);

void emxInit_struct1_T(const emlrtStack *sp, emxArray_struct1_T **pEmxArray,
                       int32_T numDimensions, const emlrtRTEInfo *srcLocation,
                       boolean_T doPush);

void emxInit_uint8_T(const emlrtStack *sp, emxArray_uint8_T **pEmxArray,
                     int32_T numDimensions, const emlrtRTEInfo *srcLocation,
                     boolean_T doPush);

void emxTrim_struct0_T(emxArray_struct0_T *emxArray, int32_T fromIndex,
                       int32_T toIndex);
