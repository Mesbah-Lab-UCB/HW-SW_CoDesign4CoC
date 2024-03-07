#pragma once

#include "plasma_nn_wrapper_float_mex_types.h"
#include "rtwtypes.h"
#include "emlrt.h"

#ifndef typedef_rtDesignRangeCheckInfo
#define typedef_rtDesignRangeCheckInfo
typedef struct {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
} rtDesignRangeCheckInfo;
#endif
