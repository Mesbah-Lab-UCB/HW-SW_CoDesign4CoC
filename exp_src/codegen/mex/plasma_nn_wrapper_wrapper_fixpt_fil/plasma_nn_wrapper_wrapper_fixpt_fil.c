/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * plasma_nn_wrapper_wrapper_fixpt_fil.c
 *
 * Code generation for function 'plasma_nn_wrapper_wrapper_fixpt_fil'
 *
 */

/* Include files */
#include "plasma_nn_wrapper_wrapper_fixpt_fil.h"
#include "plasma_nn_wrapper_wrapper_fixpt_fil_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    11,                                    /* lineNo */
    "plasma_nn_wrapper_wrapper_fixpt_fil", /* fcnName */
    "/home/kimberlychan/Desktop/DNN_Generality/matlab/hdlcoder_fullDNN/codegen/"
    "plasma_nn_wrapper/fil/plasma_nn_wrapper_wrapper_fixpt_"
    "fil.m" /* pathName */
};

static emlrtMCInfo b_emlrtMCI = {
    24,                            /* lineNo */
    1,                             /* colNo */
    "plasma_nn_wrapper_fixpt_fil", /* fName */
    "/home/kimberlychan/Desktop/DNN_Generality/matlab/hdlcoder_fullDNN/codegen/"
    "plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil.m" /* pName */
};

static emlrtMCInfo c_emlrtMCI = {
    27,                            /* lineNo */
    1,                             /* colNo */
    "plasma_nn_wrapper_fixpt_fil", /* fName */
    "/home/kimberlychan/Desktop/DNN_Generality/matlab/hdlcoder_fullDNN/codegen/"
    "plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil.m" /* pName */
};

static emlrtMCInfo d_emlrtMCI = {
    28,                            /* lineNo */
    1,                             /* colNo */
    "plasma_nn_wrapper_fixpt_fil", /* fName */
    "/home/kimberlychan/Desktop/DNN_Generality/matlab/hdlcoder_fullDNN/codegen/"
    "plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil.m" /* pName */
};

static emlrtRSInfo p_emlrtRSI = {
    24,                            /* lineNo */
    "plasma_nn_wrapper_fixpt_fil", /* fcnName */
    "/home/kimberlychan/Desktop/DNN_Generality/matlab/hdlcoder_fullDNN/codegen/"
    "plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil.m" /* pathName */
};

static emlrtRSInfo q_emlrtRSI = {
    28,                            /* lineNo */
    "plasma_nn_wrapper_fixpt_fil", /* fcnName */
    "/home/kimberlychan/Desktop/DNN_Generality/matlab/hdlcoder_fullDNN/codegen/"
    "plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil.m" /* pathName */
};

static emlrtRSInfo r_emlrtRSI = {
    27,                            /* lineNo */
    "plasma_nn_wrapper_fixpt_fil", /* fcnName */
    "/home/kimberlychan/Desktop/DNN_Generality/matlab/hdlcoder_fullDNN/codegen/"
    "plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil.m" /* pathName */
};

/* Function Declarations */
static void c_plasma_nn_wrapper_fixpt_sysob(
    const emlrtStack *sp, const mxArray *b, const mxArray *c, const mxArray *d,
    emlrtMCInfo *location, const mxArray **e, const mxArray **f);

static void hdlverifier_assert(const emlrtStack *sp, const mxArray *b,
                               const mxArray *c, const mxArray *d,
                               emlrtMCInfo *location);

/* Function Definitions */
static void c_plasma_nn_wrapper_fixpt_sysob(
    const emlrtStack *sp, const mxArray *b, const mxArray *c, const mxArray *d,
    emlrtMCInfo *location, const mxArray **e, const mxArray **f)
{
  const mxArray *pArrays[3];
  const mxArray *mv[2];
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  emlrtAssign(e, emlrtCallMATLABR2012b(
                     (emlrtCTX)sp, 2, &mv[0], 3, &pArrays[0],
                     (const char_T *)"plasma_nn_wrapper_fixpt_sysobj_fil", true,
                     location));
  emlrtAssign(f, mv[1]);
}

