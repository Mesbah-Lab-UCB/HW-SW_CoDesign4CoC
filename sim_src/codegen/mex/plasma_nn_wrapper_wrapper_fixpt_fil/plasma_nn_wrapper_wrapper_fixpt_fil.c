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
    "/home/kimberlychan/Desktop/DNN_Generality/matlab_v3/hdlcoder_fullDNN/"
    "codegen/plasma_nn_wrapper/fil/plasma_nn_wrapper_wrapper_fix"
    "pt_fil.m" /* pathName */
};

static emlrtMCInfo b_emlrtMCI = {
    24,                            /* lineNo */
    1,                             /* colNo */
    "plasma_nn_wrapper_fixpt_fil", /* fName */
    "/home/kimberlychan/Desktop/DNN_Generality/matlab_v3/hdlcoder_fullDNN/"
    "codegen/plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil.m" /* pName */
};

static emlrtMCInfo c_emlrtMCI = {
    27,                            /* lineNo */
    1,                             /* colNo */
    "plasma_nn_wrapper_fixpt_fil", /* fName */
    "/home/kimberlychan/Desktop/DNN_Generality/matlab_v3/hdlcoder_fullDNN/"
    "codegen/plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil.m" /* pName */
};

static emlrtMCInfo d_emlrtMCI = {
    28,                            /* lineNo */
    1,                             /* colNo */
    "plasma_nn_wrapper_fixpt_fil", /* fName */
    "/home/kimberlychan/Desktop/DNN_Generality/matlab_v3/hdlcoder_fullDNN/"
    "codegen/plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil.m" /* pName */
};

static emlrtRSInfo n_emlrtRSI = {
    24,                            /* lineNo */
    "plasma_nn_wrapper_fixpt_fil", /* fcnName */
    "/home/kimberlychan/Desktop/DNN_Generality/matlab_v3/hdlcoder_fullDNN/"
    "codegen/plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil.m" /* pathName */
};

static emlrtRSInfo o_emlrtRSI = {
    28,                            /* lineNo */
    "plasma_nn_wrapper_fixpt_fil", /* fcnName */
    "/home/kimberlychan/Desktop/DNN_Generality/matlab_v3/hdlcoder_fullDNN/"
    "codegen/plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil.m" /* pathName */
};

