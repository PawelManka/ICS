/*
 * rpdriver_with_nn.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "rpdriver_with_nn".
 *
 * Model version              : 1.353
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Wed Dec  6 11:10:19 2023
 *
 * Target selection: rtcon_rpend_usb2.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_rpdriver_with_nn_h_
#define RTW_HEADER_rpdriver_with_nn_h_
#include <stddef.h>
#include <string.h>
#include <math.h>
#include <float.h>
#ifndef rpdriver_with_nn_COMMON_INCLUDES_
# define rpdriver_with_nn_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif                                 /* rpdriver_with_nn_COMMON_INCLUDES_ */

#include "rpdriver_with_nn_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T SFunction_o1;                 /* '<S2>/S-Function' */
  real_T SFunction_o2;                 /* '<S2>/S-Function' */
  real_T SFunction_o3;                 /* '<S2>/S-Function' */
  real_T SFunction_o4;                 /* '<S2>/S-Function' */
  real_T SFunction_o5;                 /* '<S2>/S-Function' */
  real_T SFunction_o6;                 /* '<S2>/S-Function' */
  real_T SFunction_o7[2];              /* '<S2>/S-Function' */
  real_T PendulumAnglerad;             /* '<S2>/Pendulum Convert to rad' */
  real_T PendPos_ZeroDown;             /* '<S6>/Trigonometric Function' */
  real_T PendPos_ZeroUp;               /* '<S6>/Trigonometric Function3' */
  real_T Periodms;                     /* '<S2>/Gain1' */
  real_T PendulumVelrads;              /* '<S2>/Divide1' */
  real_T DCAnglerad;                   /* '<S2>/DC Convert to rad' */
  real_T DCVelrads;                    /* '<S2>/Divide' */
  real_T DCConverttoA1;                /* '<S2>/DC Convert to [A]1' */
  real_T Control;                      /* '<Root>/Gain3' */
  real_T Addminx;                      /* '<S23>/Add min x' */
  real_T Addminx_f;                    /* '<S38>/Add min x' */
  real_T Derivative;                   /* '<Root>/Derivative' */
  real_T Gain[2];                      /* '<S2>/Gain' */
  real_T Prescaler;                    /* '<S2>/Prescaler' */
  real_T Saturation;                   /* '<S2>/Saturation' */
  real_T ThermFlag;                    /* '<S2>/ThermFlag' */
  real_T Beta_output;                  /* '<Root>/MATLAB Function' */
} B_rpdriver_with_nn_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory2_PreviousInput;        /* '<S2>/Memory2' */
  real_T Memory_PreviousInput;         /* '<S2>/Memory' */
  real_T Memory1_PreviousInput;        /* '<S2>/Memory1' */
  real_T Memory_PreviousInput_i;       /* '<Root>/Memory' */
  real_T Memory1_PreviousInput_l;      /* '<Root>/Memory1' */
  real_T TimeStampA;                   /* '<Root>/Derivative' */
  real_T LastUAtTimeA;                 /* '<Root>/Derivative' */
  real_T TimeStampB;                   /* '<Root>/Derivative' */
  real_T LastUAtTimeB;                 /* '<Root>/Derivative' */
  struct {
    void *LoggedData[8];
  } PlotState_PWORK;                   /* '<Root>/PlotState' */

  struct {
    void *LoggedData[3];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData[5];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */
} DW_rpdriver_with_nn_T;

