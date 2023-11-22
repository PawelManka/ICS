/*
 * rpdriver_with_nn_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "rpdriver_with_nn".
 *
 * Model version              : 1.349
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Wed Nov 22 10:20:40 2023
 *
 * Target selection: rtcon_rpend_usb2.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rpdriver_with_nn.h"
#include "rpdriver_with_nn_private.h"

/* Block parameters (default storage) */
P_rpdriver_with_nn_T rpdriver_with_nn_P = {
  /* Mask Parameter: mapminmax_xmax
   * Referenced by: '<S22>/range y // range x'
   */
  { 0.68094001404114135, 0.68094001404114135 },

  /* Mask Parameter: mapminmax_reverse_xmax
   * Referenced by: '<S23>/Divide by range y'
   */
  0.68094001404114135,

  /* Mask Parameter: mapminmax_xmax_o
   * Referenced by: '<S37>/range y // range x'
   */
  { 2.3395440491283188, 2.3395440491283188 },

  /* Mask Parameter: mapminmax_reverse_xmax_g
   * Referenced by: '<S38>/Divide by range y'
   */
  2.3395440491283188,

  /* Mask Parameter: mapminmax_xmin
   * Referenced by:
   *   '<S22>/Subtract min x'
   *   '<S22>/range y // range x'
   */
  { -0.53362236311735733, -0.53362236311735733 },

  /* Mask Parameter: mapminmax_reverse_xmin
   * Referenced by:
   *   '<S23>/Add min x'
   *   '<S23>/Divide by range y'
   */
  -0.53362236311735733,

  /* Mask Parameter: mapminmax_xmin_f
   * Referenced by:
   *   '<S37>/Subtract min x'
   *   '<S37>/range y // range x'
   */
  { -2.0633980548777759, -2.0633980548777759 },

  /* Mask Parameter: mapminmax_reverse_xmin_e
   * Referenced by:
   *   '<S38>/Add min x'
   *   '<S38>/Divide by range y'
   */
  -2.0633980548777759,

  /* Mask Parameter: mapminmax_ymax
   * Referenced by: '<S22>/range y // range x'
   */
  1.0,

  /* Mask Parameter: mapminmax_reverse_ymax
   * Referenced by: '<S23>/Divide by range y'
   */
  1.0,

  /* Mask Parameter: mapminmax_ymax_h
   * Referenced by: '<S37>/range y // range x'
   */
  1.0,

  /* Mask Parameter: mapminmax_reverse_ymax_j
   * Referenced by: '<S38>/Divide by range y'
   */
  1.0,

  /* Mask Parameter: mapminmax_ymin
   * Referenced by:
   *   '<S22>/Add min y'
   *   '<S22>/range y // range x'
   */
  -1.0,

  /* Mask Parameter: mapminmax_reverse_ymin
   * Referenced by:
   *   '<S23>/Subtract min y'
   *   '<S23>/Divide by range y'
   */
  -1.0,

  /* Mask Parameter: mapminmax_ymin_n
   * Referenced by:
   *   '<S37>/Add min y'
   *   '<S37>/range y // range x'
   */
  -1.0,

  /* Mask Parameter: mapminmax_reverse_ymin_j
   * Referenced by:
   *   '<S38>/Subtract min y'
   *   '<S38>/Divide by range y'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<Root>/DC_Ctrl2'
   */
  0.0,

  /* Expression: 0.9
   * Referenced by: '<Root>/Saturation'
   */
  0.9,

  /* Expression: -0.9
   * Referenced by: '<Root>/Saturation'
   */
  -0.9,

  /* Expression: 1
   * Referenced by: '<Root>/Gain1'
   */
  1.0,

  /* Expression: 0.1
   * Referenced by: '<Root>/DC_Ctrl1'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<Root>/Normal'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Reset'
   */
  1.0,

  /* Computed Parameter: SFunction_P1_Size
   * Referenced by: '<S1>/S-Function'
   */
  { 1.0, 1.0 },

  /* Expression: 1
   * Referenced by: '<S1>/S-Function'
   */
  1.0,

  /* Computed Parameter: SFunction_P2_Size
   * Referenced by: '<S1>/S-Function'
   */
  { 1.0, 1.0 },

  /* Expression: 0.01
   * Referenced by: '<S1>/S-Function'
   */
  0.01,

  /* Expression: 2*pi/20000
   * Referenced by: '<S1>/Pendulum Convert to rad'
   */
  0.00031415926535897931,

  /* Expression: pi
   * Referenced by: '<S5>/Constant'
   */
  3.1415926535897931,

  /* Expression: 0
   * Referenced by: '<S1>/Memory2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/rad2rad//s'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Memory'
   */
  0.0,

  /* Expression: 1/20000000
   * Referenced by: '<S1>/Gain1'
   */
  5.0E-8,

  /* Expression: 2*pi/4096
   * Referenced by: '<S1>/DC Convert to rad'
   */
  0.0015339807878856412,

  /* Expression: 0
   * Referenced by: '<S1>/Memory1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/rad2RPM'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S1>/DC Convert to [A]1'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Gain3'
   */
  1.0,

  /* Expression: [1.9534821513318345598264613727224059402942657470703125;0.2772406769403119586314687694539315998554229736328125;-0.0161124272243524553627214146445112419314682483673095703125;1.182343962777292478705248868209309875965118408203125]
   * Referenced by: '<S19>/IW{2,1}(1,:)''
   */
  { 1.9534821513318346, 0.27724067694031196, -0.016112427224352455,
    1.1823439627772925 },

  /* Expression: [-0.466303739642262293774166437287931330502033233642578125;0.96594306525236850458071558023220859467983245849609375]
   * Referenced by: '<S12>/IW{1,1}(1,:)''
   */
  { -0.46630373964226229, 0.9659430652523685 },

  /* Expression: 0
   * Referenced by: '<Root>/Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Memory1'
   */
  0.0,

  /* Expression: [-1.55268314583509603465927284560166299343109130859375;2.943114096559206860348467671428807079792022705078125]
   * Referenced by: '<S12>/IW{1,1}(2,:)''
   */
  { -1.552683145835096, 2.9431140965592069 },

  /* Expression: [-1.780215091870313681710058517637662589550018310546875;-0.659402923602290247373503007111139595508575439453125]
   * Referenced by: '<S12>/IW{1,1}(3,:)''
   */
  { -1.7802150918703137, -0.65940292360229025 },

  /* Expression: [2.88201231265911861356698864256031811237335205078125;-0.683979171490019410839522606693208217620849609375]
   * Referenced by: '<S12>/IW{1,1}(4,:)''
   */
  { 2.8820123126591186, -0.68397917149001941 },

  /* Expression: [0.5067900146138837325082704410306178033351898193359375;-0.86413407894146565535464787899400107562541961669921875;-0.39424585760358177299877979748998768627643585205078125;-3.8565998867119173354467420722357928752899169921875]
   * Referenced by: '<S7>/b{1}'
   */
  { 0.50679001461388373, -0.86413407894146566, -0.39424585760358177,
    -3.8565998867119173 },

  /* Expression: -2
   * Referenced by: '<S13>/Gain'
   */
  -2.0,

  /* Expression: 1
   * Referenced by: '<S13>/one'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S13>/Gain1'
   */
  2.0,

  /* Expression: 1
   * Referenced by: '<S13>/one1'
   */
  1.0,

  /* Expression: 0.455809173642511555879508478028583340346813201904296875
   * Referenced by: '<S8>/b{2}'
   */
  0.45580917364251156,

  /* Expression: [-1.84914557638342191836500205681659281253814697265625;-4.173814275745581170440345886163413524627685546875]
   * Referenced by: '<S34>/IW{2,1}(1,:)''
   */
  { -1.8491455763834219, -4.1738142757455812 },

  /* Expression: [0.317501847104528611698270879060146398842334747314453125;-0.63437724697761022074615766541683115065097808837890625]
   * Referenced by: '<S29>/IW{1,1}(1,:)''
   */
  { 0.31750184710452861, -0.63437724697761022 },

  /* Expression: [0.2100822536402155715773432120840880088508129119873046875;-0.420616928478684315440006002972950227558612823486328125]
   * Referenced by: '<S29>/IW{1,1}(2,:)''
   */
  { 0.21008225364021557, -0.42061692847868432 },

  /* Expression: [0.83689402231300424883642108397907577455043792724609375;-0.50502772206030532853304748641676269471645355224609375]
   * Referenced by: '<S24>/b{1}'
   */
  { 0.83689402231300425, -0.50502772206030533 },

  /* Expression: -2
   * Referenced by: '<S30>/Gain'
   */
  -2.0,

  /* Expression: 1
   * Referenced by: '<S30>/one'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S30>/Gain1'
   */
  2.0,

  /* Expression: 1
   * Referenced by: '<S30>/one1'
   */
  1.0,

  /* Expression: -0.6801722526561981840842463498120196163654327392578125
   * Referenced by: '<S25>/b{2}'
   */
  -0.68017225265619818,

  /* Expression: [1;1]
   * Referenced by: '<S1>/Gain'
   */
  { 1.0, 1.0 },

  /* Expression: 1
   * Referenced by: '<S1>/Gain2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Prescaler'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/Saturation'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S1>/Saturation'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S1>/ThermFlag'
   */
  0.0,

  /* Computed Parameter: ResetEncoders2_CurrentSetting
   * Referenced by: '<Root>/Reset Encoders2'
   */
  0U,

  /* Computed Parameter: ResetEncoders1_CurrentSetting
   * Referenced by: '<Root>/Reset Encoders1'
   */
  0U,

  /* Computed Parameter: ResetEncoders_CurrentSetting
   * Referenced by: '<Root>/Reset Encoders'
   */
  0U
};