static emlrtRSInfo p_emlrtRSI = {
    27,                            /* lineNo */
    "plasma_nn_wrapper_fixpt_fil", /* fcnName */
    "/home/kimberlychan/Desktop/DNN_Generality/matlab_v3/hdlcoder_fullDNN/"
    "codegen/plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil.m" /* pathName */
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
  static const int64_T iv[8] = {-16904880128L, -25853820928L, 23285071872L,
                                37209374720L,  19995164672L,  -52663156736L,
                                -727187456L,   44570247168L};
  static const int64_T iv1[8] = {24578097152L,  -1983905792L,  27329560576L,
                                 -52073332736L, -45335969792L, -67631841280L,
                                 24271388672L,  111924477952L};
  static const int64_T iv2[8] = {46637776896L,  -33064484864L, -5188091904L,
                                 58317340672L,  -85371650048L, -66821029888L,
                                 -27205566464L, -10976755712L};
  static const int64_T iv3[2] = {120586240L, -8605040640L};
  static const int32_T b_a0[64] = {
      61905,   -19092,  265912,  39825,   77176,   288508,  207135,  -39373,
      182272,  44679,   21831,   439383,  -54682,  -35033,  -44849,  -108319,
      45440,   514,     -143550, -19873,  -216847, 54031,   85678,   -75306,
      -66433,  166449,  26380,   68716,   -166705, 75932,   -134662, -229272,
      -190986, -222906, 132241,  -100005, 133599,  -26998,  151965,  -203535,
      -80037,  -21566,  212088,  14973,   2838,    -161675, -76198,  256037,
      333567,  -251297, 53020,   -97667,  -106871, -52096,  109641,  -249383,
      78523,   3573,    -195091, -338365, -320946, 81978,   39391,   225248};
  static const int32_T c_a0[64] = {
      41767,   -231739, 88755,   -156060, 160848,  -86020,  -186607, 172808,
      88387,   1523,    -50239,  31581,   -116178, 37109,   176974,  249738,
      257244,  -104257, 324631,  167188,  -132980, -195113, -63008,  94164,
      261683,  93739,   -158032, -299798, 397969,  -101696, -91119,  -177317,
      85623,   107555,  289424,  -286928, 149617,  -236068, -16414,  -27223,
      134406,  133028,  -153207, -316665, 15925,   171193,  -76225,  -88090,
      -140058, -78116,  -99678,  -20129,  35700,   -257446, 102764,  238425,
      -118988, -162840, -304898, -23374,  77188,   201987,  239785,  174378};
  static const int32_T a0[24] = {
      -339561, 206478,  -17636, 78947,   -76200, -17289,  -370809, -203504,
      -114585, -4897,   116005, -11905,  -25713, 1255,    -3288,   -34806,
      272748,  -229731, 452,    -104423, 21067,  -131699, -221847, -300973};
  static const int32_T d_a0[16] = {
      -226326, 205901, -199033, -237054, -37178, 304815, 285630, -264047,
      -237295, 213994, -70837,  7291,    228346, 274352, 144674, -121415};
  static const int32_T iv4[2] = {1, 4};
  static const int32_T iv5[2] = {1, 4};
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
  int64_T varargin_1[8];
  int64_T i;
  real_T d;
  int32_T a4[2];
  int32_T b_x1_1;
  int32_T b_x1_2;
  int32_T b_x1_3;
  int32_T l;
  int32_T x1_idx_0;
  int32_T x1_idx_1;
  int32_T x1_idx_2;
  uint32_T a1[8];
  uint32_T a3[8];
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
  d = muDoubleScalarFloor(x1_1 * 262144.0);
  if (muDoubleScalarIsNaN(d) || muDoubleScalarIsInf(d)) {
    d = 0.0;
  } else {
    d = muDoubleScalarRem(d, 1.048576E+6);
  }
  if (((int32_T)d & 524288) != 0) {
    b_x1_1 = (int32_T)d | -524288;
  } else {
    b_x1_1 = (int32_T)d & 524287;
  }
  d = muDoubleScalarFloor(x1_2 * 262144.0);
  if (muDoubleScalarIsNaN(d) || muDoubleScalarIsInf(d)) {
    d = 0.0;
  } else {
    d = muDoubleScalarRem(d, 1.048576E+6);
  }
  if (((int32_T)d & 524288) != 0) {
    b_x1_2 = (int32_T)d | -524288;
  } else {
    b_x1_2 = (int32_T)d & 524287;
  }
  d = muDoubleScalarFloor(x1_3 * 262144.0);
  if (muDoubleScalarIsNaN(d) || muDoubleScalarIsInf(d)) {
    d = 0.0;
  } else {
    d = muDoubleScalarRem(d, 1.048576E+6);
  }
  if (((int32_T)d & 524288) != 0) {
    b_x1_3 = (int32_T)d | -524288;
  } else {
    b_x1_3 = (int32_T)d & 524287;
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
  /* PLASMA_NN neural network simulation function. */
  /*  */
  /*  Auto-generated by MATLAB, 04-Oct-2023 00:25:18. */
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
  if (((b_x1_1 - -262144) & 1048576) != 0) {
    l = (b_x1_1 - -262144) | -1048576;
  } else {
    l = (b_x1_1 - -262144) & 1048575;
  }
  x1_idx_2 = (l >> 1) + -131072;
  if ((x1_idx_2 & 1048576) != 0) {
    x1_idx_2 |= -1048576;
  } else {
    x1_idx_2 &= 1048575;
  }
  if ((x1_idx_2 & 524288) != 0) {
    x1_idx_2 |= -524288;
  } else {
    x1_idx_2 &= 524287;
  }
  x1_idx_2 <<= 1;
  if ((x1_idx_2 & 524288) != 0) {
    x1_idx_0 = x1_idx_2 | -524288;
  } else {
    x1_idx_0 = x1_idx_2 & 524287;
  }
  if (((b_x1_2 - -262144) & 1048576) != 0) {
    l = (b_x1_2 - -262144) | -1048576;
  } else {
    l = (b_x1_2 - -262144) & 1048575;
  }
  x1_idx_2 = (l >> 1) + -131072;
  if ((x1_idx_2 & 1048576) != 0) {
    x1_idx_2 |= -1048576;
  } else {
    x1_idx_2 &= 1048575;
  }
  if ((x1_idx_2 & 524288) != 0) {
    x1_idx_2 |= -524288;
  } else {
    x1_idx_2 &= 524287;
  }
  x1_idx_2 <<= 1;
  if ((x1_idx_2 & 524288) != 0) {
    x1_idx_1 = x1_idx_2 | -524288;
  } else {
    x1_idx_1 = x1_idx_2 & 524287;
  }
  if (((b_x1_3 - -262144) & 1048576) != 0) {
    l = (b_x1_3 - -262144) | -1048576;
  } else {
    l = (b_x1_3 - -262144) & 1048575;
  }
  x1_idx_2 = (l >> 1) + -131072;
  if ((x1_idx_2 & 1048576) != 0) {
    x1_idx_2 |= -1048576;
  } else {
    x1_idx_2 &= 1048575;
  }
  if ((x1_idx_2 & 524288) != 0) {
    x1_idx_2 |= -524288;
  } else {
    x1_idx_2 &= 524287;
  }
  x1_idx_2 <<= 1;
  if ((x1_idx_2 & 524288) != 0) {
    x1_idx_2 |= -524288;
  } else {
    x1_idx_2 &= 524287;
  }
  /*  Layer 1 */
  /*  Linear Positive Transfer Function */
  for (l = 0; l < 8; l++) {
    i = (int64_T)a0[l] * x1_idx_0;
    if ((i & 2199023255552L) != 0L) {
      i |= -2199023255552L;
    } else {
      i &= 2199023255551L;
    }
    i += (int64_T)a0[l + 8] * x1_idx_1;
    if ((i & 2199023255552L) != 0L) {
      i |= -2199023255552L;
    } else {
      i &= 2199023255551L;
    }
    i += (int64_T)a0[l + 16] * x1_idx_2;
    if ((i & 2199023255552L) != 0L) {
      i |= -2199023255552L;
    } else {
      i &= 2199023255551L;
    }
    i += iv1[l];
    if ((i & 4398046511104L) != 0L) {
      i |= -4398046511104L;
    } else {
      i &= 4398046511103L;
    }
    if (0L < i) {
      varargin_1[l] = i;
    } else {
      varargin_1[l] = 0L;
    }
  }
  for (x1_idx_2 = 0; x1_idx_2 < 8; x1_idx_2++) {
    a1[x1_idx_2] =
        ((uint32_T)(varargin_1[x1_idx_2] >> 19) & 1048575U) << 1 & 1048575U;
  }
  /*  Layer 2 */
  /*  Linear Positive Transfer Function */
  for (l = 0; l < 8; l++) {
    i = 0L;
    for (x1_idx_2 = 0; x1_idx_2 < 8; x1_idx_2++) {
      i += (int64_T)b_a0[l + (x1_idx_2 << 3)] * a1[x1_idx_2];
      if ((i & 4398046511104L) != 0L) {
        i |= -4398046511104L;
      } else {
        i &= 4398046511103L;
      }
    }
    i += iv[l];
    if ((i & 8796093022208L) != 0L) {
      i |= -8796093022208L;
    } else {
      i &= 8796093022207L;
    }
    if (0L < i) {
      varargin_1[l] = i;
    } else {
      varargin_1[l] = 0L;
    }
  }
  for (x1_idx_2 = 0; x1_idx_2 < 8; x1_idx_2++) {
    a1[x1_idx_2] =
        ((uint32_T)(varargin_1[x1_idx_2] >> 19) & 1048575U) << 1 & 1048575U;
  }
  /*  Layer 3 */
  /*  Linear Positive Transfer Function */
  for (l = 0; l < 8; l++) {
    i = 0L;
    for (x1_idx_2 = 0; x1_idx_2 < 8; x1_idx_2++) {
      i += (int64_T)c_a0[l + (x1_idx_2 << 3)] * a1[x1_idx_2];
      if ((i & 4398046511104L) != 0L) {
        i |= -4398046511104L;
      } else {
        i &= 4398046511103L;
      }
    }
    i += iv2[l];
    if ((i & 8796093022208L) != 0L) {
      i |= -8796093022208L;
    } else {
      i &= 8796093022207L;
    }
    if (0L >= i) {
      i = 0L;
    }
    a3[l] = (uint32_T)(i >> 19) & 1048575U;
  }
  /*  Layer 4 */
  for (l = 0; l < 2; l++) {
    i = 0L;
    for (x1_idx_2 = 0; x1_idx_2 < 8; x1_idx_2++) {
      i += (int64_T)d_a0[l + (x1_idx_2 << 1)] * a3[x1_idx_2];
      if ((i & 4398046511104L) != 0L) {
        i |= -4398046511104L;
      } else {
        i &= 4398046511103L;
      }
    }
    i += iv3[l];
    if ((i & 8796093022208L) != 0L) {
      i |= -8796093022208L;
    } else {
      i &= 8796093022207L;
    }
    x1_idx_2 = (int32_T)(i >> 17);
    if ((x1_idx_2 & 524288) != 0) {
      a4[l] = x1_idx_2 | -524288;
    } else {
      a4[l] = x1_idx_2 & 524287;
    }
  }
  /*  Output 1 */
  /*  Map Minimum and Maximum Output Reverse-Processing Function */
  if (((a4[0] - -262144) & 1048576) != 0) {
    l = (a4[0] - -262144) | -1048576;
  } else {
    l = (a4[0] - -262144) & 1048575;
  }
  x1_idx_2 = l >> 1;
  if (((a4[1] - -262144) & 1048576) != 0) {
    l = (a4[1] - -262144) | -1048576;
  } else {
    l = (a4[1] - -262144) & 1048575;
  }
  x1_idx_0 = l >> 1;
  if (((x1_idx_2 + -131072) & 1048576) != 0) {
    x1_idx_2 = (x1_idx_2 + -131072) | -1048576;
  } else {
    x1_idx_2 = (x1_idx_2 + -131072) & 1048575;
  }
  if (((x1_idx_0 + -131072) & 1048576) != 0) {
    x1_idx_0 = (x1_idx_0 + -131072) | -1048576;
  } else {
    x1_idx_0 = (x1_idx_0 + -131072) & 1048575;
  }
  if ((x1_idx_2 & 524288) != 0) {
    x1_idx_2 |= -524288;
  } else {
    x1_idx_2 &= 524287;
  }
  x1_idx_2 <<= 1;
  if ((x1_idx_2 & 524288) != 0) {
    a4[0] = x1_idx_2 | -524288;
  } else {
    a4[0] = x1_idx_2 & 524287;
  }
  if ((x1_idx_0 & 524288) != 0) {
    x1_idx_0 |= -524288;
  } else {
    x1_idx_0 &= 524287;
  }
  x1_idx_2 = x1_idx_0 << 1;
  if ((x1_idx_2 & 524288) != 0) {
    a4[1] = x1_idx_2 | -524288;
  } else {
    a4[1] = x1_idx_2 & 524287;
  }
  /*  Run FPGA-in-the-Loop */
  y = NULL;
  b_y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)emlrtMxGetData(m) = b_x1_1;
  emlrtAssign(&b_y, m);
  emlrtAssign(&y, emlrtCreateFIR2013b(&st, eml_mx, b_eml_mx,
                                      (const char_T *)"simulinkarray", b_y,
                                      true, false));
  c_y = NULL;
  d_y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)emlrtMxGetData(m) = b_x1_2;
  emlrtAssign(&d_y, m);
  emlrtAssign(&c_y, emlrtCreateFIR2013b(&st, eml_mx, b_eml_mx,
                                        (const char_T *)"simulinkarray", d_y,
                                        true, false));
  e_y = NULL;
  f_y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)emlrtMxGetData(m) = b_x1_3;
  emlrtAssign(&f_y, m);
  emlrtAssign(&e_y, emlrtCreateFIR2013b(&st, eml_mx, b_eml_mx,
                                        (const char_T *)"simulinkarray", f_y,
                                        true, false));
  b_st.site = &n_emlrtRSI;
  c_plasma_nn_wrapper_fixpt_sysob(&b_st, y, c_y, e_y, &b_emlrtMCI, &b_y1_1,
                                  &b_y1_2);
  /*  Verify the FPGA-in-the-Loop output */
  g_y = NULL;
  h_y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)emlrtMxGetData(m) = a4[0];
  emlrtAssign(&h_y, m);
  emlrtAssign(&g_y, emlrtCreateFIR2013b(&st, eml_mx, b_eml_mx,
                                        (const char_T *)"simulinkarray", h_y,
                                        true, false));
  i_y = NULL;
  m = emlrtCreateCharArray(2, &iv4[0]);
  emlrtInitCharArrayR2013a(&st, 4, m, &u[0]);
  emlrtAssign(&i_y, m);
  b_st.site = &p_emlrtRSI;
  hdlverifier_assert(&b_st, emlrtAlias(b_y1_1), g_y, i_y, &c_emlrtMCI);
  j_y = NULL;
  k_y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)emlrtMxGetData(m) = a4[1];
  emlrtAssign(&k_y, m);
  emlrtAssign(&j_y, emlrtCreateFIR2013b(&st, eml_mx, b_eml_mx,
                                        (const char_T *)"simulinkarray", k_y,
                                        true, false));
  l_y = NULL;
  m = emlrtCreateCharArray(2, &iv5[0]);
  emlrtInitCharArrayR2013a(&st, 4, m, &b_u[0]);
  emlrtAssign(&l_y, m);
  b_st.site = &o_emlrtRSI;
  hdlverifier_assert(&b_st, emlrtAlias(b_y1_2), j_y, l_y, &d_emlrtMCI);
  emlrtDestroyArray(&b_y1_1);
  emlrtDestroyArray(&b_y1_2);
  *y1_1 = (real_T)a4[0] * 3.814697265625E-6;
  *y1_2 = (real_T)a4[1] * 3.814697265625E-6;
}

/* End of code generation (plasma_nn_wrapper_wrapper_fixpt_fil.c) */