static void hdlverifier_assert(const emlrtStack *sp, const mxArray *b,
                               const mxArray *c, const mxArray *d,
                               emlrtMCInfo *location)
{
  const mxArray *pArrays[3];
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  emlrtCallMATLABR2012b((emlrtCTX)sp, 0, NULL, 3, &pArrays[0],
                        (const char_T *)"hdlverifier.assert", true, location);
}

void plasma_nn_wrapper_wrapper_fixpt_fil(const emlrtStack *sp, real_T x1_1,
                                         real_T x1_2, real_T x1_3, real_T *y1_1,
                                         real_T *y1_2)
{
  static const int32_T iv[3] = {3389440, -616448, 277504};
  static const int32_T iv2[3] = {-7823360, 2662400, 536576};
  static const int32_T iv3[3] = {-128516096, 96862208, 14417920};
  static const int32_T iv5[3] = {-15081472, -16277504, -12845056};
  static const int32_T iv6[2] = {1, 4};
  static const int32_T iv7[2] = {1, 4};
  static const int16_T a0[9] = {1022, 616,  256, -1051, 1409,
                                1910, -416, -26, -1092};
  static const int16_T b_a0[9] = {-1796, -1999, -877, -852, 1663,
                                  -808,  -1698, 739,  -704};
  static const int16_T c_a0[9] = {1399, -1826, -953,  1221, -1416,
                                  -321, -137,  -1925, -568};
  static const int16_T d_a0[9] = {280, 306,  2012, -710, -451,
                                  843, -566, 88,   1770};
  static const int16_T e_a0[9] = {-99,  -534,  1474, 1051, -594,
                                  1366, -1933, 1719, 842};
  static const int16_T f_a0[6] = {545, 588, 1933, -1784, 877, -1692};
  static const int16_T iv1[3] = {-2844, 310, -1320};
  static const int16_T iv4[2] = {-2178, -2228};
  static const char_T b_u[4] = {'y', '1', '_', '2'};
  static const char_T u[4] = {'y', '1', '_', '1'};
  emlrtStack b_st;
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *b_y1_1;
  const mxArray *b_y1_2;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *i_y;
  const mxArray *j_y;
  const mxArray *k_y;
  const mxArray *l_y;
  const mxArray *m;
  const mxArray *y;
  real_T d;
  int32_T varargin_1[3];
  int32_T l;
  int32_T x1_idx_1;
  int16_T a6[2];
  int16_T b_x1_1;
  int16_T b_x1_2;
  int16_T b_x1_idx_1;
  int16_T i;
  int16_T x1_idx_0;
  int16_T x1_idx_2;
  uint16_T a1[3];
  uint16_T a3_idx_0;
  uint16_T a3_idx_1;
  uint16_T a3_idx_2;
  int8_T b_x1_3;
  uint8_T a2_idx_0;
  uint8_T a2_idx_1;
  uint8_T a2_idx_2;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   */
  /*                                                                           %
   */
  /*           Generated by MATLAB 9.10 and Fixed-Point Designer 7.2           %
   */
  /*                                                                           %
   */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   */
  d = muDoubleScalarFloor(x1_1 * 2048.0);
  if (muDoubleScalarIsNaN(d) || muDoubleScalarIsInf(d)) {
    d = 0.0;
  } else {
    d = muDoubleScalarRem(d, 8192.0);
  }
  if (((int16_T)d & 4096) != 0) {
    b_x1_1 = (int16_T)((int16_T)d | -4096);
  } else {
    b_x1_1 = (int16_T)((int16_T)d & 4095);
  }
  d = muDoubleScalarFloor(x1_2 * 2048.0);
  if (muDoubleScalarIsNaN(d) || muDoubleScalarIsInf(d)) {
    d = 0.0;
  } else {
    d = muDoubleScalarRem(d, 8192.0);
  }
  if (((int16_T)d & 4096) != 0) {
    b_x1_2 = (int16_T)((int16_T)d | -4096);
  } else {
    b_x1_2 = (int16_T)((int16_T)d & 4095);
  }
  d = muDoubleScalarFloor(x1_3);
  if (muDoubleScalarIsNaN(d) || muDoubleScalarIsInf(d)) {
    d = 0.0;
  } else {
    d = muDoubleScalarRem(d, 8.0);
  }
  if (((int8_T)d & 4) != 0) {
    b_x1_3 = (int8_T)((int8_T)d | -4);
  } else {
    b_x1_3 = (int8_T)((int8_T)d & 3);
  }
  st.site = &emlrtRSI;
  b_y1_1 = NULL;
  b_y1_2 = NULL;
  /*  Auto generated function to simulate the generated HDL code using
   * FPGA-in-the-Loop */
  /*   */
  /*  Generated by MATLAB 9.10 and HDL Coder 3.18 */
  /*  Declare persistent variables */
  /*  Initialize persistent variables */
  /*  Call the original MATLAB function to get reference signal */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   */
  /*                                                                           %
   */
  /*           Generated by MATLAB 9.10 and Fixed-Point Designer 7.2           %
   */
  /*                                                                           %
   */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   */
  i = (int16_T)(b_x1_3 << 11);
  if ((i & 4096) != 0) {
    x1_idx_2 = (int16_T)(i | -4096);
  } else {
    x1_idx_2 = (int16_T)(i & 4095);
  }
  /* PLASMA_NN neural network simulation function. */
  /*  */
  /*  Auto-generated by MATLAB, 27-Aug-2022 06:45:03. */
  /*   */
  /*  [y1] = plasma_nn(x1) takes these arguments: */
  /*    x = 3xQ matrix, input #1 */
  /*  and returns: */
  /*    y = 2xQ matrix, output #1 */
  /*  where Q is the number of samples. */
  /*  ===== NEURAL NETWORK CONSTANTS ===== */
  /*  Input 1 */
  /*  Layer 1 */
  /*  Layer 2 */
  /*  Layer 3 */
  /*  Layer 4 */
  /*  Layer 5 */
  /*  Layer 6 */
  /*  Output 1 */
  /*  ===== SIMULATION ======== */
  /*  Dimensions */
  /*  samples */
  /*  Input 1 */
  /*  ===== MODULE FUNCTIONS ======== */
  /*  Map Minimum and Maximum Input Processing Function */
  if (((b_x1_1 - -2048) & 8192) != 0) {
    i = (int16_T)((b_x1_1 - -2048) | -8192);
  } else {
    i = (int16_T)((b_x1_1 - -2048) & 8191);
  }
  if ((i & 4096) != 0) {
    x1_idx_1 = i | -4096;
  } else {
    x1_idx_1 = i & 4095;
  }
  i = (int16_T)(x1_idx_1 + -2048);
  if ((i & 8192) != 0) {
    i = (int16_T)(i | -8192);
  } else {
    i = (int16_T)(i & 8191);
  }
  if ((i & 4096) != 0) {
    x1_idx_0 = (int16_T)(i | -4096);
  } else {
    x1_idx_0 = (int16_T)(i & 4095);
  }
  if (((b_x1_2 - -2048) & 8192) != 0) {
    i = (int16_T)((b_x1_2 - -2048) | -8192);
  } else {
    i = (int16_T)((b_x1_2 - -2048) & 8191);
  }
  if ((i & 4096) != 0) {
    x1_idx_1 = i | -4096;
  } else {
    x1_idx_1 = i & 4095;
  }
  i = (int16_T)(x1_idx_1 + -2048);
  if ((i & 8192) != 0) {
    i = (int16_T)(i | -8192);
  } else {
    i = (int16_T)(i & 8191);
  }
  if ((i & 4096) != 0) {
    b_x1_idx_1 = (int16_T)(i | -4096);
  } else {
    b_x1_idx_1 = (int16_T)(i & 4095);
  }
  if (((x1_idx_2 - -2048) & 8192) != 0) {
    i = (int16_T)((x1_idx_2 - -2048) | -8192);
  } else {
    i = (int16_T)((x1_idx_2 - -2048) & 8191);
  }
  if ((i & 4096) != 0) {
    x1_idx_1 = i | -4096;
  } else {
    x1_idx_1 = i & 4095;
  }
  i = (int16_T)(x1_idx_1 + -2048);
  if ((i & 8192) != 0) {
    i = (int16_T)(i | -8192);
  } else {
    i = (int16_T)(i & 8191);
  }
  if ((i & 4096) != 0) {
    x1_idx_2 = (int16_T)(i | -4096);
  } else {
    x1_idx_2 = (int16_T)(i & 4095);
  }
  /*  Layer 1 */
  /*  Linear Positive Transfer Function */
  for (l = 0; l < 3; l++) {
    x1_idx_1 = a0[l] * x1_idx_0;
    if ((x1_idx_1 & 134217728) != 0) {
      x1_idx_1 |= -134217728;
    } else {
      x1_idx_1 &= 134217727;
    }
    x1_idx_1 += a0[l + 3] * b_x1_idx_1;
    if ((x1_idx_1 & 134217728) != 0) {
      x1_idx_1 |= -134217728;
    } else {
      x1_idx_1 &= 134217727;
    }
    x1_idx_1 += a0[l + 6] * x1_idx_2;
    if ((x1_idx_1 & 134217728) != 0) {
      x1_idx_1 |= -134217728;
    } else {
      x1_idx_1 &= 134217727;
    }
    x1_idx_1 += iv[l];
    if ((x1_idx_1 & 268435456) != 0) {
      x1_idx_1 |= -268435456;
    } else {
      x1_idx_1 &= 268435455;
    }
    if (0 >= x1_idx_1) {
      x1_idx_1 = 0;
    }
    a1[l] = (uint16_T)((uint16_T)(x1_idx_1 >> 10) & 8191);
  }
  /*  Layer 2 */
  /*  Linear Positive Transfer Function */
  a3_idx_0 = a1[0];
  a3_idx_1 = a1[1];
  a3_idx_2 = a1[2];
  for (l = 0; l < 3; l++) {
    x1_idx_1 = b_a0[l] * a3_idx_0;
    if ((x1_idx_1 & 134217728) != 0) {
      x1_idx_1 |= -134217728;
    } else {
      x1_idx_1 &= 134217727;
    }
    x1_idx_1 += b_a0[l + 3] * a3_idx_1;
    if ((x1_idx_1 & 134217728) != 0) {
      x1_idx_1 |= -134217728;
    } else {
      x1_idx_1 &= 134217727;
    }
    x1_idx_1 += b_a0[l + 6] * a3_idx_2;
    if ((x1_idx_1 & 134217728) != 0) {
      x1_idx_1 |= -134217728;
    } else {
      x1_idx_1 &= 134217727;
    }
    x1_idx_1 += iv2[l];
    if ((x1_idx_1 & 268435456) != 0) {
      x1_idx_1 |= -268435456;
    } else {
      x1_idx_1 &= 268435455;
    }
    if (0 < x1_idx_1) {
      varargin_1[l] = x1_idx_1;
    } else {
      varargin_1[l] = 0;
    }
  }
  a2_idx_0 =
      (uint8_T)((uint32_T)((uint16_T)(varargin_1[0] >> 11) & 8191) >> 12);
  a2_idx_1 =
      (uint8_T)((uint32_T)((uint16_T)(varargin_1[1] >> 11) & 8191) >> 12);
  a2_idx_2 =
      (uint8_T)((uint32_T)((uint16_T)(varargin_1[2] >> 11) & 8191) >> 12);
  /*  Layer 3 */
  /*  Linear Positive Transfer Function */
  for (l = 0; l < 3; l++) {
    x1_idx_1 = iv1[l] + (((c_a0[l] * a2_idx_0 + c_a0[l + 3] * a2_idx_1) +
                          c_a0[l + 6] * a2_idx_2)
                         << 1);
    if ((x1_idx_1 & 131072) != 0) {
      x1_idx_1 |= -131072;
    } else {
      x1_idx_1 &= 131071;
    }
    if (0 < x1_idx_1) {
      varargin_1[l] = x1_idx_1;
    } else {
      varargin_1[l] = 0;
    }
  }
  a3_idx_0 =
      (uint16_T)((uint16_T)(((uint16_T)varargin_1[0] & 8191) << 4) & 8191);
  a3_idx_1 =
      (uint16_T)((uint16_T)(((uint16_T)varargin_1[1] & 8191) << 4) & 8191);
  a3_idx_2 =
      (uint16_T)((uint16_T)(((uint16_T)varargin_1[2] & 8191) << 4) & 8191);
  /*  Layer 4 */
  /*  Linear Positive Transfer Function */
  for (l = 0; l < 3; l++) {
    x1_idx_1 = d_a0[l] * a3_idx_0 + d_a0[l + 3] * a3_idx_1;
    if ((x1_idx_1 & 134217728) != 0) {
      x1_idx_1 |= -134217728;
    } else {
      x1_idx_1 &= 134217727;
    }
    x1_idx_1 += d_a0[l + 6] * a3_idx_2;
    if ((x1_idx_1 & 134217728) != 0) {
      x1_idx_1 |= -134217728;
    } else {
      x1_idx_1 &= 134217727;
    }
    x1_idx_1 += iv3[l];
    if ((x1_idx_1 & 536870912) != 0) {
      x1_idx_1 |= -536870912;
    } else {
      x1_idx_1 &= 536870911;
    }
    if (0 < x1_idx_1) {
      varargin_1[l] = x1_idx_1;
    } else {
      varargin_1[l] = 0;
    }
  }
  a3_idx_0 = (uint16_T)(((uint16_T)(varargin_1[0] >> 15) & 8191) << 1 & 8191);
  a3_idx_1 = (uint16_T)(((uint16_T)(varargin_1[1] >> 15) & 8191) << 1 & 8191);
  a3_idx_2 = (uint16_T)(((uint16_T)(varargin_1[2] >> 15) & 8191) << 1 & 8191);
  /*  Layer 5 */
  /*  Linear Positive Transfer Function */
  for (l = 0; l < 3; l++) {
    x1_idx_1 = e_a0[l] * a3_idx_0;
    if ((x1_idx_1 & 134217728) != 0) {
      x1_idx_1 |= -134217728;
    } else {
      x1_idx_1 &= 134217727;
    }
    x1_idx_1 += e_a0[l + 3] * a3_idx_1;
    if ((x1_idx_1 & 134217728) != 0) {
      x1_idx_1 |= -134217728;
    } else {
      x1_idx_1 &= 134217727;
    }
    x1_idx_1 += e_a0[l + 6] * a3_idx_2;
    if ((x1_idx_1 & 134217728) != 0) {
      x1_idx_1 |= -134217728;
    } else {
      x1_idx_1 &= 134217727;
    }
    x1_idx_1 += iv5[l];
    if ((x1_idx_1 & 268435456) != 0) {
      x1_idx_1 |= -268435456;
    } else {
      x1_idx_1 &= 268435455;
    }
    if (0 < x1_idx_1) {
      varargin_1[l] = x1_idx_1;
    } else {
      varargin_1[l] = 0;
    }
  }
  a2_idx_0 =
      (uint8_T)((uint32_T)((uint16_T)(varargin_1[0] >> 12) & 8191) >> 12);
  a2_idx_1 =
      (uint8_T)((uint32_T)((uint16_T)(varargin_1[1] >> 12) & 8191) >> 12);
  a2_idx_2 =
      (uint8_T)((uint32_T)((uint16_T)(varargin_1[2] >> 12) & 8191) >> 12);
  /*  Layer 6 */
  for (l = 0; l < 2; l++) {
    x1_idx_1 = iv4[l] + (((f_a0[l] * a2_idx_0 + f_a0[l + 2] * a2_idx_1) +
                          f_a0[l + 4] * a2_idx_2)
                         << 2);
    if ((x1_idx_1 & 262144) != 0) {
      i = (int16_T)(x1_idx_1 | -262144);
    } else {
      i = (int16_T)(x1_idx_1 & 262143);
    }
    if ((i & 4096) != 0) {
      a6[l] = (int16_T)(i | -4096);
    } else {
      a6[l] = (int16_T)(i & 4095);
    }
  }
  /*  Output 1 */
  /*  Map Minimum and Maximum Output Reverse-Processing Function */
  i = (int16_T)((a6[0] - -8192) >> 1);
  b_x1_idx_1 = (int16_T)((a6[1] - -8192) >> 1);
  if ((i & 4096) != 0) {
    x1_idx_1 = i | -4096;
  } else {
    x1_idx_1 = i & 4095;
  }
  x1_idx_2 = (int16_T)((x1_idx_1 + -4096) | -16384);
  if ((b_x1_idx_1 & 4096) != 0) {
    x1_idx_1 = b_x1_idx_1 | -4096;
  } else {
    x1_idx_1 = b_x1_idx_1 & 4095;
  }
  x1_idx_0 = (int16_T)((x1_idx_1 + -4096) | -16384);
  if ((x1_idx_2 & 4096) != 0) {
    x1_idx_1 = x1_idx_2 | -4096;
  } else {
    x1_idx_1 = x1_idx_2 & 4095;
  }
  i = (int16_T)(x1_idx_1 << 1);
  if ((x1_idx_0 & 4096) != 0) {
    x1_idx_1 = x1_idx_0 | -4096;
  } else {
    x1_idx_1 = x1_idx_0 & 4095;
  }
  b_x1_idx_1 = (int16_T)(x1_idx_1 << 1);
  if ((i & 4096) != 0) {
    x1_idx_1 = i | -4096;
  } else {
    x1_idx_1 = i & 4095;
  }
  x1_idx_0 = (int16_T)(x1_idx_1 >> 2);
  if ((b_x1_idx_1 & 4096) != 0) {
    x1_idx_1 = b_x1_idx_1 | -4096;
  } else {
    x1_idx_1 = b_x1_idx_1 & 4095;
  }
  x1_idx_2 = (int16_T)(x1_idx_1 >> 2);
  /*  Run FPGA-in-the-Loop */
  y = NULL;
  b_y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxINT16_CLASS, mxREAL);
  *(int16_T *)emlrtMxGetData(m) = b_x1_1;
  emlrtAssign(&b_y, m);
  emlrtAssign(&y, emlrtCreateFIR2013b(&st, eml_mx, b_eml_mx,
                                      (const char_T *)"simulinkarray", b_y,
                                      true, false));
  c_y = NULL;
  d_y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxINT16_CLASS, mxREAL);
  *(int16_T *)emlrtMxGetData(m) = b_x1_2;
  emlrtAssign(&d_y, m);
  emlrtAssign(&c_y, emlrtCreateFIR2013b(&st, eml_mx, b_eml_mx,
                                        (const char_T *)"simulinkarray", d_y,
                                        true, false));
  e_y = NULL;
  f_y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxINT8_CLASS, mxREAL);
  *(int8_T *)emlrtMxGetData(m) = b_x1_3;
  emlrtAssign(&f_y, m);
  emlrtAssign(&e_y, emlrtCreateFIR2013b(&st, eml_mx, c_eml_mx,
                                        (const char_T *)"simulinkarray", f_y,
                                        true, false));
  b_st.site = &p_emlrtRSI;
  c_plasma_nn_wrapper_fixpt_sysob(&b_st, y, c_y, e_y, &b_emlrtMCI, &b_y1_1,
                                  &b_y1_2);
  /*  Verify the FPGA-in-the-Loop output */
  g_y = NULL;
  h_y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxINT16_CLASS, mxREAL);
  *(int16_T *)emlrtMxGetData(m) = x1_idx_0;
  emlrtAssign(&h_y, m);
  emlrtAssign(&g_y, emlrtCreateFIR2013b(&st, eml_mx, b_eml_mx,
                                        (const char_T *)"simulinkarray", h_y,
                                        true, false));
  i_y = NULL;
  m = emlrtCreateCharArray(2, &iv6[0]);
  emlrtInitCharArrayR2013a(&st, 4, m, &u[0]);
  emlrtAssign(&i_y, m);
  b_st.site = &r_emlrtRSI;
  hdlverifier_assert(&b_st, emlrtAlias(b_y1_1), g_y, i_y, &c_emlrtMCI);
  j_y = NULL;
  k_y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxINT16_CLASS, mxREAL);
  *(int16_T *)emlrtMxGetData(m) = x1_idx_2;
  emlrtAssign(&k_y, m);
  emlrtAssign(&j_y, emlrtCreateFIR2013b(&st, eml_mx, b_eml_mx,
                                        (const char_T *)"simulinkarray", k_y,
                                        true, false));
  l_y = NULL;
  m = emlrtCreateCharArray(2, &iv7[0]);
  emlrtInitCharArrayR2013a(&st, 4, m, &b_u[0]);
  emlrtAssign(&l_y, m);
  b_st.site = &q_emlrtRSI;
  hdlverifier_assert(&b_st, emlrtAlias(b_y1_2), j_y, l_y, &d_emlrtMCI);
  emlrtDestroyArray(&b_y1_1);
  emlrtDestroyArray(&b_y1_2);
  *y1_1 = (real_T)x1_idx_0 * 0.00048828125;
  *y1_2 = (real_T)x1_idx_2 * 0.00048828125;
}

/* End of code generation (plasma_nn_wrapper_wrapper_fixpt_fil.c) */
