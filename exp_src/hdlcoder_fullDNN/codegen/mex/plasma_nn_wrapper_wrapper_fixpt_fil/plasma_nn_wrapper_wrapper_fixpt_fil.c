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
#include "plasma_nn_wrapper_wrapper_fixpt_fil_mexutil.h"
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

static emlrtRSInfo b_emlrtRSI = {
    27,                            /* lineNo */
    "plasma_nn_wrapper_fixpt_fil", /* fcnName */
    "/home/kimberlychan/Desktop/DNN_Generality/matlab/hdlcoder_fullDNN/codegen/"
    "plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil.m" /* pathName */
};

static emlrtMCInfo b_emlrtMCI = {
    21,                            /* lineNo */
    20,                            /* colNo */
    "plasma_nn_wrapper_fixpt_fil", /* fName */
    "/home/kimberlychan/Desktop/DNN_Generality/matlab/hdlcoder_fullDNN/codegen/"
    "plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil.m" /* pName */
};

static emlrtMCInfo c_emlrtMCI = {
    21,                            /* lineNo */
    4,                             /* colNo */
    "plasma_nn_wrapper_fixpt_fil", /* fName */
    "/home/kimberlychan/Desktop/DNN_Generality/matlab/hdlcoder_fullDNN/codegen/"
    "plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil.m" /* pName */
};

static emlrtMCInfo d_emlrtMCI = {
    22,                            /* lineNo */
    20,                            /* colNo */
    "plasma_nn_wrapper_fixpt_fil", /* fName */
    "/home/kimberlychan/Desktop/DNN_Generality/matlab/hdlcoder_fullDNN/codegen/"
    "plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil.m" /* pName */
};

static emlrtMCInfo e_emlrtMCI = {
    30,                            /* lineNo */
    1,                             /* colNo */
    "plasma_nn_wrapper_fixpt_fil", /* fName */
    "/home/kimberlychan/Desktop/DNN_Generality/matlab/hdlcoder_fullDNN/codegen/"
    "plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil.m" /* pName */
};

static emlrtMCInfo f_emlrtMCI = {
    22,                            /* lineNo */
    4,                             /* colNo */
    "plasma_nn_wrapper_fixpt_fil", /* fName */
    "/home/kimberlychan/Desktop/DNN_Generality/matlab/hdlcoder_fullDNN/codegen/"
    "plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil.m" /* pName */
};

static emlrtMCInfo g_emlrtMCI = {
    33,                            /* lineNo */
    11,                            /* colNo */
    "plasma_nn_wrapper_fixpt_fil", /* fName */
    "/home/kimberlychan/Desktop/DNN_Generality/matlab/hdlcoder_fullDNN/codegen/"
    "plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil.m" /* pName */
};

static emlrtMCInfo h_emlrtMCI = {
    34,                            /* lineNo */
    11,                            /* colNo */
    "plasma_nn_wrapper_fixpt_fil", /* fName */
    "/home/kimberlychan/Desktop/DNN_Generality/matlab/hdlcoder_fullDNN/codegen/"
    "plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil.m" /* pName */
};

static emlrtMCInfo i_emlrtMCI = {
    37,                            /* lineNo */
    1,                             /* colNo */
    "plasma_nn_wrapper_fixpt_fil", /* fName */
    "/home/kimberlychan/Desktop/DNN_Generality/matlab/hdlcoder_fullDNN/codegen/"
    "plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil.m" /* pName */
};

static emlrtMCInfo j_emlrtMCI = {
    38,                            /* lineNo */
    1,                             /* colNo */
    "plasma_nn_wrapper_fixpt_fil", /* fName */
    "/home/kimberlychan/Desktop/DNN_Generality/matlab/hdlcoder_fullDNN/codegen/"
    "plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil.m" /* pName */
};

static emlrtRSInfo n_emlrtRSI = {
    22,                            /* lineNo */
    "plasma_nn_wrapper_fixpt_fil", /* fcnName */
    "/home/kimberlychan/Desktop/DNN_Generality/matlab/hdlcoder_fullDNN/codegen/"
    "plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil.m" /* pathName */
};

static emlrtRSInfo o_emlrtRSI = {
    21,                            /* lineNo */
    "plasma_nn_wrapper_fixpt_fil", /* fcnName */
    "/home/kimberlychan/Desktop/DNN_Generality/matlab/hdlcoder_fullDNN/codegen/"
    "plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil.m" /* pathName */
};

