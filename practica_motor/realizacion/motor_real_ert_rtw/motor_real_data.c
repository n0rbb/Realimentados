/*
 * motor_real_data.c
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

/* Block parameters (default storage) */
P_motor_real_T motor_real_P = {
  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S3>/UD'
   */
  0.0,

  /* Expression: 0.0001
   * Referenced by: '<S1>/Encoder A'
   */
  0.0001,

  /* Expression: 0.0001
   * Referenced by: '<S1>/Encoder B'
   */
  0.0001,

  /* Expression: 0
   * Referenced by: '<S2>/Unit Delay2'
   */
  0.0,

  /* Expression: [0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0]
   * Referenced by: '<S2>/Direct Lookup Table (n-D)'
   */
  { 0.0, -1.0, 1.0, 0.0, 1.0, 0.0, 0.0, -1.0, -1.0, 0.0, 0.0, 1.0, 0.0, 1.0,
    -1.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<Root>/giro'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S1>/Constant1'
   */
  1.0,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S3>/TSamp'
   */
  100.0,

  /* Expression: 1
   * Referenced by: '<Root>/Step'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 60
   * Referenced by: '<Root>/Step'
   */
  60.0,

  /* Computed Parameter: UnitDelay_InitialCondition
   * Referenced by: '<S2>/Unit Delay'
   */
  false,

  /* Computed Parameter: UnitDelay1_InitialCondition
   * Referenced by: '<S2>/Unit Delay1'
   */
  false,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S2>/Gain'
   */
  128U,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<S2>/Gain1'
   */
  128U,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<S2>/Gain2'
   */
  128U,

  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<S2>/Gain3'
   */
  128U
};
