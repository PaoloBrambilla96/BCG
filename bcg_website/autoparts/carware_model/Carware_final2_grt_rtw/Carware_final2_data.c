/*
 * Carware_final2_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Carware_final2".
 *
 * Model version              : 4.4
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Mon Nov 27 14:49:37 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Carware_final2.h"

/* Block parameters (default storage) */
P_Carware_final2_T Carware_final2_P = {
  /* Variable: insurance_V
   * Referenced by: '<Root>/Insurance'
   */
  3.0,

  /* Variable: magnitude_V
   * Referenced by: '<Root>/Constant11'
   */
  8.5,

  /* Variable: solution1_1
   * Referenced by: '<Root>/AFP'
   */
  0.0,

  /* Variable: solution2_1
   * Referenced by: '<Root>/ARM'
   */
  0.0,

  /* Variable: solution2_2
   * Referenced by: '<Root>/AIP'
   */
  0.0,

  /* Variable: solution2_3
   * Referenced by: '<Root>/AEP'
   */
  0.0,

  /* Variable: solution2_4
   * Referenced by: '<Root>/DRM'
   */
  10.0,

  /* Variable: solution2_5
   * Referenced by: '<Root>/DIP'
   */
  5.0,

  /* Variable: solution2_6
   * Referenced by: '<Root>/DEP'
   */
  3.0,

  /* Variable: solution3_1
   * Referenced by: '<Root>/BME'
   */
  0.0,

  /* Variable: solution3_2
   * Referenced by: '<Root>/BAE'
   */
  0.0,

  /* Variable: solution4_1
   * Referenced by: '<Root>/OTFP'
   */
  0.0,

  /* Variable: solution4_2
   * Referenced by: '<Root>/ITRM'
   */
  0.0,

  /* Variable: solution4_3
   * Referenced by: '<Root>/ITEP'
   */
  0.0,

  /* Variable: solution5_1
   * Referenced by: '<Root>/MFR'
   */
  0.0,

  /* Variable: solution5_2
   * Referenced by: '<Root>/WR'
   */
  0.0,

  /* Variable: solution5_3
   * Referenced by: '<Root>/LCR'
   */
  0.0,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S5>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant2_const
   * Referenced by: '<S11>/Constant'
   */
  0.9,

  /* Mask Parameter: CompareToConstant13_const
   * Referenced by: '<S9>/Constant'
   */
  0.0,

  /* Mask Parameter: CompareToConstant12_const
   * Referenced by: '<S8>/Constant'
   */
  0.9,

  /* Mask Parameter: CompareToConstant10_const
   * Referenced by: '<S6>/Constant'
   */
  1.7,

  /* Mask Parameter: CompareToConstant9_const
   * Referenced by: '<S18>/Constant'
   */
  0.9,

  /* Mask Parameter: CompareToConstant11_const
   * Referenced by: '<S7>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant7_const
   * Referenced by: '<S16>/Constant'
   */
  0.0,

  /* Mask Parameter: CompareToConstant4_const
   * Referenced by: '<S13>/Constant'
   */
  0.9,

  /* Mask Parameter: CompareToConstant5_const
   * Referenced by: '<S14>/Constant'
   */
  1.7,

  /* Mask Parameter: CompareToConstant3_const
   * Referenced by: '<S12>/Constant'
   */
  0.9,

  /* Mask Parameter: CompareToConstant14_const
   * Referenced by: '<S10>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S4>/Constant'
   */
  0.9,

  /* Mask Parameter: CompareToConstant8_const
   * Referenced by: '<S17>/Constant'
   */
  0.0,

  /* Mask Parameter: CompareToConstant6_const
   * Referenced by: '<S15>/Constant'
   */
  1.7,

  /* Mask Parameter: SliderGain4_gain
   * Referenced by: '<S30>/Slider Gain'
   */
  1.75,

  /* Mask Parameter: SliderGain2_gain
   * Referenced by: '<S28>/Slider Gain'
   */
  0.5,

  /* Mask Parameter: SliderGain7_gain
   * Referenced by: '<S33>/Slider Gain'
   */
  1.75,

  /* Mask Parameter: SliderGain1_gain
   * Referenced by: '<S27>/Slider Gain'
   */
  0.25,

  /* Mask Parameter: SliderGain_gain
   * Referenced by: '<S26>/Slider Gain'
   */
  0.25,

  /* Mask Parameter: SliderGain5_gain
   * Referenced by: '<S31>/Slider Gain'
   */
  1.75,

  /* Mask Parameter: SliderGain3_gain
   * Referenced by: '<S29>/Slider Gain'
   */
  1.75,

  /* Mask Parameter: SliderGain6_gain
   * Referenced by: '<S32>/Slider Gain'
   */
  1.75,

  /* Mask Parameter: MinMaxRunningResettable_vinit
   * Referenced by:
   *   '<S44>/Initial Condition'
   *   '<S44>/Memory'
   */
  0.0,

  /* Mask Parameter: MinMaxRunningResettable1_vinit
   * Referenced by:
   *   '<S45>/Initial Condition'
   *   '<S45>/Memory'
   */
  0.0,

  /* Mask Parameter: MinMaxRunningResettable2_vinit
   * Referenced by:
   *   '<S46>/Initial Condition'
   *   '<S46>/Memory'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Const6'
   */
  1.0,

  /* Expression: 0.03
   * Referenced by: '<Root>/Truck capacity'
   */
  0.03,

  /* Expression: 0.04
   * Referenced by: '<Root>/Truck capacity1'
   */
  0.04,

  /* Expression: 0.05
   * Referenced by: '<Root>/Truck capacity2'
   */
  0.05,

  /* Expression: 1
   * Referenced by: '<Root>/Const2'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Const3'
   */
  1.0,

  /* Expression: 0.075
   * Referenced by: '<Root>/ABackup price'
   */
  0.075,

  /* Expression: 0.05
   * Referenced by: '<Root>/AB deployment'
   */
  0.05,

  /* Expression: 0
   * Referenced by: '<Root>/Delay19'
   */
  0.0,

  /* Expression: 0.05
   * Referenced by: '<Root>/LCR price'
   */
  0.05,

  /* Expression: 0.05
   * Referenced by: '<Root>/WR price'
   */
  0.05,

  /* Expression: 0.09
   * Referenced by: '<Root>/MFR price'
   */
  0.09,

  /* Expression: 0.125
   * Referenced by: '<Root>/MBackup price'
   */
  0.125,

  /* Expression: 0.05
   * Referenced by: '<Root>/MB deployment'
   */
  0.05,

  /* Expression: 0.002
   * Referenced by: '<Root>/EPC'
   */
  0.002,

  /* Expression: 0.001
   * Referenced by: '<Root>/RMC'
   */
  0.001,

  /* Expression: 0.002
   * Referenced by: '<Root>/IPC'
   */
  0.002,

  /* Expression: 0.003
   * Referenced by: '<Root>/FPC '
   */
  0.003,

  /* Expression: 3
   * Referenced by: '<Root>/Delay8'
   */
  3.0,

  /* Expression: 3
   * Referenced by: '<Root>/Delay1'
   */
  3.0,

  /* Expression: 1
   * Referenced by: '<Root>/Delay9'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/IT backup'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Delay6'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Delay11'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Delay20'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<Root>/Delay18'
   */
  0.5,

  /* Expression: 1
   * Referenced by: '<Root>/Constant3'
   */
  1.0,

  /* Expression: 3
   * Referenced by: '<Root>/Delay7'
   */
  3.0,

  /* Expression: 0
   * Referenced by: '<Root>/Const1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Delay17'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Delay16'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Delay14'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Delay15'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<Root>/EP max'
   */
  10.0,

  /* Expression: 1
   * Referenced by: '<Root>/Delay4'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Const'
   */
  0.0,

  /* Expression: 0.2
   * Referenced by: '<Root>/Gain4'
   */
  0.2,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator6'
   */
  0.0,

  /* Expression: 0.2
   * Referenced by: '<Root>/Gain2'
   */
  0.2,

  /* Expression: 0.5
   * Referenced by: '<Root>/Gain1'
   */
  0.5,

  /* Expression: 0.8
   * Referenced by: '<Root>/Gain'
   */
  0.8,

  /* Expression: 10
   * Referenced by: '<Root>/IPmax'
   */
  10.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Delay'
   */
  1.0,

  /* Expression: 3
   * Referenced by: '<Root>/Delay3'
   */
  3.0,

  /* Expression: 3
   * Referenced by: '<Root>/Delay2'
   */
  3.0,

  /* Expression: 0.4
   * Referenced by: '<Root>/Gain5'
   */
  0.4,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator7'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/FPdefault'
   */
  1.0,

  /* Expression: 10
   * Referenced by: '<Root>/FPmax'
   */
  10.0,

  /* Expression: 3
   * Referenced by: '<Root>/Delay5'
   */
  3.0,

  /* Expression: 20
   * Referenced by: '<Root>/RM max'
   */
  20.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator10'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator9'
   */
  0.0,

  /* Expression: 0.002
   * Referenced by: '<Root>/ITC'
   */
  0.002,

  /* Expression: 0.003
   * Referenced by: '<Root>/OTC'
   */
  0.003,

  /* Expression: 1
   * Referenced by: '<Root>/Constant2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Const4'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Const5'
   */
  1.0,

  /* Expression: 0.002
   * Referenced by: '<Root>/ITC1'
   */
  0.002,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator8'
   */
  0.0,

  /* Expression: 0.005
   * Referenced by: '<Root>/Overtime daily'
   */
  0.005
};
