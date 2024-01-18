/*
 * controller_real.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller_real".
 *
 * Model version              : 1.6
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Wed Jan 17 11:13:59 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "controller_real.h"
#include "rtwtypes.h"
#include <math.h>
#include <string.h>
#include "controller_real_private.h"

/* Block signals (default storage) */
B_controller_real_T controller_real_B;

/* Block states (default storage) */
DW_controller_real_T controller_real_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_controller_real_T controller_real_Y;

/* Real-time model */
static RT_MODEL_controller_real_T controller_real_M_;
RT_MODEL_controller_real_T *const controller_real_M = &controller_real_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void controller_real_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(controller_real_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 1 */
  controller_real_M->Timing.RateInteraction.TID0_1 =
    (controller_real_M->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (controller_real_M->Timing.TaskCounters.TID[1])++;
  if ((controller_real_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [0.01s, 0.0s] */
    controller_real_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void controller_real_step0(void)       /* Sample time: [0.0001s, 0.0s] */
{
  real_T rtb_Gain9;
  real_T rtb_Sum1;
  boolean_T rtb_EncoderA_0;
  boolean_T rtb_EncoderB_0;

  {                                    /* Sample time: [0.0001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* UnitDelay: '<Root>/Unit Delay1' */
  controller_real_B.UnitDelay1[0] = controller_real_DW.UnitDelay1_DSTATE[0];
  controller_real_B.UnitDelay1[1] = controller_real_DW.UnitDelay1_DSTATE[1];

  /* Outport: '<Root>/pEst' */
  controller_real_Y.pEst = controller_real_B.UnitDelay1[0];

  /* Outport: '<Root>/vEst' */
  controller_real_Y.vEst = controller_real_B.UnitDelay1[1];

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<Root>/Gain3'
   *  Gain: '<Root>/Gain4'
   *  Gain: '<Root>/Gain5'
   *  Sum: '<Root>/Sum3'
   *  UnitDelay: '<Root>/Unit Delay'
   */
  rtb_Sum1 = (controller_real_P.accDirDisc * controller_real_P.targetPos -
              controller_real_P.K_i_disc * controller_real_P.accInt *
              controller_real_DW.UnitDelay_DSTATE) -
    (controller_real_P.K_r_disc[0] * controller_real_B.UnitDelay1[0] +
     controller_real_P.K_r_disc[1] * controller_real_B.UnitDelay1[1]);

  /* UnitDelay: '<S3>/Unit Delay2' */
  controller_real_B.UnitDelay2 = controller_real_DW.UnitDelay2_DSTATE;

  /* ZeroOrderHold: '<Root>/Zero-Order Hold' */
  controller_real_B.ZeroOrderHold = controller_real_B.UnitDelay2;

  /* Outport: '<Root>/p (deg)' */
  controller_real_Y.pdeg = controller_real_B.ZeroOrderHold;

  /* ZeroOrderHold: '<S3>/Zero-Order Hold' */
  if (controller_real_M->Timing.RateInteraction.TID0_1) {
    /* ZeroOrderHold: '<S3>/Zero-Order Hold' */
    controller_real_B.ZeroOrderHold_m = controller_real_B.UnitDelay2;
  }

  /* End of ZeroOrderHold: '<S3>/Zero-Order Hold' */

  /* MATLABSystem: '<S2>/Encoder A' */
  if (controller_real_DW.obj_n.SampleTime !=
      controller_real_P.EncoderA_SampleTime) {
    controller_real_DW.obj_n.SampleTime = controller_real_P.EncoderA_SampleTime;
  }

  rtb_EncoderA_0 = MW_digitalIO_read
    (controller_real_DW.obj_n.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<S2>/Encoder B' */
  if (controller_real_DW.obj.SampleTime != controller_real_P.EncoderB_SampleTime)
  {
    controller_real_DW.obj.SampleTime = controller_real_P.EncoderB_SampleTime;
  }

  rtb_EncoderB_0 = MW_digitalIO_read(controller_real_DW.obj.MW_DIGITALIO_HANDLE);

  /* ZeroOrderHold: '<Root>/Zero-Order Hold1' */
  controller_real_B.ZeroOrderHold1 = rtb_Sum1;

  /* Outport: '<Root>/Vref' */
  controller_real_Y.Vref = controller_real_B.ZeroOrderHold1;

  /* Gain: '<Root>/Gain9' */
  rtb_Gain9 = controller_real_P.Gain9_Gain * controller_real_B.ZeroOrderHold1;

  /* MATLABSystem: '<S2>/PHA' incorporates:
   *  Constant: '<S1>/Constant'
   *  RelationalOperator: '<S1>/Compare'
   */
  MW_digitalIO_write(controller_real_DW.obj_d.MW_DIGITALIO_HANDLE, rtb_Gain9 >=
                     controller_real_P.Constant_Value);

  /* MATLABSystem: '<S2>/PWDA' incorporates:
   *  Abs: '<Root>/Abs'
   */
  MW_PWM_SetDutyCycle(controller_real_DW.obj_p.MW_PWM_HANDLE, fabs(rtb_Gain9));

  /* MATLABSystem: '<S2>/ENA' incorporates:
   *  Constant: '<S2>/Constant'
   */
  MW_digitalIO_write(controller_real_DW.obj_nf.MW_DIGITALIO_HANDLE,
                     controller_real_P.Constant_Value_h != 0.0);

  /* MATLABSystem: '<S2>/ENB' incorporates:
   *  Constant: '<S2>/Constant1'
   */
  MW_digitalIO_write(controller_real_DW.obj_e.MW_DIGITALIO_HANDLE,
                     controller_real_P.Constant1_Value != 0.0);

  /* Update for UnitDelay: '<Root>/Unit Delay1' incorporates:
   *  Gain: '<Root>/Gain'
   *  Gain: '<Root>/Gain1'
   *  Gain: '<Root>/Gain2'
   *  Sum: '<Root>/Sum'
   */
  controller_real_DW.UnitDelay1_DSTATE[0] = ((controller_real_P.F[0] -
    0.00189987512764489) * controller_real_B.UnitDelay1[0] +
    controller_real_B.UnitDelay1[1] * controller_real_P.F[2]) +
    (controller_real_P.G[0] * rtb_Sum1 + controller_real_P.L_disc[0] *
     controller_real_B.ZeroOrderHold);
  controller_real_DW.UnitDelay1_DSTATE[1] = ((controller_real_P.F[1] -
    0.079644552074987579) * controller_real_B.UnitDelay1[0] +
    controller_real_B.UnitDelay1[1] * controller_real_P.F[3]) +
    (controller_real_P.G[1] * rtb_Sum1 + controller_real_P.L_disc[1] *
     controller_real_B.ZeroOrderHold);

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Sum1 > controller_real_P.Saturation_UpperSat) {
    rtb_Gain9 = controller_real_P.Saturation_UpperSat;
  } else if (rtb_Sum1 < controller_real_P.Saturation_LowerSat) {
    rtb_Gain9 = controller_real_P.Saturation_LowerSat;
  } else {
    rtb_Gain9 = rtb_Sum1;
  }

  /* Update for UnitDelay: '<Root>/Unit Delay' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<Root>/Gain6'
   *  Gain: '<Root>/Gain7'
   *  Saturate: '<Root>/Saturation'
   *  Sum: '<Root>/Sum2'
   *  Sum: '<Root>/Sum4'
   *  Sum: '<Root>/Sum5'
   */
  controller_real_DW.UnitDelay_DSTATE += ((controller_real_B.ZeroOrderHold -
    controller_real_P.targetPos) - (rtb_Gain9 - rtb_Sum1) *
    controller_real_P.k_awp) * controller_real_P.T;

  /* LookupNDDirect: '<S3>/Direct Lookup Table (n-D)' incorporates:
   *  Gain: '<S3>/Gain'
   *  Gain: '<S3>/Gain1'
   *  Gain: '<S3>/Gain2'
   *  Gain: '<S3>/Gain3'
   *  MATLABSystem: '<S2>/Encoder A'
   *  MATLABSystem: '<S2>/Encoder B'
   *  Sum: '<S3>/Add'
   *  UnitDelay: '<S3>/Unit Delay'
   *  UnitDelay: '<S3>/Unit Delay1'
   *
   * About '<S3>/Direct Lookup Table (n-D)':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  rtb_Sum1 = (((real_T)(controller_real_DW.UnitDelay_DSTATE_a ? (int32_T)
                        controller_real_P.Gain_Gain : 0) * 0.0625 + (real_T)
               (rtb_EncoderA_0 ? (int32_T)controller_real_P.Gain1_Gain : 0) *
               0.03125) + (real_T)(controller_real_DW.UnitDelay1_DSTATE_n ?
    (int32_T)controller_real_P.Gain2_Gain : 0) * 0.015625) + (real_T)
    (rtb_EncoderB_0 ? (int32_T)controller_real_P.Gain3_Gain : 0) * 0.0078125;
  if (rtb_Sum1 > 15.0) {
    rtb_Sum1 = 15.0;
  }

  /* Update for UnitDelay: '<S3>/Unit Delay2' incorporates:
   *  LookupNDDirect: '<S3>/Direct Lookup Table (n-D)'
   *  Sum: '<S3>/Sum'
   *
   * About '<S3>/Direct Lookup Table (n-D)':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  controller_real_DW.UnitDelay2_DSTATE =
    controller_real_P.DirectLookupTablenD_table[(int32_T)rtb_Sum1] +
    controller_real_B.UnitDelay2;

  /* Update for UnitDelay: '<S3>/Unit Delay' incorporates:
   *  MATLABSystem: '<S2>/Encoder A'
   */
  controller_real_DW.UnitDelay_DSTATE_a = rtb_EncoderA_0;

  /* Update for UnitDelay: '<S3>/Unit Delay1' incorporates:
   *  MATLABSystem: '<S2>/Encoder B'
   */
  controller_real_DW.UnitDelay1_DSTATE_n = rtb_EncoderB_0;

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++controller_real_M->Timing.clockTick0)) {
    ++controller_real_M->Timing.clockTickH0;
  }

  controller_real_M->Timing.taskTime0 = controller_real_M->Timing.clockTick0 *
    controller_real_M->Timing.stepSize0 + controller_real_M->Timing.clockTickH0 *
    controller_real_M->Timing.stepSize0 * 4294967296.0;
}

/* Model step function for TID1 */
void controller_real_step1(void)       /* Sample time: [0.01s, 0.0s] */
{
  real_T rtb_TSamp;

  /* SampleTimeMath: '<S4>/TSamp'
   *
   * About '<S4>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp = controller_real_B.ZeroOrderHold_m * controller_real_P.TSamp_WtEt;

  /* Sum: '<S4>/Diff' incorporates:
   *  UnitDelay: '<S4>/UD'
   */
  controller_real_B.Diff = rtb_TSamp - controller_real_DW.UD_DSTATE;

  /* Outport: '<Root>/v (deg//s)' */
  controller_real_Y.vdegs = controller_real_B.Diff;

  /* Update for UnitDelay: '<S4>/UD' */
  controller_real_DW.UD_DSTATE = rtb_TSamp;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  controller_real_M->Timing.clockTick1++;
  if (!controller_real_M->Timing.clockTick1) {
    controller_real_M->Timing.clockTickH1++;
  }
}

/* Model initialize function */
void controller_real_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)controller_real_M, 0,
                sizeof(RT_MODEL_controller_real_T));
  rtmSetTFinal(controller_real_M, 5.0);
  controller_real_M->Timing.stepSize0 = 0.0001;

  /* External mode info */
  controller_real_M->Sizes.checksums[0] = (1640481513U);
  controller_real_M->Sizes.checksums[1] = (2138717556U);
  controller_real_M->Sizes.checksums[2] = (3455548051U);
  controller_real_M->Sizes.checksums[3] = (1786613081U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    controller_real_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(controller_real_M->extModeInfo,
      &controller_real_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(controller_real_M->extModeInfo,
                        controller_real_M->Sizes.checksums);
    rteiSetTPtr(controller_real_M->extModeInfo, rtmGetTPtr(controller_real_M));
  }

  /* block I/O */
  (void) memset(((void *) &controller_real_B), 0,
                sizeof(B_controller_real_T));

  /* states (dwork) */
  (void) memset((void *)&controller_real_DW, 0,
                sizeof(DW_controller_real_T));

  /* external outputs */
  (void)memset(&controller_real_Y, 0, sizeof(ExtY_controller_real_T));

  {
    uint32_T pinname;

    /* Start for MATLABSystem: '<S2>/Encoder A' */
    controller_real_DW.obj_n.matlabCodegenIsDeleted = false;
    controller_real_DW.objisempty_k0 = true;
    controller_real_DW.obj_n.SampleTime = controller_real_P.EncoderA_SampleTime;
    controller_real_DW.obj_n.isInitialized = 1;
    pinname = A1;
    controller_real_DW.obj_n.MW_DIGITALIO_HANDLE = MW_digitalIO_open(pinname, 0);
    controller_real_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Encoder B' */
    controller_real_DW.obj.matlabCodegenIsDeleted = false;
    controller_real_DW.objisempty_d = true;
    controller_real_DW.obj.SampleTime = controller_real_P.EncoderB_SampleTime;
    controller_real_DW.obj.isInitialized = 1;
    pinname = A0;
    controller_real_DW.obj.MW_DIGITALIO_HANDLE = MW_digitalIO_open(pinname, 0);
    controller_real_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/PHA' */
    controller_real_DW.obj_d.matlabCodegenIsDeleted = false;
    controller_real_DW.objisempty_k = true;
    controller_real_DW.obj_d.isInitialized = 1;
    pinname = D3;
    controller_real_DW.obj_d.MW_DIGITALIO_HANDLE = MW_digitalIO_open(pinname, 1);
    controller_real_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/PWDA' */
    controller_real_DW.obj_p.matlabCodegenIsDeleted = false;
    controller_real_DW.objisempty = true;
    controller_real_DW.obj_p.isInitialized = 1;
    pinname = D5;
    controller_real_DW.obj_p.MW_PWM_HANDLE = MW_PWM_Open(pinname, 5000.0, 0.0);
    MW_PWM_Start(controller_real_DW.obj_p.MW_PWM_HANDLE);
    controller_real_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/ENA' */
    controller_real_DW.obj_nf.matlabCodegenIsDeleted = false;
    controller_real_DW.objisempty_i = true;
    controller_real_DW.obj_nf.isInitialized = 1;
    pinname = D2;
    controller_real_DW.obj_nf.MW_DIGITALIO_HANDLE = MW_digitalIO_open(pinname, 1);
    controller_real_DW.obj_nf.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/ENB' */
    controller_real_DW.obj_e.matlabCodegenIsDeleted = false;
    controller_real_DW.objisempty_l = true;
    controller_real_DW.obj_e.isInitialized = 1;
    pinname = D11;
    controller_real_DW.obj_e.MW_DIGITALIO_HANDLE = MW_digitalIO_open(pinname, 1);
    controller_real_DW.obj_e.isSetupComplete = true;
  }

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay1' */
  controller_real_DW.UnitDelay1_DSTATE[0] =
    controller_real_P.UnitDelay1_InitialCondition;
  controller_real_DW.UnitDelay1_DSTATE[1] =
    controller_real_P.UnitDelay1_InitialCondition;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  controller_real_DW.UnitDelay_DSTATE =
    controller_real_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay2' */
  controller_real_DW.UnitDelay2_DSTATE =
    controller_real_P.UnitDelay2_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
  controller_real_DW.UnitDelay_DSTATE_a =
    controller_real_P.UnitDelay_InitialCondition_b;

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay1' */
  controller_real_DW.UnitDelay1_DSTATE_n =
    controller_real_P.UnitDelay1_InitialCondition_n;

  /* InitializeConditions for UnitDelay: '<S4>/UD' */
  controller_real_DW.UD_DSTATE =
    controller_real_P.DiscreteDerivative_ICPrevScaled;
}

/* Model terminate function */
void controller_real_terminate(void)
{
  /* Terminate for MATLABSystem: '<S2>/Encoder A' */
  if (!controller_real_DW.obj_n.matlabCodegenIsDeleted) {
    controller_real_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((controller_real_DW.obj_n.isInitialized == 1) &&
        controller_real_DW.obj_n.isSetupComplete) {
      MW_digitalIO_close(controller_real_DW.obj_n.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Encoder A' */

  /* Terminate for MATLABSystem: '<S2>/Encoder B' */
  if (!controller_real_DW.obj.matlabCodegenIsDeleted) {
    controller_real_DW.obj.matlabCodegenIsDeleted = true;
    if ((controller_real_DW.obj.isInitialized == 1) &&
        controller_real_DW.obj.isSetupComplete) {
      MW_digitalIO_close(controller_real_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Encoder B' */
  /* Terminate for MATLABSystem: '<S2>/PHA' */
  if (!controller_real_DW.obj_d.matlabCodegenIsDeleted) {
    controller_real_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((controller_real_DW.obj_d.isInitialized == 1) &&
        controller_real_DW.obj_d.isSetupComplete) {
      MW_digitalIO_close(controller_real_DW.obj_d.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PHA' */

  /* Terminate for MATLABSystem: '<S2>/PWDA' */
  if (!controller_real_DW.obj_p.matlabCodegenIsDeleted) {
    controller_real_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((controller_real_DW.obj_p.isInitialized == 1) &&
        controller_real_DW.obj_p.isSetupComplete) {
      MW_PWM_Stop(controller_real_DW.obj_p.MW_PWM_HANDLE);
      MW_PWM_Close(controller_real_DW.obj_p.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PWDA' */

  /* Terminate for MATLABSystem: '<S2>/ENA' */
  if (!controller_real_DW.obj_nf.matlabCodegenIsDeleted) {
    controller_real_DW.obj_nf.matlabCodegenIsDeleted = true;
    if ((controller_real_DW.obj_nf.isInitialized == 1) &&
        controller_real_DW.obj_nf.isSetupComplete) {
      MW_digitalIO_close(controller_real_DW.obj_nf.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/ENA' */

  /* Terminate for MATLABSystem: '<S2>/ENB' */
  if (!controller_real_DW.obj_e.matlabCodegenIsDeleted) {
    controller_real_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((controller_real_DW.obj_e.isInitialized == 1) &&
        controller_real_DW.obj_e.isSetupComplete) {
      MW_digitalIO_close(controller_real_DW.obj_e.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/ENB' */
}
