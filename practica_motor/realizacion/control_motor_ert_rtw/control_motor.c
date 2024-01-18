/*
 * control_motor.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "control_motor".
 *
 * Model version              : 1.1
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Wed Jan 17 11:10:52 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "control_motor.h"
#include "rtwtypes.h"
#include <math.h>
#include "control_motor_private.h"
#include <string.h>

/* Block signals (default storage) */
B_control_motor_T control_motor_B;

/* Block states (default storage) */
DW_control_motor_T control_motor_DW;

/* Real-time model */
static RT_MODEL_control_motor_T control_motor_M_;
RT_MODEL_control_motor_T *const control_motor_M = &control_motor_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void control_motor_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(control_motor_M, 1));
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
  control_motor_M->Timing.RateInteraction.TID0_1 =
    (control_motor_M->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (control_motor_M->Timing.TaskCounters.TID[1])++;
  if ((control_motor_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [0.01s, 0.0s] */
    control_motor_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void control_motor_step0(void)         /* Sample time: [0.0001s, 0.0s] */
{
  real_T rtb_DirectLookupTablenD;
  real_T rtb_Sum4;

  {                                    /* Sample time: [0.0001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* UnitDelay: '<S3>/Unit Delay2' */
  control_motor_B.UnitDelay2 = control_motor_DW.UnitDelay2_DSTATE;

  /* Sum: '<Root>/Sum4' incorporates:
   *  Constant: '<Root>/Consigna'
   *  Gain: '<Root>/Gain'
   *  Gain: '<Root>/Gain3'
   *  Gain: '<Root>/acción directa'
   *  Sum: '<Root>/Sum1'
   *  UnitDelay: '<Root>/Unit Delay'
   */
  rtb_Sum4 = (control_motor_P.accindirecta_Gain * control_motor_P.Consigna_Value
              - control_motor_P.Kid[2] * control_motor_DW.UnitDelay_DSTATE) -
    (control_motor_P.Kid[0] * control_motor_DW.UnitDelay1_DSTATE[0] +
     control_motor_P.Kid[1] * control_motor_DW.UnitDelay1_DSTATE[1]);

  /* Sum: '<Root>/Sum' incorporates:
   *  Gain: '<Root>/Gain1'
   *  Gain: '<Root>/Gain2'
   *  Gain: '<Root>/Gain4'
   */
  control_motor_B.Sum[0] = (control_motor_P.Ld[0] * control_motor_B.UnitDelay2 +
    control_motor_P.Gain1_Gain[0] * rtb_Sum4) + (control_motor_P.Gain4_Gain[0] *
    control_motor_DW.UnitDelay1_DSTATE[0] + control_motor_DW.UnitDelay1_DSTATE[1]
    * control_motor_P.Gain4_Gain[2]);
  control_motor_B.Sum[1] = (control_motor_P.Ld[1] * control_motor_B.UnitDelay2 +
    control_motor_P.Gain1_Gain[1] * rtb_Sum4) +
    (control_motor_DW.UnitDelay1_DSTATE[0] * control_motor_P.Gain4_Gain[1] +
     control_motor_DW.UnitDelay1_DSTATE[1] * control_motor_P.Gain4_Gain[3]);

  /* ZeroOrderHold: '<Root>/Zero-Order Hold1' */
  control_motor_B.ZeroOrderHold1 = rtb_Sum4;

  /* Gain: '<Root>/Gain6' */
  rtb_DirectLookupTablenD = control_motor_P.Gain6_Gain *
    control_motor_B.ZeroOrderHold1;

  /* MATLABSystem: '<S2>/PHA' incorporates:
   *  Constant: '<S1>/Constant'
   *  RelationalOperator: '<S1>/Compare'
   */
  MW_digitalIO_write(control_motor_DW.obj_o.MW_DIGITALIO_HANDLE,
                     rtb_DirectLookupTablenD >= control_motor_P.Constant_Value);

  /* MATLABSystem: '<S2>/PWDA' incorporates:
   *  Abs: '<Root>/Abs'
   */
  MW_PWM_SetDutyCycle(control_motor_DW.obj_a.MW_PWM_HANDLE, fabs
                      (rtb_DirectLookupTablenD));

  /* ZeroOrderHold: '<S3>/Zero-Order Hold' */
  if (control_motor_M->Timing.RateInteraction.TID0_1) {
    /* ZeroOrderHold: '<S3>/Zero-Order Hold' */
    control_motor_B.ZeroOrderHold = control_motor_B.UnitDelay2;
  }

  /* End of ZeroOrderHold: '<S3>/Zero-Order Hold' */

  /* MATLABSystem: '<S2>/EncoderA' */
  if (control_motor_DW.obj_d.SampleTime != control_motor_P.EncoderA_SampleTime)
  {
    control_motor_DW.obj_d.SampleTime = control_motor_P.EncoderA_SampleTime;
  }

  /* MATLABSystem: '<S2>/EncoderA' */
  control_motor_B.EncoderA = MW_digitalIO_read
    (control_motor_DW.obj_d.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<S2>/EncoderB' */
  if (control_motor_DW.obj.SampleTime != control_motor_P.EncoderB_SampleTime) {
    control_motor_DW.obj.SampleTime = control_motor_P.EncoderB_SampleTime;
  }

  /* MATLABSystem: '<S2>/EncoderB' */
  control_motor_B.EncoderB = MW_digitalIO_read
    (control_motor_DW.obj.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<S2>/ENA' incorporates:
   *  Constant: '<S2>/Constant'
   */
  MW_digitalIO_write(control_motor_DW.obj_j.MW_DIGITALIO_HANDLE,
                     control_motor_P.Constant_Value_d != 0.0);

  /* MATLABSystem: '<S2>/ENB' incorporates:
   *  Constant: '<S2>/Constant1'
   */
  MW_digitalIO_write(control_motor_DW.obj_b.MW_DIGITALIO_HANDLE,
                     control_motor_P.Constant1_Value != 0.0);

  /* Update for UnitDelay: '<Root>/Unit Delay1' */
  control_motor_DW.UnitDelay1_DSTATE[0] = control_motor_B.Sum[0];
  control_motor_DW.UnitDelay1_DSTATE[1] = control_motor_B.Sum[1];

  /* LookupNDDirect: '<S3>/Direct Lookup Table (n-D)' incorporates:
   *  Gain: '<S3>/Gain'
   *  Gain: '<S3>/Gain1'
   *  Gain: '<S3>/Gain2'
   *  Gain: '<S3>/Gain3'
   *  Sum: '<S3>/Add'
   *  UnitDelay: '<S3>/Unit Delay'
   *  UnitDelay: '<S3>/Unit Delay1'
   *
   * About '<S3>/Direct Lookup Table (n-D)':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  rtb_DirectLookupTablenD = (((real_T)(control_motor_DW.UnitDelay_DSTATE_a ?
    (int32_T)control_motor_P.Gain_Gain : 0) * 0.0625 + (real_T)
    (control_motor_B.EncoderA ? (int32_T)control_motor_P.Gain1_Gain_h : 0) *
    0.03125) + (real_T)(control_motor_DW.UnitDelay1_DSTATE_e ? (int32_T)
                        control_motor_P.Gain2_Gain : 0) * 0.015625) + (real_T)
    (control_motor_B.EncoderB ? (int32_T)control_motor_P.Gain3_Gain : 0) *
    0.0078125;
  if (rtb_DirectLookupTablenD > 15.0) {
    rtb_DirectLookupTablenD = 15.0;
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
  control_motor_DW.UnitDelay2_DSTATE =
    control_motor_P.DirectLookupTablenD_table[(int32_T)rtb_DirectLookupTablenD]
    + control_motor_B.UnitDelay2;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Sum4 > control_motor_P.Saturation_UpperSat) {
    rtb_DirectLookupTablenD = control_motor_P.Saturation_UpperSat;
  } else if (rtb_Sum4 < control_motor_P.Saturation_LowerSat) {
    rtb_DirectLookupTablenD = control_motor_P.Saturation_LowerSat;
  } else {
    rtb_DirectLookupTablenD = rtb_Sum4;
  }

  /* Update for UnitDelay: '<Root>/Unit Delay' incorporates:
   *  Constant: '<Root>/Consigna'
   *  Gain: '<Root>/Gain10'
   *  Gain: '<Root>/Gain5'
   *  Gain: '<Root>/kamp'
   *  Saturate: '<Root>/Saturation'
   *  Sum: '<Root>/Sum2'
   *  Sum: '<Root>/Sum3'
   *  Sum: '<Root>/Sum5'
   */
  control_motor_DW.UnitDelay_DSTATE = ((control_motor_B.UnitDelay2 -
    (rtb_DirectLookupTablenD - rtb_Sum4) * control_motor_P.kamp_Gain) -
    control_motor_P.Consigna_Value) * control_motor_P.T +
    control_motor_P.Gain10_Gain * control_motor_DW.UnitDelay_DSTATE;

  /* Update for UnitDelay: '<S3>/Unit Delay' */
  control_motor_DW.UnitDelay_DSTATE_a = control_motor_B.EncoderA;

  /* Update for UnitDelay: '<S3>/Unit Delay1' */
  control_motor_DW.UnitDelay1_DSTATE_e = control_motor_B.EncoderB;

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++control_motor_M->Timing.clockTick0)) {
    ++control_motor_M->Timing.clockTickH0;
  }

  control_motor_M->Timing.taskTime0 = control_motor_M->Timing.clockTick0 *
    control_motor_M->Timing.stepSize0 + control_motor_M->Timing.clockTickH0 *
    control_motor_M->Timing.stepSize0 * 4294967296.0;
}

/* Model step function for TID1 */
void control_motor_step1(void)         /* Sample time: [0.01s, 0.0s] */
{
  real_T rtb_TSamp;

  /* SampleTimeMath: '<S4>/TSamp'
   *
   * About '<S4>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp = control_motor_B.ZeroOrderHold * control_motor_P.TSamp_WtEt;

  /* Sum: '<S4>/Diff' incorporates:
   *  UnitDelay: '<S4>/UD'
   */
  control_motor_B.Diff = rtb_TSamp - control_motor_DW.UD_DSTATE;

  /* Update for UnitDelay: '<S4>/UD' */
  control_motor_DW.UD_DSTATE = rtb_TSamp;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  control_motor_M->Timing.clockTick1++;
  if (!control_motor_M->Timing.clockTick1) {
    control_motor_M->Timing.clockTickH1++;
  }
}

/* Model initialize function */
void control_motor_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)control_motor_M, 0,
                sizeof(RT_MODEL_control_motor_T));
  rtmSetTFinal(control_motor_M, 5.0);
  control_motor_M->Timing.stepSize0 = 0.0001;

  /* External mode info */
  control_motor_M->Sizes.checksums[0] = (3970213450U);
  control_motor_M->Sizes.checksums[1] = (4080136491U);
  control_motor_M->Sizes.checksums[2] = (1184972306U);
  control_motor_M->Sizes.checksums[3] = (2420107778U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    control_motor_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(control_motor_M->extModeInfo,
      &control_motor_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(control_motor_M->extModeInfo,
                        control_motor_M->Sizes.checksums);
    rteiSetTPtr(control_motor_M->extModeInfo, rtmGetTPtr(control_motor_M));
  }

  /* block I/O */
  (void) memset(((void *) &control_motor_B), 0,
                sizeof(B_control_motor_T));

  /* states (dwork) */
  (void) memset((void *)&control_motor_DW, 0,
                sizeof(DW_control_motor_T));

  {
    uint32_T pinname;

    /* Start for MATLABSystem: '<S2>/PHA' */
    control_motor_DW.obj_o.matlabCodegenIsDeleted = false;
    control_motor_DW.objisempty_h = true;
    control_motor_DW.obj_o.isInitialized = 1;
    pinname = D3;
    control_motor_DW.obj_o.MW_DIGITALIO_HANDLE = MW_digitalIO_open(pinname, 1);
    control_motor_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/PWDA' */
    control_motor_DW.obj_a.matlabCodegenIsDeleted = false;
    control_motor_DW.objisempty = true;
    control_motor_DW.obj_a.isInitialized = 1;
    pinname = D5;
    control_motor_DW.obj_a.MW_PWM_HANDLE = MW_PWM_Open(pinname, 5000.0, 0.0);
    MW_PWM_Start(control_motor_DW.obj_a.MW_PWM_HANDLE);
    control_motor_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/EncoderA' */
    control_motor_DW.obj_d.matlabCodegenIsDeleted = false;
    control_motor_DW.objisempty_f = true;
    control_motor_DW.obj_d.SampleTime = control_motor_P.EncoderA_SampleTime;
    control_motor_DW.obj_d.isInitialized = 1;
    pinname = A1;
    control_motor_DW.obj_d.MW_DIGITALIO_HANDLE = MW_digitalIO_open(pinname, 0);
    control_motor_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/EncoderB' */
    control_motor_DW.obj.matlabCodegenIsDeleted = false;
    control_motor_DW.objisempty_k = true;
    control_motor_DW.obj.SampleTime = control_motor_P.EncoderB_SampleTime;
    control_motor_DW.obj.isInitialized = 1;
    pinname = A0;
    control_motor_DW.obj.MW_DIGITALIO_HANDLE = MW_digitalIO_open(pinname, 0);
    control_motor_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/ENA' */
    control_motor_DW.obj_j.matlabCodegenIsDeleted = false;
    control_motor_DW.objisempty_j = true;
    control_motor_DW.obj_j.isInitialized = 1;
    pinname = D2;
    control_motor_DW.obj_j.MW_DIGITALIO_HANDLE = MW_digitalIO_open(pinname, 1);
    control_motor_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/ENB' */
    control_motor_DW.obj_b.matlabCodegenIsDeleted = false;
    control_motor_DW.objisempty_e = true;
    control_motor_DW.obj_b.isInitialized = 1;
    pinname = D11;
    control_motor_DW.obj_b.MW_DIGITALIO_HANDLE = MW_digitalIO_open(pinname, 1);
    control_motor_DW.obj_b.isSetupComplete = true;
  }

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay1' */
  control_motor_DW.UnitDelay1_DSTATE[0] =
    control_motor_P.UnitDelay1_InitialCondition;
  control_motor_DW.UnitDelay1_DSTATE[1] =
    control_motor_P.UnitDelay1_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay2' */
  control_motor_DW.UnitDelay2_DSTATE =
    control_motor_P.UnitDelay2_InitialCondition;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  control_motor_DW.UnitDelay_DSTATE = control_motor_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
  control_motor_DW.UnitDelay_DSTATE_a =
    control_motor_P.UnitDelay_InitialCondition_f;

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay1' */
  control_motor_DW.UnitDelay1_DSTATE_e =
    control_motor_P.UnitDelay1_InitialCondition_g;

  /* InitializeConditions for UnitDelay: '<S4>/UD' */
  control_motor_DW.UD_DSTATE = control_motor_P.DiscreteDerivative_ICPrevScaled;
}

/* Model terminate function */
void control_motor_terminate(void)
{
  /* Terminate for MATLABSystem: '<S2>/PHA' */
  if (!control_motor_DW.obj_o.matlabCodegenIsDeleted) {
    control_motor_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((control_motor_DW.obj_o.isInitialized == 1) &&
        control_motor_DW.obj_o.isSetupComplete) {
      MW_digitalIO_close(control_motor_DW.obj_o.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PHA' */

  /* Terminate for MATLABSystem: '<S2>/PWDA' */
  if (!control_motor_DW.obj_a.matlabCodegenIsDeleted) {
    control_motor_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((control_motor_DW.obj_a.isInitialized == 1) &&
        control_motor_DW.obj_a.isSetupComplete) {
      MW_PWM_Stop(control_motor_DW.obj_a.MW_PWM_HANDLE);
      MW_PWM_Close(control_motor_DW.obj_a.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PWDA' */
  /* Terminate for MATLABSystem: '<S2>/EncoderA' */
  if (!control_motor_DW.obj_d.matlabCodegenIsDeleted) {
    control_motor_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((control_motor_DW.obj_d.isInitialized == 1) &&
        control_motor_DW.obj_d.isSetupComplete) {
      MW_digitalIO_close(control_motor_DW.obj_d.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/EncoderA' */

  /* Terminate for MATLABSystem: '<S2>/EncoderB' */
  if (!control_motor_DW.obj.matlabCodegenIsDeleted) {
    control_motor_DW.obj.matlabCodegenIsDeleted = true;
    if ((control_motor_DW.obj.isInitialized == 1) &&
        control_motor_DW.obj.isSetupComplete) {
      MW_digitalIO_close(control_motor_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/EncoderB' */
  /* Terminate for MATLABSystem: '<S2>/ENA' */
  if (!control_motor_DW.obj_j.matlabCodegenIsDeleted) {
    control_motor_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((control_motor_DW.obj_j.isInitialized == 1) &&
        control_motor_DW.obj_j.isSetupComplete) {
      MW_digitalIO_close(control_motor_DW.obj_j.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/ENA' */

  /* Terminate for MATLABSystem: '<S2>/ENB' */
  if (!control_motor_DW.obj_b.matlabCodegenIsDeleted) {
    control_motor_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((control_motor_DW.obj_b.isInitialized == 1) &&
        control_motor_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close(control_motor_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/ENB' */
}
