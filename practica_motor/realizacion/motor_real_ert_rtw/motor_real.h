/*
 * motor_real.h
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

#ifndef RTW_HEADER_motor_real_h_
#define RTW_HEADER_motor_real_h_
#ifndef motor_real_COMMON_INCLUDES_
#define motor_real_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_MbedPinInterface.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#endif                                 /* motor_real_COMMON_INCLUDES_ */

#include "motor_real_types.h"
#include <string.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T UnitDelay2;                   /* '<S2>/Unit Delay2' */
  real_T ZeroOrderHold;                /* '<S2>/Zero-Order Hold' */
  real_T Diff;                         /* '<S3>/Diff' */
  boolean_T EncoderB;                  /* '<S1>/Encoder B' */
  boolean_T EncoderA;                  /* '<S1>/Encoder A' */
} B_motor_real_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  mbed_DigitalRead_motor_real_T obj;   /* '<S1>/Encoder B' */
  mbed_DigitalRead_motor_real_T obj_k; /* '<S1>/Encoder A' */
  mbed_DigitalWrite_motor_real_T obj_i;/* '<S1>/PHA' */
  mbed_DigitalWrite_motor_real_T obj_ii;/* '<S1>/ENB' */
  mbed_DigitalWrite_motor_real_T obj_m;/* '<S1>/ENA' */
  mbed_PWMOutput_motor_real_T obj_l;   /* '<S1>/PWDA' */
  real_T UnitDelay2_DSTATE;            /* '<S2>/Unit Delay2' */
  real_T UD_DSTATE;                    /* '<S3>/UD' */
  boolean_T UnitDelay_DSTATE;          /* '<S2>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE;         /* '<S2>/Unit Delay1' */
  boolean_T objisempty;                /* '<S1>/PWDA' */
  boolean_T objisempty_b;              /* '<S1>/PHA' */
  boolean_T objisempty_f;              /* '<S1>/Encoder B' */
  boolean_T objisempty_n;              /* '<S1>/Encoder A' */
  boolean_T objisempty_g;              /* '<S1>/ENB' */
  boolean_T objisempty_d;              /* '<S1>/ENA' */
} DW_motor_real_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T pdeg;                         /* '<Root>/p (deg)' */
  real_T vdegs;                        /* '<Root>/v (deg//s)' */
} ExtY_motor_real_T;

/* Parameters (default storage) */
struct P_motor_real_T_ {
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S3>/UD'
                               */
  real_T EncoderA_SampleTime;          /* Expression: 0.0001
                                        * Referenced by: '<S1>/Encoder A'
                                        */
  real_T EncoderB_SampleTime;          /* Expression: 0.0001
                                        * Referenced by: '<S1>/Encoder B'
                                        */
  real_T UnitDelay2_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S2>/Unit Delay2'
                                        */
  real_T DirectLookupTablenD_table[16];
                            /* Expression: [0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0]
                             * Referenced by: '<S2>/Direct Lookup Table (n-D)'
                             */
  real_T giro_Value;                   /* Expression: 0
                                        * Referenced by: '<Root>/giro'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S3>/TSamp'
                                        */
  real_T Step_Time;                    /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 60
                                        * Referenced by: '<Root>/Step'
                                        */
  boolean_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S2>/Unit Delay'
                                */
  boolean_T UnitDelay1_InitialCondition;
                              /* Computed Parameter: UnitDelay1_InitialCondition
                               * Referenced by: '<S2>/Unit Delay1'
                               */
  uint8_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S2>/Gain'
                                        */
  uint8_T Gain1_Gain;                  /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S2>/Gain1'
                                        */
  uint8_T Gain2_Gain;                  /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S2>/Gain2'
                                        */
  uint8_T Gain3_Gain;                  /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S2>/Gain3'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_motor_real_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
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
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    uint32_T clockTick2;
    uint32_T clockTickH2;
    struct {
      uint16_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_motor_real_T motor_real_P;

/* Block signals (default storage) */
extern B_motor_real_T motor_real_B;

/* Block states (default storage) */
extern DW_motor_real_T motor_real_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_motor_real_T motor_real_Y;

/* External function called from main */
extern void motor_real_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void motor_real_initialize(void);
extern void motor_real_step0(void);
extern void motor_real_step1(void);
extern void motor_real_step2(void);
extern void motor_real_terminate(void);

/* Real-time Model object */
extern RT_MODEL_motor_real_T *const motor_real_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Data Type Duplicate' : Unused code path elimination
 */

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
 * '<Root>' : 'motor_real'
 * '<S1>'   : 'motor_real/Motor'
 * '<S2>'   : 'motor_real/Motor/Lector Encoder1'
 * '<S3>'   : 'motor_real/Motor/Lector Encoder1/Discrete Derivative'
 */
#endif                                 /* RTW_HEADER_motor_real_h_ */