static emlrtRSInfo p_emlrtRSI = {
    30,                            /* lineNo */
    "plasma_nn_wrapper_fixpt_fil", /* fcnName */
    "/home/kimberlychan/Desktop/DNN_Generality/matlab/hdlcoder_fullDNN/codegen/"
    "plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil.m" /* pathName */
};

static emlrtRSInfo q_emlrtRSI = {
    34,                            /* lineNo */
    "plasma_nn_wrapper_fixpt_fil", /* fcnName */
    "/home/kimberlychan/Desktop/DNN_Generality/matlab/hdlcoder_fullDNN/codegen/"
    "plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil.m" /* pathName */
};

static emlrtRSInfo r_emlrtRSI = {
    33,                            /* lineNo */
    "plasma_nn_wrapper_fixpt_fil", /* fcnName */
    "/home/kimberlychan/Desktop/DNN_Generality/matlab/hdlcoder_fullDNN/codegen/"
    "plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil.m" /* pathName */
};

static emlrtRSInfo s_emlrtRSI = {
    38,                            /* lineNo */
    "plasma_nn_wrapper_fixpt_fil", /* fcnName */
    "/home/kimberlychan/Desktop/DNN_Generality/matlab/hdlcoder_fullDNN/codegen/"
    "plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil.m" /* pathName */
};

static emlrtRSInfo t_emlrtRSI = {
    37,                            /* lineNo */
    "plasma_nn_wrapper_fixpt_fil", /* fcnName */
    "/home/kimberlychan/Desktop/DNN_Generality/matlab/hdlcoder_fullDNN/codegen/"
    "plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil.m" /* pathName */
};

/* Function Declarations */
static boolean_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId);

static void c_plasma_nn_wrapper_fixpt_sysob(
    const emlrtStack *sp, const mxArray *b, const mxArray *c, const mxArray *d,
    emlrtMCInfo *location, const mxArray **e, const mxArray **f);

static boolean_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId);

static boolean_T emlrt_marshallIn(const emlrtStack *sp,
                                  const mxArray *a__output_of_isempty_,
                                  const char_T *identifier);

static const mxArray *hdlverifier_Delay(const emlrtStack *sp, const mxArray *b,
                                        const mxArray *c,
                                        emlrtMCInfo *location);

static void hdlverifier_assert(const emlrtStack *sp, const mxArray *b,
                               const mxArray *c, const mxArray *d,
                               emlrtMCInfo *location);

static const mxArray *isempty(const emlrtStack *sp, const mxArray *b,
                              emlrtMCInfo *location);

static const mxArray *step(const emlrtStack *sp, const mxArray *b,
                           const mxArray *c, emlrtMCInfo *location);

/* Function Definitions */
static boolean_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = e_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

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

static boolean_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  boolean_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"logical",
                          false, 0U, (void *)&dims);
  ret = *emlrtMxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

static boolean_T emlrt_marshallIn(const emlrtStack *sp,
                                  const mxArray *a__output_of_isempty_,
                                  const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  boolean_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(a__output_of_isempty_), &thisId);
  emlrtDestroyArray(&a__output_of_isempty_);
  return y;
}

