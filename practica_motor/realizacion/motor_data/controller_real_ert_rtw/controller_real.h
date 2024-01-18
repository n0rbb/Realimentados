/*
 * controller_real.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller_real".
 *
 * Model version              : 1.6
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Wed Jan 17 10:49:17 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_controller_real_h_
#define RTW_HEADER_controller_real_h_
#ifndef controller_real_COMMON_INCLUDES_
#define controller_real_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_MbedPinInterface.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#endif                                 /* controller_real_COMMON_INCLUDES_ */

#include "controller_real_types.h"
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
  real_T UnitDelay1[2];                /* '<Root>/Unit Delay1' */
  real_T UnitDelay2;                   /* '<S3>/Unit Delay2' */
  real_T ZeroOrderHold;                /* '<Root>/Zero-Order Hold' */
  real_T ZeroOrderHold1;               /* '<Root>/Zero-Order Hold1' */
  real_T ZeroOrderHold_m;              /* '<S3>/Zero-Order Hold' */
  real_T Diff;                         /* '<S4>/Diff' */
} B_controller_real_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  mbed_DigitalRead_controller_r_T obj; /* '<S2>/Encoder B' */
  mbed_DigitalRead_controller_r_T obj_n;/* '<S2>/Encoder A' */
  mbed_DigitalWrite_controller__T obj_d;/* '<S2>/PHA' */
  mbed_DigitalWrite_controller__T obj_e;/* '<S2>/ENB' */
  mbed_DigitalWrite_controller__T obj_nf;/* '<S2>/ENA' */
  mbed_PWMOutput_controller_rea_T obj_p;/* '<S2>/PWDA' */
  real_T UnitDelay1_DSTATE[2];         /* '<Root>/Unit Delay1' */
  real_T UnitDelay_DSTATE;             /* '<Root>/Unit Delay' */
  real_T UnitDelay2_DSTATE;            /* '<S3>/Unit Delay2' */
  real_T UD_DSTATE;                    /* '<S4>/UD' */
  boolean_T UnitDelay_DSTATE_a;        /* '<S3>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE_n;       /* '<S3>/Unit Delay1' */
  boolean_T objisempty;                /* '<S2>/PWDA' */
  boolean_T objisempty_k;              /* '<S2>/PHA' */
  boolean_T objisempty_d;              /* '<S2>/Encoder B' */
  boolean_T objisempty_k0;             /* '<S2>/Encoder A' */
  boolean_T objisempty_l;              /* '<S2>/ENB' */
  boolean_T objisempty_i;              /* '<S2>/ENA' */
} DW_controller_real_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T pdeg;                         /* '<Root>/p (deg)' */
  real_T vdegs;                        /* '<Root>/v (deg//s)' */
  real_T Vref;                         /* '<Root>/Vref' */
  real_T pEst;                         /* '<Root>/pEst' */
  real_T vEst;                         /* '<Root>/vEst' */
} ExtY_controller_real_T;

/* Parameters (default storage) */
struct P_controller_real_T_ {
  real_T F[4];                         /* Variable: F
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T G[2];                         /* Variable: G
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T K_i_disc;                     /* Variable: K_i_disc
                                        * Referenced by: '<Root>/Gain5'
                                        */
  real_T K_r_disc[2];                  /* Variable: K_r_disc
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T L_disc[2];                    /* Variable: L_disc
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T T;                            /* Variable: T
                                        * Referenced by: '<Root>/Gain7'
                                        */
  real_T accDirDisc;                   /* Variable: accDirDisc
                                        * Referenced by: '<Root>/Gain4'
                                        */
  real_T accInt;                       /* Variable: accInt
                                        * Referenced by: '<Root>/Gain5'
                                        */
  real_T k_awp;                        /* Variable: k_awp
                                        * Referenced by: '<Root>/Gain6'
                                        */
  real_T targetPos;                    /* Variable: targetPos
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S4>/UD'
                               */
  real_T EncoderA_SampleTime;          /* Expression: 0.0001
                                        * Referenced by: '<S2>/Encoder A'
                                        */
  real_T EncoderB_SampleTime;          /* Expression: 0.0001
                                        * Referenced by: '<S2>/Encoder B'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay1'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  real_T UnitDelay2_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S3>/Unit Delay2'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 12
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -12
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T DirectLookupTablenD_table[16];
                            /* Expression: [0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0]
                             * Referenced by: '<S3>/Direct Lookup Table (n-D)'
                             */
  real_T Gain9_Gain;                   /* Expression: 100/12
                                        * Referenced by: '<Root>/Gain9'
                                        */
  real_T Constant_Value_h;             /* Expression: 1
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S4>/TSamp'
                                        */
  boolean_T UnitDelay_InitialCondition_b;
                             /* Computed Parameter: UnitDelay_InitialCondition_b
                              * Referenced by: '<S3>/Unit Delay'
                              */
  boolean_T UnitDelay1_InitialCondition_n;
                            /* Computed Parameter: UnitDelay1_InitialCondition_n
                             * Referenced by: '<S3>/Unit Delay1'
                             */
  uint8_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S3>/Gain'
                                        */
  uint8_T Gain1_Gain;                  /* Computed Parameter: Gain1_Gain
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
struct tag_RTM_controller_real_T {
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
extern P_controller_real_T controller_real_P;

/* Block signals (default storage) */
extern B_controller_real_T controller_real_B;

/* Block states (default storage) */
extern DW_controller_real_T controller_real_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_controller_real_T controller_real_Y;

/* External function called from main */
extern void controller_real_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void controller_real_initialize(void);
extern void controller_real_step0(void);
extern void controller_real_step1(void);
extern void controller_real_terminate(void);

/* Real-time Model object */
extern RT_MODEL_controller_real_T *const controller_real_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Data Type Duplicate' : Unused code path elimination
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
 * '<Root>' : 'controller_real'
 * '<S1>'   : 'controller_real/Compare To Zero'
 * '<S2>'   : 'controller_real/motor_real'
 * '<S3>'   : 'controller_real/motor_real/Lector Encoder1'
 * '<S4>'   : 'controller_real/motor_real/Lector Encoder1/Discrete Derivative'
 */
#endif                                 /* RTW_HEADER_controller_real_h_ */
