/*
 * control_motor.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "control_motor".
 *
 * Model version              : 1.1
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Wed Jan 17 11:03:36 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_control_motor_h_
#define RTW_HEADER_control_motor_h_
#ifndef control_motor_COMMON_INCLUDES_
#define control_motor_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_MbedPinInterface.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#endif                                 /* control_motor_COMMON_INCLUDES_ */

#include "control_motor_types.h"
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
  real_T UnitDelay2;                   /* '<S3>/Unit Delay2' */
  real_T Sum[2];                       /* '<Root>/Sum' */
  real_T ZeroOrderHold1;               /* '<Root>/Zero-Order Hold1' */
  real_T ZeroOrderHold;                /* '<S3>/Zero-Order Hold' */
  real_T Diff;                         /* '<S4>/Diff' */
  boolean_T EncoderB;                  /* '<S2>/EncoderB' */
  boolean_T EncoderA;                  /* '<S2>/EncoderA' */
} B_control_motor_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  mbed_DigitalRead_control_moto_T obj; /* '<S2>/EncoderB' */
  mbed_DigitalRead_control_moto_T obj_d;/* '<S2>/EncoderA' */
  mbed_DigitalWrite_control_mot_T obj_o;/* '<S2>/PHA' */
  mbed_DigitalWrite_control_mot_T obj_b;/* '<S2>/ENB' */
  mbed_DigitalWrite_control_mot_T obj_j;/* '<S2>/ENA' */
  mbed_PWMOutput_control_motor_T obj_a;/* '<S2>/PWDA' */
  real_T UnitDelay1_DSTATE[2];         /* '<Root>/Unit Delay1' */
  real_T UnitDelay2_DSTATE;            /* '<S3>/Unit Delay2' */
  real_T UnitDelay_DSTATE;             /* '<Root>/Unit Delay' */
  real_T UD_DSTATE;                    /* '<S4>/UD' */
  boolean_T UnitDelay_DSTATE_a;        /* '<S3>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE_e;       /* '<S3>/Unit Delay1' */
  boolean_T objisempty;                /* '<S2>/PWDA' */
  boolean_T objisempty_h;              /* '<S2>/PHA' */
  boolean_T objisempty_k;              /* '<S2>/EncoderB' */
  boolean_T objisempty_f;              /* '<S2>/EncoderA' */
  boolean_T objisempty_e;              /* '<S2>/ENB' */
  boolean_T objisempty_j;              /* '<S2>/ENA' */
} DW_control_motor_T;

/* Parameters (default storage) */
struct P_control_motor_T_ {
  real_T Kid[3];                       /* Variable: Kid
                                        * Referenced by:
                                        *   '<Root>/Gain'
                                        *   '<Root>/Gain3'
                                        */
  real_T Ld[2];                        /* Variable: Ld
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T T;                            /* Variable: T
                                        * Referenced by: '<Root>/Gain5'
                                        */
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S4>/UD'
                               */
  real_T EncoderA_SampleTime;          /* Expression: 0.0001
                                        * Referenced by: '<S2>/EncoderA'
                                        */
  real_T EncoderB_SampleTime;          /* Expression: 0.0001
                                        * Referenced by: '<S2>/EncoderB'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay1'
                                        */
  real_T Gain4_Gain[4];                /* Expression: sysd.A-Ld*C
                                        * Referenced by: '<Root>/Gain4'
                                        */
  real_T UnitDelay2_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S3>/Unit Delay2'
                                        */
  real_T Consigna_Value;               /* Expression: -240
                                        * Referenced by: '<Root>/Consigna'
                                        */
  real_T accindirecta_Gain;            /* Expression: 1
                                        * Referenced by: '<Root>/acción directa'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  real_T Gain1_Gain[2];                /* Expression: sysd.B
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 12
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -12
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T kamp_Gain;                    /* Expression: 0.1
                                        * Referenced by: '<Root>/kamp'
                                        */
  real_T Gain10_Gain;                  /* Expression: 1
                                        * Referenced by: '<Root>/Gain10'
                                        */
  real_T Gain6_Gain;                   /* Expression: 100/12
                                        * Referenced by: '<Root>/Gain6'
                                        */
  real_T DirectLookupTablenD_table[16];
                            /* Expression: [0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0]
                             * Referenced by: '<S3>/Direct Lookup Table (n-D)'
                             */
  real_T Constant_Value_d;             /* Expression: 1
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S4>/TSamp'
                                        */
  boolean_T UnitDelay_InitialCondition_f;
                             /* Computed Parameter: UnitDelay_InitialCondition_f
                              * Referenced by: '<S3>/Unit Delay'
                              */
  boolean_T UnitDelay1_InitialCondition_g;
                            /* Computed Parameter: UnitDelay1_InitialCondition_g
                             * Referenced by: '<S3>/Unit Delay1'
                             */
  uint8_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S3>/Gain'
                                        */
  uint8_T Gain1_Gain_h;                /* Computed Parameter: Gain1_Gain_h
                                        * Referenced by: '<S3>/Gain1'
                                        */
  uint8_T Gain2_Gain;                  /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S3>/Gain2'
                                        */
  uint8_T Gain3_Gain;                  /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S3>/Gain3'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_control_motor_T {
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
    struct {
      uint8_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_control_motor_T control_motor_P;

/* Block signals (default storage) */
extern B_control_motor_T control_motor_B;

/* Block states (default storage) */
extern DW_control_motor_T control_motor_DW;

/* External function called from main */
extern void control_motor_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void control_motor_initialize(void);
extern void control_motor_step0(void);
extern void control_motor_step1(void);
extern void control_motor_terminate(void);

/* Real-time Model object */
extern RT_MODEL_control_motor_T *const control_motor_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Data Type Duplicate' : Unused code path elimination
 * Block '<Root>/Zero-Order Hold' : Eliminated since input and output rates are identical
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
 * '<Root>' : 'control_motor'
 * '<S1>'   : 'control_motor/Compare To Zero'
 * '<S2>'   : 'control_motor/Motor'
 * '<S3>'   : 'control_motor/Motor/Lector Encoder'
 * '<S4>'   : 'control_motor/Motor/Lector Encoder/Discrete Derivative'
 */
#endif                                 /* RTW_HEADER_control_motor_h_ */
