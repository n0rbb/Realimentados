/*
 * controller_real_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller_real".
 *
 * Model version              : 1.6
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Wed Jan 17 11:15:32 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "controller_real.h"

/* Block parameters (default storage) */
P_controller_real_T controller_real_P = {
  /* Variable: F
   * Referenced by: '<Root>/Gain2'
   */
  { 1.0, 0.0, 9.9622219997532591E-5, 0.99245392646847952 },

  /* Variable: G
   * Referenced by: '<Root>/Gain'
   */
  { 3.6443870293579786E-5, 0.72795839698337061 },

  /* Variable: K_i_disc
   * Referenced by: '<Root>/Gain5'
   */
  2.4975288025388656,

  /* Variable: K_r_disc
   * Referenced by: '<Root>/Gain3'
   */
  { 0.28679240352712665, 0.00053055466235046736 },

  /* Variable: L_disc
   * Referenced by: '<Root>/Gain1'
   */
  { 0.00189987512764489, 0.079644552074987579 },

  /* Variable: T
   * Referenced by: '<Root>/Gain7'
   */
  0.0001,

  /* Variable: accDirDisc
   * Referenced by: '<Root>/Gain4'
   */
  0.28679240352712976,

  /* Variable: accInt
   * Referenced by: '<Root>/Gain5'
   */
  1.0,

  /* Variable: k_awp
   * Referenced by: '<Root>/Gain6'
   */
  0.1,

  /* Variable: targetPos
   * Referenced by: '<Root>/Constant'
   */
  -180.0,

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S4>/UD'
   */
  0.0,

  /* Expression: 0.0001
   * Referenced by: '<S2>/Encoder A'
   */
  0.0001,

  /* Expression: 0.0001
   * Referenced by: '<S2>/Encoder B'
   */
  0.0001,

  /* Expression: 0
   * Referenced by: '<S1>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Unit Delay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Unit Delay2'
   */
  0.0,

  /* Expression: 12
   * Referenced by: '<Root>/Saturation'
   */
  12.0,

  /* Expression: -12
   * Referenced by: '<Root>/Saturation'
   */
  -12.0,

  /* Expression: [0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0]
   * Referenced by: '<S3>/Direct Lookup Table (n-D)'
   */
  { 0.0, -1.0, 1.0, 0.0, 1.0, 0.0, 0.0, -1.0, -1.0, 0.0, 0.0, 1.0, 0.0, 1.0,
    -1.0, 0.0 },

  /* Expression: 100/12
   * Referenced by: '<Root>/Gain9'
   */
  8.3333333333333339,

  /* Expression: 1
   * Referenced by: '<S2>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S2>/Constant1'
   */
  1.0,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S4>/TSamp'
   */
  100.0,

  /* Computed Parameter: UnitDelay_InitialCondition_b
   * Referenced by: '<S3>/Unit Delay'
   */
  false,

  /* Computed Parameter: UnitDelay1_InitialCondition_n
   * Referenced by: '<S3>/Unit Delay1'
   */
  false,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S3>/Gain'
   */
  128U,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<S3>/Gain1'
   */
  128U,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<S3>/Gain2'
   */
  128U,

  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<S3>/Gain3'
   */
  128U
};
