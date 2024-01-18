/*
 * motor_real.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "motor_real".
 *
 * Model version              : 1.7
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Wed Jan 17 11:21:08 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "motor_real.h"
#include "rtwtypes.h"
#include <string.h>
#include "motor_real_private.h"

/* Block signals (default storage) */
B_motor_real_T motor_real_B;

/* Block states (default storage) */
DW_motor_real_T motor_real_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_motor_real_T motor_real_Y;

/* Real-time model */
static RT_MODEL_motor_real_T motor_real_M_;
RT_MODEL_motor_real_T *const motor_real_M = &motor_real_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void motor_real_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(motor_real_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(motor_real_M, 2));
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
  motor_real_M->Timing.RateInteraction.TID0_1 =
    (motor_real_M->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (motor_real_M->Timing.TaskCounters.TID[1])++;
  if ((motor_real_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [0.01s, 0.0s] */
    motor_real_M->Timing.TaskCounters.TID[1] = 0;
  }

  (motor_real_M->Timing.TaskCounters.TID[2])++;
  if ((motor_real_M->Timing.TaskCounters.TID[2]) > 999) {/* Sample time: [0.1s, 0.0s] */
    motor_real_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Model step function for TID0 */
void motor_real_step0(void)            /* Sample time: [0.0001s, 0.0s] */
{
  real_T u0;

  {                                    /* Sample time: [0.0001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* UnitDelay: '<S2>/Unit Delay2' */
  motor_real_B.UnitDelay2 = motor_real_DW.UnitDelay2_DSTATE;

  /* Outport: '<Root>/p (deg)' */
  motor_real_Y.pdeg = motor_real_B.UnitDelay2;

  /* ZeroOrderHold: '<S2>/Zero-Order Hold' */
  if (motor_real_M->Timing.RateInteraction.TID0_1) {
    /* ZeroOrderHold: '<S2>/Zero-Order Hold' */
    motor_real_B.ZeroOrderHold = motor_real_B.UnitDelay2;
  }

  /* End of ZeroOrderHold: '<S2>/Zero-Order Hold' */

  /* MATLABSystem: '<S1>/Encoder A' */
  if (motor_real_DW.obj_k.SampleTime != motor_real_P.EncoderA_SampleTime) {
    motor_real_DW.obj_k.SampleTime = motor_real_P.EncoderA_SampleTime;
  }

  /* MATLABSystem: '<S1>/Encoder A' */
  motor_real_B.EncoderA = MW_digitalIO_read
    (motor_real_DW.obj_k.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<S1>/Encoder B' */
  if (motor_real_DW.obj.SampleTime != motor_real_P.EncoderB_SampleTime) {
    motor_real_DW.obj.SampleTime = motor_real_P.EncoderB_SampleTime;
  }

  /* MATLABSystem: '<S1>/Encoder B' */
  motor_real_B.EncoderB = MW_digitalIO_read
    (motor_real_DW.obj.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<S1>/PHA' incorporates:
   *  Constant: '<Root>/giro'
   */
  MW_digitalIO_write(motor_real_DW.obj_i.MW_DIGITALIO_HANDLE,
                     motor_real_P.giro_Value != 0.0);

  /* MATLABSystem: '<S1>/ENA' incorporates:
   *  Constant: '<S1>/Constant'
   */
  MW_digitalIO_write(motor_real_DW.obj_m.MW_DIGITALIO_HANDLE,
                     motor_real_P.Constant_Value != 0.0);

  /* MATLABSystem: '<S1>/ENB' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  MW_digitalIO_write(motor_real_DW.obj_ii.MW_DIGITALIO_HANDLE,
                     motor_real_P.Constant1_Value != 0.0);

  /* LookupNDDirect: '<S2>/Direct Lookup Table (n-D)' incorporates:
   *  Gain: '<S2>/Gain'
   *  Gain: '<S2>/Gain1'
   *  Gain: '<S2>/Gain2'
   *  Gain: '<S2>/Gain3'
   *  Sum: '<S2>/Add'
   *  UnitDelay: '<S2>/Unit Delay'
   *  UnitDelay: '<S2>/Unit Delay1'
   *
   * About '<S2>/Direct Lookup Table (n-D)':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  u0 = (((real_T)(motor_real_DW.UnitDelay_DSTATE ? (int32_T)
                  motor_real_P.Gain_Gain : 0) * 0.0625 + (real_T)
         (motor_real_B.EncoderA ? (int32_T)motor_real_P.Gain1_Gain : 0) *
         0.03125) + (real_T)(motor_real_DW.UnitDelay1_DSTATE ? (int32_T)
         motor_real_P.Gain2_Gain : 0) * 0.015625) + (real_T)
    (motor_real_B.EncoderB ? (int32_T)motor_real_P.Gain3_Gain : 0) * 0.0078125;
  if (u0 > 15.0) {
    u0 = 15.0;
  }

  /* Update for UnitDelay: '<S2>/Unit Delay2' incorporates:
   *  LookupNDDirect: '<S2>/Direct Lookup Table (n-D)'
   *  Sum: '<S2>/Sum'
   *
   * About '<S2>/Direct Lookup Table (n-D)':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  motor_real_DW.UnitDelay2_DSTATE = motor_real_P.DirectLookupTablenD_table
    [(int32_T)u0] + motor_real_B.UnitDelay2;

  /* Update for UnitDelay: '<S2>/Unit Delay' */
  motor_real_DW.UnitDelay_DSTATE = motor_real_B.EncoderA;

  /* Update for UnitDelay: '<S2>/Unit Delay1' */
  motor_real_DW.UnitDelay1_DSTATE = motor_real_B.EncoderB;

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++motor_real_M->Timing.clockTick0)) {
    ++motor_real_M->Timing.clockTickH0;
  }

  motor_real_M->Timing.taskTime0 = motor_real_M->Timing.clockTick0 *
    motor_real_M->Timing.stepSize0 + motor_real_M->Timing.clockTickH0 *
    motor_real_M->Timing.stepSize0 * 4294967296.0;
}

/* Model step function for TID1 */
void motor_real_step1(void)            /* Sample time: [0.01s, 0.0s] */
{
  real_T rtb_TSamp;

  /* SampleTimeMath: '<S3>/TSamp'
   *
   * About '<S3>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp = motor_real_B.ZeroOrderHold * motor_real_P.TSamp_WtEt;

  /* Sum: '<S3>/Diff' incorporates:
   *  UnitDelay: '<S3>/UD'
   */
  motor_real_B.Diff = rtb_TSamp - motor_real_DW.UD_DSTATE;

  /* Outport: '<Root>/v (deg//s)' */
  motor_real_Y.vdegs = motor_real_B.Diff;

  /* Update for UnitDelay: '<S3>/UD' */
  motor_real_DW.UD_DSTATE = rtb_TSamp;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  motor_real_M->Timing.clockTick1++;
  if (!motor_real_M->Timing.clockTick1) {
    motor_real_M->Timing.clockTickH1++;
  }
}

/* Model step function for TID2 */
void motor_real_step2(void)            /* Sample time: [0.1s, 0.0s] */
{
  real_T tmp;

  /* Step: '<Root>/Step' */
  if ((((motor_real_M->Timing.clockTick2+motor_real_M->Timing.clockTickH2*
         4294967296.0)) * 0.1) < motor_real_P.Step_Time) {
    tmp = motor_real_P.Step_Y0;
  } else {
    tmp = motor_real_P.Step_YFinal;
  }

  /* MATLABSystem: '<S1>/PWDA' incorporates:
   *  Step: '<Root>/Step'
   */
  MW_PWM_SetDutyCycle(motor_real_DW.obj_l.MW_PWM_HANDLE, tmp);

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  motor_real_M->Timing.clockTick2++;
  if (!motor_real_M->Timing.clockTick2) {
    motor_real_M->Timing.clockTickH2++;
  }
}

/* Model initialize function */
void motor_real_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)motor_real_M, 0,
                sizeof(RT_MODEL_motor_real_T));
  rtmSetTFinal(motor_real_M, 5.0);
  motor_real_M->Timing.stepSize0 = 0.0001;

  /* External mode info */
  motor_real_M->Sizes.checksums[0] = (509553799U);
  motor_real_M->Sizes.checksums[1] = (2478466033U);
  motor_real_M->Sizes.checksums[2] = (148540425U);
  motor_real_M->Sizes.checksums[3] = (2072131447U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    motor_real_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(motor_real_M->extModeInfo,
      &motor_real_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(motor_real_M->extModeInfo, motor_real_M->Sizes.checksums);
    rteiSetTPtr(motor_real_M->extModeInfo, rtmGetTPtr(motor_real_M));
  }

  /* block I/O */
  (void) memset(((void *) &motor_real_B), 0,
                sizeof(B_motor_real_T));

  /* states (dwork) */
  (void) memset((void *)&motor_real_DW, 0,
                sizeof(DW_motor_real_T));

  /* external outputs */
  (void)memset(&motor_real_Y, 0, sizeof(ExtY_motor_real_T));

  {
    uint32_T pinname;

    /* Start for MATLABSystem: '<S1>/Encoder A' */
    motor_real_DW.obj_k.matlabCodegenIsDeleted = false;
    motor_real_DW.objisempty_n = true;
    motor_real_DW.obj_k.SampleTime = motor_real_P.EncoderA_SampleTime;
    motor_real_DW.obj_k.isInitialized = 1;
    pinname = A1;
    motor_real_DW.obj_k.MW_DIGITALIO_HANDLE = MW_digitalIO_open(pinname, 0);
    motor_real_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Encoder B' */
    motor_real_DW.obj.matlabCodegenIsDeleted = false;
    motor_real_DW.objisempty_f = true;
    motor_real_DW.obj.SampleTime = motor_real_P.EncoderB_SampleTime;
    motor_real_DW.obj.isInitialized = 1;
    pinname = A0;
    motor_real_DW.obj.MW_DIGITALIO_HANDLE = MW_digitalIO_open(pinname, 0);
    motor_real_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PHA' */
    motor_real_DW.obj_i.matlabCodegenIsDeleted = false;
    motor_real_DW.objisempty_b = true;
    motor_real_DW.obj_i.isInitialized = 1;
    pinname = D3;
    motor_real_DW.obj_i.MW_DIGITALIO_HANDLE = MW_digitalIO_open(pinname, 1);
    motor_real_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/ENA' */
    motor_real_DW.obj_m.matlabCodegenIsDeleted = false;
    motor_real_DW.objisempty_d = true;
    motor_real_DW.obj_m.isInitialized = 1;
    pinname = D2;
    motor_real_DW.obj_m.MW_DIGITALIO_HANDLE = MW_digitalIO_open(pinname, 1);
    motor_real_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/ENB' */
    motor_real_DW.obj_ii.matlabCodegenIsDeleted = false;
    motor_real_DW.objisempty_g = true;
    motor_real_DW.obj_ii.isInitialized = 1;
    pinname = D11;
    motor_real_DW.obj_ii.MW_DIGITALIO_HANDLE = MW_digitalIO_open(pinname, 1);
    motor_real_DW.obj_ii.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PWDA' */
    motor_real_DW.obj_l.matlabCodegenIsDeleted = false;
    motor_real_DW.objisempty = true;
    motor_real_DW.obj_l.isInitialized = 1;
    pinname = D5;
    motor_real_DW.obj_l.MW_PWM_HANDLE = MW_PWM_Open(pinname, 5000.0, 0.0);
    MW_PWM_Start(motor_real_DW.obj_l.MW_PWM_HANDLE);
    motor_real_DW.obj_l.isSetupComplete = true;
  }

  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay2' */
  motor_real_DW.UnitDelay2_DSTATE = motor_real_P.UnitDelay2_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay' */
  motor_real_DW.UnitDelay_DSTATE = motor_real_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay1' */
  motor_real_DW.UnitDelay1_DSTATE = motor_real_P.UnitDelay1_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S3>/UD' */
  motor_real_DW.UD_DSTATE = motor_real_P.DiscreteDerivative_ICPrevScaled;
}

/* Model terminate function */
void motor_real_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/Encoder A' */
  if (!motor_real_DW.obj_k.matlabCodegenIsDeleted) {
    motor_real_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((motor_real_DW.obj_k.isInitialized == 1) &&
        motor_real_DW.obj_k.isSetupComplete) {
      MW_digitalIO_close(motor_real_DW.obj_k.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Encoder A' */

  /* Terminate for MATLABSystem: '<S1>/Encoder B' */
  if (!motor_real_DW.obj.matlabCodegenIsDeleted) {
    motor_real_DW.obj.matlabCodegenIsDeleted = true;
    if ((motor_real_DW.obj.isInitialized == 1) &&
        motor_real_DW.obj.isSetupComplete) {
      MW_digitalIO_close(motor_real_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Encoder B' */
  /* Terminate for MATLABSystem: '<S1>/PHA' */
  if (!motor_real_DW.obj_i.matlabCodegenIsDeleted) {
    motor_real_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((motor_real_DW.obj_i.isInitialized == 1) &&
        motor_real_DW.obj_i.isSetupComplete) {
      MW_digitalIO_close(motor_real_DW.obj_i.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PHA' */

  /* Terminate for MATLABSystem: '<S1>/ENA' */
  if (!motor_real_DW.obj_m.matlabCodegenIsDeleted) {
    motor_real_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((motor_real_DW.obj_m.isInitialized == 1) &&
        motor_real_DW.obj_m.isSetupComplete) {
      MW_digitalIO_close(motor_real_DW.obj_m.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/ENA' */

  /* Terminate for MATLABSystem: '<S1>/ENB' */
  if (!motor_real_DW.obj_ii.matlabCodegenIsDeleted) {
    motor_real_DW.obj_ii.matlabCodegenIsDeleted = true;
    if ((motor_real_DW.obj_ii.isInitialized == 1) &&
        motor_real_DW.obj_ii.isSetupComplete) {
      MW_digitalIO_close(motor_real_DW.obj_ii.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/ENB' */
  /* Terminate for MATLABSystem: '<S1>/PWDA' */
  if (!motor_real_DW.obj_l.matlabCodegenIsDeleted) {
    motor_real_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((motor_real_DW.obj_l.isInitialized == 1) &&
        motor_real_DW.obj_l.isSetupComplete) {
      MW_PWM_Stop(motor_real_DW.obj_l.MW_PWM_HANDLE);
      MW_PWM_Close(motor_real_DW.obj_l.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWDA' */
}
