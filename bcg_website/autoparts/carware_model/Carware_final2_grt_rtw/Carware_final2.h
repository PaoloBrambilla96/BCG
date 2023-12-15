/*
 * Carware_final2.h
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

#ifndef RTW_HEADER_Carware_final2_h_
#define RTW_HEADER_Carware_final2_h_
#ifndef Carware_final2_COMMON_INCLUDES_
#define Carware_final2_COMMON_INCLUDES_
#include <stdio.h>
#include <string.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* Carware_final2_COMMON_INCLUDES_ */

#include "Carware_final2_types.h"
#include <stddef.h>
#include <float.h>
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
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
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Delayed;                      /* '<Root>/Delay19' */
  real_T Switch1;                      /* '<Root>/Switch1' */
  real_T Delayed_f;                    /* '<Root>/Delay20' */
  real_T SliderGain;                   /* '<S28>/Slider Gain' */
  real_T Switch7;                      /* '<Root>/Switch7' */
  real_T Add1;                         /* '<Root>/Add1' */
  real_T Integrator;                   /* '<Root>/Integrator' */
  real_T Delayed_h;                    /* '<Root>/Delay16' */
  real_T Add2;                         /* '<Root>/Add2' */
  real_T Memory;                       /* '<S44>/Memory' */
  real_T Reset;                        /* '<S44>/Reset' */
  real_T Delayed_b;                    /* '<Root>/Delay14' */
  real_T Add3;                         /* '<Root>/Add3' */
  real_T Memory_e;                     /* '<S45>/Memory' */
  real_T Reset_b;                      /* '<S45>/Reset' */
  real_T Add11;                        /* '<Root>/Add11' */
  real_T Delayed_c;                    /* '<Root>/Delay15' */
  real_T Add4;                         /* '<Root>/Add4' */
  real_T Memory_n;                     /* '<S46>/Memory' */
  real_T Reset_k;                      /* '<S46>/Reset' */
  real_T Add10;                        /* '<Root>/Add10' */
  real_T Add7;                         /* '<Root>/Add7' */
  real_T Switch3;                      /* '<Root>/Switch3' */
  real_T Integrator6;                  /* '<Root>/Integrator6' */
  real_T Gain2;                        /* '<Root>/Gain2' */
  real_T Gain1;                        /* '<Root>/Gain1' */
  real_T Gain;                         /* '<Root>/Gain' */
  real_T Add12;                        /* '<Root>/Add12' */
  real_T Add16;                        /* '<Root>/Add16' */
  real_T Add14;                        /* '<Root>/Add14' */
  real_T Add6;                         /* '<Root>/Add6' */
  real_T Switch;                       /* '<Root>/Switch' */
  real_T Add15;                        /* '<Root>/Add15' */
  real_T Integrator4;                  /* '<Root>/Integrator4' */
  real_T Integrator5;                  /* '<Root>/Integrator5' */
  real_T Add9;                         /* '<Root>/Add9' */
  real_T Integrator3;                  /* '<Root>/Integrator3' */
  real_T Integrator2;                  /* '<Root>/Integrator2' */
  real_T Integrator7;                  /* '<Root>/Integrator7' */
  real_T Add18;                        /* '<Root>/Add18' */
  real_T Clock;                        /* '<Root>/Clock' */
  real_T Switch5;                      /* '<Root>/Switch5' */
  real_T Add8;                         /* '<Root>/Add8' */
  real_T Integrator1;                  /* '<Root>/Integrator1' */
  real_T Integrator10;                 /* '<Root>/Integrator10' */
  real_T Integrator9;                  /* '<Root>/Integrator9' */
  real_T Product3;                     /* '<Root>/Product3' */
  real_T Product4;                     /* '<Root>/Product4' */
  real_T Add13;                        /* '<Root>/Add13' */
  real_T Add23;                        /* '<Root>/Add23' */
  real_T Integrator8;                  /* '<Root>/Integrator8' */
  real_T Product11;                    /* '<Root>/Product11' */
  real_T Product12;                    /* '<Root>/Product12' */
  real_T Product14;                    /* '<Root>/Product14' */
  real_T Damage;                       /* '<Root>/State Transition Table9' */
  real_T Damage_m;                     /* '<Root>/State Transition Table8' */
  real_T Damage_n;                     /* '<Root>/State Transition Table7' */
  real_T Damage_l;                     /* '<Root>/State Transition Table6' */
  real_T Inventory;                    /* '<Root>/State Transition Table5' */
  real_T Damage_p;                     /* '<Root>/State Transition Table5' */
  real_T Logistics;                    /* '<Root>/State Transition Table4' */
  real_T Maintenance;                  /* '<Root>/State Transition Table3' */
  real_T Electricity;                  /* '<Root>/State Transition Table2' */
  real_T Damage_d;                     /* '<Root>/State Transition Table1' */
  real_T MxRM;                         /* '<Root>/Raw Material' */
  real_T LxRM;                         /* '<Root>/Raw Material' */
  real_T RawMaterial;                  /* '<Root>/Raw Material' */
  real_T LossIP;                       /* '<Root>/Internal' */
  real_T AxIP;                         /* '<Root>/Internal' */
  real_T MxIP;                         /* '<Root>/Internal' */
  real_T IParts;                       /* '<Root>/Internal' */
  real_T AxFP;                        /* '<Root>/Finished Products Warehouse' */
  real_T LxFP;                        /* '<Root>/Finished Products Warehouse' */
  real_T FinishedProducts;            /* '<Root>/Finished Products Warehouse' */
  real_T LxEP;                         /* '<Root>/External' */
  real_T AxEP;                         /* '<Root>/External' */
  real_T EParts;                       /* '<Root>/External' */
  real_T Loss;                         /* '<Root>/External' */
  real_T CR;                           /* '<Root>/Chart2' */
  real_T Level;                        /* '<Root>/Chart2' */
  real_T NL;                           /* '<Root>/Chart1' */
  real_T Premium;                      /* '<Root>/Chart1' */
  real_T NLBC;                         /* '<Root>/Chart1' */
  real_T NLBuilding;                   /* '<Root>/Chart1' */
  real_T NLProfit;                     /* '<Root>/Chart1' */
  real_T NLProperty;                   /* '<Root>/Chart1' */
  real_T AxO;                          /* '<Root>/Chart' */
  real_T Loss_h;                       /* '<Root>/Chart' */
  real_T Orders;                       /* '<Root>/Chart' */
} B_Carware_final2_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay19_DSTATE[100];          /* '<Root>/Delay19' */
  real_T Delay8_DSTATE;                /* '<Root>/Delay8' */
  real_T Delay1_DSTATE;                /* '<Root>/Delay1' */
  real_T Delay9_DSTATE;                /* '<Root>/Delay9' */
  real_T Delay6_DSTATE;                /* '<Root>/Delay6' */
  real_T Delay11_DSTATE;               /* '<Root>/Delay11' */
  real_T Delay20_DSTATE[20];           /* '<Root>/Delay20' */
  real_T Delay18_DSTATE[20];           /* '<Root>/Delay18' */
  real_T Delay7_DSTATE;                /* '<Root>/Delay7' */
  real_T Delay17_DSTATE;               /* '<Root>/Delay17' */
  real_T Delay16_DSTATE[30];           /* '<Root>/Delay16' */
  real_T Delay14_DSTATE[60];           /* '<Root>/Delay14' */
  real_T Delay15_DSTATE[90];           /* '<Root>/Delay15' */
  real_T Delay4_DSTATE;                /* '<Root>/Delay4' */
  real_T Delay13_DSTATE;               /* '<Root>/Delay13' */
  real_T Delay_DSTATE[30];             /* '<Root>/Delay' */
  real_T Delay3_DSTATE;                /* '<Root>/Delay3' */
  real_T Delay2_DSTATE;                /* '<Root>/Delay2' */
  real_T Delay10_DSTATE;               /* '<Root>/Delay10' */
  real_T Delay12_DSTATE;               /* '<Root>/Delay12' */
  real_T Delay5_DSTATE;                /* '<Root>/Delay5' */
  real_T Memory_PreviousInput;         /* '<S44>/Memory' */
  real_T Memory_PreviousInput_i;       /* '<S45>/Memory' */
  real_T Memory_PreviousInput_f;       /* '<S46>/Memory' */
  real_T T;                            /* '<Root>/State Transition Table9' */
  real_T RT_f;                         /* '<Root>/State Transition Table9' */
  real_T T_b;                          /* '<Root>/State Transition Table8' */
  real_T RT_p;                         /* '<Root>/State Transition Table8' */
  real_T T_c;                          /* '<Root>/State Transition Table7' */
  real_T RT_j;                         /* '<Root>/State Transition Table7' */
  real_T T_k;                          /* '<Root>/State Transition Table6' */
  real_T RT_c;                         /* '<Root>/State Transition Table6' */
  real_T T_n;                          /* '<Root>/State Transition Table5' */
  real_T RT_e;                         /* '<Root>/State Transition Table5' */
  real_T T_j;                          /* '<Root>/State Transition Table4' */
  real_T RTl;                          /* '<Root>/State Transition Table4' */
  real_T FRl;                          /* '<Root>/State Transition Table4' */
  real_T T_h;                          /* '<Root>/State Transition Table3' */
  real_T RTm;                          /* '<Root>/State Transition Table3' */
  real_T FRm;                          /* '<Root>/State Transition Table3' */
  real_T T_g;                          /* '<Root>/State Transition Table2' */
  real_T RTe;                          /* '<Root>/State Transition Table2' */
  real_T FRe;                          /* '<Root>/State Transition Table2' */
  real_T T_gh;                         /* '<Root>/State Transition Table1' */
  real_T RT_b;                         /* '<Root>/State Transition Table1' */
  real_T T_i;                          /* '<Root>/State Transition Table' */
  real_T DamageIP;                     /* '<Root>/Internal' */
  real_T Damage;                       /* '<Root>/External' */
  real_T TotalCont;                    /* '<Root>/Chart2' */
  real_T Shipped;                      /* '<Root>/Chart2' */
  real_T Return;                       /* '<Root>/Chart2' */
  real_T Coverage;                     /* '<Root>/Chart1' */
  real_T OSales;                       /* '<Root>/Chart' */
  real_T ShippedS;                     /* '<Root>/Chart' */
  real_T ShippingS;                    /* '<Root>/Chart' */
  struct {
    void *FilePtr;
  } ToFile_PWORK;                      /* '<Root>/To File' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile_IWORK;                      /* '<Root>/To File' */

  uint8_T is_active_c3_Carware_final2; /* '<Root>/State Transition Table9' */
  uint8_T is_c3_Carware_final2;        /* '<Root>/State Transition Table9' */
  uint8_T is_active_c14_Carware_final2;/* '<Root>/State Transition Table8' */
  uint8_T is_c14_Carware_final2;       /* '<Root>/State Transition Table8' */
  uint8_T is_active_c13_Carware_final2;/* '<Root>/State Transition Table7' */
  uint8_T is_c13_Carware_final2;       /* '<Root>/State Transition Table7' */
  uint8_T is_active_c12_Carware_final2;/* '<Root>/State Transition Table6' */
  uint8_T is_c12_Carware_final2;       /* '<Root>/State Transition Table6' */
  uint8_T is_active_c11_Carware_final2;/* '<Root>/State Transition Table5' */
  uint8_T is_c11_Carware_final2;       /* '<Root>/State Transition Table5' */
  uint8_T is_active_c10_Carware_final2;/* '<Root>/State Transition Table4' */
  uint8_T is_c10_Carware_final2;       /* '<Root>/State Transition Table4' */
  uint8_T is_active_c9_Carware_final2; /* '<Root>/State Transition Table3' */
  uint8_T is_c9_Carware_final2;        /* '<Root>/State Transition Table3' */
  uint8_T is_active_c8_Carware_final2; /* '<Root>/State Transition Table2' */
  uint8_T is_c8_Carware_final2;        /* '<Root>/State Transition Table2' */
  uint8_T is_active_c7_Carware_final2; /* '<Root>/State Transition Table1' */
  uint8_T is_c7_Carware_final2;        /* '<Root>/State Transition Table1' */
  uint8_T is_active_c4_Carware_final2; /* '<Root>/State Transition Table' */
  uint8_T is_c4_Carware_final2;        /* '<Root>/State Transition Table' */
  uint8_T is_active_c1_Carware_final2; /* '<Root>/Raw Material' */
  uint8_T is_c1_Carware_final2;        /* '<Root>/Raw Material' */
  uint8_T is_active_c2_Carware_final2; /* '<Root>/Internal' */
  uint8_T is_c2_Carware_final2;        /* '<Root>/Internal' */
  uint8_T is_active_c5_Carware_final2;/* '<Root>/Finished Products Warehouse' */
  uint8_T is_c5_Carware_final2;       /* '<Root>/Finished Products Warehouse' */
  uint8_T is_active_c15_Carware_final2;/* '<Root>/External' */
  uint8_T is_c15_Carware_final2;       /* '<Root>/External' */
  uint8_T is_active_c6_Carware_final2; /* '<Root>/Chart2' */
  uint8_T is_c6_Carware_final2;        /* '<Root>/Chart2' */
  uint8_T is_active_c17_Carware_final2;/* '<Root>/Chart1' */
  uint8_T is_c17_Carware_final2;       /* '<Root>/Chart1' */
  uint8_T is_active_c16_Carware_final2;/* '<Root>/Chart' */
  uint8_T is_c16_Carware_final2;       /* '<Root>/Chart' */
  boolean_T icLoad;                    /* '<Root>/Delay13' */
  boolean_T icLoad_b;                  /* '<Root>/Delay10' */
  boolean_T icLoad_c;                  /* '<Root>/Delay12' */
} DW_Carware_final2_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T Integrator6_CSTATE;           /* '<Root>/Integrator6' */
  real_T Integrator4_CSTATE;           /* '<Root>/Integrator4' */
  real_T Integrator5_CSTATE;           /* '<Root>/Integrator5' */
  real_T Integrator3_CSTATE;           /* '<Root>/Integrator3' */
  real_T Integrator2_CSTATE;           /* '<Root>/Integrator2' */
  real_T Integrator7_CSTATE;           /* '<Root>/Integrator7' */
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
  real_T Integrator10_CSTATE;          /* '<Root>/Integrator10' */
  real_T Integrator9_CSTATE;           /* '<Root>/Integrator9' */
  real_T Integrator8_CSTATE;           /* '<Root>/Integrator8' */
} X_Carware_final2_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T Integrator6_CSTATE;           /* '<Root>/Integrator6' */
  real_T Integrator4_CSTATE;           /* '<Root>/Integrator4' */
  real_T Integrator5_CSTATE;           /* '<Root>/Integrator5' */
  real_T Integrator3_CSTATE;           /* '<Root>/Integrator3' */
  real_T Integrator2_CSTATE;           /* '<Root>/Integrator2' */
  real_T Integrator7_CSTATE;           /* '<Root>/Integrator7' */
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
  real_T Integrator10_CSTATE;          /* '<Root>/Integrator10' */
  real_T Integrator9_CSTATE;           /* '<Root>/Integrator9' */
  real_T Integrator8_CSTATE;           /* '<Root>/Integrator8' */
} XDot_Carware_final2_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<Root>/Integrator' */
  boolean_T Integrator6_CSTATE;        /* '<Root>/Integrator6' */
  boolean_T Integrator4_CSTATE;        /* '<Root>/Integrator4' */
  boolean_T Integrator5_CSTATE;        /* '<Root>/Integrator5' */
  boolean_T Integrator3_CSTATE;        /* '<Root>/Integrator3' */
  boolean_T Integrator2_CSTATE;        /* '<Root>/Integrator2' */
  boolean_T Integrator7_CSTATE;        /* '<Root>/Integrator7' */
  boolean_T Integrator1_CSTATE;        /* '<Root>/Integrator1' */
  boolean_T Integrator10_CSTATE;       /* '<Root>/Integrator10' */
  boolean_T Integrator9_CSTATE;        /* '<Root>/Integrator9' */
  boolean_T Integrator8_CSTATE;        /* '<Root>/Integrator8' */
} XDis_Carware_final2_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_Carware_final2_T_ {
  real_T insurance_V;                  /* Variable: insurance_V
                                        * Referenced by: '<Root>/Insurance'
                                        */
  real_T magnitude_V;                  /* Variable: magnitude_V
                                        * Referenced by: '<Root>/Constant11'
                                        */
  real_T solution1_1;                  /* Variable: solution1_1
                                        * Referenced by: '<Root>/AFP'
                                        */
  real_T solution2_1;                  /* Variable: solution2_1
                                        * Referenced by: '<Root>/ARM'
                                        */
  real_T solution2_2;                  /* Variable: solution2_2
                                        * Referenced by: '<Root>/AIP'
                                        */
  real_T solution2_3;                  /* Variable: solution2_3
                                        * Referenced by: '<Root>/AEP'
                                        */
  real_T solution2_4;                  /* Variable: solution2_4
                                        * Referenced by: '<Root>/DRM'
                                        */
  real_T solution2_5;                  /* Variable: solution2_5
                                        * Referenced by: '<Root>/DIP'
                                        */
  real_T solution2_6;                  /* Variable: solution2_6
                                        * Referenced by: '<Root>/DEP'
                                        */
  real_T solution3_1;                  /* Variable: solution3_1
                                        * Referenced by: '<Root>/BME'
                                        */
  real_T solution3_2;                  /* Variable: solution3_2
                                        * Referenced by: '<Root>/BAE'
                                        */
  real_T solution4_1;                  /* Variable: solution4_1
                                        * Referenced by: '<Root>/OTFP'
                                        */
  real_T solution4_2;                  /* Variable: solution4_2
                                        * Referenced by: '<Root>/ITRM'
                                        */
  real_T solution4_3;                  /* Variable: solution4_3
                                        * Referenced by: '<Root>/ITEP'
                                        */
  real_T solution5_1;                  /* Variable: solution5_1
                                        * Referenced by: '<Root>/MFR'
                                        */
  real_T solution5_2;                  /* Variable: solution5_2
                                        * Referenced by: '<Root>/WR'
                                        */
  real_T solution5_3;                  /* Variable: solution5_3
                                        * Referenced by: '<Root>/LCR'
                                        */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S5>/Constant'
                                      */
  real_T CompareToConstant2_const;   /* Mask Parameter: CompareToConstant2_const
                                      * Referenced by: '<S11>/Constant'
                                      */
  real_T CompareToConstant13_const; /* Mask Parameter: CompareToConstant13_const
                                     * Referenced by: '<S9>/Constant'
                                     */
  real_T CompareToConstant12_const; /* Mask Parameter: CompareToConstant12_const
                                     * Referenced by: '<S8>/Constant'
                                     */
  real_T CompareToConstant10_const; /* Mask Parameter: CompareToConstant10_const
                                     * Referenced by: '<S6>/Constant'
                                     */
  real_T CompareToConstant9_const;   /* Mask Parameter: CompareToConstant9_const
                                      * Referenced by: '<S18>/Constant'
                                      */
  real_T CompareToConstant11_const; /* Mask Parameter: CompareToConstant11_const
                                     * Referenced by: '<S7>/Constant'
                                     */
  real_T CompareToConstant7_const;   /* Mask Parameter: CompareToConstant7_const
                                      * Referenced by: '<S16>/Constant'
                                      */
  real_T CompareToConstant4_const;   /* Mask Parameter: CompareToConstant4_const
                                      * Referenced by: '<S13>/Constant'
                                      */
  real_T CompareToConstant5_const;   /* Mask Parameter: CompareToConstant5_const
                                      * Referenced by: '<S14>/Constant'
                                      */
  real_T CompareToConstant3_const;   /* Mask Parameter: CompareToConstant3_const
                                      * Referenced by: '<S12>/Constant'
                                      */
  real_T CompareToConstant14_const; /* Mask Parameter: CompareToConstant14_const
                                     * Referenced by: '<S10>/Constant'
                                     */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S4>/Constant'
                                       */
  real_T CompareToConstant8_const;   /* Mask Parameter: CompareToConstant8_const
                                      * Referenced by: '<S17>/Constant'
                                      */
  real_T CompareToConstant6_const;   /* Mask Parameter: CompareToConstant6_const
                                      * Referenced by: '<S15>/Constant'
                                      */
  real_T SliderGain4_gain;             /* Mask Parameter: SliderGain4_gain
                                        * Referenced by: '<S30>/Slider Gain'
                                        */
  real_T SliderGain2_gain;             /* Mask Parameter: SliderGain2_gain
                                        * Referenced by: '<S28>/Slider Gain'
                                        */
  real_T SliderGain7_gain;             /* Mask Parameter: SliderGain7_gain
                                        * Referenced by: '<S33>/Slider Gain'
                                        */
  real_T SliderGain1_gain;             /* Mask Parameter: SliderGain1_gain
                                        * Referenced by: '<S27>/Slider Gain'
                                        */
  real_T SliderGain_gain;              /* Mask Parameter: SliderGain_gain
                                        * Referenced by: '<S26>/Slider Gain'
                                        */
  real_T SliderGain5_gain;             /* Mask Parameter: SliderGain5_gain
                                        * Referenced by: '<S31>/Slider Gain'
                                        */
  real_T SliderGain3_gain;             /* Mask Parameter: SliderGain3_gain
                                        * Referenced by: '<S29>/Slider Gain'
                                        */
  real_T SliderGain6_gain;             /* Mask Parameter: SliderGain6_gain
                                        * Referenced by: '<S32>/Slider Gain'
                                        */
  real_T MinMaxRunningResettable_vinit;
                                /* Mask Parameter: MinMaxRunningResettable_vinit
                                 * Referenced by:
                                 *   '<S44>/Initial Condition'
                                 *   '<S44>/Memory'
                                 */
  real_T MinMaxRunningResettable1_vinit;
                               /* Mask Parameter: MinMaxRunningResettable1_vinit
                                * Referenced by:
                                *   '<S45>/Initial Condition'
                                *   '<S45>/Memory'
                                */
  real_T MinMaxRunningResettable2_vinit;
                               /* Mask Parameter: MinMaxRunningResettable2_vinit
                                * Referenced by:
                                *   '<S46>/Initial Condition'
                                *   '<S46>/Memory'
                                */
  real_T Const6_Value;                 /* Expression: 1
                                        * Referenced by: '<Root>/Const6'
                                        */
  real_T Truckcapacity_Value;          /* Expression: 0.03
                                        * Referenced by: '<Root>/Truck capacity'
                                        */
  real_T Truckcapacity1_Value;         /* Expression: 0.04
                                        * Referenced by: '<Root>/Truck capacity1'
                                        */
  real_T Truckcapacity2_Value;         /* Expression: 0.05
                                        * Referenced by: '<Root>/Truck capacity2'
                                        */
  real_T Const2_Value;                 /* Expression: 1
                                        * Referenced by: '<Root>/Const2'
                                        */
  real_T Const3_Value;                 /* Expression: 1
                                        * Referenced by: '<Root>/Const3'
                                        */
  real_T ABackupprice_Value;           /* Expression: 0.075
                                        * Referenced by: '<Root>/ABackup price'
                                        */
  real_T ABdeployment_Value;           /* Expression: 0.05
                                        * Referenced by: '<Root>/AB deployment'
                                        */
  real_T Delay19_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<Root>/Delay19'
                                        */
  real_T LCRprice_Value;               /* Expression: 0.05
                                        * Referenced by: '<Root>/LCR price'
                                        */
  real_T WRprice_Value;                /* Expression: 0.05
                                        * Referenced by: '<Root>/WR price'
                                        */
  real_T MFRprice_Value;               /* Expression: 0.09
                                        * Referenced by: '<Root>/MFR price'
                                        */
  real_T MBackupprice_Value;           /* Expression: 0.125
                                        * Referenced by: '<Root>/MBackup price'
                                        */
  real_T MBdeployment_Value;           /* Expression: 0.05
                                        * Referenced by: '<Root>/MB deployment'
                                        */
  real_T EPC_Value;                    /* Expression: 0.002
                                        * Referenced by: '<Root>/EPC'
                                        */
  real_T RMC_Value;                    /* Expression: 0.001
                                        * Referenced by: '<Root>/RMC'
                                        */
  real_T IPC_Value;                    /* Expression: 0.002
                                        * Referenced by: '<Root>/IPC'
                                        */
  real_T FPC_Value;                    /* Expression: 0.003
                                        * Referenced by: '<Root>/FPC '
                                        */
  real_T Delay8_InitialCondition;      /* Expression: 3
                                        * Referenced by: '<Root>/Delay8'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 3
                                        * Referenced by: '<Root>/Delay1'
                                        */
  real_T Delay9_InitialCondition;      /* Expression: 1
                                        * Referenced by: '<Root>/Delay9'
                                        */
  real_T ITbackup_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/IT backup'
                                        */
  real_T Delay6_InitialCondition;      /* Expression: 1
                                        * Referenced by: '<Root>/Delay6'
                                        */
  real_T Delay11_InitialCondition;     /* Expression: 1
                                        * Referenced by: '<Root>/Delay11'
                                        */
  real_T Delay20_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<Root>/Delay20'
                                        */
  real_T Delay18_InitialCondition;     /* Expression: 0.5
                                        * Referenced by: '<Root>/Delay18'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Delay7_InitialCondition;      /* Expression: 3
                                        * Referenced by: '<Root>/Delay7'
                                        */
  real_T Const1_Value;                 /* Expression: 0
                                        * Referenced by: '<Root>/Const1'
                                        */
  real_T Delay17_InitialCondition;     /* Expression: 1
                                        * Referenced by: '<Root>/Delay17'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  real_T Delay16_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<Root>/Delay16'
                                        */
  real_T Delay14_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<Root>/Delay14'
                                        */
  real_T Delay15_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<Root>/Delay15'
                                        */
  real_T EPmax_Value;                  /* Expression: 10
                                        * Referenced by: '<Root>/EP max'
                                        */
  real_T Delay4_InitialCondition;      /* Expression: 1
                                        * Referenced by: '<Root>/Delay4'
                                        */
  real_T Const_Value;                  /* Expression: 0
                                        * Referenced by: '<Root>/Const'
                                        */
  real_T Gain4_Gain;                   /* Expression: 0.2
                                        * Referenced by: '<Root>/Gain4'
                                        */
  real_T Integrator6_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator6'
                                        */
  real_T Gain2_Gain;                   /* Expression: 0.2
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Gain1_Gain;                   /* Expression: 0.5
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.8
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T IPmax_Value;                  /* Expression: 10
                                        * Referenced by: '<Root>/IPmax'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 1
                                        * Referenced by: '<Root>/Delay'
                                        */
  real_T Delay3_InitialCondition;      /* Expression: 3
                                        * Referenced by: '<Root>/Delay3'
                                        */
  real_T Delay2_InitialCondition;      /* Expression: 3
                                        * Referenced by: '<Root>/Delay2'
                                        */
  real_T Gain5_Gain;                   /* Expression: 0.4
                                        * Referenced by: '<Root>/Gain5'
                                        */
  real_T Integrator4_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator4'
                                        */
  real_T Integrator5_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator5'
                                        */
  real_T Integrator3_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator3'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator2'
                                        */
  real_T Integrator7_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator7'
                                        */
  real_T FPdefault_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/FPdefault'
                                        */
  real_T FPmax_Value;                  /* Expression: 10
                                        * Referenced by: '<Root>/FPmax'
                                        */
  real_T Delay5_InitialCondition;      /* Expression: 3
                                        * Referenced by: '<Root>/Delay5'
                                        */
  real_T RMmax_Value;                  /* Expression: 20
                                        * Referenced by: '<Root>/RM max'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  real_T Integrator10_IC;              /* Expression: 0
                                        * Referenced by: '<Root>/Integrator10'
                                        */
  real_T Integrator9_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator9'
                                        */
  real_T ITC_Value;                    /* Expression: 0.002
                                        * Referenced by: '<Root>/ITC'
                                        */
  real_T OTC_Value;                    /* Expression: 0.003
                                        * Referenced by: '<Root>/OTC'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Const4_Value;                 /* Expression: 0
                                        * Referenced by: '<Root>/Const4'
                                        */
  real_T Const5_Value;                 /* Expression: 1
                                        * Referenced by: '<Root>/Const5'
                                        */
  real_T ITC1_Value;                   /* Expression: 0.002
                                        * Referenced by: '<Root>/ITC1'
                                        */
  real_T Integrator8_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator8'
                                        */
  real_T Overtimedaily_Value;          /* Expression: 0.005
                                        * Referenced by: '<Root>/Overtime daily'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Carware_final2_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_Carware_final2_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_Carware_final2_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[11];
  real_T odeF[3][11];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Carware_final2_T Carware_final2_P;

/* Block signals (default storage) */
extern B_Carware_final2_T Carware_final2_B;

/* Continuous states (default storage) */
extern X_Carware_final2_T Carware_final2_X;

/* Block states (default storage) */
extern DW_Carware_final2_T Carware_final2_DW;

/* Model entry point functions */
extern void Carware_final2_initialize(void);
extern void Carware_final2_step(void);
extern void Carware_final2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Carware_final2_T *const Carware_final2_M;

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
 * '<Root>' : 'Carware_final2'
 * '<S1>'   : 'Carware_final2/Chart'
 * '<S2>'   : 'Carware_final2/Chart1'
 * '<S3>'   : 'Carware_final2/Chart2'
 * '<S4>'   : 'Carware_final2/Compare To Constant'
 * '<S5>'   : 'Carware_final2/Compare To Constant1'
 * '<S6>'   : 'Carware_final2/Compare To Constant10'
 * '<S7>'   : 'Carware_final2/Compare To Constant11'
 * '<S8>'   : 'Carware_final2/Compare To Constant12'
 * '<S9>'   : 'Carware_final2/Compare To Constant13'
 * '<S10>'  : 'Carware_final2/Compare To Constant14'
 * '<S11>'  : 'Carware_final2/Compare To Constant2'
 * '<S12>'  : 'Carware_final2/Compare To Constant3'
 * '<S13>'  : 'Carware_final2/Compare To Constant4'
 * '<S14>'  : 'Carware_final2/Compare To Constant5'
 * '<S15>'  : 'Carware_final2/Compare To Constant6'
 * '<S16>'  : 'Carware_final2/Compare To Constant7'
 * '<S17>'  : 'Carware_final2/Compare To Constant8'
 * '<S18>'  : 'Carware_final2/Compare To Constant9'
 * '<S19>'  : 'Carware_final2/External'
 * '<S20>'  : 'Carware_final2/Finished Products Warehouse'
 * '<S21>'  : 'Carware_final2/Internal'
 * '<S22>'  : 'Carware_final2/MinMax Running Resettable'
 * '<S23>'  : 'Carware_final2/MinMax Running Resettable1'
 * '<S24>'  : 'Carware_final2/MinMax Running Resettable2'
 * '<S25>'  : 'Carware_final2/Raw Material'
 * '<S26>'  : 'Carware_final2/Slider Gain'
 * '<S27>'  : 'Carware_final2/Slider Gain1'
 * '<S28>'  : 'Carware_final2/Slider Gain2'
 * '<S29>'  : 'Carware_final2/Slider Gain3'
 * '<S30>'  : 'Carware_final2/Slider Gain4'
 * '<S31>'  : 'Carware_final2/Slider Gain5'
 * '<S32>'  : 'Carware_final2/Slider Gain6'
 * '<S33>'  : 'Carware_final2/Slider Gain7'
 * '<S34>'  : 'Carware_final2/State Transition Table'
 * '<S35>'  : 'Carware_final2/State Transition Table1'
 * '<S36>'  : 'Carware_final2/State Transition Table2'
 * '<S37>'  : 'Carware_final2/State Transition Table3'
 * '<S38>'  : 'Carware_final2/State Transition Table4'
 * '<S39>'  : 'Carware_final2/State Transition Table5'
 * '<S40>'  : 'Carware_final2/State Transition Table6'
 * '<S41>'  : 'Carware_final2/State Transition Table7'
 * '<S42>'  : 'Carware_final2/State Transition Table8'
 * '<S43>'  : 'Carware_final2/State Transition Table9'
 * '<S44>'  : 'Carware_final2/MinMax Running Resettable/Subsystem'
 * '<S45>'  : 'Carware_final2/MinMax Running Resettable1/Subsystem'
 * '<S46>'  : 'Carware_final2/MinMax Running Resettable2/Subsystem'
 */
#endif                                 /* RTW_HEADER_Carware_final2_h_ */
