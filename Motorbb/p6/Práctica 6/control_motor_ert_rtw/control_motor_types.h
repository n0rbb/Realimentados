/*
 * control_motor_types.h
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

#ifndef RTW_HEADER_control_motor_types_h_
#define RTW_HEADER_control_motor_types_h_
#include "rtwtypes.h"
#include "MW_SVD.h"

/* Custom Type definition for MATLABSystem: '<S2>/PWDA' */
#include "MW_SVD.h"
#ifndef struct_tag_KxFW01GBdhqk5JOEHU3GlD
#define struct_tag_KxFW01GBdhqk5JOEHU3GlD

struct tag_KxFW01GBdhqk5JOEHU3GlD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
};

#endif                                 /* struct_tag_KxFW01GBdhqk5JOEHU3GlD */

#ifndef typedef_mbed_DigitalWrite_control_mot_T
#define typedef_mbed_DigitalWrite_control_mot_T

typedef struct tag_KxFW01GBdhqk5JOEHU3GlD mbed_DigitalWrite_control_mot_T;

#endif                             /* typedef_mbed_DigitalWrite_control_mot_T */

#ifndef struct_tag_5FwKk6wA1XPbMoI1XCDeDF
#define struct_tag_5FwKk6wA1XPbMoI1XCDeDF

struct tag_5FwKk6wA1XPbMoI1XCDeDF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
  real_T SampleTime;
};

#endif                                 /* struct_tag_5FwKk6wA1XPbMoI1XCDeDF */

#ifndef typedef_mbed_DigitalRead_control_moto_T
#define typedef_mbed_DigitalRead_control_moto_T

typedef struct tag_5FwKk6wA1XPbMoI1XCDeDF mbed_DigitalRead_control_moto_T;

#endif                             /* typedef_mbed_DigitalRead_control_moto_T */

#ifndef struct_tag_UndvUYqhBVOhRRpUse3fWF
#define struct_tag_UndvUYqhBVOhRRpUse3fWF

struct tag_UndvUYqhBVOhRRpUse3fWF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_PWM_HANDLE;
};

#endif                                 /* struct_tag_UndvUYqhBVOhRRpUse3fWF */

#ifndef typedef_mbed_PWMOutput_control_motor_T
#define typedef_mbed_PWMOutput_control_motor_T

typedef struct tag_UndvUYqhBVOhRRpUse3fWF mbed_PWMOutput_control_motor_T;

#endif                              /* typedef_mbed_PWMOutput_control_motor_T */

/* Parameters (default storage) */
typedef struct P_control_motor_T_ P_control_motor_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_control_motor_T RT_MODEL_control_motor_T;

#endif                                 /* RTW_HEADER_control_motor_types_h_ */
