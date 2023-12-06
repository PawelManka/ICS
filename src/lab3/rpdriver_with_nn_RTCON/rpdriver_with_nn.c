/*
 * rpdriver_with_nn.c
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

#include "rpdriver_with_nn.h"
#include "rpdriver_with_nn_private.h"
#include "rpdriver_with_nn_dt.h"

/* Block signals (default storage) */
B_rpdriver_with_nn_T rpdriver_with_nn_B;

/* Block states (default storage) */
DW_rpdriver_with_nn_T rpdriver_with_nn_DW;

/* Real-time model */
RT_MODEL_rpdriver_with_nn_T rpdriver_with_nn_M_;
RT_MODEL_rpdriver_with_nn_T *const rpdriver_with_nn_M = &rpdriver_with_nn_M_;
real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model step function */
void rpdriver_with_nn_step(void)
{
  /* local block i/o variables */
  real_T rtb_Memory;

  {
    real_T *lastU;
    real_T rtb_Memory1;
    real_T rtb_Sum1_d_idx_0;

    /* S-Function (rtdacusb2_rpend_dd): '<S2>/S-Function' */

    /* Level2 S-Function Block: '<S2>/S-Function' (rtdacusb2_rpend_dd) */
    {
      SimStruct *rts = rpdriver_with_nn_M->childSfunctions[0];
      sfcnOutputs(rts,1);
    }

    /* Gain: '<S2>/Pendulum Convert to rad' */
    rpdriver_with_nn_B.PendulumAnglerad =
      rpdriver_with_nn_P.PendulumConverttorad_Gain *
      rpdriver_with_nn_B.SFunction_o2;

    /* Trigonometry: '<S6>/Trigonometric Function' incorporates:
     *  Trigonometry: '<S6>/Trigonometric Function1'
     *  Trigonometry: '<S6>/Trigonometric Function2'
     */
    rpdriver_with_nn_B.PendPos_ZeroDown = rt_atan2d_snf(sin
      (rpdriver_with_nn_B.PendulumAnglerad), cos
      (rpdriver_with_nn_B.PendulumAnglerad));

    /* Sum: '<S6>/Add' incorporates:
     *  Constant: '<S6>/Constant'
     */
    rtb_Memory1 = rpdriver_with_nn_B.PendulumAnglerad +
      rpdriver_with_nn_P.Constant_Value;

    /* Trigonometry: '<S6>/Trigonometric Function3' incorporates:
     *  Trigonometry: '<S6>/Trigonometric Function4'
     *  Trigonometry: '<S6>/Trigonometric Function5'
     */
    rpdriver_with_nn_B.PendPos_ZeroUp = rt_atan2d_snf(sin(rtb_Memory1), cos
      (rtb_Memory1));

    /* Gain: '<S2>/Gain1' incorporates:
     *  Memory: '<S2>/Memory'
     *  Sum: '<S2>/Add'
     */
    rpdriver_with_nn_B.Periodms = (rpdriver_with_nn_B.SFunction_o6 -
      rpdriver_with_nn_DW.Memory_PreviousInput) *
      rpdriver_with_nn_P.Gain1_Gain_h;

    /* Product: '<S2>/Divide1' incorporates:
     *  Gain: '<S2>/rad2rad//s'
     *  Memory: '<S2>/Memory2'
     *  Sum: '<S2>/Add2'
     */
    rpdriver_with_nn_B.PendulumVelrads = (rpdriver_with_nn_B.PendulumAnglerad -
      rpdriver_with_nn_DW.Memory2_PreviousInput) *
      rpdriver_with_nn_P.rad2rads_Gain / rpdriver_with_nn_B.Periodms;

    /* Gain: '<S2>/DC Convert to rad' */
    rpdriver_with_nn_B.DCAnglerad = rpdriver_with_nn_P.DCConverttorad_Gain *
      rpdriver_with_nn_B.SFunction_o3;

    /* Product: '<S2>/Divide' incorporates:
     *  Gain: '<S2>/rad2RPM'
     *  Memory: '<S2>/Memory1'
     *  Sum: '<S2>/Add1'
     */
    rpdriver_with_nn_B.DCVelrads = (rpdriver_with_nn_B.DCAnglerad -
      rpdriver_with_nn_DW.Memory1_PreviousInput) *
      rpdriver_with_nn_P.rad2RPM_Gain / rpdriver_with_nn_B.Periodms;

    /* Gain: '<S2>/DC Convert to [A]1' */
    rpdriver_with_nn_B.DCConverttoA1 = rpdriver_with_nn_P.DCConverttoA1_Gain *
      rpdriver_with_nn_B.SFunction_o4;

    /* ManualSwitch: '<Root>/Reset Encoders1' incorporates:
     *  Constant: '<Root>/DC_Ctrl2'
     */
    if (rpdriver_with_nn_P.ResetEncoders1_CurrentSetting == 1) {
      /* ManualSwitch: '<Root>/Reset Encoders2' incorporates:
       *  Constant: '<Root>/DC_Ctrl1'
       *  Gain: '<Root>/Gain1'
       *  Saturate: '<Root>/Saturation'
       */
      if (rpdriver_with_nn_P.ResetEncoders2_CurrentSetting == 1) {
        rtb_Memory1 = rpdriver_with_nn_P.DC_Ctrl1_Value;
      } else {
        if (0.0 > rpdriver_with_nn_P.Saturation_UpperSat) {
          /* Saturate: '<Root>/Saturation' */
          rtb_Sum1_d_idx_0 = rpdriver_with_nn_P.Saturation_UpperSat;
        } else if (0.0 < rpdriver_with_nn_P.Saturation_LowerSat) {
          /* Saturate: '<Root>/Saturation' */
          rtb_Sum1_d_idx_0 = rpdriver_with_nn_P.Saturation_LowerSat;
        } else {
          /* Saturate: '<Root>/Saturation' */
          rtb_Sum1_d_idx_0 = 0.0;
        }

        rtb_Memory1 = rpdriver_with_nn_P.Gain1_Gain * rtb_Sum1_d_idx_0;
      }

      /* End of ManualSwitch: '<Root>/Reset Encoders2' */
    } else {
      rtb_Memory1 = rpdriver_with_nn_P.DC_Ctrl2_Value;
    }

    /* End of ManualSwitch: '<Root>/Reset Encoders1' */

    /* Gain: '<Root>/Gain3' */
    rpdriver_with_nn_B.Control = rpdriver_with_nn_P.Gain3_Gain * rtb_Memory1;

    /* Scope: '<Root>/PlotState' */
    {
      StructLogVar *svar = (StructLogVar *)
        rpdriver_with_nn_DW.PlotState_PWORK.LoggedData[0];
      LogVar *var = svar->signals.values;

      /* time */
      {
        double locTime = rpdriver_with_nn_M->Timing.t[1];
        ;
        rt_UpdateLogVar((LogVar *)svar->time, &locTime, 0);
      }

      /* signals */
      {
        real_T up0[1];
        up0[0] = rpdriver_with_nn_B.PendulumAnglerad;
        rt_UpdateLogVar((LogVar *)var, up0, 0);
        var = var->next;
      }

      {
        real_T up1[1];
        up1[0] = rpdriver_with_nn_B.PendPos_ZeroDown;
        rt_UpdateLogVar((LogVar *)var, up1, 0);
        var = var->next;
      }

      {
        real_T up2[1];
        up2[0] = rpdriver_with_nn_B.PendPos_ZeroUp;
        rt_UpdateLogVar((LogVar *)var, up2, 0);
        var = var->next;
      }

      {
        real_T up3[1];
        up3[0] = rpdriver_with_nn_B.PendulumVelrads;
        rt_UpdateLogVar((LogVar *)var, up3, 0);
        var = var->next;
      }

      {
        real_T up4[1];
        up4[0] = rpdriver_with_nn_B.DCAnglerad;
        rt_UpdateLogVar((LogVar *)var, up4, 0);
        var = var->next;
      }

      {
        real_T up5[1];
        up5[0] = rpdriver_with_nn_B.DCVelrads;
        rt_UpdateLogVar((LogVar *)var, up5, 0);
        var = var->next;
      }

      {
        real_T up6[1];
        up6[0] = rpdriver_with_nn_B.DCConverttoA1;
        rt_UpdateLogVar((LogVar *)var, up6, 0);
        var = var->next;
      }

      {
        real_T up7[1];
        up7[0] = rpdriver_with_nn_B.Control;
        rt_UpdateLogVar((LogVar *)var, up7, 0);
      }
    }

    /* Memory: '<Root>/Memory' */
    rtb_Memory = rpdriver_with_nn_DW.Memory_PreviousInput_i;

    /* Gain: '<S22>/range y // range x' */
    rtb_Memory1 = rpdriver_with_nn_P.mapminmax_ymax -
      rpdriver_with_nn_P.mapminmax_ymin;

    /* Bias: '<S22>/Add min y' incorporates:
     *  Bias: '<S22>/Subtract min x'
     *  Gain: '<S22>/range y // range x'
     *  Memory: '<Root>/Memory1'
     */
    rtb_Sum1_d_idx_0 = rtb_Memory1 / (rpdriver_with_nn_P.mapminmax_xmax[0] -
      rpdriver_with_nn_P.mapminmax_xmin[0]) * (rtb_Memory +
      -rpdriver_with_nn_P.mapminmax_xmin[0]) + rpdriver_with_nn_P.mapminmax_ymin;
    rtb_Memory1 = rtb_Memory1 / (rpdriver_with_nn_P.mapminmax_xmax[1] -
      rpdriver_with_nn_P.mapminmax_xmin[1]) *
      (rpdriver_with_nn_DW.Memory1_PreviousInput_l +
       -rpdriver_with_nn_P.mapminmax_xmin[1]) +
      rpdriver_with_nn_P.mapminmax_ymin;

    /* Bias: '<S23>/Add min x' incorporates:
     *  Bias: '<S23>/Subtract min y'
     *  Constant: '<S12>/IW{1,1}(1,:)''
     *  Constant: '<S12>/IW{1,1}(2,:)''
     *  Constant: '<S12>/IW{1,1}(3,:)''
     *  Constant: '<S12>/IW{1,1}(4,:)''
     *  Constant: '<S13>/one'
     *  Constant: '<S13>/one1'
     *  Constant: '<S19>/IW{2,1}(1,:)''
     *  Constant: '<S7>/b{1}'
     *  Constant: '<S8>/b{2}'
     *  DotProduct: '<S14>/Dot Product'
     *  DotProduct: '<S15>/Dot Product'
     *  DotProduct: '<S16>/Dot Product'
     *  DotProduct: '<S17>/Dot Product'
     *  DotProduct: '<S21>/Dot Product'
     *  Gain: '<S13>/Gain'
     *  Gain: '<S13>/Gain1'
     *  Gain: '<S23>/Divide by range y'
     *  Math: '<S13>/Exp'
     *  Math: '<S13>/Reciprocal'
     *  Sum: '<S13>/Sum'
     *  Sum: '<S13>/Sum1'
     *  Sum: '<S7>/netsum'
     *  Sum: '<S8>/netsum'
     *
     * About '<S13>/Exp':
     *  Operator: exp
     *
     * About '<S13>/Reciprocal':
     *  Operator: reciprocal
     */
    rpdriver_with_nn_B.Addminx = ((((((1.0 / (exp
      (((rpdriver_with_nn_P.IW111_Value[0] * rtb_Sum1_d_idx_0 +
         rpdriver_with_nn_P.IW111_Value[1] * rtb_Memory1) +
        rpdriver_with_nn_P.b1_Value[0]) * rpdriver_with_nn_P.Gain_Gain) +
      rpdriver_with_nn_P.one_Value) * rpdriver_with_nn_P.Gain1_Gain_g -
      rpdriver_with_nn_P.one1_Value) * rpdriver_with_nn_P.IW211_Value[0] + (1.0 /
      (exp(((rpdriver_with_nn_P.IW112_Value[0] * rtb_Sum1_d_idx_0 +
             rpdriver_with_nn_P.IW112_Value[1] * rtb_Memory1) +
            rpdriver_with_nn_P.b1_Value[1]) * rpdriver_with_nn_P.Gain_Gain) +
       rpdriver_with_nn_P.one_Value) * rpdriver_with_nn_P.Gain1_Gain_g -
      rpdriver_with_nn_P.one1_Value) * rpdriver_with_nn_P.IW211_Value[1]) + (1.0
      / (exp(((rpdriver_with_nn_P.IW113_Value[0] * rtb_Sum1_d_idx_0 +
               rpdriver_with_nn_P.IW113_Value[1] * rtb_Memory1) +
              rpdriver_with_nn_P.b1_Value[2]) * rpdriver_with_nn_P.Gain_Gain) +
         rpdriver_with_nn_P.one_Value) * rpdriver_with_nn_P.Gain1_Gain_g -
      rpdriver_with_nn_P.one1_Value) * rpdriver_with_nn_P.IW211_Value[2]) + (1.0
      / (exp(((rpdriver_with_nn_P.IW114_Value[0] * rtb_Sum1_d_idx_0 +
               rpdriver_with_nn_P.IW114_Value[1] * rtb_Memory1) +
              rpdriver_with_nn_P.b1_Value[3]) * rpdriver_with_nn_P.Gain_Gain) +
         rpdriver_with_nn_P.one_Value) * rpdriver_with_nn_P.Gain1_Gain_g -
      rpdriver_with_nn_P.one1_Value) * rpdriver_with_nn_P.IW211_Value[3]) +
      rpdriver_with_nn_P.b2_Value) + -rpdriver_with_nn_P.mapminmax_reverse_ymin)
      * ((rpdriver_with_nn_P.mapminmax_reverse_xmax -
          rpdriver_with_nn_P.mapminmax_reverse_xmin) /
         (rpdriver_with_nn_P.mapminmax_reverse_ymax -
          rpdriver_with_nn_P.mapminmax_reverse_ymin)) +
      rpdriver_with_nn_P.mapminmax_reverse_xmin;

    /* Gain: '<S37>/range y // range x' */
    rtb_Memory1 = rpdriver_with_nn_P.mapminmax_ymax_h -
      rpdriver_with_nn_P.mapminmax_ymin_n;

    /* Bias: '<S37>/Add min y' incorporates:
     *  Bias: '<S37>/Subtract min x'
     *  Gain: '<S37>/range y // range x'
     *  Memory: '<Root>/Memory1'
     */
    rtb_Sum1_d_idx_0 = rtb_Memory1 / (rpdriver_with_nn_P.mapminmax_xmax_o[0] -
      rpdriver_with_nn_P.mapminmax_xmin_f[0]) * (rtb_Memory +
      -rpdriver_with_nn_P.mapminmax_xmin_f[0]) +
      rpdriver_with_nn_P.mapminmax_ymin_n;
    rtb_Memory1 = rtb_Memory1 / (rpdriver_with_nn_P.mapminmax_xmax_o[1] -
      rpdriver_with_nn_P.mapminmax_xmin_f[1]) *
      (rpdriver_with_nn_DW.Memory1_PreviousInput_l +
       -rpdriver_with_nn_P.mapminmax_xmin_f[1]) +
      rpdriver_with_nn_P.mapminmax_ymin_n;

    /* Bias: '<S38>/Add min x' incorporates:
     *  Bias: '<S38>/Subtract min y'
     *  Constant: '<S24>/b{1}'
     *  Constant: '<S25>/b{2}'
     *  Constant: '<S29>/IW{1,1}(1,:)''
     *  Constant: '<S29>/IW{1,1}(2,:)''
     *  Constant: '<S30>/one'
     *  Constant: '<S30>/one1'
     *  Constant: '<S34>/IW{2,1}(1,:)''
     *  DotProduct: '<S31>/Dot Product'
     *  DotProduct: '<S32>/Dot Product'
     *  DotProduct: '<S36>/Dot Product'
     *  Gain: '<S30>/Gain'
     *  Gain: '<S30>/Gain1'
     *  Gain: '<S38>/Divide by range y'
     *  Math: '<S30>/Exp'
     *  Math: '<S30>/Reciprocal'
     *  Sum: '<S24>/netsum'
     *  Sum: '<S25>/netsum'
     *  Sum: '<S30>/Sum'
     *  Sum: '<S30>/Sum1'
     *
     * About '<S30>/Exp':
     *  Operator: exp
     *
     * About '<S30>/Reciprocal':
     *  Operator: reciprocal
     */
    rpdriver_with_nn_B.Addminx_f = ((((1.0 / (exp
      (((rpdriver_with_nn_P.IW111_Value_g[0] * rtb_Sum1_d_idx_0 +
         rpdriver_with_nn_P.IW111_Value_g[1] * rtb_Memory1) +
        rpdriver_with_nn_P.b1_Value_n[0]) * rpdriver_with_nn_P.Gain_Gain_i) +
      rpdriver_with_nn_P.one_Value_g) * rpdriver_with_nn_P.Gain1_Gain_hd -
      rpdriver_with_nn_P.one1_Value_m) * rpdriver_with_nn_P.IW211_Value_j[0] +
      (1.0 / (exp(((rpdriver_with_nn_P.IW112_Value_j[0] * rtb_Sum1_d_idx_0 +
                    rpdriver_with_nn_P.IW112_Value_j[1] * rtb_Memory1) +
                   rpdriver_with_nn_P.b1_Value_n[1]) *
                  rpdriver_with_nn_P.Gain_Gain_i) +
              rpdriver_with_nn_P.one_Value_g) * rpdriver_with_nn_P.Gain1_Gain_hd
       - rpdriver_with_nn_P.one1_Value_m) * rpdriver_with_nn_P.IW211_Value_j[1])
      + rpdriver_with_nn_P.b2_Value_m) +
      -rpdriver_with_nn_P.mapminmax_reverse_ymin_j) *
      ((rpdriver_with_nn_P.mapminmax_reverse_xmax_g -
        rpdriver_with_nn_P.mapminmax_reverse_xmin_e) /
       (rpdriver_with_nn_P.mapminmax_reverse_ymax_j -
        rpdriver_with_nn_P.mapminmax_reverse_ymin_j)) +
      rpdriver_with_nn_P.mapminmax_reverse_xmin_e;

    /* Scope: '<Root>/Scope' */
    {
      StructLogVar *svar = (StructLogVar *)
        rpdriver_with_nn_DW.Scope_PWORK.LoggedData[0];
      LogVar *var = svar->signals.values;

      /* time */
      {
        double locTime = rpdriver_with_nn_M->Timing.t[1];
        ;
        rt_UpdateLogVar((LogVar *)svar->time, &locTime, 0);
      }

      /* signals */
      {
        real_T up0[1];
        up0[0] = rpdriver_with_nn_B.PendulumAnglerad;
        rt_UpdateLogVar((LogVar *)var, up0, 0);
        var = var->next;
      }

      {
        real_T up1[1];
        up1[0] = rpdriver_with_nn_B.Addminx;
        rt_UpdateLogVar((LogVar *)var, up1, 0);
        var = var->next;
      }

      {
        real_T up2[1];
        up2[0] = rpdriver_with_nn_B.Addminx_f;
        rt_UpdateLogVar((LogVar *)var, up2, 0);
      }
    }

    /* Derivative: '<Root>/Derivative' */
    rtb_Sum1_d_idx_0 = rpdriver_with_nn_M->Timing.t[0];
    if ((rpdriver_with_nn_DW.TimeStampA >= rtb_Sum1_d_idx_0) &&
        (rpdriver_with_nn_DW.TimeStampB >= rtb_Sum1_d_idx_0)) {
      rpdriver_with_nn_B.Derivative = 0.0;
    } else {
      rtb_Memory1 = rpdriver_with_nn_DW.TimeStampA;
      lastU = &rpdriver_with_nn_DW.LastUAtTimeA;
      if (rpdriver_with_nn_DW.TimeStampA < rpdriver_with_nn_DW.TimeStampB) {
        if (rpdriver_with_nn_DW.TimeStampB < rtb_Sum1_d_idx_0) {
          rtb_Memory1 = rpdriver_with_nn_DW.TimeStampB;
          lastU = &rpdriver_with_nn_DW.LastUAtTimeB;
        }
      } else {
        if (rpdriver_with_nn_DW.TimeStampA >= rtb_Sum1_d_idx_0) {
          rtb_Memory1 = rpdriver_with_nn_DW.TimeStampB;
          lastU = &rpdriver_with_nn_DW.LastUAtTimeB;
        }
      }

      rpdriver_with_nn_B.Derivative = (rpdriver_with_nn_B.PendulumVelrads -
        *lastU) / (rtb_Sum1_d_idx_0 - rtb_Memory1);
    }

    /* End of Derivative: '<Root>/Derivative' */

    /* MATLAB Function: '<Root>/MATLAB Function' */
    /* MATLAB Function 'MATLAB Function': '<S1>:1' */
    /* '<S1>:1:2' */
    /* '<S1>:1:3' */
    rpdriver_with_nn_B.Beta_output = (rpdriver_with_nn_B.Derivative - -4.9764 *
      rpdriver_with_nn_B.PendulumAnglerad) / rpdriver_with_nn_B.PendulumVelrads;

    /* ManualSwitch: '<Root>/Reset Encoders' incorporates:
     *  Constant: '<Root>/Normal'
     *  Constant: '<Root>/Reset'
     */
    if (rpdriver_with_nn_P.ResetEncoders_CurrentSetting == 1) {
      rtb_Memory1 = rpdriver_with_nn_P.Reset_Value;
    } else {
      rtb_Memory1 = rpdriver_with_nn_P.Normal_Value;
    }

    /* End of ManualSwitch: '<Root>/Reset Encoders' */

    /* Gain: '<S2>/Gain' */
    rpdriver_with_nn_B.Gain[0] = rpdriver_with_nn_P.Gain_Gain_d[0] * rtb_Memory1;
    rpdriver_with_nn_B.Gain[1] = rpdriver_with_nn_P.Gain_Gain_d[1] * rtb_Memory1;

    /* Constant: '<S2>/Prescaler' */
    rpdriver_with_nn_B.Prescaler = rpdriver_with_nn_P.Prescaler_Value;

    /* Gain: '<S2>/Gain2' */
    rtb_Memory1 = rpdriver_with_nn_P.Gain2_Gain * rpdriver_with_nn_B.Control;

    /* Saturate: '<S2>/Saturation' */
    if (rtb_Memory1 > rpdriver_with_nn_P.Saturation_UpperSat_h) {
      rpdriver_with_nn_B.Saturation = rpdriver_with_nn_P.Saturation_UpperSat_h;
    } else if (rtb_Memory1 < rpdriver_with_nn_P.Saturation_LowerSat_f) {
      rpdriver_with_nn_B.Saturation = rpdriver_with_nn_P.Saturation_LowerSat_f;
    } else {
      rpdriver_with_nn_B.Saturation = rtb_Memory1;
    }

    /* End of Saturate: '<S2>/Saturation' */

    /* Constant: '<S2>/ThermFlag' */
    rpdriver_with_nn_B.ThermFlag = rpdriver_with_nn_P.ThermFlag_Value;
  }

  /* Matfile logging */
  rt_UpdateTXYLogVars(rpdriver_with_nn_M->rtwLogInfo,
                      (rpdriver_with_nn_M->Timing.t));

  {
    real_T *lastU;

    /* Update for Memory: '<S2>/Memory2' */
    rpdriver_with_nn_DW.Memory2_PreviousInput =
      rpdriver_with_nn_B.PendulumAnglerad;

    /* Update for Memory: '<S2>/Memory' */
    rpdriver_with_nn_DW.Memory_PreviousInput = rpdriver_with_nn_B.SFunction_o6;

    /* Update for Memory: '<S2>/Memory1' */
    rpdriver_with_nn_DW.Memory1_PreviousInput = rpdriver_with_nn_B.DCAnglerad;

    /* Update for Memory: '<Root>/Memory' */
    rpdriver_with_nn_DW.Memory_PreviousInput_i =
      rpdriver_with_nn_B.PendulumAnglerad;

    /* Update for Memory: '<Root>/Memory1' */
    rpdriver_with_nn_DW.Memory1_PreviousInput_l = rtb_Memory;

    /* Update for Derivative: '<Root>/Derivative' */
    if (rpdriver_with_nn_DW.TimeStampA == (rtInf)) {
      rpdriver_with_nn_DW.TimeStampA = rpdriver_with_nn_M->Timing.t[0];
      lastU = &rpdriver_with_nn_DW.LastUAtTimeA;
    } else if (rpdriver_with_nn_DW.TimeStampB == (rtInf)) {
      rpdriver_with_nn_DW.TimeStampB = rpdriver_with_nn_M->Timing.t[0];
      lastU = &rpdriver_with_nn_DW.LastUAtTimeB;
    } else if (rpdriver_with_nn_DW.TimeStampA < rpdriver_with_nn_DW.TimeStampB)
    {
      rpdriver_with_nn_DW.TimeStampA = rpdriver_with_nn_M->Timing.t[0];
      lastU = &rpdriver_with_nn_DW.LastUAtTimeA;
    } else {
      rpdriver_with_nn_DW.TimeStampB = rpdriver_with_nn_M->Timing.t[0];
      lastU = &rpdriver_with_nn_DW.LastUAtTimeB;
    }

    *lastU = rpdriver_with_nn_B.PendulumVelrads;

    /* End of Update for Derivative: '<Root>/Derivative' */
  }

  /* External mode */
  rtExtModeUploadCheckTrigger(2);

  {                                    /* Sample time: [0.0s, 0.0s] */
    rtExtModeUpload(0, (real_T)rpdriver_with_nn_M->Timing.t[0]);
  }

  {                                    /* Sample time: [0.01s, 0.0s] */
    rtExtModeUpload(1, (real_T)rpdriver_with_nn_M->Timing.t[1]);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(rpdriver_with_nn_M)!=-1) &&
        !((rtmGetTFinal(rpdriver_with_nn_M)-rpdriver_with_nn_M->Timing.t[0]) >
          rpdriver_with_nn_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(rpdriver_with_nn_M, "Simulation finished");
    }

    if (rtmGetStopRequested(rpdriver_with_nn_M)) {
      rtmSetErrorStatus(rpdriver_with_nn_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++rpdriver_with_nn_M->Timing.clockTick0)) {
    ++rpdriver_with_nn_M->Timing.clockTickH0;
  }

  rpdriver_with_nn_M->Timing.t[0] = rpdriver_with_nn_M->Timing.clockTick0 *
    rpdriver_with_nn_M->Timing.stepSize0 +
    rpdriver_with_nn_M->Timing.clockTickH0 *
    rpdriver_with_nn_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++rpdriver_with_nn_M->Timing.clockTick1)) {
      ++rpdriver_with_nn_M->Timing.clockTickH1;
    }

    rpdriver_with_nn_M->Timing.t[1] = rpdriver_with_nn_M->Timing.clockTick1 *
      rpdriver_with_nn_M->Timing.stepSize1 +
      rpdriver_with_nn_M->Timing.clockTickH1 *
      rpdriver_with_nn_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void rpdriver_with_nn_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)rpdriver_with_nn_M, 0,
                sizeof(RT_MODEL_rpdriver_with_nn_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&rpdriver_with_nn_M->solverInfo,
                          &rpdriver_with_nn_M->Timing.simTimeStep);
    rtsiSetTPtr(&rpdriver_with_nn_M->solverInfo, &rtmGetTPtr(rpdriver_with_nn_M));
    rtsiSetStepSizePtr(&rpdriver_with_nn_M->solverInfo,
                       &rpdriver_with_nn_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&rpdriver_with_nn_M->solverInfo, (&rtmGetErrorStatus
      (rpdriver_with_nn_M)));
    rtsiSetRTModelPtr(&rpdriver_with_nn_M->solverInfo, rpdriver_with_nn_M);
  }

  rtsiSetSimTimeStep(&rpdriver_with_nn_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&rpdriver_with_nn_M->solverInfo,"FixedStepDiscrete");
  rpdriver_with_nn_M->solverInfoPtr = (&rpdriver_with_nn_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = rpdriver_with_nn_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    rpdriver_with_nn_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    rpdriver_with_nn_M->Timing.sampleTimes =
      (&rpdriver_with_nn_M->Timing.sampleTimesArray[0]);
    rpdriver_with_nn_M->Timing.offsetTimes =
      (&rpdriver_with_nn_M->Timing.offsetTimesArray[0]);

    /* task periods */
    rpdriver_with_nn_M->Timing.sampleTimes[0] = (0.0);
    rpdriver_with_nn_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    rpdriver_with_nn_M->Timing.offsetTimes[0] = (0.0);
    rpdriver_with_nn_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(rpdriver_with_nn_M, &rpdriver_with_nn_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = rpdriver_with_nn_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    rpdriver_with_nn_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(rpdriver_with_nn_M, 999.0);
  rpdriver_with_nn_M->Timing.stepSize0 = 0.01;
  rpdriver_with_nn_M->Timing.stepSize1 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    rpdriver_with_nn_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(rpdriver_with_nn_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(rpdriver_with_nn_M->rtwLogInfo, (NULL));
    rtliSetLogT(rpdriver_with_nn_M->rtwLogInfo, "tout");
    rtliSetLogX(rpdriver_with_nn_M->rtwLogInfo, "");
    rtliSetLogXFinal(rpdriver_with_nn_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(rpdriver_with_nn_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(rpdriver_with_nn_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(rpdriver_with_nn_M->rtwLogInfo, 0);
    rtliSetLogDecimation(rpdriver_with_nn_M->rtwLogInfo, 1);
    rtliSetLogY(rpdriver_with_nn_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(rpdriver_with_nn_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(rpdriver_with_nn_M->rtwLogInfo, (NULL));
  }

  /* External mode info */
  rpdriver_with_nn_M->Sizes.checksums[0] = (820520137U);
  rpdriver_with_nn_M->Sizes.checksums[1] = (2136940501U);
  rpdriver_with_nn_M->Sizes.checksums[2] = (2196775533U);
  rpdriver_with_nn_M->Sizes.checksums[3] = (1805923083U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[8];
    rpdriver_with_nn_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(rpdriver_with_nn_M->extModeInfo,
      &rpdriver_with_nn_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(rpdriver_with_nn_M->extModeInfo,
                        rpdriver_with_nn_M->Sizes.checksums);
    rteiSetTPtr(rpdriver_with_nn_M->extModeInfo, rtmGetTPtr(rpdriver_with_nn_M));
  }

  rpdriver_with_nn_M->solverInfoPtr = (&rpdriver_with_nn_M->solverInfo);
  rpdriver_with_nn_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&rpdriver_with_nn_M->solverInfo, 0.01);
  rtsiSetSolverMode(&rpdriver_with_nn_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  (void) memset(((void *) &rpdriver_with_nn_B), 0,
                sizeof(B_rpdriver_with_nn_T));

  /* states (dwork) */
  (void) memset((void *)&rpdriver_with_nn_DW, 0,
                sizeof(DW_rpdriver_with_nn_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    rpdriver_with_nn_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &rpdriver_with_nn_M->NonInlinedSFcns.sfcnInfo;
    rpdriver_with_nn_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(rpdriver_with_nn_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &rpdriver_with_nn_M->Sizes.numSampTimes);
    rpdriver_with_nn_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (rpdriver_with_nn_M)[0]);
    rpdriver_with_nn_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (rpdriver_with_nn_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,rpdriver_with_nn_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(rpdriver_with_nn_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(rpdriver_with_nn_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (rpdriver_with_nn_M));
    rtssSetStepSizePtr(sfcnInfo, &rpdriver_with_nn_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(rpdriver_with_nn_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &rpdriver_with_nn_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &rpdriver_with_nn_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &rpdriver_with_nn_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &rpdriver_with_nn_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &rpdriver_with_nn_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &rpdriver_with_nn_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &rpdriver_with_nn_M->solverInfoPtr);
  }

  rpdriver_with_nn_M->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)&rpdriver_with_nn_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  1*sizeof(SimStruct));
    rpdriver_with_nn_M->childSfunctions =
      (&rpdriver_with_nn_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    rpdriver_with_nn_M->childSfunctions[0] =
      (&rpdriver_with_nn_M->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: rpdriver_with_nn/<S2>/S-Function (rtdacusb2_rpend_dd) */
    {
      SimStruct *rts = rpdriver_with_nn_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = rpdriver_with_nn_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = rpdriver_with_nn_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = rpdriver_with_nn_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &rpdriver_with_nn_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &rpdriver_with_nn_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, rpdriver_with_nn_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &rpdriver_with_nn_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &rpdriver_with_nn_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &rpdriver_with_nn_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &rpdriver_with_nn_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &rpdriver_with_nn_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 4);
        ssSetPortInfoForInputs(rts,
          &rpdriver_with_nn_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &rpdriver_with_nn_M->NonInlinedSFcns.Sfcn0.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        ssSetInputPortUnit(rts, 2, 0);
        ssSetInputPortUnit(rts, 3, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &rpdriver_with_nn_M->NonInlinedSFcns.Sfcn0.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);
        ssSetInputPortIsContinuousQuantity(rts, 2, 0);
        ssSetInputPortIsContinuousQuantity(rts, 3, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &rpdriver_with_nn_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &rpdriver_with_nn_B.Saturation;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &rpdriver_with_nn_M->NonInlinedSFcns.Sfcn0.UPtrs1;
          sfcnUPtrs[0] = rpdriver_with_nn_B.Gain;
          sfcnUPtrs[1] = &rpdriver_with_nn_B.Gain[1];
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 2);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &rpdriver_with_nn_M->NonInlinedSFcns.Sfcn0.UPtrs2;
          sfcnUPtrs[0] = &rpdriver_with_nn_B.Prescaler;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &rpdriver_with_nn_M->NonInlinedSFcns.Sfcn0.UPtrs3;
          sfcnUPtrs[0] = &rpdriver_with_nn_B.ThermFlag;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &rpdriver_with_nn_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 7);
        _ssSetPortInfo2ForOutputUnits(rts,
          &rpdriver_with_nn_M->NonInlinedSFcns.Sfcn0.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        ssSetOutputPortUnit(rts, 2, 0);
        ssSetOutputPortUnit(rts, 3, 0);
        ssSetOutputPortUnit(rts, 4, 0);
        ssSetOutputPortUnit(rts, 5, 0);
        ssSetOutputPortUnit(rts, 6, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &rpdriver_with_nn_M->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 2, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 3, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 4, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 5, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 6, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &rpdriver_with_nn_B.SFunction_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &rpdriver_with_nn_B.SFunction_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            &rpdriver_with_nn_B.SFunction_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *)
            &rpdriver_with_nn_B.SFunction_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *)
            &rpdriver_with_nn_B.SFunction_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *)
            &rpdriver_with_nn_B.SFunction_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 2);
          ssSetOutputPortSignal(rts, 6, ((real_T *)
            rpdriver_with_nn_B.SFunction_o7));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts, "rpdriver_with_nn/RP Driver/S-Function");
      ssSetRTModel(rts,rpdriver_with_nn_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &rpdriver_with_nn_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)rpdriver_with_nn_P.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)rpdriver_with_nn_P.SFunction_P2_Size);
      }

      /* registration */
      rtdacusb2_rpend_dd(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetInputPortConnected(rts, 2, 1);
      _ssSetInputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 4, 1);
      _ssSetOutputPortConnected(rts, 5, 1);
      _ssSetOutputPortConnected(rts, 6, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 6, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
      ssSetInputPortBufferDstPort(rts, 3, -1);
    }
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(rpdriver_with_nn_M->rtwLogInfo, 0.0,
    rtmGetTFinal(rpdriver_with_nn_M), rpdriver_with_nn_M->Timing.stepSize0,
    (&rtmGetErrorStatus(rpdriver_with_nn_M)));

  /* Start for S-Function (rtdacusb2_rpend_dd): '<S2>/S-Function' */
  /* Level2 S-Function Block: '<S2>/S-Function' (rtdacusb2_rpend_dd) */
  {
    SimStruct *rts = rpdriver_with_nn_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Scope: '<Root>/PlotState' */
  {
    RTWLogSignalInfo rt_ScopeSignalInfo;
    static int_T rt_ScopeSignalWidths[] = { 1, 1, 1, 1, 1, 1, 1, 1 };

    static int_T rt_ScopeSignalNumDimensions[] = { 1, 1, 1, 1, 1, 1, 1, 1 };

    static int_T rt_ScopeSignalDimensions[] = { 1, 1, 1, 1, 1, 1, 1, 1 };

    static void *rt_ScopeCurrSigDims[] = { (NULL), (NULL), (NULL), (NULL), (NULL),
      (NULL), (NULL), (NULL) };

    static int_T rt_ScopeCurrSigDimsSize[] = { 4, 4, 4, 4, 4, 4, 4, 4 };

    static const char_T *rt_ScopeSignalLabels[] = { "<Pendulum Angle [rad]>",
      "<PendPos_ZeroDown>",
      "<PendPos_ZeroUp>",
      "<Pendulum Vel [rad/s]>",
      "<DC Angle [rad]>",
      "<DC Vel [rad/s]>",
      "DC Current",
      "Control" };

    static char_T rt_ScopeSignalTitles[] =
      "<Pendulum Angle [rad]><PendPos_ZeroDown><PendPos_ZeroUp><Pendulum Vel [rad/s]><DC Angle [rad]><DC Vel [rad/s]>DC CurrentControl";
    static int_T rt_ScopeSignalTitleLengths[] = { 22, 18, 16, 22, 16, 16, 10, 7
    };

    static boolean_T rt_ScopeSignalIsVarDims[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

    static int_T rt_ScopeSignalPlotStyles[] = { 1, 1, 1, 1, 1, 1, 1, 1 };

    BuiltInDTypeId dTypes[8] = { SS_DOUBLE, SS_DOUBLE, SS_DOUBLE, SS_DOUBLE,
      SS_DOUBLE, SS_DOUBLE, SS_DOUBLE, SS_DOUBLE };

    static char_T rt_ScopeBlockName[] = "rpdriver_with_nn/PlotState";
    static int_T rt_ScopeFrameData[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

    static RTWPreprocessingFcnPtr rt_ScopeSignalLoggingPreprocessingFcnPtrs[] =
      {
      (NULL), (NULL), (NULL), (NULL), (NULL), (NULL), (NULL), (NULL)
    };

    rt_ScopeSignalInfo.numSignals = 8;
    rt_ScopeSignalInfo.numCols = rt_ScopeSignalWidths;
    rt_ScopeSignalInfo.numDims = rt_ScopeSignalNumDimensions;
    rt_ScopeSignalInfo.dims = rt_ScopeSignalDimensions;
    rt_ScopeSignalInfo.isVarDims = rt_ScopeSignalIsVarDims;
    rt_ScopeSignalInfo.currSigDims = rt_ScopeCurrSigDims;
    rt_ScopeSignalInfo.currSigDimsSize = rt_ScopeCurrSigDimsSize;
    rt_ScopeSignalInfo.dataTypes = dTypes;
    rt_ScopeSignalInfo.complexSignals = (NULL);
    rt_ScopeSignalInfo.frameData = rt_ScopeFrameData;
    rt_ScopeSignalInfo.preprocessingPtrs =
      rt_ScopeSignalLoggingPreprocessingFcnPtrs;
    rt_ScopeSignalInfo.labels.cptr = rt_ScopeSignalLabels;
    rt_ScopeSignalInfo.titles = rt_ScopeSignalTitles;
    rt_ScopeSignalInfo.titleLengths = rt_ScopeSignalTitleLengths;
    rt_ScopeSignalInfo.plotStyles = rt_ScopeSignalPlotStyles;
    rt_ScopeSignalInfo.blockNames.cptr = (NULL);
    rt_ScopeSignalInfo.stateNames.cptr = (NULL);
    rt_ScopeSignalInfo.crossMdlRef = (NULL);
    rt_ScopeSignalInfo.dataTypeConvert = (NULL);
    rpdriver_with_nn_DW.PlotState_PWORK.LoggedData[0] = rt_CreateStructLogVar(
      rpdriver_with_nn_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(rpdriver_with_nn_M),
      rpdriver_with_nn_M->Timing.stepSize0,
      (&rtmGetErrorStatus(rpdriver_with_nn_M)),
      "dane_NN_liczenie_bety",
      1,
      0,
      1,
      0.01,
      &rt_ScopeSignalInfo,
      rt_ScopeBlockName);
    if (rpdriver_with_nn_DW.PlotState_PWORK.LoggedData[0] == (NULL))
      return;
  }

  /* Start for Scope: '<Root>/Scope' */
  {
    RTWLogSignalInfo rt_ScopeSignalInfo;
    static int_T rt_ScopeSignalWidths[] = { 1, 1, 1 };

    static int_T rt_ScopeSignalNumDimensions[] = { 1, 1, 1 };

    static int_T rt_ScopeSignalDimensions[] = { 1, 1, 1 };

    static void *rt_ScopeCurrSigDims[] = { (NULL), (NULL), (NULL) };

    static int_T rt_ScopeCurrSigDimsSize[] = { 4, 4, 4 };

    static const char_T *rt_ScopeSignalLabels[] = { "<Pendulum Angle [rad]>",
      "",
      "" };

    static char_T rt_ScopeSignalTitles[] = "<Pendulum Angle [rad]>";
    static int_T rt_ScopeSignalTitleLengths[] = { 22, 0, 0 };

    static boolean_T rt_ScopeSignalIsVarDims[] = { 0, 0, 0 };

    static int_T rt_ScopeSignalPlotStyles[] = { 1, 1, 1 };

    BuiltInDTypeId dTypes[3] = { SS_DOUBLE, SS_DOUBLE, SS_DOUBLE };

    static char_T rt_ScopeBlockName[] = "rpdriver_with_nn/Scope";
    static int_T rt_ScopeFrameData[] = { 0, 0, 0 };

    static RTWPreprocessingFcnPtr rt_ScopeSignalLoggingPreprocessingFcnPtrs[] =
      {
      (NULL), (NULL), (NULL)
    };

    rt_ScopeSignalInfo.numSignals = 3;
    rt_ScopeSignalInfo.numCols = rt_ScopeSignalWidths;
    rt_ScopeSignalInfo.numDims = rt_ScopeSignalNumDimensions;
    rt_ScopeSignalInfo.dims = rt_ScopeSignalDimensions;
    rt_ScopeSignalInfo.isVarDims = rt_ScopeSignalIsVarDims;
    rt_ScopeSignalInfo.currSigDims = rt_ScopeCurrSigDims;
    rt_ScopeSignalInfo.currSigDimsSize = rt_ScopeCurrSigDimsSize;
    rt_ScopeSignalInfo.dataTypes = dTypes;
    rt_ScopeSignalInfo.complexSignals = (NULL);
    rt_ScopeSignalInfo.frameData = rt_ScopeFrameData;
    rt_ScopeSignalInfo.preprocessingPtrs =
      rt_ScopeSignalLoggingPreprocessingFcnPtrs;
    rt_ScopeSignalInfo.labels.cptr = rt_ScopeSignalLabels;
    rt_ScopeSignalInfo.titles = rt_ScopeSignalTitles;
    rt_ScopeSignalInfo.titleLengths = rt_ScopeSignalTitleLengths;
    rt_ScopeSignalInfo.plotStyles = rt_ScopeSignalPlotStyles;
    rt_ScopeSignalInfo.blockNames.cptr = (NULL);
    rt_ScopeSignalInfo.stateNames.cptr = (NULL);
    rt_ScopeSignalInfo.crossMdlRef = (NULL);
    rt_ScopeSignalInfo.dataTypeConvert = (NULL);
    rpdriver_with_nn_DW.Scope_PWORK.LoggedData[0] = rt_CreateStructLogVar(
      rpdriver_with_nn_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(rpdriver_with_nn_M),
      rpdriver_with_nn_M->Timing.stepSize0,
      (&rtmGetErrorStatus(rpdriver_with_nn_M)),
      "walidacja_modelu_sieci",
      1,
      0,
      1,
      0.01,
      &rt_ScopeSignalInfo,
      rt_ScopeBlockName);
    if (rpdriver_with_nn_DW.Scope_PWORK.LoggedData[0] == (NULL))
      return;
  }

  /* Start for Constant: '<S2>/Prescaler' */
  rpdriver_with_nn_B.Prescaler = rpdriver_with_nn_P.Prescaler_Value;

  /* Start for Constant: '<S2>/ThermFlag' */
  rpdriver_with_nn_B.ThermFlag = rpdriver_with_nn_P.ThermFlag_Value;

  /* InitializeConditions for Memory: '<S2>/Memory2' */
  rpdriver_with_nn_DW.Memory2_PreviousInput =
    rpdriver_with_nn_P.Memory2_InitialCondition;

  /* InitializeConditions for Memory: '<S2>/Memory' */
  rpdriver_with_nn_DW.Memory_PreviousInput =
    rpdriver_with_nn_P.Memory_InitialCondition;

  /* InitializeConditions for Memory: '<S2>/Memory1' */
  rpdriver_with_nn_DW.Memory1_PreviousInput =
    rpdriver_with_nn_P.Memory1_InitialCondition;

  /* InitializeConditions for Memory: '<Root>/Memory' */
  rpdriver_with_nn_DW.Memory_PreviousInput_i =
    rpdriver_with_nn_P.Memory_InitialCondition_j;

  /* InitializeConditions for Memory: '<Root>/Memory1' */
  rpdriver_with_nn_DW.Memory1_PreviousInput_l =
    rpdriver_with_nn_P.Memory1_InitialCondition_f;

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  rpdriver_with_nn_DW.TimeStampA = (rtInf);
  rpdriver_with_nn_DW.TimeStampB = (rtInf);
}

/* Model terminate function */
void rpdriver_with_nn_terminate(void)
{
  /* Terminate for S-Function (rtdacusb2_rpend_dd): '<S2>/S-Function' */
  /* Level2 S-Function Block: '<S2>/S-Function' (rtdacusb2_rpend_dd) */
  {
    SimStruct *rts = rpdriver_with_nn_M->childSfunctions[0];
    sfcnTerminate(rts);
  }
}

#include <stdio.h>

/* Final time from "Simulation Parameters"   */
real_T finaltime = 999.0;
real_T StepSize = 0.01;

////////////////////////////////////////////////
//
//  Return compilation date and time
//
char *GetDateAndTime( void )
{
  static char AuxStr[ 128 ];
  sprintf( AuxStr, "%s %s", __DATE__, __TIME__ );
  return( AuxStr );
}
