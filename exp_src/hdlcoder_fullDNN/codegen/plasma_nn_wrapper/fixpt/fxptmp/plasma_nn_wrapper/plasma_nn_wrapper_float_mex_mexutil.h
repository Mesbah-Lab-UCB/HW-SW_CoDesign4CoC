#pragma once

#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void emlrtInitVarDataTables(emlrtLocationLoggingDataType dataTables[70]);

void emlrt_update_log_2(const real_T in[3],
                        emlrtLocationLoggingDataType table[], int32_T b_index);