/* Parameters (default storage) */
struct P_rpdriver_with_nn_T_ {
  real_T mapminmax_xmax[2];            /* Mask Parameter: mapminmax_xmax
                                        * Referenced by: '<S22>/range y // range x'
                                        */
  real_T mapminmax_reverse_xmax;       /* Mask Parameter: mapminmax_reverse_xmax
                                        * Referenced by: '<S23>/Divide by range y'
                                        */
  real_T mapminmax_xmax_o[2];          /* Mask Parameter: mapminmax_xmax_o
                                        * Referenced by: '<S37>/range y // range x'
                                        */
  real_T mapminmax_reverse_xmax_g;     /* Mask Parameter: mapminmax_reverse_xmax_g
                                        * Referenced by: '<S38>/Divide by range y'
                                        */
  real_T mapminmax_xmin[2];            /* Mask Parameter: mapminmax_xmin
                                        * Referenced by:
                                        *   '<S22>/Subtract min x'
                                        *   '<S22>/range y // range x'
                                        */
  real_T mapminmax_reverse_xmin;       /* Mask Parameter: mapminmax_reverse_xmin
                                        * Referenced by:
                                        *   '<S23>/Add min x'
                                        *   '<S23>/Divide by range y'
                                        */
  real_T mapminmax_xmin_f[2];          /* Mask Parameter: mapminmax_xmin_f
                                        * Referenced by:
                                        *   '<S37>/Subtract min x'
                                        *   '<S37>/range y // range x'
                                        */
  real_T mapminmax_reverse_xmin_e;     /* Mask Parameter: mapminmax_reverse_xmin_e
                                        * Referenced by:
                                        *   '<S38>/Add min x'
                                        *   '<S38>/Divide by range y'
                                        */
  real_T mapminmax_ymax;               /* Mask Parameter: mapminmax_ymax
                                        * Referenced by: '<S22>/range y // range x'
                                        */
  real_T mapminmax_reverse_ymax;       /* Mask Parameter: mapminmax_reverse_ymax
                                        * Referenced by: '<S23>/Divide by range y'
                                        */
  real_T mapminmax_ymax_h;             /* Mask Parameter: mapminmax_ymax_h
                                        * Referenced by: '<S37>/range y // range x'
                                        */
  real_T mapminmax_reverse_ymax_j;     /* Mask Parameter: mapminmax_reverse_ymax_j
                                        * Referenced by: '<S38>/Divide by range y'
                                        */
  real_T mapminmax_ymin;               /* Mask Parameter: mapminmax_ymin
                                        * Referenced by:
                                        *   '<S22>/Add min y'
                                        *   '<S22>/range y // range x'
                                        */
  real_T mapminmax_reverse_ymin;       /* Mask Parameter: mapminmax_reverse_ymin
                                        * Referenced by:
                                        *   '<S23>/Subtract min y'
                                        *   '<S23>/Divide by range y'
                                        */
  real_T mapminmax_ymin_n;             /* Mask Parameter: mapminmax_ymin_n
                                        * Referenced by:
                                        *   '<S37>/Add min y'
                                        *   '<S37>/range y // range x'
                                        */
  real_T mapminmax_reverse_ymin_j;     /* Mask Parameter: mapminmax_reverse_ymin_j
                                        * Referenced by:
                                        *   '<S38>/Subtract min y'
                                        *   '<S38>/Divide by range y'
                                        */
  real_T DC_Ctrl2_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/DC_Ctrl2'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 0.9
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -0.9
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T DC_Ctrl1_Value;               /* Expression: 0.1
                                        * Referenced by: '<Root>/DC_Ctrl1'
                                        */
  real_T Normal_Value;                 /* Expression: 0
                                        * Referenced by: '<Root>/Normal'
                                        */
  real_T Reset_Value;                  /* Expression: 1
                                        * Referenced by: '<Root>/Reset'
                                        */
  real_T SFunction_P1_Size[2];         /* Computed Parameter: SFunction_P1_Size
                                        * Referenced by: '<S2>/S-Function'
                                        */
  real_T SFunction_P1;                 /* Expression: 1
                                        * Referenced by: '<S2>/S-Function'
                                        */
  real_T SFunction_P2_Size[2];         /* Computed Parameter: SFunction_P2_Size
                                        * Referenced by: '<S2>/S-Function'
                                        */
  real_T SFunction_P2;                 /* Expression: 0.01
                                        * Referenced by: '<S2>/S-Function'
                                        */
  real_T PendulumConverttorad_Gain;    /* Expression: 2*pi/20000
                                        * Referenced by: '<S2>/Pendulum Convert to rad'
                                        */
  real_T Constant_Value;               /* Expression: pi
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Memory2_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S2>/Memory2'
                                        */
  real_T rad2rads_Gain;                /* Expression: 1
                                        * Referenced by: '<S2>/rad2rad//s'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S2>/Memory'
                                        */
  real_T Gain1_Gain_h;                 /* Expression: 1/20000000
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T DCConverttorad_Gain;          /* Expression: 2*pi/4096
                                        * Referenced by: '<S2>/DC Convert to rad'
                                        */
  real_T Memory1_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S2>/Memory1'
                                        */
  real_T rad2RPM_Gain;                 /* Expression: 1
                                        * Referenced by: '<S2>/rad2RPM'
                                        */
  real_T DCConverttoA1_Gain;           /* Expression: 1
                                        * Referenced by: '<S2>/DC Convert to [A]1'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T IW211_Value[4];               /* Expression: [1.9534821513318345598264613727224059402942657470703125;0.2772406769403119586314687694539315998554229736328125;-0.0161124272243524553627214146445112419314682483673095703125;1.182343962777292478705248868209309875965118408203125]
                                        * Referenced by: '<S19>/IW{2,1}(1,:)''
                                        */
  real_T IW111_Value[2];               /* Expression: [-0.466303739642262293774166437287931330502033233642578125;0.96594306525236850458071558023220859467983245849609375]
                                        * Referenced by: '<S12>/IW{1,1}(1,:)''
                                        */
  real_T Memory_InitialCondition_j;    /* Expression: 0
                                        * Referenced by: '<Root>/Memory'
                                        */
  real_T Memory1_InitialCondition_f;   /* Expression: 0
                                        * Referenced by: '<Root>/Memory1'
                                        */
  real_T IW112_Value[2];               /* Expression: [-1.55268314583509603465927284560166299343109130859375;2.943114096559206860348467671428807079792022705078125]
                                        * Referenced by: '<S12>/IW{1,1}(2,:)''
                                        */
  real_T IW113_Value[2];               /* Expression: [-1.780215091870313681710058517637662589550018310546875;-0.659402923602290247373503007111139595508575439453125]
                                        * Referenced by: '<S12>/IW{1,1}(3,:)''
                                        */
  real_T IW114_Value[2];               /* Expression: [2.88201231265911861356698864256031811237335205078125;-0.683979171490019410839522606693208217620849609375]
                                        * Referenced by: '<S12>/IW{1,1}(4,:)''
                                        */
  real_T b1_Value[4];                  /* Expression: [0.5067900146138837325082704410306178033351898193359375;-0.86413407894146565535464787899400107562541961669921875;-0.39424585760358177299877979748998768627643585205078125;-3.8565998867119173354467420722357928752899169921875]
                                        * Referenced by: '<S7>/b{1}'
                                        */
  real_T Gain_Gain;                    /* Expression: -2
                                        * Referenced by: '<S13>/Gain'
                                        */
  real_T one_Value;                    /* Expression: 1
                                        * Referenced by: '<S13>/one'
                                        */
  real_T Gain1_Gain_g;                 /* Expression: 2
                                        * Referenced by: '<S13>/Gain1'
                                        */
  real_T one1_Value;                   /* Expression: 1
                                        * Referenced by: '<S13>/one1'
                                        */
  real_T b2_Value;                     /* Expression: 0.455809173642511555879508478028583340346813201904296875
                                        * Referenced by: '<S8>/b{2}'
                                        */
  real_T IW211_Value_j[2];             /* Expression: [-1.84914557638342191836500205681659281253814697265625;-4.173814275745581170440345886163413524627685546875]
                                        * Referenced by: '<S34>/IW{2,1}(1,:)''
                                        */
  real_T IW111_Value_g[2];             /* Expression: [0.317501847104528611698270879060146398842334747314453125;-0.63437724697761022074615766541683115065097808837890625]
                                        * Referenced by: '<S29>/IW{1,1}(1,:)''
                                        */
  real_T IW112_Value_j[2];             /* Expression: [0.2100822536402155715773432120840880088508129119873046875;-0.420616928478684315440006002972950227558612823486328125]
                                        * Referenced by: '<S29>/IW{1,1}(2,:)''
                                        */
  real_T b1_Value_n[2];                /* Expression: [0.83689402231300424883642108397907577455043792724609375;-0.50502772206030532853304748641676269471645355224609375]
                                        * Referenced by: '<S24>/b{1}'
                                        */
  real_T Gain_Gain_i;                  /* Expression: -2
                                        * Referenced by: '<S30>/Gain'
                                        */
  real_T one_Value_g;                  /* Expression: 1
                                        * Referenced by: '<S30>/one'
                                        */
  real_T Gain1_Gain_hd;                /* Expression: 2
                                        * Referenced by: '<S30>/Gain1'
                                        */
  real_T one1_Value_m;                 /* Expression: 1
                                        * Referenced by: '<S30>/one1'
                                        */
  real_T b2_Value_m;                   /* Expression: -0.6801722526561981840842463498120196163654327392578125
                                        * Referenced by: '<S25>/b{2}'
                                        */
  real_T Gain_Gain_d[2];               /* Expression: [1;1]
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1
                                        * Referenced by: '<S2>/Gain2'
                                        */
  real_T Prescaler_Value;              /* Expression: 0
                                        * Referenced by: '<S2>/Prescaler'
                                        */
  real_T Saturation_UpperSat_h;        /* Expression: 1
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Saturation_LowerSat_f;        /* Expression: -1
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T ThermFlag_Value;              /* Expression: 0
                                        * Referenced by: '<S2>/ThermFlag'
                                        */
  uint8_T ResetEncoders2_CurrentSetting;/* Computed Parameter: ResetEncoders2_CurrentSetting
                                         * Referenced by: '<Root>/Reset Encoders2'
                                         */
  uint8_T ResetEncoders1_CurrentSetting;/* Computed Parameter: ResetEncoders1_CurrentSetting
                                         * Referenced by: '<Root>/Reset Encoders1'
                                         */
  uint8_T ResetEncoders_CurrentSetting;/* Computed Parameter: ResetEncoders_CurrentSetting
                                        * Referenced by: '<Root>/Reset Encoders'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_rpdriver_with_nn_T {
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[2];
    SimStruct childSFunctions[1];
    SimStruct *childSFunctionPtrs[1];
    struct _ssBlkInfo2 blkInfo2[1];
    struct _ssSFcnModelMethods2 methods2[1];
    struct _ssSFcnModelMethods3 methods3[1];
    struct _ssSFcnModelMethods4 methods4[1];
    struct _ssStatesInfo2 statesInfo2[1];
    ssPeriodicStatesInfo periodicStatesInfo[1];
    struct _ssPortInfo2 inputOutputPortInfo2[1];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[4];
      struct _ssInPortUnit inputPortUnits[4];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[4];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[2];
      real_T const *UPtrs2[1];
      real_T const *UPtrs3[1];
      struct _ssPortOutputs outputPortInfo[7];
      struct _ssOutPortUnit outputPortUnits[7];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[7];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn0;
  } NonInlinedSFcns;

  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_rpdriver_with_nn_T rpdriver_with_nn_P;

/* Block signals (default storage) */
extern B_rpdriver_with_nn_T rpdriver_with_nn_B;

/* Block states (default storage) */
extern DW_rpdriver_with_nn_T rpdriver_with_nn_DW;

/* Model entry point functions */
extern void rpdriver_with_nn_initialize(void);
extern void rpdriver_with_nn_step(void);
extern void rpdriver_with_nn_terminate(void);

/* Real-time Model object */
extern RT_MODEL_rpdriver_with_nn_T *const rpdriver_with_nn_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'rpdriver_with_nn'
 * '<S1>'   : 'rpdriver_with_nn/MATLAB Function'
 * '<S2>'   : 'rpdriver_with_nn/RP Driver'
 * '<S3>'   : 'rpdriver_with_nn/Stair Generator'
 * '<S4>'   : 'rpdriver_with_nn/dane_1_HL_2  '
 * '<S5>'   : 'rpdriver_with_nn/dane_2_HL_2 '
 * '<S6>'   : 'rpdriver_with_nn/RP Driver/Alfa Normalization'
 * '<S7>'   : 'rpdriver_with_nn/dane_1_HL_2  /Layer 1'
 * '<S8>'   : 'rpdriver_with_nn/dane_1_HL_2  /Layer 2'
 * '<S9>'   : 'rpdriver_with_nn/dane_1_HL_2  /Process Input 1'
 * '<S10>'  : 'rpdriver_with_nn/dane_1_HL_2  /Process Output 1'
 * '<S11>'  : 'rpdriver_with_nn/dane_1_HL_2  /Layer 1/Delays 1'
 * '<S12>'  : 'rpdriver_with_nn/dane_1_HL_2  /Layer 1/IW{1,1}'
 * '<S13>'  : 'rpdriver_with_nn/dane_1_HL_2  /Layer 1/tansig'
 * '<S14>'  : 'rpdriver_with_nn/dane_1_HL_2  /Layer 1/IW{1,1}/dotprod1'
 * '<S15>'  : 'rpdriver_with_nn/dane_1_HL_2  /Layer 1/IW{1,1}/dotprod2'
 * '<S16>'  : 'rpdriver_with_nn/dane_1_HL_2  /Layer 1/IW{1,1}/dotprod3'
 * '<S17>'  : 'rpdriver_with_nn/dane_1_HL_2  /Layer 1/IW{1,1}/dotprod4'
 * '<S18>'  : 'rpdriver_with_nn/dane_1_HL_2  /Layer 2/Delays 1'
 * '<S19>'  : 'rpdriver_with_nn/dane_1_HL_2  /Layer 2/LW{2,1}'
 * '<S20>'  : 'rpdriver_with_nn/dane_1_HL_2  /Layer 2/purelin'
 * '<S21>'  : 'rpdriver_with_nn/dane_1_HL_2  /Layer 2/LW{2,1}/dotprod1'
 * '<S22>'  : 'rpdriver_with_nn/dane_1_HL_2  /Process Input 1/mapminmax'
 * '<S23>'  : 'rpdriver_with_nn/dane_1_HL_2  /Process Output 1/mapminmax_reverse'
 * '<S24>'  : 'rpdriver_with_nn/dane_2_HL_2 /Layer 1'
 * '<S25>'  : 'rpdriver_with_nn/dane_2_HL_2 /Layer 2'
 * '<S26>'  : 'rpdriver_with_nn/dane_2_HL_2 /Process Input 1'
 * '<S27>'  : 'rpdriver_with_nn/dane_2_HL_2 /Process Output 1'
 * '<S28>'  : 'rpdriver_with_nn/dane_2_HL_2 /Layer 1/Delays 1'
 * '<S29>'  : 'rpdriver_with_nn/dane_2_HL_2 /Layer 1/IW{1,1}'
 * '<S30>'  : 'rpdriver_with_nn/dane_2_HL_2 /Layer 1/tansig'
 * '<S31>'  : 'rpdriver_with_nn/dane_2_HL_2 /Layer 1/IW{1,1}/dotprod1'
 * '<S32>'  : 'rpdriver_with_nn/dane_2_HL_2 /Layer 1/IW{1,1}/dotprod2'
 * '<S33>'  : 'rpdriver_with_nn/dane_2_HL_2 /Layer 2/Delays 1'
 * '<S34>'  : 'rpdriver_with_nn/dane_2_HL_2 /Layer 2/LW{2,1}'
 * '<S35>'  : 'rpdriver_with_nn/dane_2_HL_2 /Layer 2/purelin'
 * '<S36>'  : 'rpdriver_with_nn/dane_2_HL_2 /Layer 2/LW{2,1}/dotprod1'
 * '<S37>'  : 'rpdriver_with_nn/dane_2_HL_2 /Process Input 1/mapminmax'
 * '<S38>'  : 'rpdriver_with_nn/dane_2_HL_2 /Process Output 1/mapminmax_reverse'
 */
#endif                                 /* RTW_HEADER_rpdriver_with_nn_h_ */
