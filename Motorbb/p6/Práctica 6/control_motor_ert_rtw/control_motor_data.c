/*
 * control_motor_data.c
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

#include "control_motor.h"

/* Block parameters (default storage) */
P_control_motor_T control_motor_P = {
  /* Variable: Kid
   * Referenced by:
   *   '<Root>/Gain'
   *   '<Root>/Gain3'
   */
  { 0.99800963896978112, 0.012104553543450023, 14.356856178461191 },

  /* Variable: Ld
   * Referenced by: '<Root>/Gain2'
   */
  { 0.0088937051429676187, 0.016105594954557961 },

  /* Variable: T
   * Referenced by: '<Root>/Gain5'
   */
  0.0001,

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S4>/UD'
   */
  0.0,

  /* Expression: 0.0001
   * Referenced by: '<S2>/EncoderA'
   */
  0.0001,

  /* Expression: 0.0001
   * Referenced by: '<S2>/EncoderB'
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

  /* Expression: sysd.A-Ld*C
   * Referenced by: '<Root>/Gain4'
   */
  { 0.99110629485703239, -0.016105594954557961, 9.9681682304771584E-5,
    0.99364040835063783 },

  /* Expression: 0
   * Referenced by: '<S3>/Unit Delay2'
   */
  0.0,

  /* Expression: -240
   * Referenced by: '<Root>/Consigna'
   */
  -240.0,

  /* Expression: 1
   * Referenced by: '<Root>/acción directa'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Unit Delay'
   */
  0.0,

  /* Expression: sysd.B
   * Referenced by: '<Root>/Gain1'
   */
  { 3.1465548754026158E-5, 0.628642529455042 },

  /* Expression: 12
   * Referenced by: '<Root>/Saturation'
   */
  12.0,

  /* Expression: -12
   * Referenced by: '<Root>/Saturation'
   */
  -12.0,

  /* Expression: 0.1
   * Referenced by: '<Root>/kamp'
   */
  0.1,

  /* Expression: 1
   * Referenced by: '<Root>/Gain10'
   */
  1.0,

  /* Expression: 100/12
   * Referenced by: '<Root>/Gain6'
   */
  8.3333333333333339,

  /* Expression: [0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0]
   * Referenced by: '<S3>/Direct Lookup Table (n-D)'
   */
  { 0.0, -1.0, 1.0, 0.0, 1.0, 0.0, 0.0, -1.0, -1.0, 0.0, 0.0, 1.0, 0.0, 1.0,
    -1.0, 0.0 },

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

  /* Computed Parameter: UnitDelay_InitialCondition_f
   * Referenced by: '<S3>/Unit Delay'
   */
  false,

  /* Computed Parameter: UnitDelay1_InitialCondition_g
   * Referenced by: '<S3>/Unit Delay1'
   */
  false,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S3>/Gain'
   */
  128U,

  /* Computed Parameter: Gain1_Gain_h
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
