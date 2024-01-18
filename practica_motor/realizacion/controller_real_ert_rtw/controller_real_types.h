/*
 * controller_real_types.h
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

#ifndef RTW_HEADER_controller_real_types_h_
#define RTW_HEADER_controller_real_types_h_
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

#ifndef typedef_mbed_DigitalWrite_controller__T
#define typedef_mbed_DigitalWrite_controller__T

typedef struct tag_KxFW01GBdhqk5JOEHU3GlD mbed_DigitalWrite_controller__T;

#endif                             /* typedef_mbed_DigitalWrite_controller__T */

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

#ifndef typedef_mbed_DigitalRead_controller_r_T
#define typedef_mbed_DigitalRead_controller_r_T

typedef struct tag_5FwKk6wA1XPbMoI1XCDeDF mbed_DigitalRead_controller_r_T;

#endif                             /* typedef_mbed_DigitalRead_controller_r_T */

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

#ifndef typedef_mbed_PWMOutput_controller_rea_T
#define typedef_mbed_PWMOutput_controller_rea_T

typedef struct tag_UndvUYqhBVOhRRpUse3fWF mbed_PWMOutput_controller_rea_T;

#endif                             /* typedef_mbed_PWMOutput_controller_rea_T */

/* Parameters (default storage) */
typedef struct P_controller_real_T_ P_controller_real_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_controller_real_T RT_MODEL_controller_real_T;

#endif                                 /* RTW_HEADER_controller_real_types_h_ */