static const mxArray *hdlverifier_Delay(const emlrtStack *sp, const mxArray *b,
                                        const mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b((emlrtCTX)sp, 1, &m, 2, &pArrays[0],
                               (const char_T *)"hdlverifier.Delay", true,
                               location);
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

static const mxArray *isempty(const emlrtStack *sp, const mxArray *b,
                              emlrtMCInfo *location)
{
  const mxArray *m;
  const mxArray *pArray;
  pArray = b;
  return emlrtCallMATLABR2012b((emlrtCTX)sp, 1, &m, 1, &pArray,
                               (const char_T *)"isempty", true, location);
}

static const mxArray *step(const emlrtStack *sp, const mxArray *b,
                           const mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b((emlrtCTX)sp, 1, &m, 2, &pArrays[0],
                               (const char_T *)"step", true, location);
}

void plasma_nn_wrapper_wrapper_fixpt_fil(const emlrtStack *sp, real_T x1_1,
                                         real_T x1_2, real_T x1_3, real_T *y1_1,
                                         real_T *y1_2)
{
  static const int64_T iv2[5] = {9527492608L, -706609152L, -1815740416L,
                                 8103657472L, -3407347712L};
  static const int64_T iv3[5] = {5128978432L, 4550361088L, -417136640L,
                                 -3066494976L, -1505165312L};
  static const int64_T iv4[5] = {-4548591616L, -1108738048L, 1084293120L,
                                 -3516989440L, 1093140480L};
  static const int64_T iv5[2] = {716177408L, -5205262336L};
  static const int32_T b_a0[25] = {
      914,    43406, -80686, 34750, -32579, -56623, 99110, 28958, -5723,
      -32968, 20967, -55859, -4545, 35941,  8472,   14555, 30894, 37795,
      -15484, -6731, -68426, 41021, -48600, -67637, -28444};
  static const int32_T c_a0[25] = {
      73712, -32011, -29139, 7570,  -10789, 43049, -30920, -27945, -20768,
      30570, 10932,  16919,  16970, -30028, 20381, -34457, -27772, 53936,
      20041, 13059,  4809,   -2641, 4555,   21651, 24877};
  static const int32_T a0[15] = {-109264, 6665,   -17982, 81496, -92017,
                                 21466,   -16883, 24708,  7505,  22953,
                                 -45609,  102915, 6855,   -142,  -76939};
  static const int32_T d_a0[10] = {-90348, 58862, 10902, -6093, 40049,
                                   -4255,  60747, 17333, 24484, -2097};
  static const int32_T iv[2] = {1, 6};
  static const int32_T iv1[2] = {1, 6};
  static const int32_T iv6[2] = {1, 4};
  static const int32_T iv7[2] = {1, 4};
  static const char_T u[6] = {'L', 'e', 'n', 'g', 't', 'h'};
  static const char_T b_u[4] = {'y', '1', '_', '1'};
  static const char_T c_u[4] = {'y', '1', '_', '2'};
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
  const mxArray *m_y;
  const mxArray *n_y;
  const mxArray *y;
  const mxArray *y1_1_d7;
  const mxArray *y1_2_d7;
  int64_T varargin_1[5];
  int64_T i;
  real_T d;
  int32_T b_a4[2];
  int32_T a4;
  int32_T b_x1_1;
  int32_T b_x1_2;
  int32_T l;
  int32_T x1_idx_0;
  int32_T x1_idx_1;
  int32_T x1_idx_2;
  uint32_T a1[5];
  uint32_T ref_y1_1;
  int8_T b_x1_3;
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
  d = muDoubleScalarFloor(x1_1 * 65536.0);
  if (muDoubleScalarIsNaN(d) || muDoubleScalarIsInf(d)) {
    d = 0.0;
  } else {
    d = muDoubleScalarRem(d, 262144.0);
  }
  if (((int32_T)d & 131072) != 0) {
    b_x1_1 = (int32_T)d | -131072;
  } else {
    b_x1_1 = (int32_T)d & 131071;
  }
  d = muDoubleScalarFloor(x1_2 * 65536.0);
  if (muDoubleScalarIsNaN(d) || muDoubleScalarIsInf(d)) {
    d = 0.0;
  } else {
    d = muDoubleScalarRem(d, 262144.0);
  }
  if (((int32_T)d & 131072) != 0) {
    b_x1_2 = (int32_T)d | -131072;
  } else {
    b_x1_2 = (int32_T)d & 131071;
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
  y1_1_d7 = NULL;
  y1_2_d7 = NULL;
  b_y1_1 = NULL;
  b_y1_2 = NULL;
  /*  Auto generated function to simulate the generated HDL code using
   * FPGA-in-the-Loop */
  /*   */
  /*  Generated by MATLAB 9.10 and HDL Coder 3.18 */
  /*  Declare persistent variables */
  /*  Initialize persistent variables */
  if (!initialized_not_empty) {
    initialized_not_empty = true;
    /*  Instantiate delay System object(s) */
    y = NULL;
    m = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a(&st, 6, m, &u[0]);
    emlrtAssign(&y, m);
    b_st.site = &o_emlrtRSI;
    emlrtAssignP(
        &delayobj_y1_1,
        hdlverifier_Delay(&b_st, y, emlrt_marshallOut(7.0), &b_emlrtMCI));
    b_st.site = &o_emlrtRSI;
    emlrt_marshallIn(&b_st,
                     isempty(&b_st, emlrtAliasP(delayobj_y1_1), &c_emlrtMCI),
                     "<output of isempty>");
    b_y = NULL;
    m = emlrtCreateCharArray(2, &iv1[0]);
    emlrtInitCharArrayR2013a(&st, 6, m, &u[0]);
    emlrtAssign(&b_y, m);
    b_st.site = &n_emlrtRSI;
    emlrtAssignP(
        &delayobj_y1_2,
        hdlverifier_Delay(&b_st, b_y, emlrt_marshallOut(7.0), &d_emlrtMCI));
    b_st.site = &n_emlrtRSI;
    emlrt_marshallIn(&b_st,
                     isempty(&b_st, emlrtAliasP(delayobj_y1_2), &f_emlrtMCI),
                     "<output of isempty>");
  }
  /*  Call the original MATLAB function to get reference signal */
  b_st.site = &b_emlrtRSI;
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
  a4 = b_x1_3 << 16;
  if ((a4 & 131072) != 0) {
    x1_idx_2 = a4 | -131072;
  } else {
    x1_idx_2 = a4 & 131071;
  }
  /* PLASMA_NN neural network simulation function. */
  /*  */
  /*  Auto-generated by MATLAB, 04-Jan-2022 18:12:37. */
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
  /*  Output 1 */
  /*  ===== SIMULATION ======== */
  /*  Dimensions */
  /*  samples */
  /*  Input 1 */
  /*  ===== MODULE FUNCTIONS ======== */
  /*  Map Minimum and Maximum Input Processing Function */
  if (((b_x1_1 - -65536) & 262144) != 0) {
    a4 = (b_x1_1 - -65536) | -262144;
  } else {
    a4 = (b_x1_1 - -65536) & 262143;
  }
  if ((a4 & 131072) != 0) {
    a4 |= -131072;
  } else {
    a4 &= 131071;
  }
  a4 += -65536;
  if ((a4 & 262144) != 0) {
    a4 |= -262144;
  } else {
    a4 &= 262143;
  }
  if ((a4 & 131072) != 0) {
    x1_idx_0 = a4 | -131072;
  } else {
    x1_idx_0 = a4 & 131071;
  }
  if (((b_x1_2 - -65536) & 262144) != 0) {
    a4 = (b_x1_2 - -65536) | -262144;
  } else {
    a4 = (b_x1_2 - -65536) & 262143;
  }
  if ((a4 & 131072) != 0) {
    a4 |= -131072;
  } else {
    a4 &= 131071;
  }
  a4 += -65536;
  if ((a4 & 262144) != 0) {
    a4 |= -262144;
  } else {
    a4 &= 262143;
  }
  if ((a4 & 131072) != 0) {
    x1_idx_1 = a4 | -131072;
  } else {
    x1_idx_1 = a4 & 131071;
  }
  if (((x1_idx_2 - -65536) & 262144) != 0) {
    a4 = (x1_idx_2 - -65536) | -262144;
  } else {
    a4 = (x1_idx_2 - -65536) & 262143;
  }
  if ((a4 & 131072) != 0) {
    a4 |= -131072;
  } else {
    a4 &= 131071;
  }
  a4 += -65536;
  if ((a4 & 262144) != 0) {
    a4 |= -262144;
  } else {
    a4 &= 262143;
  }
  if ((a4 & 131072) != 0) {
    x1_idx_2 = a4 | -131072;
  } else {
    x1_idx_2 = a4 & 131071;
  }
  /*  Layer 1 */
  /*  Linear Positive Transfer Function */
  for (l = 0; l < 5; l++) {
    i = (int64_T)a0[l] * x1_idx_0;
    if ((i & 137438953472L) != 0L) {
      i |= -137438953472L;
    } else {
      i &= 137438953471L;
    }
    i += (int64_T)a0[l + 5] * x1_idx_1;
    if ((i & 137438953472L) != 0L) {
      i |= -137438953472L;
    } else {
      i &= 137438953471L;
    }
    i += (int64_T)a0[l + 10] * x1_idx_2;
    if ((i & 137438953472L) != 0L) {
      i |= -137438953472L;
    } else {
      i &= 137438953471L;
    }
    i += iv3[l];
    if ((i & 274877906944L) != 0L) {
      i |= -274877906944L;
    } else {
      i &= 274877906943L;
    }
    if (0L >= i) {
      i = 0L;
    }
    a1[l] = (uint32_T)(i >> 16) & 262143U;
  }
  /*  Layer 2 */
  /*  Linear Positive Transfer Function */
  for (l = 0; l < 5; l++) {
    i = 0L;
    for (x1_idx_2 = 0; x1_idx_2 < 5; x1_idx_2++) {
      i += (int64_T)b_a0[l + 5 * x1_idx_2] * a1[x1_idx_2];
      if ((i & 274877906944L) != 0L) {
        i |= -274877906944L;
      } else {
        i &= 274877906943L;
      }
    }
    i += iv2[l];
    if ((i & 549755813888L) != 0L) {
      i |= -549755813888L;
    } else {
      i &= 549755813887L;
    }
    if (0L < i) {
      varargin_1[l] = i;
    } else {
      varargin_1[l] = 0L;
    }
  }
  for (x1_idx_2 = 0; x1_idx_2 < 5; x1_idx_2++) {
    a1[x1_idx_2] = (uint32_T)(varargin_1[x1_idx_2] >> 16) & 262143U;
  }
  /*  Layer 3 */
  /*  Linear Positive Transfer Function */
  for (l = 0; l < 5; l++) {
    i = 0L;
    for (x1_idx_2 = 0; x1_idx_2 < 5; x1_idx_2++) {
      i += (int64_T)c_a0[l + 5 * x1_idx_2] * a1[x1_idx_2];
      if ((i & 274877906944L) != 0L) {
        i |= -274877906944L;
      } else {
        i &= 274877906943L;
      }
    }
    i += iv4[l];
    if ((i & 549755813888L) != 0L) {
      i |= -549755813888L;
    } else {
      i &= 549755813887L;
    }
    if (0L < i) {
      varargin_1[l] = i;
    } else {
      varargin_1[l] = 0L;
    }
  }
  for (x1_idx_2 = 0; x1_idx_2 < 5; x1_idx_2++) {
    a1[x1_idx_2] = (uint32_T)(varargin_1[x1_idx_2] >> 15) & 262143U;
  }
  /*  Layer 4 */
  for (l = 0; l < 2; l++) {
    i = 0L;
    for (x1_idx_2 = 0; x1_idx_2 < 5; x1_idx_2++) {
      i += (int64_T)d_a0[l + (x1_idx_2 << 1)] * a1[x1_idx_2];
      if ((i & 274877906944L) != 0L) {
        i |= -274877906944L;
      } else {
        i &= 274877906943L;
      }
    }
    i += iv5[l];
    if ((i & 549755813888L) != 0L) {
      i |= -549755813888L;
    } else {
      i &= 549755813887L;
    }
    a4 = (int32_T)(i >> 15);
    if ((a4 & 131072) != 0) {
      b_a4[l] = a4 | -131072;
    } else {
      b_a4[l] = a4 & 131071;
    }
  }
  /*  Output 1 */
  /*  Map Minimum and Maximum Output Reverse-Processing Function */
  if (((b_a4[0] - -65536) & 262144) != 0) {
    a4 = (b_a4[0] - -65536) | -262144;
  } else {
    a4 = (b_a4[0] - -65536) & 262143;
  }
  x1_idx_2 = a4 >> 1;
  if (((b_a4[1] - -65536) & 262144) != 0) {
    a4 = (b_a4[1] - -65536) | -262144;
  } else {
    a4 = (b_a4[1] - -65536) & 262143;
  }
  x1_idx_0 = a4 >> 1;
  if (((x1_idx_2 + -32768) & 262144) != 0) {
    x1_idx_2 = (x1_idx_2 + -32768) | -262144;
  } else {
    x1_idx_2 = (x1_idx_2 + -32768) & 262143;
  }
  if (((x1_idx_0 + -32768) & 262144) != 0) {
    x1_idx_0 = (x1_idx_0 + -32768) | -262144;
  } else {
    x1_idx_0 = (x1_idx_0 + -32768) & 262143;
  }
  if ((x1_idx_2 & 131072) != 0) {
    x1_idx_2 |= -131072;
  } else {
    x1_idx_2 &= 131071;
  }
  a4 = x1_idx_2 << 1;
  if ((x1_idx_0 & 131072) != 0) {
    x1_idx_0 |= -131072;
  } else {
    x1_idx_0 &= 131071;
  }
  x1_idx_2 = x1_idx_0 << 1;
  if ((x1_idx_2 & 131072) != 0) {
    b_a4[1] = x1_idx_2 | -131072;
  } else {
    b_a4[1] = x1_idx_2 & 131071;
  }
  if ((a4 & 131072) != 0) {
    a4 |= -131072;
  } else {
    a4 &= 131071;
  }
  ref_y1_1 = (uint32_T)a4 << 1 & 262143U;
  /*  Run FPGA-in-the-Loop */
  c_y = NULL;
  d_y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)emlrtMxGetData(m) = b_x1_1;
  emlrtAssign(&d_y, m);
  emlrtAssign(&c_y, emlrtCreateFIR2013b(&st, eml_mx, b_eml_mx,
                                        (const char_T *)"simulinkarray", d_y,
                                        true, false));
  e_y = NULL;
  f_y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)emlrtMxGetData(m) = b_x1_2;
  emlrtAssign(&f_y, m);
  emlrtAssign(&e_y, emlrtCreateFIR2013b(&st, eml_mx, b_eml_mx,
                                        (const char_T *)"simulinkarray", f_y,
                                        true, false));
  g_y = NULL;
  h_y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxINT8_CLASS, mxREAL);
  *(int8_T *)emlrtMxGetData(m) = b_x1_3;
  emlrtAssign(&h_y, m);
  emlrtAssign(&g_y, emlrtCreateFIR2013b(&st, eml_mx, c_eml_mx,
                                        (const char_T *)"simulinkarray", h_y,
                                        true, false));
  b_st.site = &p_emlrtRSI;
  c_plasma_nn_wrapper_fixpt_sysob(&b_st, c_y, e_y, g_y, &e_emlrtMCI, &b_y1_1,
                                  &b_y1_2);
  /*  Delay reference signal */
  i_y = NULL;
  j_y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
  *(uint32_T *)emlrtMxGetData(m) = ref_y1_1;
  emlrtAssign(&j_y, m);
  emlrtAssign(&i_y, emlrtCreateFIR2013b(&st, eml_mx, d_eml_mx,
                                        (const char_T *)"simulinkarray", j_y,
                                        true, false));
  b_st.site = &r_emlrtRSI;
  emlrtAssign(&y1_1_d7,
              step(&b_st, emlrtAliasP(delayobj_y1_1), i_y, &g_emlrtMCI));
  k_y = NULL;
  l_y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)emlrtMxGetData(m) = b_a4[1];
  emlrtAssign(&l_y, m);
  emlrtAssign(&k_y, emlrtCreateFIR2013b(&st, eml_mx, b_eml_mx,
                                        (const char_T *)"simulinkarray", l_y,
                                        true, false));
  b_st.site = &q_emlrtRSI;
  emlrtAssign(&y1_2_d7,
              step(&b_st, emlrtAliasP(delayobj_y1_2), k_y, &h_emlrtMCI));
  /*  Verify the FPGA-in-the-Loop output */
  m_y = NULL;
  m = emlrtCreateCharArray(2, &iv6[0]);
  emlrtInitCharArrayR2013a(&st, 4, m, &b_u[0]);
  emlrtAssign(&m_y, m);
  b_st.site = &t_emlrtRSI;
  hdlverifier_assert(&b_st, emlrtAlias(b_y1_1), emlrtAlias(y1_1_d7), m_y,
                     &i_emlrtMCI);
  n_y = NULL;
  m = emlrtCreateCharArray(2, &iv7[0]);
  emlrtInitCharArrayR2013a(&st, 4, m, &c_u[0]);
  emlrtAssign(&n_y, m);
  b_st.site = &s_emlrtRSI;
  hdlverifier_assert(&b_st, emlrtAlias(b_y1_2), emlrtAlias(y1_2_d7), n_y,
                     &j_emlrtMCI);
  emlrtDestroyArray(&y1_1_d7);
  emlrtDestroyArray(&y1_2_d7);
  emlrtDestroyArray(&b_y1_1);
  emlrtDestroyArray(&b_y1_2);
  *y1_1 = (real_T)ref_y1_1 * 7.62939453125E-6;
  *y1_2 = (real_T)b_a4[1] * 1.52587890625E-5;
}

/* End of code generation (plasma_nn_wrapper_wrapper_fixpt_fil.c) */
