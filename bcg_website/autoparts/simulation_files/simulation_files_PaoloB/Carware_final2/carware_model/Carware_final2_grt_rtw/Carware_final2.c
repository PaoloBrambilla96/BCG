/*
 * Carware_final2.c
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
#include "rtwtypes.h"
#include <math.h>
#include "Carware_final2_private.h"
#include <string.h>
#include "rt_nonfinite.h"

/* Named constants for Chart: '<Root>/Chart' */
#define Carware_fin_IN_ContractRecovery ((uint8_T)1U)
#define Carware_fina_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Carware_final2_IN_Empty        ((uint8_T)2U)
#define Carware_final2_IN_Init         ((uint8_T)3U)
#define Carware_final2_IN_SalesRecovery ((uint8_T)4U)
#define Carware_final2_IN_Update       ((uint8_T)5U)

/* Named constants for Chart: '<Root>/Chart1' */
#define Carware_final2_IN_BC           ((uint8_T)1U)
#define Carware_final2_IN_Full         ((uint8_T)2U)
#define Carware_final2_IN_NoInsurance  ((uint8_T)4U)
#define Carware_final2_IN_Package1     ((uint8_T)5U)
#define Carware_final2_IN_Package2     ((uint8_T)6U)
#define Carware_final2_IN_Package3     ((uint8_T)7U)
#define Carware_final2_IN_Package4     ((uint8_T)8U)
#define Carware_final2_IN_Package5     ((uint8_T)9U)

/* Named constants for Chart: '<Root>/Chart2' */
#define Carware_final2_IN_Init_c       ((uint8_T)1U)
#define Carware_final2_IN_Normal       ((uint8_T)2U)
#define Carware_final2_IN_RecoveryC    ((uint8_T)3U)
#define Carware_final2_IN_RecoveryO    ((uint8_T)4U)

/* Named constants for Chart: '<Root>/External' */
#define Carware_final2_IN_Empty_b      ((uint8_T)1U)
#define Carware_final2_IN_Update_o     ((uint8_T)4U)

/* Named constants for State Transition Table: '<Root>/State Transition Table' */
#define Carware_final2_IN_Level1       ((uint8_T)1U)
#define Carware_final2_IN_Level2       ((uint8_T)2U)
#define Carware_final2_IN_Level3       ((uint8_T)3U)
#define Carware_final2_IN_Level4       ((uint8_T)4U)
#define Carware_final2_IN_Level5       ((uint8_T)5U)
#define Carware_final2_IN_Level6       ((uint8_T)6U)
#define Carware_final2_IN_Normal_i     ((uint8_T)7U)

/* Named constants for State Transition Table: '<Root>/State Transition Table1' */
#define Carware_final2_IN_Great        ((uint8_T)1U)
#define Carware_final2_IN_Init_f       ((uint8_T)2U)
#define Carware_final2_IN_Major        ((uint8_T)3U)
#define Carware_final2_IN_Moderate     ((uint8_T)4U)
#define Carware_final2_IN_Over         ((uint8_T)5U)
#define Carware_final2_IN_Strong       ((uint8_T)6U)

/* Named constants for State Transition Table: '<Root>/State Transition Table2' */
#define Carware_final2_IN_Great1       ((uint8_T)2U)
#define Carware_final2_IN_Major1       ((uint8_T)5U)
#define Carware_final2_IN_Major_g      ((uint8_T)4U)
#define Carware_final2_IN_Moderate_j   ((uint8_T)6U)
#define Carware_final2_IN_Over_a       ((uint8_T)7U)
#define Carware_final2_IN_Strong1      ((uint8_T)9U)
#define Carware_final2_IN_Strong_o     ((uint8_T)8U)

/* Named constants for State Transition Table: '<Root>/State Transition Table7' */
#define Carware_final2_IN_MBackup      ((uint8_T)3U)
#define Carware_final2_IN_Moderate_p   ((uint8_T)5U)
#define Carware_final2_IN_Over_b       ((uint8_T)6U)
#define Carware_final2_IN_Strong_l     ((uint8_T)7U)

/* Named constants for State Transition Table: '<Root>/State Transition Table8' */
#define Carware_final2_IN_ABackup      ((uint8_T)1U)
#define Carware_final2_IN_Great_c      ((uint8_T)2U)

/* Named constants for State Transition Table: '<Root>/State Transition Table9' */
#define Carware_final2_IN_ITBackup     ((uint8_T)2U)

/* Block signals (default storage) */
B_Carware_final2_T Carware_final2_B;

/* Continuous states */
X_Carware_final2_T Carware_final2_X;

/* Block states (default storage) */
DW_Carware_final2_T Carware_final2_DW;

/* Real-time model */
static RT_MODEL_Carware_final2_T Carware_final2_M_;
RT_MODEL_Carware_final2_T *const Carware_final2_M = &Carware_final2_M_;

/* Forward declaration for local functions */
static void Carw_enter_atomic_SalesRecovery(void);
static void Carware_fin_enter_atomic_Update(void);
static void Carware_f_enter_atomic_Update_b(void);
static void Carware_final2_enter_atomic_BC(void);
static void Carware_f_enter_atomic_Update_l(void);

/*
 * Writes out MAT-file header.  Returns success or failure.
 * Returns:
 * 0 - success
 * 1 - failure
 */
int_T rt_WriteMat4FileHeader(FILE *fp, int32_T m, int32_T n, const char *name)
{
  typedef enum { ELITTLE_ENDIAN, EBIG_ENDIAN } ByteOrder;

  int16_T one = 1;
  ByteOrder byteOrder = (*((int8_T *)&one)==1) ? ELITTLE_ENDIAN : EBIG_ENDIAN;
  int32_T type = (byteOrder == ELITTLE_ENDIAN) ? 0: 1000;
  int32_T imagf = 0;
  int32_T name_len = (int32_T)strlen(name) + 1;
  if ((fwrite(&type, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&m, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&n, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&imagf, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&name_len, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(name, sizeof(char), name_len, fp) == 0)) {
    return(1);
  } else {
    return(0);
  }
}                                      /* end rt_WriteMat4FileHeader */

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 11;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Carware_final2_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Carware_final2_step();
  Carware_final2_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Carware_final2_step();
  Carware_final2_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Function for Chart: '<Root>/Chart' */
static void Carw_enter_atomic_SalesRecovery(void)
{
  if (((Carware_final2_B.Orders - 1.0) + Carware_final2_B.Add1) +
      Carware_final2_B.SliderGain < Carware_final2_B.Switch1) {
    Carware_final2_B.Orders = 1.0;
  } else {
    Carware_final2_B.Orders = ((Carware_final2_B.Orders + Carware_final2_B.Add1)
      + Carware_final2_B.SliderGain) - Carware_final2_B.Switch1;
  }

  if (Carware_final2_B.Switch7 >= 0.0) {
    Carware_final2_DW.ShippingS = Carware_final2_B.Switch7 - 0.5;
  }

  if (Carware_final2_B.Switch7 < 0.5) {
    Carware_final2_DW.ShippingS = 0.0;
  }

  Carware_final2_DW.ShippedS += Carware_final2_DW.ShippingS;
  Carware_final2_DW.OSales = (Carware_final2_DW.OSales + Carware_final2_B.Add1)
    - Carware_final2_DW.ShippingS;
}

/* Function for Chart: '<Root>/External' */
static void Carware_fin_enter_atomic_Update(void)
{
  Carware_final2_B.LxEP = 3.0;
  Carware_final2_B.AxEP = 3.0;
  if ((Carware_final2_B.Inventory < 1.0) && (Carware_final2_DW.Damage == 0.0)) {
    Carware_final2_B.Loss = (1.0 - Carware_final2_B.Inventory) *
      Carware_final2_B.EParts;
    Carware_final2_B.EParts *= Carware_final2_B.Inventory;
    Carware_final2_DW.Damage = 1.0;
  }

  if ((Carware_final2_B.Switch1 == 1.0) && (fabs(Carware_final2_B.EParts -
        Carware_final2_P.solution2_6) < fabs(1.0 - Carware_final2_B.Switch3))) {
    /* Constant: '<Root>/DEP' */
    Carware_final2_B.EParts = Carware_final2_P.solution2_6;
  } else {
    Carware_final2_B.EParts = (Carware_final2_B.EParts +
      Carware_final2_B.Switch3) - Carware_final2_B.Switch1;
  }

  if (Carware_final2_B.EParts < 0.0) {
    Carware_final2_B.AxEP = Carware_final2_B.Switch3;
    Carware_final2_B.EParts = 0.0;
  } else if (Carware_final2_B.EParts > Carware_final2_B.Add7) {
    Carware_final2_B.LxEP = Carware_final2_B.Switch1;
    Carware_final2_B.EParts = Carware_final2_B.Add7;
  }
}

/* Function for Chart: '<Root>/Internal' */
static void Carware_f_enter_atomic_Update_b(void)
{
  Carware_final2_B.MxIP = 3.0;
  Carware_final2_B.AxIP = 3.0;
  if ((Carware_final2_B.Inventory < 1.0) && (Carware_final2_DW.DamageIP == 0.0))
  {
    Carware_final2_B.LossIP = (1.0 - Carware_final2_B.Inventory) *
      Carware_final2_B.IParts;
    Carware_final2_B.IParts *= Carware_final2_B.Inventory;
    Carware_final2_DW.DamageIP = 1.0;
  }

  if (((Carware_final2_B.Switch1 == 1.0) || (Carware_final2_B.Switch == 1.0)) &&
      (fabs(Carware_final2_B.IParts - Carware_final2_P.solution2_5) < fabs
       (Carware_final2_B.Switch1 - Carware_final2_B.Switch))) {
    /* Constant: '<Root>/DIP' */
    Carware_final2_B.IParts = Carware_final2_P.solution2_5;
  } else {
    Carware_final2_B.IParts = (Carware_final2_B.IParts + Carware_final2_B.Switch)
      - Carware_final2_B.Switch1;
  }

  if (Carware_final2_B.IParts < 0.0) {
    Carware_final2_B.AxIP = Carware_final2_B.Switch;
    Carware_final2_B.IParts = 0.0;
  } else if (Carware_final2_B.IParts > Carware_final2_B.Add6) {
    Carware_final2_B.MxIP = Carware_final2_B.Switch1;
    Carware_final2_B.IParts = Carware_final2_B.Add6;
  }
}

/* Function for Chart: '<Root>/Chart1' */
static void Carware_final2_enter_atomic_BC(void)
{
  if (Carware_final2_B.Delayed > 8.0) {
    Carware_final2_DW.Coverage = 7.0;
  }

  if (Carware_final2_B.Delayed > 7.0) {
    Carware_final2_DW.Coverage = 6.0;
  }

  if (Carware_final2_B.Delayed > 6.0) {
    Carware_final2_DW.Coverage = 5.0;
  }

  if (Carware_final2_B.Delayed > 5.0) {
    Carware_final2_DW.Coverage = 4.0;
  }

  if (Carware_final2_B.Add18 > Carware_final2_DW.Coverage) {
    Carware_final2_B.NLBC = Carware_final2_B.Add18 - Carware_final2_DW.Coverage;
  } else {
    Carware_final2_B.NLBC = 0.0;
  }

  Carware_final2_B.NL = ((Carware_final2_B.NLBuilding +
    Carware_final2_B.NLProperty) + Carware_final2_B.NLProfit) +
    Carware_final2_B.NLBC;
}

/* Function for Chart: '<Root>/Raw Material' */
static void Carware_f_enter_atomic_Update_l(void)
{
  if ((Carware_final2_B.Switch == 1.0) && (fabs(Carware_final2_B.RawMaterial -
        Carware_final2_P.solution2_4) < fabs(1.0 - Carware_final2_B.Switch5))) {
    /* Constant: '<Root>/DRM' */
    Carware_final2_B.RawMaterial = Carware_final2_P.solution2_4;
  } else {
    Carware_final2_B.RawMaterial = (Carware_final2_B.RawMaterial +
      Carware_final2_B.Switch5) - Carware_final2_B.Switch;
  }

  /* Constant: '<Root>/DRM' */
  if ((Carware_final2_B.Switch == 1.0) && (Carware_final2_B.RawMaterial >
       Carware_final2_P.solution2_4)) {
    Carware_final2_B.LxRM = 0.0;
  } else {
    Carware_final2_B.MxRM = 3.0;
    Carware_final2_B.LxRM = 3.0;
  }

  if (Carware_final2_B.RawMaterial < 0.0) {
    Carware_final2_B.MxRM = Carware_final2_B.Switch5;
    Carware_final2_B.RawMaterial = 0.0;
  } else if (Carware_final2_B.RawMaterial > Carware_final2_B.Add8) {
    Carware_final2_B.LxRM = Carware_final2_B.Switch;
    Carware_final2_B.RawMaterial = Carware_final2_B.Add8;
  }
}

/* Model step function */
void Carware_final2_step(void)
{
  if (rtmIsMajorTimeStep(Carware_final2_M)) {
    /* set solver stop time */
    if (!(Carware_final2_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Carware_final2_M->solverInfo,
                            ((Carware_final2_M->Timing.clockTickH0 + 1) *
        Carware_final2_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Carware_final2_M->solverInfo,
                            ((Carware_final2_M->Timing.clockTick0 + 1) *
        Carware_final2_M->Timing.stepSize0 +
        Carware_final2_M->Timing.clockTickH0 *
        Carware_final2_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Carware_final2_M)) {
    Carware_final2_M->Timing.t[0] = rtsiGetT(&Carware_final2_M->solverInfo);
  }

  {
    real_T rtb_TmpSignalConversionAtToFile[22];
    real_T AxO_tmp;
    real_T rtb_Add21;
    real_T rtb_Add22;
    real_T rtb_AssemEq;
    real_T rtb_Assembly;
    real_T rtb_Delayed;
    real_T rtb_Delayed_js;
    real_T rtb_Delayed_n;
    real_T rtb_Gain4;
    real_T rtb_ITEq;
    real_T rtb_InboundLogistics;
    real_T rtb_InboundLogistics_e;
    real_T rtb_LogisticsCenter;
    real_T rtb_MainFacility;
    real_T rtb_ManufEq;
    real_T rtb_MinMax_j;
    real_T rtb_Mnf;
    real_T rtb_Product10;
    real_T rtb_Product15;
    real_T rtb_Product16;
    real_T rtb_Product17;
    real_T rtb_Product5;
    real_T rtb_Product6;
    real_T rtb_Product8;
    real_T rtb_Switch13;
    real_T rtb_Switch2;
    real_T rtb_Switch4;
    real_T rtb_Switch9;
    real_T rtb_Warehouse;
    boolean_T guard1;
    boolean_T rtb_Compare_bi;
    boolean_T rtb_LogicalOperator;
    boolean_T rtb_LogicalOperator1;
    boolean_T rtb_LogicalOperator2;
    boolean_T rtb_LogicalOperator4;
    boolean_T rtb_LogicalOperator5;
    boolean_T rtb_LogicalOperator7;
    boolean_T rtb_RelationalOperator1;
    if (rtmIsMajorTimeStep(Carware_final2_M)) {
      /* Product: '<Root>/Product9' incorporates:
       *  Constant: '<Root>/AB deployment'
       *  Constant: '<Root>/ABackup price'
       *  Constant: '<Root>/BAE'
       *  Sum: '<Root>/Add19'
       */
      rtb_Add21 = (Carware_final2_P.ABackupprice_Value +
                   Carware_final2_P.ABdeployment_Value) *
        Carware_final2_P.solution3_2;

      /* Delay: '<Root>/Delay19' */
      Carware_final2_B.Delayed = Carware_final2_DW.Delay19_DSTATE[0];

      /* State Transition Table: '<Root>/State Transition Table8' incorporates:
       *  Constant: '<Root>/BAE'
       */
      if (Carware_final2_DW.is_active_c14_Carware_final2 == 0U) {
        Carware_final2_DW.is_active_c14_Carware_final2 = 1U;
        Carware_final2_DW.is_c14_Carware_final2 = Carware_final2_IN_Init;
        Carware_final2_DW.T_b = 0.0;
        rtb_AssemEq = 1.0;
        Carware_final2_B.Damage_m = 0.0;
      } else {
        switch (Carware_final2_DW.is_c14_Carware_final2) {
         case Carware_final2_IN_ABackup:
          if (Carware_final2_DW.T_b >= Carware_final2_DW.RT_p) {
            Carware_final2_DW.is_c14_Carware_final2 = Carware_final2_IN_Over_b;
            rtb_AssemEq = 1.0;
          } else {
            rtb_AssemEq = 0.0;
            Carware_final2_DW.RT_p = 4.0;
            Carware_final2_DW.T_b++;
          }
          break;

         case Carware_final2_IN_Great_c:
          if (Carware_final2_DW.T_b >= Carware_final2_DW.RT_p) {
            Carware_final2_DW.is_c14_Carware_final2 = Carware_final2_IN_Over_b;
            rtb_AssemEq = 1.0;
          } else if (Carware_final2_P.solution3_2 > 0.0) {
            Carware_final2_DW.is_c14_Carware_final2 = Carware_final2_IN_ABackup;
            rtb_AssemEq = 0.0;
            Carware_final2_DW.RT_p = 4.0;
            Carware_final2_DW.T_b++;
          } else {
            rtb_AssemEq = 0.0;
            Carware_final2_DW.RT_p = 180.0;
            Carware_final2_DW.T_b++;
          }
          break;

         case Carware_final2_IN_Init:
          if (Carware_final2_B.Delayed >= 8.0) {
            Carware_final2_B.Damage_m = 5.0;
            Carware_final2_DW.is_c14_Carware_final2 = Carware_final2_IN_Great_c;
            rtb_AssemEq = 0.0;
            Carware_final2_DW.RT_p = 180.0;
            Carware_final2_DW.T_b++;
          } else if (Carware_final2_B.Delayed >= 7.0) {
            Carware_final2_B.Damage_m = 2.5;
            Carware_final2_DW.is_c14_Carware_final2 = Carware_final2_IN_Major_g;
            rtb_AssemEq = 0.0;
            Carware_final2_DW.RT_p = 20.0;
            Carware_final2_DW.T_b++;
          } else if (Carware_final2_B.Delayed >= 6.0) {
            Carware_final2_B.Damage_m = 1.0;
            Carware_final2_DW.is_c14_Carware_final2 = Carware_final2_IN_Strong_l;
            rtb_AssemEq = 0.0;
            Carware_final2_DW.RT_p = 7.0;
            Carware_final2_DW.T_b++;
          } else if (Carware_final2_B.Delayed >= 5.0) {
            Carware_final2_B.Damage_m = 0.25;
            Carware_final2_DW.is_c14_Carware_final2 =
              Carware_final2_IN_Moderate_p;
            rtb_AssemEq = 0.0;
            Carware_final2_DW.RT_p = 1.0;
            Carware_final2_DW.T_b++;
          } else {
            Carware_final2_DW.T_b = 0.0;
            rtb_AssemEq = 1.0;
            Carware_final2_B.Damage_m = 0.0;
          }
          break;

         case Carware_final2_IN_Major_g:
          if (Carware_final2_DW.T_b >= Carware_final2_DW.RT_p) {
            Carware_final2_DW.is_c14_Carware_final2 = Carware_final2_IN_Over_b;
            rtb_AssemEq = 1.0;
          } else if (Carware_final2_P.solution3_2 > 0.0) {
            Carware_final2_DW.is_c14_Carware_final2 = Carware_final2_IN_ABackup;
            rtb_AssemEq = 0.0;
            Carware_final2_DW.RT_p = 4.0;
            Carware_final2_DW.T_b++;
          } else {
            rtb_AssemEq = 0.0;
            Carware_final2_DW.RT_p = 20.0;
            Carware_final2_DW.T_b++;
          }
          break;

         case Carware_final2_IN_Moderate_p:
          Carware_final2_DW.is_c14_Carware_final2 = Carware_final2_IN_Over_b;
          rtb_AssemEq = 1.0;
          break;

         case Carware_final2_IN_Over_b:
          rtb_AssemEq = 1.0;
          break;

         default:
          /* case IN_Strong: */
          if (Carware_final2_DW.T_b >= Carware_final2_DW.RT_p) {
            Carware_final2_DW.is_c14_Carware_final2 = Carware_final2_IN_Over_b;
            rtb_AssemEq = 1.0;
          } else if (Carware_final2_P.solution3_2 > 0.0) {
            Carware_final2_DW.is_c14_Carware_final2 = Carware_final2_IN_ABackup;
            rtb_AssemEq = 0.0;
            Carware_final2_DW.RT_p = 4.0;
            Carware_final2_DW.T_b++;
          } else {
            rtb_AssemEq = 0.0;
            Carware_final2_DW.RT_p = 7.0;
            Carware_final2_DW.T_b++;
          }
          break;
        }
      }

      /* End of State Transition Table: '<Root>/State Transition Table8' */
      /* Product: '<Root>/Product17' incorporates:
       *  Constant: '<Root>/LCR'
       *  Constant: '<Root>/LCR price'
       */
      rtb_Product17 = Carware_final2_P.solution5_3 *
        Carware_final2_P.LCRprice_Value;

      /* Product: '<Root>/Product16' incorporates:
       *  Constant: '<Root>/WR'
       *  Constant: '<Root>/WR price'
       */
      rtb_Product16 = Carware_final2_P.solution5_2 *
        Carware_final2_P.WRprice_Value;

      /* Product: '<Root>/Product15' incorporates:
       *  Constant: '<Root>/MFR'
       *  Constant: '<Root>/MFR price'
       */
      rtb_Product15 = Carware_final2_P.solution5_1 *
        Carware_final2_P.MFRprice_Value;

      /* Product: '<Root>/Product10' incorporates:
       *  Constant: '<Root>/BME'
       *  Constant: '<Root>/MB deployment'
       *  Constant: '<Root>/MBackup price'
       *  Sum: '<Root>/Add20'
       */
      rtb_Product10 = (Carware_final2_P.MBackupprice_Value +
                       Carware_final2_P.MBdeployment_Value) *
        Carware_final2_P.solution3_1;

      /* Product: '<Root>/Product7' incorporates:
       *  Constant: '<Root>/AEP'
       *  Constant: '<Root>/EPC'
       */
      rtb_MinMax_j = Carware_final2_P.solution2_3 * Carware_final2_P.EPC_Value;

      /* Product: '<Root>/Product8' incorporates:
       *  Constant: '<Root>/ARM'
       *  Constant: '<Root>/RMC'
       */
      rtb_Product8 = Carware_final2_P.solution2_1 * Carware_final2_P.RMC_Value;

      /* Product: '<Root>/Product6' incorporates:
       *  Constant: '<Root>/AIP'
       *  Constant: '<Root>/IPC'
       */
      rtb_Product6 = Carware_final2_P.solution2_2 * Carware_final2_P.IPC_Value;

      /* Product: '<Root>/Product5' incorporates:
       *  Constant: '<Root>/AFP'
       *  Constant: '<Root>/FPC '
       */
      rtb_Product5 = Carware_final2_P.solution1_1 * Carware_final2_P.FPC_Value;

      /* Sum: '<Root>/Add21' */
      rtb_Add21 = (((((((rtb_Product17 + rtb_Product16) + rtb_Product15) +
                       rtb_Add21) + rtb_Product10) + rtb_MinMax_j) +
                    rtb_Product8) + rtb_Product6) + rtb_Product5;

      /* Delay: '<Root>/Delay8' */
      rtb_InboundLogistics = Carware_final2_DW.Delay8_DSTATE;

      /* Delay: '<Root>/Delay1' */
      rtb_Switch4 = Carware_final2_DW.Delay1_DSTATE;

      /* Delay: '<Root>/Delay9' */
      rtb_Switch2 = Carware_final2_DW.Delay9_DSTATE;

      /* State Transition Table: '<Root>/State Transition Table6' */
      if (Carware_final2_DW.is_active_c12_Carware_final2 == 0U) {
        Carware_final2_DW.is_active_c12_Carware_final2 = 1U;
        Carware_final2_DW.is_c12_Carware_final2 = Carware_final2_IN_Init_f;
        Carware_final2_DW.T_k = 0.0;
        rtb_LogisticsCenter = 1.0;
        Carware_final2_B.Damage_l = 0.0;
      } else {
        guard1 = false;
        switch (Carware_final2_DW.is_c12_Carware_final2) {
         case Carware_final2_IN_Great:
          if (Carware_final2_DW.T_k >= Carware_final2_DW.RT_c) {
            Carware_final2_DW.is_c12_Carware_final2 = Carware_final2_IN_Over;
            rtb_LogisticsCenter = 1.0;
          } else {
            rtb_LogisticsCenter = 0.0;
            Carware_final2_DW.RT_c = 90.0;
            Carware_final2_DW.T_k++;
          }
          break;

         case Carware_final2_IN_Init_f:
          if ((Carware_final2_B.Delayed > 0.0) && (Carware_final2_P.solution5_3 ==
               1.0)) {
            guard1 = true;
          } else if (Carware_final2_B.Delayed >= 8.0) {
            Carware_final2_B.Damage_l = 6.0;
            Carware_final2_DW.is_c12_Carware_final2 = Carware_final2_IN_Great;
            rtb_LogisticsCenter = 0.0;
            Carware_final2_DW.RT_c = 90.0;
            Carware_final2_DW.T_k++;
          } else if (Carware_final2_B.Delayed >= 7.0) {
            Carware_final2_B.Damage_l = 3.6;
            Carware_final2_DW.is_c12_Carware_final2 = Carware_final2_IN_Major;
            rtb_LogisticsCenter = 0.0;
            Carware_final2_DW.RT_c = 45.0;
            Carware_final2_DW.T_k++;
          } else if (Carware_final2_B.Delayed >= 6.0) {
            Carware_final2_B.Damage_l = 1.5;
            Carware_final2_DW.is_c12_Carware_final2 = Carware_final2_IN_Strong;
            rtb_LogisticsCenter = 0.0;
            Carware_final2_DW.RT_c = 10.0;
            Carware_final2_DW.T_k++;
          } else if (Carware_final2_B.Delayed >= 5.0) {
            guard1 = true;
          } else {
            Carware_final2_DW.T_k = 0.0;
            rtb_LogisticsCenter = 1.0;
            Carware_final2_B.Damage_l = 0.0;
          }
          break;

         case Carware_final2_IN_Major:
          if (Carware_final2_DW.T_k >= Carware_final2_DW.RT_c) {
            Carware_final2_DW.is_c12_Carware_final2 = Carware_final2_IN_Over;
            rtb_LogisticsCenter = 1.0;
          } else {
            rtb_LogisticsCenter = 0.0;
            Carware_final2_DW.RT_c = 45.0;
            Carware_final2_DW.T_k++;
          }
          break;

         case Carware_final2_IN_Moderate:
          if (Carware_final2_DW.T_k >= Carware_final2_DW.RT_c) {
            Carware_final2_DW.is_c12_Carware_final2 = Carware_final2_IN_Over;
            rtb_LogisticsCenter = 1.0;
          } else {
            rtb_LogisticsCenter = 0.0;
            Carware_final2_DW.RT_c = 1.0;
            Carware_final2_DW.T_k++;
          }
          break;

         case Carware_final2_IN_Over:
          rtb_LogisticsCenter = 1.0;
          break;

         default:
          /* case IN_Strong: */
          if (Carware_final2_DW.T_k >= Carware_final2_DW.RT_c) {
            Carware_final2_DW.is_c12_Carware_final2 = Carware_final2_IN_Over;
            rtb_LogisticsCenter = 1.0;
          } else {
            rtb_LogisticsCenter = 0.0;
            Carware_final2_DW.RT_c = 10.0;
            Carware_final2_DW.T_k++;
          }
          break;
        }

        if (guard1) {
          Carware_final2_DW.is_c12_Carware_final2 = Carware_final2_IN_Moderate;
          rtb_LogisticsCenter = 0.0;
          Carware_final2_DW.RT_c = 1.0;
          Carware_final2_DW.T_k++;
        }
      }

      /* End of State Transition Table: '<Root>/State Transition Table6' */

      /* State Transition Table: '<Root>/State Transition Table9' incorporates:
       *  Constant: '<Root>/IT backup'
       */
      if (Carware_final2_DW.is_active_c3_Carware_final2 == 0U) {
        Carware_final2_DW.is_active_c3_Carware_final2 = 1U;
        Carware_final2_DW.is_c3_Carware_final2 = Carware_final2_IN_Init;
        Carware_final2_DW.T = 0.0;
        rtb_ITEq = 1.0;
        Carware_final2_B.Damage = 0.0;
      } else {
        switch (Carware_final2_DW.is_c3_Carware_final2) {
         case Carware_final2_IN_Great:
          if (Carware_final2_DW.T >= Carware_final2_DW.RT_f) {
            Carware_final2_DW.is_c3_Carware_final2 = Carware_final2_IN_Over_b;
            rtb_ITEq = 1.0;
          } else if (Carware_final2_P.ITbackup_Value > 0.0) {
            Carware_final2_DW.is_c3_Carware_final2 = Carware_final2_IN_ITBackup;
            rtb_ITEq = 0.0;
            Carware_final2_DW.RT_f = 4.0;
            Carware_final2_DW.T++;
          } else {
            rtb_ITEq = 0.0;
            Carware_final2_DW.RT_f = 30.0;
            Carware_final2_DW.T++;
          }
          break;

         case Carware_final2_IN_ITBackup:
          if (Carware_final2_DW.T >= Carware_final2_DW.RT_f) {
            Carware_final2_DW.is_c3_Carware_final2 = Carware_final2_IN_Over_b;
            rtb_ITEq = 1.0;
          } else {
            rtb_ITEq = 0.0;
            Carware_final2_DW.RT_f = 4.0;
            Carware_final2_DW.T++;
          }
          break;

         case Carware_final2_IN_Init:
          if (Carware_final2_B.Delayed >= 8.0) {
            Carware_final2_B.Damage = 2.5;
            Carware_final2_DW.is_c3_Carware_final2 = Carware_final2_IN_Great;
            rtb_ITEq = 0.0;
            Carware_final2_DW.RT_f = 30.0;
            Carware_final2_DW.T++;
          } else if (Carware_final2_B.Delayed >= 7.0) {
            Carware_final2_B.Damage = 1.5;
            Carware_final2_DW.is_c3_Carware_final2 = Carware_final2_IN_Major_g;
            rtb_ITEq = 0.0;
            Carware_final2_DW.RT_f = 5.0;
            Carware_final2_DW.T++;
          } else if (Carware_final2_B.Delayed >= 6.0) {
            Carware_final2_B.Damage = 0.45;
            Carware_final2_DW.is_c3_Carware_final2 = Carware_final2_IN_Strong_l;
            rtb_ITEq = 0.0;
            Carware_final2_DW.RT_f = 1.0;
            Carware_final2_DW.T++;
          } else if (Carware_final2_B.Delayed >= 5.0) {
            Carware_final2_DW.is_c3_Carware_final2 =
              Carware_final2_IN_Moderate_p;
            rtb_ITEq = 1.0;
          } else {
            Carware_final2_DW.T = 0.0;
            rtb_ITEq = 1.0;
            Carware_final2_B.Damage = 0.0;
          }
          break;

         case Carware_final2_IN_Major_g:
          if (Carware_final2_DW.T >= Carware_final2_DW.RT_f) {
            Carware_final2_DW.is_c3_Carware_final2 = Carware_final2_IN_Over_b;
            rtb_ITEq = 1.0;
          } else if (Carware_final2_P.ITbackup_Value > 0.0) {
            Carware_final2_DW.is_c3_Carware_final2 = Carware_final2_IN_ITBackup;
            rtb_ITEq = 0.0;
            Carware_final2_DW.RT_f = 4.0;
            Carware_final2_DW.T++;
          } else {
            rtb_ITEq = 0.0;
            Carware_final2_DW.RT_f = 5.0;
            Carware_final2_DW.T++;
          }
          break;

         case Carware_final2_IN_Moderate_p:
          Carware_final2_DW.is_c3_Carware_final2 = Carware_final2_IN_Over_b;
          rtb_ITEq = 1.0;
          break;

         case Carware_final2_IN_Over_b:
          rtb_ITEq = 1.0;
          break;

         default:
          /* case IN_Strong: */
          if (Carware_final2_DW.T >= Carware_final2_DW.RT_f) {
            Carware_final2_DW.is_c3_Carware_final2 = Carware_final2_IN_Over_b;
            rtb_ITEq = 1.0;
          } else if (Carware_final2_P.ITbackup_Value > 0.0) {
            Carware_final2_DW.is_c3_Carware_final2 = Carware_final2_IN_ITBackup;
            rtb_ITEq = 0.0;
            Carware_final2_DW.RT_f = 4.0;
            Carware_final2_DW.T++;
          } else {
            rtb_ITEq = 0.0;
            Carware_final2_DW.RT_f = 1.0;
            Carware_final2_DW.T++;
          }
          break;
        }
      }

      /* End of State Transition Table: '<Root>/State Transition Table9' */

      /* State Transition Table: '<Root>/State Transition Table2' */
      if (Carware_final2_DW.is_active_c8_Carware_final2 == 0U) {
        Carware_final2_DW.is_active_c8_Carware_final2 = 1U;
        Carware_final2_DW.is_c8_Carware_final2 = Carware_final2_IN_Init;
        Carware_final2_DW.T_g = 0.0;
        Carware_final2_B.Electricity = 1.0;
      } else {
        switch (Carware_final2_DW.is_c8_Carware_final2) {
         case Carware_final2_IN_Great:
          if (Carware_final2_DW.T_g >= Carware_final2_DW.RTe) {
            Carware_final2_DW.is_c8_Carware_final2 = Carware_final2_IN_Great1;
            Carware_final2_B.Electricity = 0.4;
            Carware_final2_DW.FRe = 90.0;
            Carware_final2_DW.T_g++;
          } else {
            Carware_final2_B.Electricity = 0.0;
            Carware_final2_DW.RTe = 45.0;
            Carware_final2_DW.T_g++;
          }
          break;

         case Carware_final2_IN_Great1:
          if (Carware_final2_DW.T_g >= Carware_final2_DW.FRe) {
            Carware_final2_DW.is_c8_Carware_final2 = Carware_final2_IN_Over_a;
            Carware_final2_B.Electricity = 1.0;
          } else {
            Carware_final2_B.Electricity = 0.4;
            Carware_final2_DW.FRe = 90.0;
            Carware_final2_DW.T_g++;
          }
          break;

         case Carware_final2_IN_Init:
          if (Carware_final2_B.Delayed >= 8.0) {
            Carware_final2_DW.is_c8_Carware_final2 = Carware_final2_IN_Great;
            Carware_final2_B.Electricity = 0.0;
            Carware_final2_DW.RTe = 45.0;
            Carware_final2_DW.T_g++;
          } else if (Carware_final2_B.Delayed >= 7.0) {
            Carware_final2_DW.is_c8_Carware_final2 = Carware_final2_IN_Major_g;
            Carware_final2_B.Electricity = 0.0;
            Carware_final2_DW.RTe = 10.0;
            Carware_final2_DW.T_g++;
          } else if (Carware_final2_B.Delayed >= 6.0) {
            Carware_final2_DW.is_c8_Carware_final2 = Carware_final2_IN_Strong_o;
            Carware_final2_B.Electricity = 0.0;
            Carware_final2_DW.RTe = 3.0;
            Carware_final2_DW.T_g++;
          } else if (Carware_final2_B.Delayed >= 5.0) {
            Carware_final2_DW.is_c8_Carware_final2 =
              Carware_final2_IN_Moderate_j;
          } else {
            Carware_final2_DW.T_g = 0.0;
            Carware_final2_B.Electricity = 1.0;
          }
          break;

         case Carware_final2_IN_Major_g:
          if (Carware_final2_DW.T_g >= Carware_final2_DW.RTe) {
            Carware_final2_DW.is_c8_Carware_final2 = Carware_final2_IN_Major1;
            Carware_final2_B.Electricity = 0.5;
            Carware_final2_DW.FRe = 30.0;
            Carware_final2_DW.T_g++;
          } else {
            Carware_final2_B.Electricity = 0.0;
            Carware_final2_DW.RTe = 10.0;
            Carware_final2_DW.T_g++;
          }
          break;

         case Carware_final2_IN_Major1:
          if (Carware_final2_DW.T_g >= Carware_final2_DW.FRe) {
            Carware_final2_DW.is_c8_Carware_final2 = Carware_final2_IN_Over_a;
            Carware_final2_B.Electricity = 1.0;
          } else {
            Carware_final2_B.Electricity = 0.5;
            Carware_final2_DW.FRe = 30.0;
            Carware_final2_DW.T_g++;
          }
          break;

         case Carware_final2_IN_Moderate_j:
          break;

         case Carware_final2_IN_Over_a:
          Carware_final2_B.Electricity = 1.0;
          break;

         case Carware_final2_IN_Strong_o:
          if (Carware_final2_DW.T_g >= Carware_final2_DW.RTe) {
            Carware_final2_DW.is_c8_Carware_final2 = Carware_final2_IN_Strong1;
            Carware_final2_B.Electricity = 1.0;
            Carware_final2_DW.FRe = 3.0;
            Carware_final2_DW.T_g++;
          } else {
            Carware_final2_B.Electricity = 0.0;
            Carware_final2_DW.RTe = 3.0;
            Carware_final2_DW.T_g++;
          }
          break;

         default:
          /* case IN_Strong1: */
          if (Carware_final2_DW.T_g >= Carware_final2_DW.FRe) {
            Carware_final2_DW.is_c8_Carware_final2 = Carware_final2_IN_Over_a;
            Carware_final2_B.Electricity = 1.0;
          } else {
            Carware_final2_B.Electricity = 1.0;
            Carware_final2_DW.FRe = 3.0;
            Carware_final2_DW.T_g++;
          }
          break;
        }
      }

      /* End of State Transition Table: '<Root>/State Transition Table2' */

      /* MinMax: '<Root>/MinMax1' */
      rtb_Assembly = fmin(fmin(fmin(rtb_LogisticsCenter, rtb_ITEq),
        Carware_final2_B.Electricity), rtb_AssemEq);

      /* Delay: '<Root>/Delay6' */
      rtb_Delayed_n = Carware_final2_DW.Delay6_DSTATE;

      /* MinMax: '<Root>/MinMax2' */
      rtb_InboundLogistics = fmin(fmin(fmin(fmin(rtb_InboundLogistics,
        rtb_Switch4), rtb_Switch2), rtb_Assembly), rtb_Delayed_n);

      /* Delay: '<Root>/Delay11' */
      rtb_Delayed = Carware_final2_DW.Delay11_DSTATE;

      /* Logic: '<Root>/Logical Operator1' incorporates:
       *  Constant: '<S11>/Constant'
       *  Constant: '<S5>/Constant'
       *  Delay: '<Root>/Delay11'
       *  RelationalOperator: '<S11>/Compare'
       *  RelationalOperator: '<S5>/Compare'
       */
      rtb_LogicalOperator1 = ((Carware_final2_DW.Delay11_DSTATE >
        Carware_final2_P.CompareToConstant1_const) && (rtb_InboundLogistics >
        Carware_final2_P.CompareToConstant2_const));

      /* Switch: '<Root>/Switch1' */
      if (rtb_LogicalOperator1) {
        /* Switch: '<Root>/Switch1' incorporates:
         *  Gain: '<S30>/Slider Gain'
         */
        Carware_final2_B.Switch1 = Carware_final2_P.SliderGain4_gain *
          rtb_InboundLogistics;
      } else {
        /* Switch: '<Root>/Switch1' */
        Carware_final2_B.Switch1 = rtb_InboundLogistics;
      }

      /* End of Switch: '<Root>/Switch1' */

      /* Delay: '<Root>/Delay20' */
      Carware_final2_B.Delayed_f = Carware_final2_DW.Delay20_DSTATE[0];

      /* Gain: '<S28>/Slider Gain' incorporates:
       *  Constant: '<Root>/Constant3'
       */
      Carware_final2_B.SliderGain = Carware_final2_P.SliderGain2_gain *
        Carware_final2_P.Constant3_Value;

      /* Delay: '<Root>/Delay7' */
      rtb_Delayed_n = Carware_final2_DW.Delay7_DSTATE;

      /* State Transition Table: '<Root>/State Transition Table4' */
      if (Carware_final2_DW.is_active_c10_Carware_final2 == 0U) {
        Carware_final2_DW.is_active_c10_Carware_final2 = 1U;
        Carware_final2_DW.is_c10_Carware_final2 = Carware_final2_IN_Init;
        Carware_final2_DW.T_j = 0.0;
        Carware_final2_B.Logistics = 1.0;
      } else {
        switch (Carware_final2_DW.is_c10_Carware_final2) {
         case Carware_final2_IN_Great:
          if (Carware_final2_DW.T_j >= Carware_final2_DW.RTl) {
            Carware_final2_DW.is_c10_Carware_final2 = Carware_final2_IN_Great1;
            Carware_final2_B.Logistics = 0.3;
            Carware_final2_DW.FRl = 145.0;
            Carware_final2_DW.T_j++;
          } else {
            Carware_final2_B.Logistics = 0.0;
            Carware_final2_DW.RTl = 75.0;
            Carware_final2_DW.T_j++;
          }
          break;

         case Carware_final2_IN_Great1:
          if (Carware_final2_DW.T_j >= Carware_final2_DW.FRl) {
            Carware_final2_DW.is_c10_Carware_final2 = Carware_final2_IN_Over_a;
            Carware_final2_B.Logistics = 1.0;
          } else {
            Carware_final2_B.Logistics = 0.3;
            Carware_final2_DW.FRl = 145.0;
            Carware_final2_DW.T_j++;
          }
          break;

         case Carware_final2_IN_Init:
          if (Carware_final2_B.Delayed >= 8.0) {
            Carware_final2_DW.is_c10_Carware_final2 = Carware_final2_IN_Great;
            Carware_final2_B.Logistics = 0.0;
            Carware_final2_DW.RTl = 75.0;
            Carware_final2_DW.T_j++;
          } else if (Carware_final2_B.Delayed >= 7.0) {
            Carware_final2_DW.is_c10_Carware_final2 = Carware_final2_IN_Major_g;
            Carware_final2_B.Logistics = 0.0;
            Carware_final2_DW.RTl = 30.0;
            Carware_final2_DW.T_j++;
          } else if (Carware_final2_B.Delayed >= 6.0) {
            Carware_final2_DW.is_c10_Carware_final2 = Carware_final2_IN_Strong_o;
            Carware_final2_B.Logistics = 0.0;
            Carware_final2_DW.RTl = 3.0;
            Carware_final2_DW.T_j++;
          } else if (Carware_final2_B.Delayed >= 5.0) {
            Carware_final2_DW.is_c10_Carware_final2 =
              Carware_final2_IN_Moderate_j;
          } else {
            Carware_final2_DW.T_j = 0.0;
            Carware_final2_B.Logistics = 1.0;
          }
          break;

         case Carware_final2_IN_Major_g:
          if (Carware_final2_DW.T_j >= Carware_final2_DW.RTl) {
            Carware_final2_DW.is_c10_Carware_final2 = Carware_final2_IN_Major1;
            Carware_final2_B.Logistics = 0.5;
            Carware_final2_DW.FRl = 60.0;
            Carware_final2_DW.T_j++;
          } else {
            Carware_final2_B.Logistics = 0.0;
            Carware_final2_DW.RTl = 30.0;
            Carware_final2_DW.T_j++;
          }
          break;

         case Carware_final2_IN_Major1:
          if (Carware_final2_DW.T_j >= Carware_final2_DW.FRl) {
            Carware_final2_DW.is_c10_Carware_final2 = Carware_final2_IN_Over_a;
            Carware_final2_B.Logistics = 1.0;
          } else {
            Carware_final2_B.Logistics = 0.5;
            Carware_final2_DW.FRl = 60.0;
            Carware_final2_DW.T_j++;
          }
          break;

         case Carware_final2_IN_Moderate_j:
          break;

         case Carware_final2_IN_Over_a:
          Carware_final2_B.Logistics = 1.0;
          break;

         case Carware_final2_IN_Strong_o:
          if (Carware_final2_DW.T_j >= Carware_final2_DW.RTl) {
            Carware_final2_DW.is_c10_Carware_final2 = Carware_final2_IN_Strong1;
            Carware_final2_B.Logistics = 1.0;
            Carware_final2_DW.FRl = 3.0;
            Carware_final2_DW.T_j++;
          } else {
            Carware_final2_B.Logistics = 0.0;
            Carware_final2_DW.RTl = 3.0;
            Carware_final2_DW.T_j++;
          }
          break;

         default:
          /* case IN_Strong1: */
          if (Carware_final2_DW.T_j >= Carware_final2_DW.FRl) {
            Carware_final2_DW.is_c10_Carware_final2 = Carware_final2_IN_Over_a;
            Carware_final2_B.Logistics = 1.0;
          } else {
            Carware_final2_B.Logistics = 1.0;
            Carware_final2_DW.FRl = 3.0;
            Carware_final2_DW.T_j++;
          }
          break;
        }
      }

      /* End of State Transition Table: '<Root>/State Transition Table4' */

      /* Logic: '<Root>/Logical Operator7' incorporates:
       *  Constant: '<S8>/Constant'
       *  Constant: '<S9>/Constant'
       *  RelationalOperator: '<S8>/Compare'
       *  RelationalOperator: '<S9>/Compare'
       */
      rtb_LogicalOperator7 = ((rtb_Delayed_n >
        Carware_final2_P.CompareToConstant13_const) &&
        (Carware_final2_B.Logistics < Carware_final2_P.CompareToConstant12_const));

      /* Switch: '<Root>/Switch2' incorporates:
       *  Constant: '<Root>/Const1'
       *  Constant: '<Root>/OTFP'
       *  Constant: '<Root>/Truck capacity'
       *  Product: '<Root>/Product1'
       */
      if (rtb_LogicalOperator7) {
        rtb_Switch2 = Carware_final2_P.solution4_1 *
          Carware_final2_P.Truckcapacity_Value;
      } else {
        rtb_Switch2 = Carware_final2_P.Const1_Value;
      }

      /* End of Switch: '<Root>/Switch2' */

      /* Sum: '<Root>/Sum2' */
      rtb_Switch4 = rtb_Switch2 + Carware_final2_B.Logistics;

      /* MinMax: '<Root>/MinMax5' */
      rtb_Switch4 = fmin(rtb_Delayed_n, rtb_Switch4);

      /* Switch: '<Root>/Switch7' incorporates:
       *  Constant: '<S18>/Constant'
       *  Constant: '<S6>/Constant'
       *  Constant: '<S7>/Constant'
       *  Delay: '<Root>/Delay17'
       *  Logic: '<Root>/Logical Operator6'
       *  RelationalOperator: '<S18>/Compare'
       *  RelationalOperator: '<S6>/Compare'
       *  RelationalOperator: '<S7>/Compare'
       */
      if ((rtb_Delayed_n >= Carware_final2_P.CompareToConstant10_const) &&
          (Carware_final2_B.Logistics >
           Carware_final2_P.CompareToConstant9_const) &&
          (Carware_final2_DW.Delay17_DSTATE >
           Carware_final2_P.CompareToConstant11_const)) {
        /* Switch: '<Root>/Switch7' incorporates:
         *  Gain: '<S33>/Slider Gain'
         */
        Carware_final2_B.Switch7 = Carware_final2_P.SliderGain7_gain *
          rtb_Switch4;
      } else {
        /* Switch: '<Root>/Switch7' */
        Carware_final2_B.Switch7 = rtb_Switch4;
      }

      /* End of Switch: '<Root>/Switch7' */

      /* Sum: '<Root>/Add1' incorporates:
       *  Constant: '<Root>/Constant3'
       *  Gain: '<S26>/Slider Gain'
       *  Gain: '<S27>/Slider Gain'
       */
      Carware_final2_B.Add1 = Carware_final2_P.SliderGain1_gain *
        Carware_final2_P.Constant3_Value + Carware_final2_P.SliderGain_gain *
        rtb_ITEq;

      /* Chart: '<Root>/Chart2' */
      if (Carware_final2_DW.is_active_c6_Carware_final2 == 0U) {
        Carware_final2_DW.is_active_c6_Carware_final2 = 1U;
        Carware_final2_DW.is_c6_Carware_final2 = Carware_final2_IN_Init_c;
        Carware_final2_DW.Shipped = 0.0;
        Carware_final2_DW.TotalCont = 0.0;
        Carware_final2_B.Level = Carware_final2_B.Switch7 * 0.5;
        Carware_final2_DW.Return = 0.0;
      } else {
        switch (Carware_final2_DW.is_c6_Carware_final2) {
         case Carware_final2_IN_Init_c:
          if (Carware_final2_B.Level > 0.0) {
            Carware_final2_DW.is_c6_Carware_final2 = Carware_final2_IN_Normal;
            Carware_final2_B.CR = 0.0;
            Carware_final2_DW.Return = 0.0;
            Carware_final2_B.Level = Carware_final2_B.Switch7 * 0.5;
            Carware_final2_DW.Shipped += Carware_final2_B.Level;
            Carware_final2_DW.TotalCont += Carware_final2_B.SliderGain;
          } else {
            Carware_final2_DW.Shipped = 0.0;
            Carware_final2_DW.TotalCont = 0.0;
            Carware_final2_B.Level = Carware_final2_B.Switch7 * 0.5;
            Carware_final2_DW.Return = 0.0;
          }
          break;

         case Carware_final2_IN_Normal:
          if (Carware_final2_DW.TotalCont > Carware_final2_DW.Shipped) {
            Carware_final2_DW.is_c6_Carware_final2 = Carware_final2_IN_RecoveryC;
            Carware_final2_B.CR = 1.0;
            AxO_tmp = Carware_final2_DW.TotalCont - Carware_final2_DW.Shipped;
            if (AxO_tmp > Carware_final2_B.Switch7 - Carware_final2_B.SliderGain)
            {
              Carware_final2_B.Level = Carware_final2_B.Switch7;
            } else {
              Carware_final2_B.Level = AxO_tmp + Carware_final2_B.SliderGain;
              Carware_final2_DW.Return = 1.0;
            }

            Carware_final2_DW.Shipped += Carware_final2_B.Level;
            Carware_final2_DW.TotalCont += Carware_final2_B.SliderGain;
          } else {
            Carware_final2_B.CR = 0.0;
            Carware_final2_DW.Return = 0.0;
            Carware_final2_B.Level = Carware_final2_B.Switch7 * 0.5;
            Carware_final2_DW.Shipped += Carware_final2_B.Level;
            Carware_final2_DW.TotalCont += Carware_final2_B.SliderGain;
          }
          break;

         case Carware_final2_IN_RecoveryC:
          if (Carware_final2_DW.Return == 1.0) {
            Carware_final2_DW.is_c6_Carware_final2 = Carware_final2_IN_RecoveryO;
            Carware_final2_B.CR = 0.0;
            Carware_final2_B.Level = 0.5;
            Carware_final2_DW.Shipped += Carware_final2_B.Level;
            Carware_final2_DW.TotalCont += Carware_final2_B.SliderGain;
          } else {
            Carware_final2_B.CR = 1.0;
            AxO_tmp = Carware_final2_DW.TotalCont - Carware_final2_DW.Shipped;
            if (AxO_tmp > Carware_final2_B.Switch7 - Carware_final2_B.SliderGain)
            {
              Carware_final2_B.Level = Carware_final2_B.Switch7;
            } else {
              Carware_final2_B.Level = AxO_tmp + Carware_final2_B.SliderGain;
              Carware_final2_DW.Return = 1.0;
            }

            Carware_final2_DW.Shipped += Carware_final2_B.Level;
            Carware_final2_DW.TotalCont += Carware_final2_B.SliderGain;
          }
          break;

         default:
          /* case IN_RecoveryO: */
          if (Carware_final2_B.Switch7 == 1.0) {
            Carware_final2_DW.is_c6_Carware_final2 = Carware_final2_IN_Normal;
            Carware_final2_B.CR = 0.0;
            Carware_final2_DW.Return = 0.0;
            Carware_final2_B.Level = Carware_final2_B.Switch7 * 0.5;
            Carware_final2_DW.Shipped += Carware_final2_B.Level;
            Carware_final2_DW.TotalCont += Carware_final2_B.SliderGain;
          } else {
            Carware_final2_B.CR = 0.0;
            Carware_final2_B.Level = 0.5;
            Carware_final2_DW.Shipped += Carware_final2_B.Level;
            Carware_final2_DW.TotalCont += Carware_final2_B.SliderGain;
          }
          break;
        }
      }

      /* End of Chart: '<Root>/Chart2' */

      /* Chart: '<Root>/Chart' incorporates:
       *  Delay: '<Root>/Delay18'
       */
      if (Carware_final2_DW.is_active_c16_Carware_final2 == 0U) {
        Carware_final2_DW.is_active_c16_Carware_final2 = 1U;
        Carware_final2_DW.is_c16_Carware_final2 = Carware_final2_IN_Init;
        Carware_final2_B.AxO = 3.0;
        Carware_final2_B.Orders = 1.0;
        Carware_final2_DW.OSales = 0.5;
        Carware_final2_DW.ShippingS = 0.5;
        Carware_final2_DW.ShippedS = 0.5;
        Carware_final2_B.Loss_h = 0.0;
      } else {
        switch (Carware_final2_DW.is_c16_Carware_final2) {
         case Carware_fin_IN_ContractRecovery:
          if ((Carware_final2_B.CR == 0.0) && (Carware_final2_DW.OSales <= 0.5))
          {
            Carware_final2_DW.is_c16_Carware_final2 = Carware_final2_IN_Update;
            Carware_final2_B.Orders = ((Carware_final2_B.Orders +
              Carware_final2_B.Add1) + Carware_final2_B.SliderGain) -
              Carware_final2_B.Switch1;
            Carware_final2_B.AxO = 3.0;
            Carware_final2_DW.ShippingS = 0.5;
            Carware_final2_DW.ShippedS += 0.5;
            if (Carware_final2_B.Orders < 0.0) {
              Carware_final2_B.AxO = Carware_final2_B.Add1 +
                Carware_final2_B.SliderGain;
              Carware_final2_B.Orders = 0.0;
            }

            Carware_final2_DW.OSales = (Carware_final2_DW.OSales +
              Carware_final2_B.Add1) - 0.5;
          } else if ((Carware_final2_B.CR == 0.0) && (Carware_final2_DW.OSales >
                      0.5)) {
            Carware_final2_DW.is_c16_Carware_final2 =
              Carware_final2_IN_SalesRecovery;
            Carw_enter_atomic_SalesRecovery();
          } else {
            Carware_final2_DW.ShippingS = 0.0;
            Carware_final2_B.Orders = ((Carware_final2_B.Orders +
              Carware_final2_B.Add1) + Carware_final2_B.SliderGain) -
              Carware_final2_B.Switch1;
            Carware_final2_DW.OSales += Carware_final2_B.Add1;
            if (Carware_final2_B.Delayed_f - Carware_final2_DW.ShippedS > 0.0) {
              Carware_final2_B.Loss_h += Carware_final2_DW.Delay18_DSTATE[0];
              Carware_final2_B.Orders -= Carware_final2_DW.Delay18_DSTATE[0];
              Carware_final2_DW.OSales -= Carware_final2_DW.Delay18_DSTATE[0];
            }
          }
          break;

         case Carware_final2_IN_Empty:
          if (Carware_final2_B.Orders > 0.0) {
            Carware_final2_DW.is_c16_Carware_final2 = Carware_final2_IN_Update;
            Carware_final2_B.Orders = ((Carware_final2_B.Orders +
              Carware_final2_B.Add1) + Carware_final2_B.SliderGain) -
              Carware_final2_B.Switch1;
            Carware_final2_B.AxO = 3.0;
            Carware_final2_DW.ShippingS = 0.5;
            Carware_final2_DW.ShippedS += 0.5;
            if (Carware_final2_B.Orders < 0.0) {
              Carware_final2_B.AxO = Carware_final2_B.Add1 +
                Carware_final2_B.SliderGain;
              Carware_final2_B.Orders = 0.0;
            }

            Carware_final2_DW.OSales = (Carware_final2_DW.OSales +
              Carware_final2_B.Add1) - 0.5;
          } else {
            AxO_tmp = Carware_final2_B.Add1 + Carware_final2_B.SliderGain;
            Carware_final2_B.AxO = AxO_tmp;
            if (Carware_final2_B.Switch1 >= AxO_tmp) {
              Carware_final2_B.Orders = 0.0;
            } else {
              Carware_final2_B.Orders = AxO_tmp - Carware_final2_B.Switch1;
            }
          }
          break;

         case Carware_final2_IN_Init:
          if ((Carware_final2_B.Add1 > 0.0) || (Carware_final2_B.Switch1 > 0.0) ||
              (Carware_final2_B.SliderGain > 0.0)) {
            Carware_final2_DW.is_c16_Carware_final2 = Carware_final2_IN_Update;
            Carware_final2_B.Orders = ((Carware_final2_B.Orders +
              Carware_final2_B.Add1) + Carware_final2_B.SliderGain) -
              Carware_final2_B.Switch1;
            Carware_final2_B.AxO = 3.0;
            Carware_final2_DW.ShippingS = 0.5;
            Carware_final2_DW.ShippedS += 0.5;
            if (Carware_final2_B.Orders < 0.0) {
              Carware_final2_B.AxO = Carware_final2_B.Add1 +
                Carware_final2_B.SliderGain;
              Carware_final2_B.Orders = 0.0;
            }

            Carware_final2_DW.OSales = (Carware_final2_DW.OSales +
              Carware_final2_B.Add1) - 0.5;
          } else {
            Carware_final2_B.AxO = 3.0;
            Carware_final2_B.Orders = 1.0;
            Carware_final2_DW.OSales = 0.5;
            Carware_final2_DW.ShippingS = 0.5;
            Carware_final2_DW.ShippedS = 0.5;
            Carware_final2_B.Loss_h = 0.0;
          }
          break;

         case Carware_final2_IN_SalesRecovery:
          if (Carware_final2_B.CR != 0.0) {
            Carware_final2_DW.is_c16_Carware_final2 =
              Carware_fin_IN_ContractRecovery;
            Carware_final2_DW.ShippingS = 0.0;
            Carware_final2_B.Orders = ((Carware_final2_B.Orders +
              Carware_final2_B.Add1) + Carware_final2_B.SliderGain) -
              Carware_final2_B.Switch1;
            Carware_final2_DW.OSales += Carware_final2_B.Add1;
            if (Carware_final2_B.Delayed_f - Carware_final2_DW.ShippedS > 0.0) {
              Carware_final2_B.Loss_h += Carware_final2_DW.Delay18_DSTATE[0];
              Carware_final2_B.Orders -= Carware_final2_DW.Delay18_DSTATE[0];
              Carware_final2_DW.OSales -= Carware_final2_DW.Delay18_DSTATE[0];
            }
          } else if (Carware_final2_DW.OSales <= 0.5) {
            Carware_final2_DW.is_c16_Carware_final2 = Carware_final2_IN_Update;
            Carware_final2_B.Orders = ((Carware_final2_B.Orders +
              Carware_final2_B.Add1) + Carware_final2_B.SliderGain) -
              Carware_final2_B.Switch1;
            Carware_final2_B.AxO = 3.0;
            Carware_final2_DW.ShippingS = 0.5;
            Carware_final2_DW.ShippedS += 0.5;
            if (Carware_final2_B.Orders < 0.0) {
              Carware_final2_B.AxO = Carware_final2_B.Add1 +
                Carware_final2_B.SliderGain;
              Carware_final2_B.Orders = 0.0;
            }

            Carware_final2_DW.OSales = (Carware_final2_DW.OSales +
              Carware_final2_B.Add1) - 0.5;
          } else {
            if (((Carware_final2_B.Orders - 1.0) + Carware_final2_B.Add1) +
                Carware_final2_B.SliderGain < Carware_final2_B.Switch1) {
              Carware_final2_B.Orders = 1.0;
            } else {
              Carware_final2_B.Orders = ((Carware_final2_B.Orders +
                Carware_final2_B.Add1) + Carware_final2_B.SliderGain) -
                Carware_final2_B.Switch1;
            }

            if (Carware_final2_B.Switch7 >= 0.0) {
              Carware_final2_DW.ShippingS = Carware_final2_B.Switch7 - 0.5;
            }

            if (Carware_final2_B.Switch7 < 0.5) {
              Carware_final2_DW.ShippingS = 0.0;
            }

            Carware_final2_DW.ShippedS += Carware_final2_DW.ShippingS;
            Carware_final2_DW.OSales = (Carware_final2_DW.OSales +
              Carware_final2_B.Add1) - Carware_final2_DW.ShippingS;
          }
          break;

         default:
          /* case IN_Update: */
          if (Carware_final2_B.CR != 0.0) {
            Carware_final2_DW.is_c16_Carware_final2 =
              Carware_fin_IN_ContractRecovery;
            Carware_final2_DW.ShippingS = 0.0;
            Carware_final2_B.Orders = ((Carware_final2_B.Orders +
              Carware_final2_B.Add1) + Carware_final2_B.SliderGain) -
              Carware_final2_B.Switch1;
            Carware_final2_DW.OSales += Carware_final2_B.Add1;
            if (Carware_final2_B.Delayed_f - Carware_final2_DW.ShippedS > 0.0) {
              Carware_final2_B.Loss_h += Carware_final2_DW.Delay18_DSTATE[0];
              Carware_final2_B.Orders -= Carware_final2_DW.Delay18_DSTATE[0];
              Carware_final2_DW.OSales -= Carware_final2_DW.Delay18_DSTATE[0];
            }
          } else if ((Carware_final2_B.CR == 0.0) && (Carware_final2_DW.OSales >
                      0.5)) {
            Carware_final2_DW.is_c16_Carware_final2 =
              Carware_final2_IN_SalesRecovery;
            Carw_enter_atomic_SalesRecovery();
          } else if (Carware_final2_B.Orders <= 0.0) {
            Carware_final2_DW.is_c16_Carware_final2 = Carware_final2_IN_Empty;
            AxO_tmp = Carware_final2_B.Add1 + Carware_final2_B.SliderGain;
            Carware_final2_B.AxO = AxO_tmp;
            if (Carware_final2_B.Switch1 >= AxO_tmp) {
              Carware_final2_B.Orders = 0.0;
            } else {
              Carware_final2_B.Orders = AxO_tmp - Carware_final2_B.Switch1;
            }
          } else {
            Carware_final2_B.Orders = ((Carware_final2_B.Orders +
              Carware_final2_B.Add1) + Carware_final2_B.SliderGain) -
              Carware_final2_B.Switch1;
            Carware_final2_B.AxO = 3.0;
            Carware_final2_DW.ShippingS = 0.5;
            Carware_final2_DW.ShippedS += 0.5;
            if (Carware_final2_B.Orders < 0.0) {
              Carware_final2_B.AxO = Carware_final2_B.Add1 +
                Carware_final2_B.SliderGain;
              Carware_final2_B.Orders = 0.0;
            }

            Carware_final2_DW.OSales = (Carware_final2_DW.OSales +
              Carware_final2_B.Add1) - 0.5;
          }
          break;
        }
      }

      /* End of Chart: '<Root>/Chart' */
      /* Delay: '<Root>/Delay16' */
      Carware_final2_B.Delayed_h = Carware_final2_DW.Delay16_DSTATE[0];
    }

    /* Integrator: '<Root>/Integrator' */
    Carware_final2_B.Integrator = Carware_final2_X.Integrator_CSTATE;

    /* Sum: '<Root>/Add2' */
    Carware_final2_B.Add2 = Carware_final2_B.Delayed_h -
      Carware_final2_B.Integrator;
    if (rtmIsMajorTimeStep(Carware_final2_M)) {
      /* Memory: '<S44>/Memory' */
      Carware_final2_B.Memory = Carware_final2_DW.Memory_PreviousInput;

      /* Delay: '<Root>/Delay14' */
      Carware_final2_B.Delayed_b = Carware_final2_DW.Delay14_DSTATE[0];
    }

    /* Switch: '<S44>/Reset' incorporates:
     *  MinMax: '<S22>/MinMax'
     */
    Carware_final2_B.Reset = fmax(Carware_final2_B.Add2, Carware_final2_B.Memory);

    /* Sum: '<Root>/Add3' */
    Carware_final2_B.Add3 = Carware_final2_B.Delayed_b -
      Carware_final2_B.Integrator;
    if (rtmIsMajorTimeStep(Carware_final2_M)) {
      /* Memory: '<S45>/Memory' */
      Carware_final2_B.Memory_e = Carware_final2_DW.Memory_PreviousInput_i;
    }

    /* Switch: '<S45>/Reset' incorporates:
     *  MinMax: '<S23>/MinMax'
     */
    Carware_final2_B.Reset_b = fmax(Carware_final2_B.Add3,
      Carware_final2_B.Memory_e);

    /* Sum: '<Root>/Add11' */
    Carware_final2_B.Add11 = Carware_final2_B.Reset - Carware_final2_B.Reset_b;
    if (rtmIsMajorTimeStep(Carware_final2_M)) {
      /* Delay: '<Root>/Delay15' */
      Carware_final2_B.Delayed_c = Carware_final2_DW.Delay15_DSTATE[0];

      /* Memory: '<S46>/Memory' */
      Carware_final2_B.Memory_n = Carware_final2_DW.Memory_PreviousInput_f;
    }

    /* Sum: '<Root>/Add4' */
    Carware_final2_B.Add4 = Carware_final2_B.Delayed_c -
      Carware_final2_B.Integrator;

    /* Switch: '<S46>/Reset' incorporates:
     *  MinMax: '<S24>/MinMax'
     */
    Carware_final2_B.Reset_k = fmax(Carware_final2_B.Add4,
      Carware_final2_B.Memory_n);

    /* Sum: '<Root>/Add10' */
    Carware_final2_B.Add10 = Carware_final2_B.Reset_b - Carware_final2_B.Reset_k;
    if (rtmIsMajorTimeStep(Carware_final2_M)) {
      /* Sum: '<Root>/Add7' incorporates:
       *  Constant: '<Root>/AEP'
       *  Constant: '<Root>/EP max'
       */
      Carware_final2_B.Add7 = Carware_final2_P.solution2_3 +
        Carware_final2_P.EPmax_Value;

      /* State Transition Table: '<Root>/State Transition Table5' */
      if (Carware_final2_DW.is_active_c11_Carware_final2 == 0U) {
        Carware_final2_DW.is_active_c11_Carware_final2 = 1U;
        Carware_final2_DW.is_c11_Carware_final2 = Carware_final2_IN_Init_f;
        Carware_final2_DW.T_n = 0.0;
        rtb_Warehouse = 1.0;
        Carware_final2_B.Damage_p = 0.0;
        Carware_final2_B.Inventory = 1.0;
      } else {
        guard1 = false;
        switch (Carware_final2_DW.is_c11_Carware_final2) {
         case Carware_final2_IN_Great:
          if (Carware_final2_DW.T_n >= Carware_final2_DW.RT_e) {
            Carware_final2_DW.is_c11_Carware_final2 = Carware_final2_IN_Over;
            rtb_Warehouse = 1.0;
          } else {
            rtb_Warehouse = 0.0;
            Carware_final2_DW.RT_e = 90.0;
            Carware_final2_DW.T_n++;
          }
          break;

         case Carware_final2_IN_Init_f:
          if ((Carware_final2_B.Delayed > 0.0) && (Carware_final2_P.solution5_2 ==
               1.0)) {
            guard1 = true;
          } else if (Carware_final2_B.Delayed >= 8.0) {
            Carware_final2_B.Inventory = 0.2;
            Carware_final2_B.Damage_p = 4.0;
            Carware_final2_DW.is_c11_Carware_final2 = Carware_final2_IN_Great;
            rtb_Warehouse = 0.0;
            Carware_final2_DW.RT_e = 90.0;
            Carware_final2_DW.T_n++;
          } else if (Carware_final2_B.Delayed >= 7.0) {
            Carware_final2_B.Inventory = 0.5;
            Carware_final2_B.Damage_p = 2.4;
            Carware_final2_DW.is_c11_Carware_final2 = Carware_final2_IN_Major;
            rtb_Warehouse = 0.0;
            Carware_final2_DW.RT_e = 45.0;
            Carware_final2_DW.T_n++;
          } else if (Carware_final2_B.Delayed >= 6.0) {
            Carware_final2_B.Inventory = 0.9;
            Carware_final2_B.Damage_p = 1.0;
            Carware_final2_DW.is_c11_Carware_final2 = Carware_final2_IN_Strong;
            rtb_Warehouse = 0.0;
            Carware_final2_DW.RT_e = 10.0;
            Carware_final2_DW.T_n++;
          } else if (Carware_final2_B.Delayed >= 5.0) {
            guard1 = true;
          } else {
            Carware_final2_DW.T_n = 0.0;
            rtb_Warehouse = 1.0;
            Carware_final2_B.Damage_p = 0.0;
            Carware_final2_B.Inventory = 1.0;
          }
          break;

         case Carware_final2_IN_Major:
          if (Carware_final2_DW.T_n >= Carware_final2_DW.RT_e) {
            Carware_final2_DW.is_c11_Carware_final2 = Carware_final2_IN_Over;
            rtb_Warehouse = 1.0;
          } else {
            rtb_Warehouse = 0.0;
            Carware_final2_DW.RT_e = 45.0;
            Carware_final2_DW.T_n++;
          }
          break;

         case Carware_final2_IN_Moderate:
          if (Carware_final2_DW.T_n >= Carware_final2_DW.RT_e) {
            Carware_final2_DW.is_c11_Carware_final2 = Carware_final2_IN_Over;
            rtb_Warehouse = 1.0;
          } else {
            rtb_Warehouse = 0.0;
            Carware_final2_DW.RT_e = 1.0;
            Carware_final2_DW.T_n++;
          }
          break;

         case Carware_final2_IN_Over:
          rtb_Warehouse = 1.0;
          break;

         default:
          /* case IN_Strong: */
          if (Carware_final2_DW.T_n >= Carware_final2_DW.RT_e) {
            Carware_final2_DW.is_c11_Carware_final2 = Carware_final2_IN_Over;
            rtb_Warehouse = 1.0;
          } else {
            rtb_Warehouse = 0.0;
            Carware_final2_DW.RT_e = 10.0;
            Carware_final2_DW.T_n++;
          }
          break;
        }

        if (guard1) {
          Carware_final2_DW.is_c11_Carware_final2 = Carware_final2_IN_Moderate;
          rtb_Warehouse = 0.0;
          Carware_final2_DW.RT_e = 1.0;
          Carware_final2_DW.T_n++;
        }
      }

      /* End of State Transition Table: '<Root>/State Transition Table5' */

      /* Delay: '<Root>/Delay4' */
      rtb_Delayed_n = Carware_final2_DW.Delay4_DSTATE;

      /* RelationalOperator: '<S13>/Compare' incorporates:
       *  Constant: '<S13>/Constant'
       */
      rtb_LogicalOperator5 = (Carware_final2_B.Logistics <
        Carware_final2_P.CompareToConstant4_const);

      /* Logic: '<Root>/Logical Operator4' incorporates:
       *  Constant: '<S16>/Constant'
       *  RelationalOperator: '<S16>/Compare'
       */
      rtb_LogicalOperator4 = ((rtb_Delayed_n >
        Carware_final2_P.CompareToConstant7_const) && rtb_LogicalOperator5);

      /* Switch: '<Root>/Switch4' incorporates:
       *  Constant: '<Root>/Const'
       *  Constant: '<Root>/ITEP'
       *  Constant: '<Root>/Truck capacity1'
       *  Product: '<Root>/Product2'
       */
      if (rtb_LogicalOperator4) {
        rtb_Switch4 = Carware_final2_P.solution4_3 *
          Carware_final2_P.Truckcapacity1_Value;
      } else {
        rtb_Switch4 = Carware_final2_P.Const_Value;
      }

      /* End of Switch: '<Root>/Switch4' */

      /* Sum: '<Root>/Sum1' */
      rtb_InboundLogistics = rtb_Switch4 + Carware_final2_B.Logistics;

      /* MinMax: '<Root>/MinMax4' */
      rtb_InboundLogistics = fmin(rtb_Delayed_n, rtb_InboundLogistics);

      /* RelationalOperator: '<S12>/Compare' incorporates:
       *  Constant: '<S12>/Constant'
       */
      rtb_Compare_bi = (Carware_final2_B.Logistics >
                        Carware_final2_P.CompareToConstant3_const);

      /* Delay: '<Root>/Delay13' incorporates:
       *  Constant: '<Root>/DEP'
       */
      if (Carware_final2_DW.icLoad) {
        Carware_final2_DW.Delay13_DSTATE = Carware_final2_P.solution2_6;
      }

      rtb_Delayed_js = Carware_final2_DW.Delay13_DSTATE;

      /* End of Delay: '<Root>/Delay13' */

      /* Logic: '<Root>/Logical Operator2' incorporates:
       *  Constant: '<Root>/DEP'
       *  Constant: '<S14>/Constant'
       *  RelationalOperator: '<Root>/Relational Operator2'
       *  RelationalOperator: '<S14>/Compare'
       */
      rtb_LogicalOperator2 = ((rtb_Delayed_n >=
        Carware_final2_P.CompareToConstant5_const) && rtb_Compare_bi &&
        (rtb_Delayed_js < Carware_final2_P.solution2_6));

      /* Switch: '<Root>/Switch3' */
      if (rtb_LogicalOperator2) {
        /* Switch: '<Root>/Switch3' incorporates:
         *  Gain: '<S31>/Slider Gain'
         */
        Carware_final2_B.Switch3 = Carware_final2_P.SliderGain5_gain *
          rtb_InboundLogistics;
      } else {
        /* Switch: '<Root>/Switch3' */
        Carware_final2_B.Switch3 = rtb_InboundLogistics;
      }

      /* End of Switch: '<Root>/Switch3' */

      /* Chart: '<Root>/External' incorporates:
       *  Constant: '<Root>/DEP'
       */
      if (Carware_final2_DW.is_active_c15_Carware_final2 == 0U) {
        Carware_final2_DW.is_active_c15_Carware_final2 = 1U;
        Carware_final2_DW.is_c15_Carware_final2 = Carware_final2_IN_Init;
        Carware_final2_B.EParts = Carware_final2_P.solution2_6;
        Carware_final2_B.LxEP = 3.0;
        Carware_final2_B.AxEP = 3.0;
        Carware_final2_DW.Damage = 0.0;
      } else {
        switch (Carware_final2_DW.is_c15_Carware_final2) {
         case Carware_final2_IN_Empty_b:
          if (Carware_final2_B.EParts > 0.0) {
            Carware_final2_DW.is_c15_Carware_final2 = Carware_final2_IN_Update_o;
            Carware_fin_enter_atomic_Update();
          } else {
            Carware_final2_B.AxEP = Carware_final2_B.Switch3;
            if (Carware_final2_B.Switch1 >= Carware_final2_B.Switch3) {
              Carware_final2_B.EParts = 0.0;
            } else {
              Carware_final2_B.EParts = Carware_final2_B.Switch3 -
                Carware_final2_B.Switch1;
            }
          }
          break;

         case Carware_final2_IN_Full:
          if (Carware_final2_B.EParts < Carware_final2_B.Add7) {
            Carware_final2_DW.is_c15_Carware_final2 = Carware_final2_IN_Update_o;
            Carware_fin_enter_atomic_Update();
          } else {
            Carware_final2_B.LxEP = Carware_final2_B.Switch1;
            if (Carware_final2_B.Switch3 >= Carware_final2_B.Switch1) {
              Carware_final2_B.EParts = Carware_final2_B.Add7;
            } else {
              Carware_final2_B.EParts = (Carware_final2_B.Add7 +
                Carware_final2_B.Switch3) - Carware_final2_B.Switch1;
            }
          }
          break;

         case Carware_final2_IN_Init:
          if ((Carware_final2_B.Switch1 > 0.0) || (Carware_final2_B.Switch3 >
               0.0)) {
            Carware_final2_DW.is_c15_Carware_final2 = Carware_final2_IN_Update_o;
            Carware_fin_enter_atomic_Update();
          } else {
            Carware_final2_B.EParts = Carware_final2_P.solution2_6;
            Carware_final2_B.LxEP = 3.0;
            Carware_final2_B.AxEP = 3.0;
            Carware_final2_DW.Damage = 0.0;
          }
          break;

         default:
          /* case IN_Update: */
          if (Carware_final2_B.EParts >= Carware_final2_B.Add7) {
            Carware_final2_DW.is_c15_Carware_final2 = Carware_final2_IN_Full;
            Carware_final2_B.LxEP = Carware_final2_B.Switch1;
            if (Carware_final2_B.Switch3 >= Carware_final2_B.Switch1) {
              Carware_final2_B.EParts = Carware_final2_B.Add7;
            } else {
              Carware_final2_B.EParts = (Carware_final2_B.Add7 +
                Carware_final2_B.Switch3) - Carware_final2_B.Switch1;
            }
          } else if (Carware_final2_B.EParts <= 0.0) {
            Carware_final2_DW.is_c15_Carware_final2 = Carware_final2_IN_Empty_b;
            Carware_final2_B.AxEP = Carware_final2_B.Switch3;
            if (Carware_final2_B.Switch1 >= Carware_final2_B.Switch3) {
              Carware_final2_B.EParts = 0.0;
            } else {
              Carware_final2_B.EParts = Carware_final2_B.Switch3 -
                Carware_final2_B.Switch1;
            }
          } else {
            Carware_final2_B.LxEP = 3.0;
            Carware_final2_B.AxEP = 3.0;
            if ((Carware_final2_B.Inventory < 1.0) && (Carware_final2_DW.Damage ==
                 0.0)) {
              Carware_final2_B.Loss = (1.0 - Carware_final2_B.Inventory) *
                Carware_final2_B.EParts;
              Carware_final2_B.EParts *= Carware_final2_B.Inventory;
              Carware_final2_DW.Damage = 1.0;
            }

            if ((Carware_final2_B.Switch1 == 1.0) && (fabs
                 (Carware_final2_B.EParts - Carware_final2_P.solution2_6) < fabs
                 (Carware_final2_B.Switch1 - Carware_final2_B.Switch3))) {
              Carware_final2_B.EParts = Carware_final2_P.solution2_6;
            } else {
              Carware_final2_B.EParts = (Carware_final2_B.EParts +
                Carware_final2_B.Switch3) - Carware_final2_B.Switch1;
            }

            if (Carware_final2_B.EParts < 0.0) {
              Carware_final2_B.AxEP = Carware_final2_B.Switch3;
              Carware_final2_B.EParts = 0.0;
            } else if (Carware_final2_B.EParts > Carware_final2_B.Add7) {
              Carware_final2_B.LxEP = Carware_final2_B.Switch1;
              Carware_final2_B.EParts = Carware_final2_B.Add7;
            }
          }
          break;
        }
      }

      /* End of Chart: '<Root>/External' */

      /* Gain: '<Root>/Gain4' */
      rtb_Gain4 = Carware_final2_P.Gain4_Gain * Carware_final2_B.Loss;
    }

    /* Integrator: '<Root>/Integrator6' */
    Carware_final2_B.Integrator6 = Carware_final2_X.Integrator6_CSTATE;

    /* Gain: '<Root>/Gain2' */
    Carware_final2_B.Gain2 = Carware_final2_P.Gain2_Gain *
      Carware_final2_B.Add11;

    /* Gain: '<Root>/Gain1' */
    Carware_final2_B.Gain1 = Carware_final2_P.Gain1_Gain *
      Carware_final2_B.Add10;

    /* Gain: '<Root>/Gain' */
    Carware_final2_B.Gain = Carware_final2_P.Gain_Gain *
      Carware_final2_B.Reset_k;

    /* Sum: '<Root>/Add12' */
    Carware_final2_B.Add12 = (Carware_final2_B.Gain2 + Carware_final2_B.Gain1) +
      Carware_final2_B.Gain;

    /* Sum: '<Root>/Add16' */
    Carware_final2_B.Add16 = (Carware_final2_B.Integrator6 +
      Carware_final2_B.Loss_h) + Carware_final2_B.Add12;
    if (rtmIsMajorTimeStep(Carware_final2_M)) {
      /* State Transition Table: '<Root>/State Transition Table1' */
      if (Carware_final2_DW.is_active_c7_Carware_final2 == 0U) {
        Carware_final2_DW.is_active_c7_Carware_final2 = 1U;
        Carware_final2_DW.is_c7_Carware_final2 = Carware_final2_IN_Init_f;
        Carware_final2_DW.T_gh = 0.0;
        rtb_MainFacility = 1.0;
        Carware_final2_B.Damage_d = 0.0;
      } else {
        guard1 = false;
        switch (Carware_final2_DW.is_c7_Carware_final2) {
         case Carware_final2_IN_Great:
          if (Carware_final2_DW.T_gh >= Carware_final2_DW.RT_b) {
            Carware_final2_DW.is_c7_Carware_final2 = Carware_final2_IN_Over;
            rtb_MainFacility = 1.0;
          } else {
            rtb_MainFacility = 0.0;
            Carware_final2_DW.RT_b = 120.0;
            Carware_final2_DW.T_gh++;
          }
          break;

         case Carware_final2_IN_Init_f:
          if ((Carware_final2_B.Delayed > 0.0) && (Carware_final2_P.solution5_1 ==
               1.0)) {
            guard1 = true;
          } else if (Carware_final2_B.Delayed >= 8.0) {
            Carware_final2_B.Damage_d = 10.0;
            Carware_final2_DW.is_c7_Carware_final2 = Carware_final2_IN_Great;
            rtb_MainFacility = 0.0;
            Carware_final2_DW.RT_b = 120.0;
            Carware_final2_DW.T_gh++;
          } else if (Carware_final2_B.Delayed >= 7.0) {
            Carware_final2_B.Damage_d = 6.0;
            Carware_final2_DW.is_c7_Carware_final2 = Carware_final2_IN_Major;
            rtb_MainFacility = 0.0;
            Carware_final2_DW.RT_b = 60.0;
            Carware_final2_DW.T_gh++;
          } else if (Carware_final2_B.Delayed >= 6.0) {
            Carware_final2_B.Damage_d = 2.5;
            Carware_final2_DW.is_c7_Carware_final2 = Carware_final2_IN_Strong;
            rtb_MainFacility = 0.0;
            Carware_final2_DW.RT_b = 3.0;
            Carware_final2_DW.T_gh++;
          } else if (Carware_final2_B.Delayed >= 5.0) {
            guard1 = true;
          } else {
            Carware_final2_DW.T_gh = 0.0;
            rtb_MainFacility = 1.0;
            Carware_final2_B.Damage_d = 0.0;
          }
          break;

         case Carware_final2_IN_Major:
          if (Carware_final2_DW.T_gh >= Carware_final2_DW.RT_b) {
            Carware_final2_DW.is_c7_Carware_final2 = Carware_final2_IN_Over;
            rtb_MainFacility = 1.0;
          } else {
            rtb_MainFacility = 0.0;
            Carware_final2_DW.RT_b = 60.0;
            Carware_final2_DW.T_gh++;
          }
          break;

         case Carware_final2_IN_Moderate:
          if (Carware_final2_DW.T_gh >= Carware_final2_DW.RT_b) {
            Carware_final2_DW.is_c7_Carware_final2 = Carware_final2_IN_Over;
            rtb_MainFacility = 1.0;
          } else {
            rtb_MainFacility = 0.0;
            Carware_final2_DW.RT_b = 1.0;
            Carware_final2_DW.T_gh++;
          }
          break;

         case Carware_final2_IN_Over:
          rtb_MainFacility = 1.0;
          break;

         default:
          /* case IN_Strong: */
          if (Carware_final2_DW.T_gh >= Carware_final2_DW.RT_b) {
            Carware_final2_DW.is_c7_Carware_final2 = Carware_final2_IN_Over;
            rtb_MainFacility = 1.0;
          } else {
            rtb_MainFacility = 0.0;
            Carware_final2_DW.RT_b = 3.0;
            Carware_final2_DW.T_gh++;
          }
          break;
        }

        if (guard1) {
          Carware_final2_DW.is_c7_Carware_final2 = Carware_final2_IN_Moderate;
          rtb_MainFacility = 0.0;
          Carware_final2_DW.RT_b = 1.0;
          Carware_final2_DW.T_gh++;
        }
      }

      /* End of State Transition Table: '<Root>/State Transition Table1' */

      /* Sum: '<Root>/Add14' */
      Carware_final2_B.Add14 = (Carware_final2_B.Damage_l +
        Carware_final2_B.Damage_p) + Carware_final2_B.Damage_d;

      /* Sum: '<Root>/Add6' incorporates:
       *  Constant: '<Root>/AIP'
       *  Constant: '<Root>/IPmax'
       */
      Carware_final2_B.Add6 = Carware_final2_P.IPmax_Value +
        Carware_final2_P.solution2_2;

      /* State Transition Table: '<Root>/State Transition Table7' incorporates:
       *  Constant: '<Root>/BME'
       */
      if (Carware_final2_DW.is_active_c13_Carware_final2 == 0U) {
        Carware_final2_DW.is_active_c13_Carware_final2 = 1U;
        Carware_final2_DW.is_c13_Carware_final2 = Carware_final2_IN_Init_f;
        Carware_final2_DW.T_c = 0.0;
        rtb_ManufEq = 1.0;
        Carware_final2_B.Damage_n = 0.0;
      } else {
        switch (Carware_final2_DW.is_c13_Carware_final2) {
         case Carware_final2_IN_Great:
          if (Carware_final2_DW.T_c >= Carware_final2_DW.RT_j) {
            Carware_final2_DW.is_c13_Carware_final2 = Carware_final2_IN_Over_b;
            rtb_ManufEq = 1.0;
          } else if (Carware_final2_P.solution3_1 > 0.0) {
            Carware_final2_DW.is_c13_Carware_final2 = Carware_final2_IN_MBackup;
            rtb_ManufEq = 0.0;
            Carware_final2_DW.RT_j = 5.0;
            Carware_final2_DW.T_c++;
          } else {
            rtb_ManufEq = 0.0;
            Carware_final2_DW.RT_j = 180.0;
            Carware_final2_DW.T_c++;
          }
          break;

         case Carware_final2_IN_Init_f:
          if (Carware_final2_B.Delayed >= 8.0) {
            Carware_final2_B.Damage_n = 10.0;
            Carware_final2_DW.is_c13_Carware_final2 = Carware_final2_IN_Great;
            rtb_ManufEq = 0.0;
            Carware_final2_DW.RT_j = 180.0;
            Carware_final2_DW.T_c++;
          } else if (Carware_final2_B.Delayed >= 7.0) {
            Carware_final2_B.Damage_n = 5.0;
            Carware_final2_DW.is_c13_Carware_final2 = Carware_final2_IN_Major_g;
            rtb_ManufEq = 0.0;
            Carware_final2_DW.RT_j = 30.0;
            Carware_final2_DW.T_c++;
          } else if (Carware_final2_B.Delayed >= 6.0) {
            Carware_final2_B.Damage_n = 2.0;
            Carware_final2_DW.is_c13_Carware_final2 = Carware_final2_IN_Strong_l;
            rtb_ManufEq = 0.0;
            Carware_final2_DW.RT_j = 7.0;
            Carware_final2_DW.T_c++;
          } else if (Carware_final2_B.Delayed >= 5.0) {
            Carware_final2_B.Damage_n = 0.5;
            Carware_final2_DW.is_c13_Carware_final2 =
              Carware_final2_IN_Moderate_p;
            rtb_ManufEq = 0.0;
            Carware_final2_DW.RT_j = 1.0;
            Carware_final2_DW.T_c++;
          } else {
            Carware_final2_DW.T_c = 0.0;
            rtb_ManufEq = 1.0;
            Carware_final2_B.Damage_n = 0.0;
          }
          break;

         case Carware_final2_IN_MBackup:
          if (Carware_final2_DW.T_c >= Carware_final2_DW.RT_j) {
            Carware_final2_DW.is_c13_Carware_final2 = Carware_final2_IN_Over_b;
            rtb_ManufEq = 1.0;
          } else {
            rtb_ManufEq = 0.0;
            Carware_final2_DW.RT_j = 5.0;
            Carware_final2_DW.T_c++;
          }
          break;

         case Carware_final2_IN_Major_g:
          if (Carware_final2_DW.T_c >= Carware_final2_DW.RT_j) {
            Carware_final2_DW.is_c13_Carware_final2 = Carware_final2_IN_Over_b;
            rtb_ManufEq = 1.0;
          } else if (Carware_final2_P.solution3_1 > 0.0) {
            Carware_final2_DW.is_c13_Carware_final2 = Carware_final2_IN_MBackup;
            rtb_ManufEq = 0.0;
            Carware_final2_DW.RT_j = 5.0;
            Carware_final2_DW.T_c++;
          } else {
            rtb_ManufEq = 0.0;
            Carware_final2_DW.RT_j = 30.0;
            Carware_final2_DW.T_c++;
          }
          break;

         case Carware_final2_IN_Moderate_p:
          Carware_final2_DW.is_c13_Carware_final2 = Carware_final2_IN_Over_b;
          rtb_ManufEq = 1.0;
          break;

         case Carware_final2_IN_Over_b:
          rtb_ManufEq = 1.0;
          break;

         default:
          /* case IN_Strong: */
          if (Carware_final2_DW.T_c >= Carware_final2_DW.RT_j) {
            Carware_final2_DW.is_c13_Carware_final2 = Carware_final2_IN_Over_b;
            rtb_ManufEq = 1.0;
          } else if (Carware_final2_P.solution3_1 > 0.0) {
            Carware_final2_DW.is_c13_Carware_final2 = Carware_final2_IN_MBackup;
            rtb_ManufEq = 0.0;
            Carware_final2_DW.RT_j = 5.0;
            Carware_final2_DW.T_c++;
          } else {
            rtb_ManufEq = 0.0;
            Carware_final2_DW.RT_j = 7.0;
            Carware_final2_DW.T_c++;
          }
          break;
        }
      }

      /* End of State Transition Table: '<Root>/State Transition Table7' */

      /* MinMax: '<Root>/MinMax' */
      rtb_MinMax_j = fmin(fmin(fmin(Carware_final2_B.Electricity, rtb_ITEq),
        rtb_MainFacility), rtb_ManufEq);

      /* State Transition Table: '<Root>/State Transition Table3' */
      if (Carware_final2_DW.is_active_c9_Carware_final2 == 0U) {
        Carware_final2_DW.is_active_c9_Carware_final2 = 1U;
        Carware_final2_DW.is_c9_Carware_final2 = Carware_final2_IN_Init;
        Carware_final2_DW.T_h = 0.0;
        Carware_final2_B.Maintenance = 1.0;
      } else {
        switch (Carware_final2_DW.is_c9_Carware_final2) {
         case Carware_final2_IN_Great:
          if (Carware_final2_DW.T_h >= Carware_final2_DW.RTm) {
            Carware_final2_DW.is_c9_Carware_final2 = Carware_final2_IN_Great1;
            Carware_final2_B.Maintenance = 1.0;
            Carware_final2_DW.FRm = 120.0;
            Carware_final2_DW.T_h++;
          } else {
            Carware_final2_B.Maintenance = 0.0;
            Carware_final2_DW.RTm = 120.0;
            Carware_final2_DW.T_h++;
          }
          break;

         case Carware_final2_IN_Great1:
          if (Carware_final2_DW.T_h >= Carware_final2_DW.FRm) {
            Carware_final2_DW.is_c9_Carware_final2 = Carware_final2_IN_Over_a;
            Carware_final2_B.Maintenance = 1.0;
          } else {
            Carware_final2_B.Maintenance = 1.0;
            Carware_final2_DW.FRm = 120.0;
            Carware_final2_DW.T_h++;
          }
          break;

         case Carware_final2_IN_Init:
          if (Carware_final2_B.Delayed >= 8.0) {
            Carware_final2_DW.is_c9_Carware_final2 = Carware_final2_IN_Great;
            Carware_final2_B.Maintenance = 0.0;
            Carware_final2_DW.RTm = 120.0;
            Carware_final2_DW.T_h++;
          } else if (Carware_final2_B.Delayed >= 7.0) {
            Carware_final2_DW.is_c9_Carware_final2 = Carware_final2_IN_Major_g;
            Carware_final2_B.Maintenance = 0.0;
            Carware_final2_DW.RTm = 45.0;
            Carware_final2_DW.T_h++;
          } else if (Carware_final2_B.Delayed >= 6.0) {
            Carware_final2_DW.is_c9_Carware_final2 = Carware_final2_IN_Strong_o;
            Carware_final2_B.Maintenance = 0.0;
            Carware_final2_DW.RTm = 10.0;
            Carware_final2_DW.T_h++;
          } else if (Carware_final2_B.Delayed >= 5.0) {
            Carware_final2_DW.is_c9_Carware_final2 =
              Carware_final2_IN_Moderate_j;
          } else {
            Carware_final2_DW.T_h = 0.0;
            Carware_final2_B.Maintenance = 1.0;
          }
          break;

         case Carware_final2_IN_Major_g:
          if (Carware_final2_DW.T_h >= Carware_final2_DW.RTm) {
            Carware_final2_DW.is_c9_Carware_final2 = Carware_final2_IN_Major1;
            Carware_final2_B.Maintenance = 1.0;
            Carware_final2_DW.FRm = 45.0;
            Carware_final2_DW.T_h++;
          } else {
            Carware_final2_B.Maintenance = 0.0;
            Carware_final2_DW.RTm = 45.0;
            Carware_final2_DW.T_h++;
          }
          break;

         case Carware_final2_IN_Major1:
          if (Carware_final2_DW.T_h >= Carware_final2_DW.FRm) {
            Carware_final2_DW.is_c9_Carware_final2 = Carware_final2_IN_Over_a;
            Carware_final2_B.Maintenance = 1.0;
          } else {
            Carware_final2_B.Maintenance = 1.0;
            Carware_final2_DW.FRm = 45.0;
            Carware_final2_DW.T_h++;
          }
          break;

         case Carware_final2_IN_Moderate_j:
          break;

         case Carware_final2_IN_Over_a:
          Carware_final2_B.Maintenance = 1.0;
          break;

         case Carware_final2_IN_Strong_o:
          if (Carware_final2_DW.T_h >= Carware_final2_DW.RTm) {
            Carware_final2_DW.is_c9_Carware_final2 = Carware_final2_IN_Strong1;
            Carware_final2_B.Maintenance = 1.0;
            Carware_final2_DW.FRm = 10.0;
            Carware_final2_DW.T_h++;
          } else {
            Carware_final2_B.Maintenance = 0.0;
            Carware_final2_DW.RTm = 10.0;
            Carware_final2_DW.T_h++;
          }
          break;

         default:
          /* case IN_Strong1: */
          if (Carware_final2_DW.T_h >= Carware_final2_DW.FRm) {
            Carware_final2_DW.is_c9_Carware_final2 = Carware_final2_IN_Over_a;
            Carware_final2_B.Maintenance = 1.0;
          } else {
            Carware_final2_B.Maintenance = 1.0;
            Carware_final2_DW.FRm = 10.0;
            Carware_final2_DW.T_h++;
          }
          break;
        }
      }

      /* End of State Transition Table: '<Root>/State Transition Table3' */

      /* State Transition Table: '<Root>/State Transition Table' incorporates:
       *  Delay: '<Root>/Delay'
       */
      if (Carware_final2_DW.is_active_c4_Carware_final2 == 0U) {
        Carware_final2_DW.is_active_c4_Carware_final2 = 1U;
        Carware_final2_DW.is_c4_Carware_final2 = Carware_final2_IN_Normal_i;
        Carware_final2_DW.T_i = 0.0;
        rtb_Mnf = 0.0;
      } else {
        switch (Carware_final2_DW.is_c4_Carware_final2) {
         case Carware_final2_IN_Level1:
          if ((Carware_final2_DW.Delay_DSTATE[0U] <= 0.0) &&
              (Carware_final2_B.Maintenance <= 0.0) && (Carware_final2_DW.T_i >=
               30.0)) {
            Carware_final2_DW.is_c4_Carware_final2 = Carware_final2_IN_Level2;
            rtb_Mnf = 0.22;
            Carware_final2_DW.T_i++;
          } else if (Carware_final2_B.Maintenance > 0.0) {
            Carware_final2_DW.is_c4_Carware_final2 = Carware_final2_IN_Normal_i;
            Carware_final2_DW.T_i = 0.0;
            rtb_Mnf = 0.0;
          } else {
            rtb_Mnf = 0.1;
            Carware_final2_DW.T_i++;
          }
          break;

         case Carware_final2_IN_Level2:
          if ((Carware_final2_DW.Delay_DSTATE[0U] <= 0.0) &&
              (Carware_final2_B.Maintenance <= 0.0) && (Carware_final2_DW.T_i >=
               60.0)) {
            Carware_final2_DW.is_c4_Carware_final2 = Carware_final2_IN_Level3;
            rtb_Mnf = 0.36;
            Carware_final2_DW.T_i++;
          } else if (Carware_final2_B.Maintenance > 0.0) {
            Carware_final2_DW.is_c4_Carware_final2 = Carware_final2_IN_Normal_i;
            Carware_final2_DW.T_i = 0.0;
            rtb_Mnf = 0.0;
          } else {
            rtb_Mnf = 0.22;
            Carware_final2_DW.T_i++;
          }
          break;

         case Carware_final2_IN_Level3:
          if ((Carware_final2_DW.Delay_DSTATE[0U] <= 0.0) &&
              (Carware_final2_B.Maintenance <= 0.0) && (Carware_final2_DW.T_i >=
               90.0)) {
            Carware_final2_DW.is_c4_Carware_final2 = Carware_final2_IN_Level4;
            rtb_Mnf = 0.54;
            Carware_final2_DW.T_i++;
          } else if (Carware_final2_B.Maintenance > 0.0) {
            Carware_final2_DW.is_c4_Carware_final2 = Carware_final2_IN_Normal_i;
            Carware_final2_DW.T_i = 0.0;
            rtb_Mnf = 0.0;
          } else {
            rtb_Mnf = 0.36;
            Carware_final2_DW.T_i++;
          }
          break;

         case Carware_final2_IN_Level4:
          if ((Carware_final2_DW.Delay_DSTATE[0U] <= 0.0) &&
              (Carware_final2_B.Maintenance <= 0.0) && (Carware_final2_DW.T_i >=
               120.0)) {
            Carware_final2_DW.is_c4_Carware_final2 = Carware_final2_IN_Level5;
            rtb_Mnf = 0.74;
            Carware_final2_DW.T_i++;
          } else if (Carware_final2_B.Maintenance > 0.0) {
            Carware_final2_DW.is_c4_Carware_final2 = Carware_final2_IN_Normal_i;
            Carware_final2_DW.T_i = 0.0;
            rtb_Mnf = 0.0;
          } else {
            rtb_Mnf = 0.54;
            Carware_final2_DW.T_i++;
          }
          break;

         case Carware_final2_IN_Level5:
          if ((Carware_final2_DW.Delay_DSTATE[0U] <= 0.0) &&
              (Carware_final2_B.Maintenance <= 0.0) && (Carware_final2_DW.T_i >=
               150.0)) {
            Carware_final2_DW.is_c4_Carware_final2 = Carware_final2_IN_Level6;
            rtb_Mnf = 1.0;
            Carware_final2_DW.T_i++;
          } else if (Carware_final2_B.Maintenance > 0.0) {
            Carware_final2_DW.is_c4_Carware_final2 = Carware_final2_IN_Normal_i;
            Carware_final2_DW.T_i = 0.0;
            rtb_Mnf = 0.0;
          } else {
            rtb_Mnf = 0.74;
            Carware_final2_DW.T_i++;
          }
          break;

         case Carware_final2_IN_Level6:
          if (Carware_final2_B.Maintenance > 0.0) {
            Carware_final2_DW.is_c4_Carware_final2 = Carware_final2_IN_Normal_i;
            Carware_final2_DW.T_i = 0.0;
            rtb_Mnf = 0.0;
          } else {
            rtb_Mnf = 1.0;
            Carware_final2_DW.T_i++;
          }
          break;

         default:
          /* case IN_Normal: */
          if ((Carware_final2_DW.Delay_DSTATE[0U] <= 0.0) &&
              (Carware_final2_B.Maintenance <= 0.0)) {
            Carware_final2_DW.is_c4_Carware_final2 = Carware_final2_IN_Level1;
            rtb_Mnf = 0.1;
            Carware_final2_DW.T_i++;
          } else {
            Carware_final2_DW.T_i = 0.0;
            rtb_Mnf = 0.0;
          }
          break;
        }
      }

      /* End of State Transition Table: '<Root>/State Transition Table' */

      /* Sum: '<Root>/Add' incorporates:
       *  Constant: '<Root>/Constant'
       */
      rtb_InboundLogistics_e = Carware_final2_P.Constant_Value - rtb_Mnf;

      /* Product: '<Root>/Product' */
      rtb_Switch9 = rtb_MinMax_j * rtb_InboundLogistics_e;

      /* Delay: '<Root>/Delay3' */
      rtb_Add22 = Carware_final2_DW.Delay3_DSTATE;

      /* Delay: '<Root>/Delay2' */
      rtb_Switch13 = Carware_final2_DW.Delay2_DSTATE;

      /* MinMax: '<Root>/MinMax3' */
      rtb_Switch9 = fmin(fmin(rtb_Switch9, rtb_Add22), rtb_Switch13);

      /* Delay: '<Root>/Delay10' incorporates:
       *  Constant: '<Root>/DIP'
       */
      if (Carware_final2_DW.icLoad_b) {
        Carware_final2_DW.Delay10_DSTATE = Carware_final2_P.solution2_5;
      }

      /* Logic: '<Root>/Logical Operator' incorporates:
       *  Constant: '<Root>/DIP'
       *  Constant: '<S10>/Constant'
       *  Constant: '<S4>/Constant'
       *  Delay: '<Root>/Delay10'
       *  Logic: '<Root>/Logical Operator8'
       *  RelationalOperator: '<Root>/Relational Operator'
       *  RelationalOperator: '<S10>/Compare'
       *  RelationalOperator: '<S4>/Compare'
       *  Sum: '<Root>/Add24'
       */
      rtb_LogicalOperator = (((rtb_Delayed - Carware_final2_DW.Delay10_DSTATE >
        Carware_final2_P.CompareToConstant14_const) ||
        (Carware_final2_DW.Delay10_DSTATE < Carware_final2_P.solution2_5)) &&
        (rtb_Switch9 > Carware_final2_P.CompareToConstant_const));

      /* Switch: '<Root>/Switch' */
      if (rtb_LogicalOperator) {
        /* Switch: '<Root>/Switch' incorporates:
         *  Gain: '<S29>/Slider Gain'
         */
        Carware_final2_B.Switch = Carware_final2_P.SliderGain3_gain *
          rtb_Switch9;
      } else {
        /* Switch: '<Root>/Switch' */
        Carware_final2_B.Switch = rtb_Switch9;
      }

      /* End of Switch: '<Root>/Switch' */

      /* Chart: '<Root>/Internal' incorporates:
       *  Constant: '<Root>/DIP'
       */
      if (Carware_final2_DW.is_active_c2_Carware_final2 == 0U) {
        Carware_final2_DW.is_active_c2_Carware_final2 = 1U;
        Carware_final2_DW.is_c2_Carware_final2 = Carware_final2_IN_Init;
        Carware_final2_B.IParts = Carware_final2_P.solution2_5;
        Carware_final2_B.MxIP = 3.0;
        Carware_final2_B.AxIP = 3.0;
        Carware_final2_DW.DamageIP = 0.0;
      } else {
        switch (Carware_final2_DW.is_c2_Carware_final2) {
         case Carware_final2_IN_Empty_b:
          if (Carware_final2_B.IParts > 0.0) {
            Carware_final2_DW.is_c2_Carware_final2 = Carware_final2_IN_Update_o;
            Carware_f_enter_atomic_Update_b();
          } else {
            Carware_final2_B.AxIP = Carware_final2_B.Switch;
            if (Carware_final2_B.Switch1 >= Carware_final2_B.Switch) {
              Carware_final2_B.IParts = 0.0;
            } else {
              Carware_final2_B.IParts = Carware_final2_B.Switch -
                Carware_final2_B.Switch1;
            }
          }
          break;

         case Carware_final2_IN_Full:
          if (Carware_final2_B.IParts < Carware_final2_B.Add6) {
            Carware_final2_DW.is_c2_Carware_final2 = Carware_final2_IN_Update_o;
            Carware_f_enter_atomic_Update_b();
          } else {
            Carware_final2_B.MxIP = Carware_final2_B.Switch1;
            if (Carware_final2_B.Switch >= Carware_final2_B.Switch1) {
              Carware_final2_B.IParts = Carware_final2_B.Add6;
            } else {
              Carware_final2_B.IParts = (Carware_final2_B.Add6 +
                Carware_final2_B.Switch) - Carware_final2_B.Switch1;
            }
          }
          break;

         case Carware_final2_IN_Init:
          if ((Carware_final2_B.Switch > 0.0) || (Carware_final2_B.Switch1 > 0.0)
              || (Carware_final2_B.Inventory < 1.0)) {
            Carware_final2_DW.is_c2_Carware_final2 = Carware_final2_IN_Update_o;
            Carware_f_enter_atomic_Update_b();
          } else {
            Carware_final2_B.IParts = Carware_final2_P.solution2_5;
            Carware_final2_B.MxIP = 3.0;
            Carware_final2_B.AxIP = 3.0;
            Carware_final2_DW.DamageIP = 0.0;
          }
          break;

         default:
          /* case IN_Update: */
          if (Carware_final2_B.IParts >= Carware_final2_B.Add6) {
            Carware_final2_DW.is_c2_Carware_final2 = Carware_final2_IN_Full;
            Carware_final2_B.MxIP = Carware_final2_B.Switch1;
            if (Carware_final2_B.Switch >= Carware_final2_B.Switch1) {
              Carware_final2_B.IParts = Carware_final2_B.Add6;
            } else {
              Carware_final2_B.IParts = (Carware_final2_B.Add6 +
                Carware_final2_B.Switch) - Carware_final2_B.Switch1;
            }
          } else if (Carware_final2_B.IParts <= 0.0) {
            Carware_final2_DW.is_c2_Carware_final2 = Carware_final2_IN_Empty_b;
            Carware_final2_B.AxIP = Carware_final2_B.Switch;
            if (Carware_final2_B.Switch1 >= Carware_final2_B.Switch) {
              Carware_final2_B.IParts = 0.0;
            } else {
              Carware_final2_B.IParts = Carware_final2_B.Switch -
                Carware_final2_B.Switch1;
            }
          } else {
            Carware_final2_B.MxIP = 3.0;
            Carware_final2_B.AxIP = 3.0;
            if ((Carware_final2_B.Inventory < 1.0) &&
                (Carware_final2_DW.DamageIP == 0.0)) {
              Carware_final2_B.LossIP = (1.0 - Carware_final2_B.Inventory) *
                Carware_final2_B.IParts;
              Carware_final2_B.IParts *= Carware_final2_B.Inventory;
              Carware_final2_DW.DamageIP = 1.0;
            }

            if (((Carware_final2_B.Switch1 == 1.0) || (Carware_final2_B.Switch ==
                  1.0)) && (fabs(Carware_final2_B.IParts -
                                 Carware_final2_P.solution2_5) < fabs
                            (Carware_final2_B.Switch1 - Carware_final2_B.Switch)))
            {
              Carware_final2_B.IParts = Carware_final2_P.solution2_5;
            } else {
              Carware_final2_B.IParts = (Carware_final2_B.IParts +
                Carware_final2_B.Switch) - Carware_final2_B.Switch1;
            }

            if (Carware_final2_B.IParts < 0.0) {
              Carware_final2_B.AxIP = Carware_final2_B.Switch;
              Carware_final2_B.IParts = 0.0;
            } else if (Carware_final2_B.IParts > Carware_final2_B.Add6) {
              Carware_final2_B.MxIP = Carware_final2_B.Switch1;
              Carware_final2_B.IParts = Carware_final2_B.Add6;
            }
          }
          break;
        }
      }

      /* End of Chart: '<Root>/Internal' */

      /* Gain: '<Root>/Gain5' */
      rtb_Switch13 = Carware_final2_P.Gain5_Gain * Carware_final2_B.LossIP;

      /* Sum: '<Root>/Add15' */
      Carware_final2_B.Add15 = (((rtb_Gain4 + rtb_Switch13) +
        Carware_final2_B.Damage_m) + Carware_final2_B.Damage_n) +
        Carware_final2_B.Damage;
    }

    /* Integrator: '<Root>/Integrator4' */
    Carware_final2_B.Integrator4 = Carware_final2_X.Integrator4_CSTATE;

    /* Integrator: '<Root>/Integrator5' */
    Carware_final2_B.Integrator5 = Carware_final2_X.Integrator5_CSTATE;

    /* Sum: '<Root>/Add9' */
    Carware_final2_B.Add9 = Carware_final2_B.Integrator4 +
      Carware_final2_B.Integrator5;

    /* Integrator: '<Root>/Integrator3' */
    Carware_final2_B.Integrator3 = Carware_final2_X.Integrator3_CSTATE;

    /* Integrator: '<Root>/Integrator2' */
    Carware_final2_B.Integrator2 = Carware_final2_X.Integrator2_CSTATE;

    /* Integrator: '<Root>/Integrator7' */
    Carware_final2_B.Integrator7 = Carware_final2_X.Integrator7_CSTATE;

    /* Sum: '<Root>/Add18' incorporates:
     *  Sum: '<Root>/Add17'
     */
    Carware_final2_B.Add18 = ((Carware_final2_B.Integrator3 +
      Carware_final2_B.Integrator2) + Carware_final2_B.Integrator7) +
      Carware_final2_B.Add9;

    /* Clock: '<Root>/Clock' */
    Carware_final2_B.Clock = Carware_final2_M->Timing.t[0];
    if (rtmIsMajorTimeStep(Carware_final2_M)) {
      /* Chart: '<Root>/Chart1' incorporates:
       *  Constant: '<Root>/Insurance'
       */
      if (Carware_final2_DW.is_active_c17_Carware_final2 == 0U) {
        Carware_final2_DW.is_active_c17_Carware_final2 = 1U;
        Carware_final2_DW.is_c17_Carware_final2 = Carware_final2_IN_Init;
        Carware_final2_DW.Coverage = 0.0;
      } else {
        switch (Carware_final2_DW.is_c17_Carware_final2) {
         case Carware_final2_IN_BC:
          if (Carware_final2_B.Delayed > 8.0) {
            Carware_final2_DW.Coverage = 7.0;
          }

          if (Carware_final2_B.Delayed > 7.0) {
            Carware_final2_DW.Coverage = 6.0;
          }

          if (Carware_final2_B.Delayed > 6.0) {
            Carware_final2_DW.Coverage = 5.0;
          }

          if (Carware_final2_B.Delayed > 5.0) {
            Carware_final2_DW.Coverage = 4.0;
          }

          if (Carware_final2_B.Add18 > Carware_final2_DW.Coverage) {
            Carware_final2_B.NLBC = Carware_final2_B.Add18 -
              Carware_final2_DW.Coverage;
          } else {
            Carware_final2_B.NLBC = 0.0;
          }

          Carware_final2_B.NL = ((Carware_final2_B.NLBuilding +
            Carware_final2_B.NLProperty) + Carware_final2_B.NLProfit) +
            Carware_final2_B.NLBC;
          break;

         case Carware_final2_IN_Full:
          Carware_final2_B.Premium = 0.5;
          rtb_Add22 = (Carware_final2_B.Add14 + Carware_final2_B.Add15) +
            Carware_final2_B.Add16;
          if (Carware_final2_B.Delayed > 8.0) {
            Carware_final2_DW.Coverage = 20.0;
          }

          if (Carware_final2_B.Delayed > 7.0) {
            Carware_final2_DW.Coverage = 15.0;
          }

          if (Carware_final2_B.Delayed > 6.0) {
            Carware_final2_DW.Coverage = 10.0;
          }

          if (Carware_final2_B.Delayed > 5.0) {
            Carware_final2_DW.Coverage = 7.0;
          }

          if (Carware_final2_B.Add18 > Carware_final2_DW.Coverage) {
            Carware_final2_B.NLBC = Carware_final2_B.Add18 -
              Carware_final2_DW.Coverage;
          } else {
            Carware_final2_B.NLBC = 0.0;
          }

          if (rtb_Add22 > 50.0) {
            AxO_tmp = rtb_Add22 - 50.0;
          } else {
            AxO_tmp = 0.0;
          }

          Carware_final2_B.NL = AxO_tmp + Carware_final2_B.NLBC;
          break;

         case Carware_final2_IN_Init:
          if ((Carware_final2_P.insurance_V == 3.0) && (Carware_final2_B.Clock >
               690.0)) {
            Carware_final2_DW.is_c17_Carware_final2 = Carware_final2_IN_Package3;
            Carware_final2_B.Premium = 0.2;
            if (Carware_final2_B.Add14 > 10.0) {
              Carware_final2_B.NLBuilding = Carware_final2_B.Add14 - 10.0;
            } else {
              Carware_final2_B.NLBuilding = 0.0;
            }

            if (Carware_final2_B.Add16 > 30.0) {
              Carware_final2_B.NLProfit = Carware_final2_B.Add16 - 30.0;
            } else {
              Carware_final2_B.NLProfit = 0.0;
            }

            Carware_final2_B.NLProperty = Carware_final2_B.Add15;
            Carware_final2_B.NLBC = Carware_final2_B.Add18;
            Carware_final2_B.NL = ((Carware_final2_B.NLBuilding +
              Carware_final2_B.NLProperty) + Carware_final2_B.NLProfit) +
              Carware_final2_B.NLBC;
          } else if ((Carware_final2_P.insurance_V == 0.0) &&
                     (Carware_final2_B.Clock > 690.0)) {
            Carware_final2_DW.is_c17_Carware_final2 =
              Carware_final2_IN_NoInsurance;
            Carware_final2_B.NLBuilding = Carware_final2_B.Add14;
            Carware_final2_B.NLProperty = Carware_final2_B.Add15;
            Carware_final2_B.NLProfit = Carware_final2_B.Add16;
            Carware_final2_B.NLBC = Carware_final2_B.Add18;
            Carware_final2_B.NL = ((Carware_final2_B.NLBuilding +
              Carware_final2_B.NLProperty) + Carware_final2_B.NLProfit) +
              Carware_final2_B.NLBC;
          } else if ((Carware_final2_P.insurance_V == 1.0) &&
                     (Carware_final2_B.Clock > 690.0)) {
            Carware_final2_DW.is_c17_Carware_final2 = Carware_final2_IN_Package1;
            Carware_final2_B.Premium = 0.1;
            if (Carware_final2_B.Add14 > 10.0) {
              Carware_final2_B.NLBuilding = Carware_final2_B.Add14 - 10.0;
            } else {
              Carware_final2_B.NLBuilding = 0.0;
            }

            Carware_final2_B.NLProperty = Carware_final2_B.Add15;
            Carware_final2_B.NLProfit = Carware_final2_B.Add16;
            Carware_final2_B.NLBC = Carware_final2_B.Add18;
            Carware_final2_B.NL = ((Carware_final2_B.NLBuilding +
              Carware_final2_B.NLProperty) + Carware_final2_B.NLProfit) +
              Carware_final2_B.NLBC;
          } else if ((Carware_final2_P.insurance_V == 2.0) &&
                     (Carware_final2_B.Clock > 690.0)) {
            Carware_final2_DW.is_c17_Carware_final2 = Carware_final2_IN_Package2;
            Carware_final2_B.Premium = 0.3;
            if (Carware_final2_B.Add14 > 10.0) {
              Carware_final2_B.NLBuilding = Carware_final2_B.Add14 - 10.0;
            } else {
              Carware_final2_B.NLBuilding = 0.0;
            }

            if (Carware_final2_B.Add15 > 15.0) {
              Carware_final2_B.NLProperty = Carware_final2_B.Add15 - 15.0;
            } else {
              Carware_final2_B.NLProperty = 0.0;
            }

            Carware_final2_B.NLProfit = Carware_final2_B.Add16;
            Carware_final2_B.NLBC = Carware_final2_B.Add18;
            Carware_final2_B.NL = ((Carware_final2_B.NLBuilding +
              Carware_final2_B.NLProperty) + Carware_final2_B.NLProfit) +
              Carware_final2_B.NLBC;
          } else if ((Carware_final2_P.insurance_V == 4.0) &&
                     (Carware_final2_B.Clock > 690.0)) {
            Carware_final2_DW.is_c17_Carware_final2 = Carware_final2_IN_Package4;
            Carware_final2_B.Premium = 0.11;
            if (Carware_final2_B.Add14 > 10.0) {
              Carware_final2_B.NLBuilding = Carware_final2_B.Add14 - 10.0;
            } else {
              Carware_final2_B.NLBuilding = 0.0;
            }

            Carware_final2_B.NLProperty = Carware_final2_B.Add15;
            Carware_final2_B.NLProfit = Carware_final2_B.Add16;
          } else if ((Carware_final2_P.insurance_V == 5.0) &&
                     (Carware_final2_B.Clock > 690.0)) {
            Carware_final2_DW.is_c17_Carware_final2 = Carware_final2_IN_Package5;
            Carware_final2_B.Premium = 0.02;
            Carware_final2_B.NLBuilding = Carware_final2_B.Add14;
            Carware_final2_B.NLProperty = Carware_final2_B.Add15;
            Carware_final2_B.NLProfit = Carware_final2_B.Add16;
          } else if ((Carware_final2_P.insurance_V == 6.0) &&
                     (Carware_final2_B.Clock > 690.0)) {
            Carware_final2_DW.is_c17_Carware_final2 = Carware_final2_IN_Full;
            Carware_final2_B.Premium = 0.5;
            rtb_Add22 = (Carware_final2_B.Add14 + Carware_final2_B.Add15) +
              Carware_final2_B.Add16;
            if (Carware_final2_B.Delayed > 8.0) {
              Carware_final2_DW.Coverage = 20.0;
            }

            if (Carware_final2_B.Delayed > 7.0) {
              Carware_final2_DW.Coverage = 15.0;
            }

            if (Carware_final2_B.Delayed > 6.0) {
              Carware_final2_DW.Coverage = 10.0;
            }

            if (Carware_final2_B.Delayed > 5.0) {
              Carware_final2_DW.Coverage = 7.0;
            }

            if (Carware_final2_B.Add18 > Carware_final2_DW.Coverage) {
              Carware_final2_B.NLBC = Carware_final2_B.Add18 -
                Carware_final2_DW.Coverage;
            } else {
              Carware_final2_B.NLBC = 0.0;
            }

            if (rtb_Add22 > 50.0) {
              AxO_tmp = rtb_Add22 - 50.0;
            } else {
              AxO_tmp = 0.0;
            }

            Carware_final2_B.NL = AxO_tmp + Carware_final2_B.NLBC;
          } else {
            Carware_final2_DW.Coverage = 0.0;
          }
          break;

         case Carware_final2_IN_NoInsurance:
          Carware_final2_B.NLBuilding = Carware_final2_B.Add14;
          Carware_final2_B.NLProperty = Carware_final2_B.Add15;
          Carware_final2_B.NLProfit = Carware_final2_B.Add16;
          Carware_final2_B.NLBC = Carware_final2_B.Add18;
          Carware_final2_B.NL = ((Carware_final2_B.NLBuilding +
            Carware_final2_B.NLProperty) + Carware_final2_B.NLProfit) +
            Carware_final2_B.NLBC;
          break;

         case Carware_final2_IN_Package1:
          Carware_final2_B.Premium = 0.1;
          if (Carware_final2_B.Add14 > 10.0) {
            Carware_final2_B.NLBuilding = Carware_final2_B.Add14 - 10.0;
          } else {
            Carware_final2_B.NLBuilding = 0.0;
          }

          Carware_final2_B.NLProperty = Carware_final2_B.Add15;
          Carware_final2_B.NLProfit = Carware_final2_B.Add16;
          Carware_final2_B.NLBC = Carware_final2_B.Add18;
          Carware_final2_B.NL = ((Carware_final2_B.NLBuilding +
            Carware_final2_B.NLProperty) + Carware_final2_B.NLProfit) +
            Carware_final2_B.NLBC;
          break;

         case Carware_final2_IN_Package2:
          Carware_final2_B.Premium = 0.3;
          if (Carware_final2_B.Add14 > 10.0) {
            Carware_final2_B.NLBuilding = Carware_final2_B.Add14 - 10.0;
          } else {
            Carware_final2_B.NLBuilding = 0.0;
          }

          if (Carware_final2_B.Add15 > 15.0) {
            Carware_final2_B.NLProperty = Carware_final2_B.Add15 - 15.0;
          } else {
            Carware_final2_B.NLProperty = 0.0;
          }

          Carware_final2_B.NLProfit = Carware_final2_B.Add16;
          Carware_final2_B.NLBC = Carware_final2_B.Add18;
          Carware_final2_B.NL = ((Carware_final2_B.NLBuilding +
            Carware_final2_B.NLProperty) + Carware_final2_B.NLProfit) +
            Carware_final2_B.NLBC;
          break;

         case Carware_final2_IN_Package3:
          Carware_final2_B.Premium = 0.2;
          if (Carware_final2_B.Add14 > 10.0) {
            Carware_final2_B.NLBuilding = Carware_final2_B.Add14 - 10.0;
          } else {
            Carware_final2_B.NLBuilding = 0.0;
          }

          if (Carware_final2_B.Add16 > 30.0) {
            Carware_final2_B.NLProfit = Carware_final2_B.Add16 - 30.0;
          } else {
            Carware_final2_B.NLProfit = 0.0;
          }

          Carware_final2_B.NLProperty = Carware_final2_B.Add15;
          Carware_final2_B.NLBC = Carware_final2_B.Add18;
          Carware_final2_B.NL = ((Carware_final2_B.NLBuilding +
            Carware_final2_B.NLProperty) + Carware_final2_B.NLProfit) +
            Carware_final2_B.NLBC;
          break;

         case Carware_final2_IN_Package4:
          if (Carware_final2_B.Delayed > 0.0) {
            Carware_final2_DW.is_c17_Carware_final2 = Carware_final2_IN_BC;
            Carware_final2_enter_atomic_BC();
          } else {
            Carware_final2_B.Premium = 0.11;
            if (Carware_final2_B.Add14 > 10.0) {
              Carware_final2_B.NLBuilding = Carware_final2_B.Add14 - 10.0;
            } else {
              Carware_final2_B.NLBuilding = 0.0;
            }

            Carware_final2_B.NLProperty = Carware_final2_B.Add15;
            Carware_final2_B.NLProfit = Carware_final2_B.Add16;
          }
          break;

         default:
          /* case IN_Package5: */
          if (Carware_final2_B.Delayed > 0.0) {
            Carware_final2_DW.is_c17_Carware_final2 = Carware_final2_IN_BC;
            Carware_final2_enter_atomic_BC();
          } else {
            Carware_final2_B.Premium = 0.02;
            Carware_final2_B.NLBuilding = Carware_final2_B.Add14;
            Carware_final2_B.NLProperty = Carware_final2_B.Add15;
            Carware_final2_B.NLProfit = Carware_final2_B.Add16;
          }
          break;
        }
      }

      /* End of Chart: '<Root>/Chart1' */

      /* Sum: '<Root>/Add22' */
      rtb_Add22 = (rtb_Add21 + Carware_final2_B.NL) + Carware_final2_B.Premium;

      /* Sum: '<Root>/Add5' incorporates:
       *  Constant: '<Root>/AFP'
       *  Constant: '<Root>/FPmax'
       */
      rtb_Product17 = Carware_final2_P.solution1_1 +
        Carware_final2_P.FPmax_Value;

      /* Chart: '<Root>/Finished Products Warehouse' incorporates:
       *  Constant: '<Root>/FPdefault'
       */
      if (Carware_final2_DW.is_active_c5_Carware_final2 == 0U) {
        Carware_final2_DW.is_active_c5_Carware_final2 = 1U;
        Carware_final2_DW.is_c5_Carware_final2 = Carware_final2_IN_Init;
        Carware_final2_B.FinishedProducts = Carware_final2_P.FPdefault_Value;
        Carware_final2_B.AxFP = 3.0;
        Carware_final2_B.LxFP = 3.0;
      } else {
        switch (Carware_final2_DW.is_c5_Carware_final2) {
         case Carware_final2_IN_Empty_b:
          if (Carware_final2_B.FinishedProducts > 0.0) {
            Carware_final2_DW.is_c5_Carware_final2 = Carware_final2_IN_Update_o;
            Carware_final2_B.FinishedProducts =
              (Carware_final2_B.FinishedProducts + Carware_final2_B.Switch1) -
              Carware_final2_B.Switch7;
            Carware_final2_B.AxFP = 3.0;
            Carware_final2_B.LxFP = 3.0;
            if (Carware_final2_B.FinishedProducts <= 0.0) {
              Carware_final2_B.LxFP = Carware_final2_B.Switch1;
              Carware_final2_B.FinishedProducts = 0.0;
            } else if (Carware_final2_B.FinishedProducts > rtb_Product17) {
              Carware_final2_B.AxFP = Carware_final2_B.Switch7;
              Carware_final2_B.FinishedProducts = rtb_Product17;
            }
          } else {
            Carware_final2_B.LxFP = Carware_final2_B.Switch1;
            if (Carware_final2_B.Switch7 >= Carware_final2_B.Switch1) {
              Carware_final2_B.FinishedProducts = 0.0;
            } else {
              Carware_final2_B.FinishedProducts = Carware_final2_B.Switch1 -
                Carware_final2_B.Switch7;
            }
          }
          break;

         case Carware_final2_IN_Full:
          if (Carware_final2_B.FinishedProducts < rtb_Product17) {
            Carware_final2_DW.is_c5_Carware_final2 = Carware_final2_IN_Update_o;
            Carware_final2_B.FinishedProducts =
              (Carware_final2_B.FinishedProducts + Carware_final2_B.Switch1) -
              Carware_final2_B.Switch7;
            Carware_final2_B.AxFP = 3.0;
            Carware_final2_B.LxFP = 3.0;
            if (Carware_final2_B.FinishedProducts <= 0.0) {
              Carware_final2_B.LxFP = Carware_final2_B.Switch1;
              Carware_final2_B.FinishedProducts = 0.0;
            } else if (Carware_final2_B.FinishedProducts > rtb_Product17) {
              Carware_final2_B.AxFP = Carware_final2_B.Switch7;
              Carware_final2_B.FinishedProducts = rtb_Product17;
            }
          } else {
            Carware_final2_B.AxFP = Carware_final2_B.Switch7;
            if (Carware_final2_B.Switch1 >= Carware_final2_B.Switch7) {
              Carware_final2_B.FinishedProducts = rtb_Product17;
            } else {
              Carware_final2_B.FinishedProducts = (rtb_Product17 +
                Carware_final2_B.Switch1) - Carware_final2_B.Switch7;
            }
          }
          break;

         case Carware_final2_IN_Init:
          if ((Carware_final2_B.Switch1 > 0.0) || (Carware_final2_B.Switch7 >
               0.0)) {
            Carware_final2_DW.is_c5_Carware_final2 = Carware_final2_IN_Update_o;
            Carware_final2_B.FinishedProducts =
              (Carware_final2_B.FinishedProducts + Carware_final2_B.Switch1) -
              Carware_final2_B.Switch7;
            Carware_final2_B.AxFP = 3.0;
            Carware_final2_B.LxFP = 3.0;
            if (Carware_final2_B.FinishedProducts <= 0.0) {
              Carware_final2_B.LxFP = Carware_final2_B.Switch1;
              Carware_final2_B.FinishedProducts = 0.0;
            } else if (Carware_final2_B.FinishedProducts > rtb_Product17) {
              Carware_final2_B.AxFP = Carware_final2_B.Switch7;
              Carware_final2_B.FinishedProducts = rtb_Product17;
            }
          } else {
            Carware_final2_B.FinishedProducts = Carware_final2_P.FPdefault_Value;
            Carware_final2_B.AxFP = 3.0;
            Carware_final2_B.LxFP = 3.0;
          }
          break;

         default:
          /* case IN_Update: */
          if (Carware_final2_B.FinishedProducts >= rtb_Product17) {
            Carware_final2_DW.is_c5_Carware_final2 = Carware_final2_IN_Full;
            Carware_final2_B.AxFP = Carware_final2_B.Switch7;
            if (Carware_final2_B.Switch1 >= Carware_final2_B.Switch7) {
              Carware_final2_B.FinishedProducts = rtb_Product17;
            } else {
              Carware_final2_B.FinishedProducts = (rtb_Product17 +
                Carware_final2_B.Switch1) - Carware_final2_B.Switch7;
            }
          } else if (Carware_final2_B.FinishedProducts <= 0.0) {
            Carware_final2_DW.is_c5_Carware_final2 = Carware_final2_IN_Empty_b;
            Carware_final2_B.LxFP = Carware_final2_B.Switch1;
            if (Carware_final2_B.Switch7 >= Carware_final2_B.Switch1) {
              Carware_final2_B.FinishedProducts = 0.0;
            } else {
              Carware_final2_B.FinishedProducts = Carware_final2_B.Switch1 -
                Carware_final2_B.Switch7;
            }
          } else {
            Carware_final2_B.FinishedProducts =
              (Carware_final2_B.FinishedProducts + Carware_final2_B.Switch1) -
              Carware_final2_B.Switch7;
            Carware_final2_B.AxFP = 3.0;
            Carware_final2_B.LxFP = 3.0;
            if (Carware_final2_B.FinishedProducts <= 0.0) {
              Carware_final2_B.LxFP = Carware_final2_B.Switch1;
              Carware_final2_B.FinishedProducts = 0.0;
            } else if (Carware_final2_B.FinishedProducts > rtb_Product17) {
              Carware_final2_B.AxFP = Carware_final2_B.Switch7;
              Carware_final2_B.FinishedProducts = rtb_Product17;
            }
          }
          break;
        }
      }

      /* End of Chart: '<Root>/Finished Products Warehouse' */
      /* Delay: '<Root>/Delay12' incorporates:
       *  Constant: '<Root>/DRM'
       */
      if (Carware_final2_DW.icLoad_c) {
        Carware_final2_DW.Delay12_DSTATE = Carware_final2_P.solution2_4;
      }

      rtb_Switch9 = Carware_final2_DW.Delay12_DSTATE;

      /* End of Delay: '<Root>/Delay12' */

      /* RelationalOperator: '<Root>/Relational Operator1' incorporates:
       *  Constant: '<Root>/DRM'
       */
      rtb_RelationalOperator1 = (rtb_Switch9 < Carware_final2_P.solution2_4);

      /* Delay: '<Root>/Delay5' */
      rtb_Switch9 = Carware_final2_DW.Delay5_DSTATE;

      /* Logic: '<Root>/Logical Operator5' incorporates:
       *  Constant: '<S17>/Constant'
       *  RelationalOperator: '<S17>/Compare'
       */
      rtb_LogicalOperator5 = (rtb_LogicalOperator5 && (rtb_Switch9 >
        Carware_final2_P.CompareToConstant8_const));

      /* Switch: '<Root>/Switch6' incorporates:
       *  Constant: '<Root>/Const'
       *  Constant: '<Root>/ITRM'
       *  Constant: '<Root>/Truck capacity2'
       *  Product: '<Root>/Product13'
       */
      if (rtb_LogicalOperator5) {
        rtb_InboundLogistics_e = Carware_final2_P.solution4_2 *
          Carware_final2_P.Truckcapacity2_Value;
      } else {
        rtb_InboundLogistics_e = Carware_final2_P.Const_Value;
      }

      /* End of Switch: '<Root>/Switch6' */
      /* MinMax: '<Root>/MinMax6' incorporates:
       *  Sum: '<Root>/Sum3'
       */
      rtb_InboundLogistics_e = fmin(rtb_Switch9, rtb_InboundLogistics_e +
        Carware_final2_B.Logistics);

      /* Switch: '<Root>/Switch5' incorporates:
       *  Constant: '<S15>/Constant'
       *  Logic: '<Root>/Logical Operator3'
       *  RelationalOperator: '<S15>/Compare'
       */
      if (rtb_Compare_bi && (rtb_Switch9 >=
                             Carware_final2_P.CompareToConstant6_const) &&
          rtb_RelationalOperator1) {
        /* Switch: '<Root>/Switch5' incorporates:
         *  Gain: '<S32>/Slider Gain'
         */
        Carware_final2_B.Switch5 = Carware_final2_P.SliderGain6_gain *
          rtb_InboundLogistics_e;
      } else {
        /* Switch: '<Root>/Switch5' */
        Carware_final2_B.Switch5 = rtb_InboundLogistics_e;
      }

      /* End of Switch: '<Root>/Switch5' */

      /* Sum: '<Root>/Add8' incorporates:
       *  Constant: '<Root>/ARM'
       *  Constant: '<Root>/RM max'
       */
      Carware_final2_B.Add8 = Carware_final2_P.RMmax_Value +
        Carware_final2_P.solution2_1;

      /* Chart: '<Root>/Raw Material' incorporates:
       *  Constant: '<Root>/DRM'
       */
      if (Carware_final2_DW.is_active_c1_Carware_final2 == 0U) {
        Carware_final2_DW.is_active_c1_Carware_final2 = 1U;
        Carware_final2_DW.is_c1_Carware_final2 = Carware_final2_IN_Init;
        Carware_final2_B.RawMaterial = Carware_final2_P.solution2_4;
        Carware_final2_B.MxRM = 3.0;
        Carware_final2_B.LxRM = 3.0;
      } else {
        switch (Carware_final2_DW.is_c1_Carware_final2) {
         case Carware_final2_IN_Empty_b:
          if (Carware_final2_B.RawMaterial > 0.0) {
            Carware_final2_DW.is_c1_Carware_final2 = Carware_final2_IN_Update_o;
            Carware_f_enter_atomic_Update_l();
          } else {
            Carware_final2_B.MxRM = Carware_final2_B.Switch5;
            if (Carware_final2_B.Switch >= Carware_final2_B.Switch5) {
              Carware_final2_B.RawMaterial = 0.0;
            } else {
              Carware_final2_B.RawMaterial = Carware_final2_B.Switch5 -
                Carware_final2_B.Switch;
            }
          }
          break;

         case Carware_final2_IN_Full:
          if (Carware_final2_B.RawMaterial < Carware_final2_B.Add8) {
            Carware_final2_DW.is_c1_Carware_final2 = Carware_final2_IN_Update_o;
            Carware_f_enter_atomic_Update_l();
          } else {
            Carware_final2_B.LxRM = Carware_final2_B.Switch;
            if (Carware_final2_B.Switch5 >= Carware_final2_B.Switch) {
              Carware_final2_B.RawMaterial = Carware_final2_B.Add8;
            } else {
              Carware_final2_B.RawMaterial = (Carware_final2_B.Add8 +
                Carware_final2_B.Switch5) - Carware_final2_B.Switch;
            }
          }
          break;

         case Carware_final2_IN_Init:
          if ((Carware_final2_B.Switch > 0.0) || (Carware_final2_B.Switch5 > 0.0))
          {
            Carware_final2_DW.is_c1_Carware_final2 = Carware_final2_IN_Update_o;
            Carware_f_enter_atomic_Update_l();
          } else {
            Carware_final2_B.RawMaterial = Carware_final2_P.solution2_4;
            Carware_final2_B.MxRM = 3.0;
            Carware_final2_B.LxRM = 3.0;
          }
          break;

         default:
          /* case IN_Update: */
          if (Carware_final2_B.RawMaterial >= Carware_final2_B.Add8) {
            Carware_final2_DW.is_c1_Carware_final2 = Carware_final2_IN_Full;
            Carware_final2_B.LxRM = Carware_final2_B.Switch;
            if (Carware_final2_B.Switch5 >= Carware_final2_B.Switch) {
              Carware_final2_B.RawMaterial = Carware_final2_B.Add8;
            } else {
              Carware_final2_B.RawMaterial = (Carware_final2_B.Add8 +
                Carware_final2_B.Switch5) - Carware_final2_B.Switch;
            }
          } else if (Carware_final2_B.RawMaterial <= 0.0) {
            Carware_final2_DW.is_c1_Carware_final2 = Carware_final2_IN_Empty_b;
            Carware_final2_B.MxRM = Carware_final2_B.Switch5;
            if (Carware_final2_B.Switch >= Carware_final2_B.Switch5) {
              Carware_final2_B.RawMaterial = 0.0;
            } else {
              Carware_final2_B.RawMaterial = Carware_final2_B.Switch5 -
                Carware_final2_B.Switch;
            }
          } else {
            if ((Carware_final2_B.Switch == 1.0) && (fabs
                 (Carware_final2_B.RawMaterial - Carware_final2_P.solution2_4) <
                 fabs(Carware_final2_B.Switch - Carware_final2_B.Switch5))) {
              Carware_final2_B.RawMaterial = Carware_final2_P.solution2_4;
            } else {
              Carware_final2_B.RawMaterial = (Carware_final2_B.RawMaterial +
                Carware_final2_B.Switch5) - Carware_final2_B.Switch;
            }

            if ((Carware_final2_B.Switch == 1.0) &&
                (Carware_final2_B.RawMaterial > Carware_final2_P.solution2_4)) {
              Carware_final2_B.LxRM = 0.0;
            } else {
              Carware_final2_B.MxRM = 3.0;
              Carware_final2_B.LxRM = 3.0;
            }

            if (Carware_final2_B.RawMaterial < 0.0) {
              Carware_final2_B.MxRM = Carware_final2_B.Switch5;
              Carware_final2_B.RawMaterial = 0.0;
            } else if (Carware_final2_B.RawMaterial > Carware_final2_B.Add8) {
              Carware_final2_B.LxRM = Carware_final2_B.Switch;
              Carware_final2_B.RawMaterial = Carware_final2_B.Add8;
            }
          }
          break;
        }
      }

      /* End of Chart: '<Root>/Raw Material' */
    }

    /* Integrator: '<Root>/Integrator1' */
    Carware_final2_B.Integrator1 = Carware_final2_X.Integrator1_CSTATE;
    if (rtmIsMajorTimeStep(Carware_final2_M)) {
    }

    /* Integrator: '<Root>/Integrator10' */
    Carware_final2_B.Integrator10 = Carware_final2_X.Integrator10_CSTATE;

    /* Integrator: '<Root>/Integrator9' */
    Carware_final2_B.Integrator9 = Carware_final2_X.Integrator9_CSTATE;
    if (rtmIsMajorTimeStep(Carware_final2_M)) {
      /* Switch: '<Root>/Switch8' incorporates:
       *  Constant: '<Root>/Const'
       *  Constant: '<Root>/Const2'
       */
      if (rtb_LogicalOperator4) {
        rtb_Switch9 = Carware_final2_P.Const2_Value;
      } else {
        rtb_Switch9 = Carware_final2_P.Const_Value;
      }

      /* End of Switch: '<Root>/Switch8' */

      /* Product: '<Root>/Product3' incorporates:
       *  Constant: '<Root>/ITC'
       *  Constant: '<Root>/ITEP'
       */
      Carware_final2_B.Product3 = rtb_Switch9 * Carware_final2_P.solution4_3 *
        Carware_final2_P.ITC_Value;

      /* Switch: '<Root>/Switch9' incorporates:
       *  Constant: '<Root>/Const1'
       *  Constant: '<Root>/Const3'
       */
      if (rtb_LogicalOperator7) {
        rtb_Switch9 = Carware_final2_P.Const3_Value;
      } else {
        rtb_Switch9 = Carware_final2_P.Const1_Value;
      }

      /* End of Switch: '<Root>/Switch9' */

      /* Product: '<Root>/Product4' incorporates:
       *  Constant: '<Root>/OTC'
       *  Constant: '<Root>/OTFP'
       */
      Carware_final2_B.Product4 = rtb_Switch9 * Carware_final2_P.OTC_Value *
        Carware_final2_P.solution4_1;

      /* SignalConversion generated from: '<Root>/To File' */
      rtb_TmpSignalConversionAtToFile[0] = Carware_final2_B.Damage_d;
      rtb_TmpSignalConversionAtToFile[1] = Carware_final2_B.Damage_p;
      rtb_TmpSignalConversionAtToFile[2] = Carware_final2_B.Damage_l;
      rtb_TmpSignalConversionAtToFile[3] = Carware_final2_B.Damage_n;
      rtb_TmpSignalConversionAtToFile[4] = Carware_final2_B.Damage_m;
      rtb_TmpSignalConversionAtToFile[5] = Carware_final2_B.Damage;
      rtb_TmpSignalConversionAtToFile[6] = rtb_Switch13;
      rtb_TmpSignalConversionAtToFile[7] = rtb_Gain4;
      rtb_TmpSignalConversionAtToFile[8] = Carware_final2_B.Add16;
      rtb_TmpSignalConversionAtToFile[9] = Carware_final2_B.Add18;
      rtb_TmpSignalConversionAtToFile[10] = rtb_Add21;
      rtb_TmpSignalConversionAtToFile[11] = rtb_Add22;
      rtb_TmpSignalConversionAtToFile[12] = Carware_final2_B.NLBuilding;
      rtb_TmpSignalConversionAtToFile[13] = Carware_final2_B.NLProperty;
      rtb_TmpSignalConversionAtToFile[14] = Carware_final2_B.NLProfit;
      rtb_TmpSignalConversionAtToFile[15] = Carware_final2_B.NLBC;
      rtb_TmpSignalConversionAtToFile[16] = Carware_final2_B.NL;
      rtb_TmpSignalConversionAtToFile[17] = Carware_final2_B.RawMaterial;
      rtb_TmpSignalConversionAtToFile[18] = Carware_final2_B.IParts;
      rtb_TmpSignalConversionAtToFile[19] = Carware_final2_B.EParts;
      rtb_TmpSignalConversionAtToFile[20] = Carware_final2_B.FinishedProducts;
      rtb_TmpSignalConversionAtToFile[21] = Carware_final2_B.Premium;

      /* ToFile: '<Root>/To File' */
      {
        if (!(++Carware_final2_DW.ToFile_IWORK.Decimation % 1) &&
            (Carware_final2_DW.ToFile_IWORK.Count * (22 + 1)) + 1 < 100000000 )
        {
          FILE *fp = (FILE *) Carware_final2_DW.ToFile_PWORK.FilePtr;
          if (fp != (NULL)) {
            real_T u[22 + 1];
            Carware_final2_DW.ToFile_IWORK.Decimation = 0;
            u[0] = (((Carware_final2_M->Timing.clockTick1+
                      Carware_final2_M->Timing.clockTickH1* 4294967296.0)) * 1.0);
            u[1] = rtb_TmpSignalConversionAtToFile[0];
            u[2] = rtb_TmpSignalConversionAtToFile[1];
            u[3] = rtb_TmpSignalConversionAtToFile[2];
            u[4] = rtb_TmpSignalConversionAtToFile[3];
            u[5] = rtb_TmpSignalConversionAtToFile[4];
            u[6] = rtb_TmpSignalConversionAtToFile[5];
            u[7] = rtb_TmpSignalConversionAtToFile[6];
            u[8] = rtb_TmpSignalConversionAtToFile[7];
            u[9] = rtb_TmpSignalConversionAtToFile[8];
            u[10] = rtb_TmpSignalConversionAtToFile[9];
            u[11] = rtb_TmpSignalConversionAtToFile[10];
            u[12] = rtb_TmpSignalConversionAtToFile[11];
            u[13] = rtb_TmpSignalConversionAtToFile[12];
            u[14] = rtb_TmpSignalConversionAtToFile[13];
            u[15] = rtb_TmpSignalConversionAtToFile[14];
            u[16] = rtb_TmpSignalConversionAtToFile[15];
            u[17] = rtb_TmpSignalConversionAtToFile[16];
            u[18] = rtb_TmpSignalConversionAtToFile[17];
            u[19] = rtb_TmpSignalConversionAtToFile[18];
            u[20] = rtb_TmpSignalConversionAtToFile[19];
            u[21] = rtb_TmpSignalConversionAtToFile[20];
            u[22] = rtb_TmpSignalConversionAtToFile[21];
            if (fwrite(u, sizeof(real_T), 22 + 1, fp) != 22 + 1) {
              rtmSetErrorStatus(Carware_final2_M,
                                "Error writing to MAT-file results.mat");
              return;
            }

            if (((++Carware_final2_DW.ToFile_IWORK.Count) * (22 + 1))+1 >=
                100000000) {
              (void)fprintf(stdout,
                            "*** The ToFile block will stop logging data before\n"
                            "    the simulation has ended, because it has reached\n"
                            "    the maximum number of elements (100000000)\n"
                            "    allowed in MAT-file results.mat.\n");
            }
          }
        }
      }

      /* Sum: '<Root>/Add13' incorporates:
       *  Constant: '<Root>/Constant2'
       */
      Carware_final2_B.Add13 = (Carware_final2_P.Constant2_Value -
        Carware_final2_B.SliderGain) - Carware_final2_B.Add1;

      /* Sum: '<Root>/Add23' */
      Carware_final2_B.Add23 = Carware_final2_B.Add1 +
        Carware_final2_B.SliderGain;

      /* Switch: '<Root>/Switch10' incorporates:
       *  Constant: '<Root>/Const4'
       *  Constant: '<Root>/Const5'
       */
      if (rtb_LogicalOperator1) {
        rtb_Switch13 = Carware_final2_P.Const5_Value;
      } else {
        rtb_Switch13 = Carware_final2_P.Const4_Value;
      }

      /* End of Switch: '<Root>/Switch10' */

      /* Product: '<Root>/Product11' incorporates:
       *  Constant: '<Root>/Overtime daily'
       */
      Carware_final2_B.Product11 = Carware_final2_P.Overtimedaily_Value *
        rtb_Switch13;

      /* Switch: '<Root>/Switch11' incorporates:
       *  Constant: '<Root>/Const4'
       *  Constant: '<Root>/Const5'
       */
      if (rtb_LogicalOperator) {
        rtb_Switch13 = Carware_final2_P.Const5_Value;
      } else {
        rtb_Switch13 = Carware_final2_P.Const4_Value;
      }

      /* End of Switch: '<Root>/Switch11' */

      /* Product: '<Root>/Product12' incorporates:
       *  Constant: '<Root>/Overtime daily'
       */
      Carware_final2_B.Product12 = Carware_final2_P.Overtimedaily_Value *
        rtb_Switch13;

      /* Switch: '<Root>/Switch13' incorporates:
       *  Constant: '<Root>/Const'
       *  Constant: '<Root>/Const6'
       */
      if (rtb_LogicalOperator5) {
        rtb_Switch13 = Carware_final2_P.Const6_Value;
      } else {
        rtb_Switch13 = Carware_final2_P.Const_Value;
      }

      /* End of Switch: '<Root>/Switch13' */

      /* Product: '<Root>/Product14' incorporates:
       *  Constant: '<Root>/ITC1'
       *  Constant: '<Root>/ITRM'
       */
      Carware_final2_B.Product14 = rtb_Switch13 * Carware_final2_P.solution4_2 *
        Carware_final2_P.ITC1_Value;
    }

    /* Integrator: '<Root>/Integrator8' */
    Carware_final2_B.Integrator8 = Carware_final2_X.Integrator8_CSTATE;
  }

  if (rtmIsMajorTimeStep(Carware_final2_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(Carware_final2_M->rtwLogInfo,
                        (Carware_final2_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Carware_final2_M)) {
    int_T idxDelay;
    if (rtmIsMajorTimeStep(Carware_final2_M)) {
      /* Update for Delay: '<Root>/Delay19' incorporates:
       *  Constant: '<Root>/Constant11'
       */
      for (idxDelay = 0; idxDelay < 99; idxDelay++) {
        Carware_final2_DW.Delay19_DSTATE[idxDelay] =
          Carware_final2_DW.Delay19_DSTATE[idxDelay + 1];
      }

      Carware_final2_DW.Delay19_DSTATE[99] = Carware_final2_P.magnitude_V;

      /* End of Update for Delay: '<Root>/Delay19' */

      /* Update for Delay: '<Root>/Delay8' */
      Carware_final2_DW.Delay8_DSTATE = Carware_final2_B.AxFP;

      /* Update for Delay: '<Root>/Delay1' */
      Carware_final2_DW.Delay1_DSTATE = Carware_final2_B.AxIP;

      /* Update for Delay: '<Root>/Delay9' */
      Carware_final2_DW.Delay9_DSTATE = Carware_final2_B.AxO;

      /* Update for Delay: '<Root>/Delay6' */
      Carware_final2_DW.Delay6_DSTATE = Carware_final2_B.AxEP;

      /* Update for Delay: '<Root>/Delay11' */
      Carware_final2_DW.Delay11_DSTATE = Carware_final2_B.Orders;
      for (idxDelay = 0; idxDelay < 19; idxDelay++) {
        /* Update for Delay: '<Root>/Delay20' */
        Carware_final2_DW.Delay20_DSTATE[idxDelay] =
          Carware_final2_DW.Delay20_DSTATE[idxDelay + 1];

        /* Update for Delay: '<Root>/Delay18' */
        Carware_final2_DW.Delay18_DSTATE[idxDelay] =
          Carware_final2_DW.Delay18_DSTATE[idxDelay + 1];
      }

      /* Update for Delay: '<Root>/Delay20' */
      Carware_final2_DW.Delay20_DSTATE[19] = Carware_final2_B.Integrator8;

      /* Update for Delay: '<Root>/Delay18' */
      Carware_final2_DW.Delay18_DSTATE[19] = Carware_final2_B.Add1;

      /* Update for Delay: '<Root>/Delay7' */
      Carware_final2_DW.Delay7_DSTATE = Carware_final2_B.LxFP;

      /* Update for Delay: '<Root>/Delay17' */
      Carware_final2_DW.Delay17_DSTATE = Carware_final2_B.FinishedProducts;

      /* Update for Delay: '<Root>/Delay16' */
      for (idxDelay = 0; idxDelay < 29; idxDelay++) {
        Carware_final2_DW.Delay16_DSTATE[idxDelay] =
          Carware_final2_DW.Delay16_DSTATE[idxDelay + 1];
      }

      Carware_final2_DW.Delay16_DSTATE[29] = Carware_final2_B.Integrator1;

      /* End of Update for Delay: '<Root>/Delay16' */

      /* Update for Memory: '<S44>/Memory' */
      Carware_final2_DW.Memory_PreviousInput = Carware_final2_B.Reset;

      /* Update for Delay: '<Root>/Delay14' */
      for (idxDelay = 0; idxDelay < 59; idxDelay++) {
        Carware_final2_DW.Delay14_DSTATE[idxDelay] =
          Carware_final2_DW.Delay14_DSTATE[idxDelay + 1];
      }

      Carware_final2_DW.Delay14_DSTATE[59] = Carware_final2_B.Integrator1;

      /* End of Update for Delay: '<Root>/Delay14' */

      /* Update for Memory: '<S45>/Memory' */
      Carware_final2_DW.Memory_PreviousInput_i = Carware_final2_B.Reset_b;

      /* Update for Delay: '<Root>/Delay15' */
      for (idxDelay = 0; idxDelay < 89; idxDelay++) {
        Carware_final2_DW.Delay15_DSTATE[idxDelay] =
          Carware_final2_DW.Delay15_DSTATE[idxDelay + 1];
      }

      Carware_final2_DW.Delay15_DSTATE[89] = Carware_final2_B.Integrator1;

      /* End of Update for Delay: '<Root>/Delay15' */

      /* Update for Memory: '<S46>/Memory' */
      Carware_final2_DW.Memory_PreviousInput_f = Carware_final2_B.Reset_k;

      /* Update for Delay: '<Root>/Delay4' */
      Carware_final2_DW.Delay4_DSTATE = Carware_final2_B.LxEP;

      /* Update for Delay: '<Root>/Delay13' */
      Carware_final2_DW.icLoad = false;
      Carware_final2_DW.Delay13_DSTATE = Carware_final2_B.EParts;

      /* Update for Delay: '<Root>/Delay' */
      for (idxDelay = 0; idxDelay < 29; idxDelay++) {
        Carware_final2_DW.Delay_DSTATE[idxDelay] =
          Carware_final2_DW.Delay_DSTATE[idxDelay + 1];
      }

      Carware_final2_DW.Delay_DSTATE[29] = Carware_final2_B.Maintenance;

      /* End of Update for Delay: '<Root>/Delay' */

      /* Update for Delay: '<Root>/Delay3' */
      Carware_final2_DW.Delay3_DSTATE = Carware_final2_B.MxRM;

      /* Update for Delay: '<Root>/Delay2' */
      Carware_final2_DW.Delay2_DSTATE = Carware_final2_B.MxIP;

      /* Update for Delay: '<Root>/Delay10' */
      Carware_final2_DW.icLoad_b = false;
      Carware_final2_DW.Delay10_DSTATE = Carware_final2_B.IParts;

      /* Update for Delay: '<Root>/Delay12' */
      Carware_final2_DW.icLoad_c = false;
      Carware_final2_DW.Delay12_DSTATE = Carware_final2_B.RawMaterial;

      /* Update for Delay: '<Root>/Delay5' */
      Carware_final2_DW.Delay5_DSTATE = Carware_final2_B.LxRM;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Carware_final2_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(Carware_final2_M)!=-1) &&
          !((rtmGetTFinal(Carware_final2_M)-
             (((Carware_final2_M->Timing.clockTick1+
                Carware_final2_M->Timing.clockTickH1* 4294967296.0)) * 1.0)) >
            (((Carware_final2_M->Timing.clockTick1+
               Carware_final2_M->Timing.clockTickH1* 4294967296.0)) * 1.0) *
            (DBL_EPSILON))) {
        rtmSetErrorStatus(Carware_final2_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&Carware_final2_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Carware_final2_M->Timing.clockTick0)) {
      ++Carware_final2_M->Timing.clockTickH0;
    }

    Carware_final2_M->Timing.t[0] = rtsiGetSolverStopTime
      (&Carware_final2_M->solverInfo);

    {
      /* Update absolute timer for sample time: [1.0s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 1.0, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      Carware_final2_M->Timing.clockTick1++;
      if (!Carware_final2_M->Timing.clockTick1) {
        Carware_final2_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Carware_final2_derivatives(void)
{
  XDot_Carware_final2_T *_rtXdot;
  _rtXdot = ((XDot_Carware_final2_T *) Carware_final2_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = Carware_final2_B.Level;

  /* Derivatives for Integrator: '<Root>/Integrator6' */
  _rtXdot->Integrator6_CSTATE = Carware_final2_B.Add13;

  /* Derivatives for Integrator: '<Root>/Integrator4' */
  _rtXdot->Integrator4_CSTATE = Carware_final2_B.Product11;

  /* Derivatives for Integrator: '<Root>/Integrator5' */
  _rtXdot->Integrator5_CSTATE = Carware_final2_B.Product12;

  /* Derivatives for Integrator: '<Root>/Integrator3' */
  _rtXdot->Integrator3_CSTATE = Carware_final2_B.Product4;

  /* Derivatives for Integrator: '<Root>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = Carware_final2_B.Product3;

  /* Derivatives for Integrator: '<Root>/Integrator7' */
  _rtXdot->Integrator7_CSTATE = Carware_final2_B.Product14;

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = Carware_final2_B.SliderGain;

  /* Derivatives for Integrator: '<Root>/Integrator10' */
  _rtXdot->Integrator10_CSTATE = Carware_final2_B.Add23;

  /* Derivatives for Integrator: '<Root>/Integrator9' */
  _rtXdot->Integrator9_CSTATE = Carware_final2_B.Switch7;

  /* Derivatives for Integrator: '<Root>/Integrator8' */
  _rtXdot->Integrator8_CSTATE = Carware_final2_B.Add1;
}

/* Model initialize function */
void Carware_final2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Carware_final2_M, 0,
                sizeof(RT_MODEL_Carware_final2_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Carware_final2_M->solverInfo,
                          &Carware_final2_M->Timing.simTimeStep);
    rtsiSetTPtr(&Carware_final2_M->solverInfo, &rtmGetTPtr(Carware_final2_M));
    rtsiSetStepSizePtr(&Carware_final2_M->solverInfo,
                       &Carware_final2_M->Timing.stepSize0);
    rtsiSetdXPtr(&Carware_final2_M->solverInfo, &Carware_final2_M->derivs);
    rtsiSetContStatesPtr(&Carware_final2_M->solverInfo, (real_T **)
                         &Carware_final2_M->contStates);
    rtsiSetNumContStatesPtr(&Carware_final2_M->solverInfo,
      &Carware_final2_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Carware_final2_M->solverInfo,
      &Carware_final2_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Carware_final2_M->solverInfo,
      &Carware_final2_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Carware_final2_M->solverInfo,
      &Carware_final2_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Carware_final2_M->solverInfo, (&rtmGetErrorStatus
      (Carware_final2_M)));
    rtsiSetRTModelPtr(&Carware_final2_M->solverInfo, Carware_final2_M);
  }

  rtsiSetSimTimeStep(&Carware_final2_M->solverInfo, MAJOR_TIME_STEP);
  Carware_final2_M->intgData.y = Carware_final2_M->odeY;
  Carware_final2_M->intgData.f[0] = Carware_final2_M->odeF[0];
  Carware_final2_M->intgData.f[1] = Carware_final2_M->odeF[1];
  Carware_final2_M->intgData.f[2] = Carware_final2_M->odeF[2];
  Carware_final2_M->contStates = ((X_Carware_final2_T *) &Carware_final2_X);
  rtsiSetSolverData(&Carware_final2_M->solverInfo, (void *)
                    &Carware_final2_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&Carware_final2_M->solverInfo, false);
  rtsiSetSolverName(&Carware_final2_M->solverInfo,"ode3");
  rtmSetTPtr(Carware_final2_M, &Carware_final2_M->Timing.tArray[0]);
  rtmSetTFinal(Carware_final2_M, 720.0);
  Carware_final2_M->Timing.stepSize0 = 1.0;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    Carware_final2_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Carware_final2_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Carware_final2_M->rtwLogInfo, (NULL));
    rtliSetLogT(Carware_final2_M->rtwLogInfo, "tout");
    rtliSetLogX(Carware_final2_M->rtwLogInfo, "");
    rtliSetLogXFinal(Carware_final2_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Carware_final2_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Carware_final2_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Carware_final2_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Carware_final2_M->rtwLogInfo, 1);
    rtliSetLogY(Carware_final2_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Carware_final2_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Carware_final2_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &Carware_final2_B), 0,
                sizeof(B_Carware_final2_T));

  /* states (continuous) */
  {
    (void) memset((void *)&Carware_final2_X, 0,
                  sizeof(X_Carware_final2_T));
  }

  /* states (dwork) */
  (void) memset((void *)&Carware_final2_DW, 0,
                sizeof(DW_Carware_final2_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Carware_final2_M->rtwLogInfo, 0.0,
    rtmGetTFinal(Carware_final2_M), Carware_final2_M->Timing.stepSize0,
    (&rtmGetErrorStatus(Carware_final2_M)));

  /* Start for ToFile: '<Root>/To File' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "results.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(Carware_final2_M, "Error creating .mat file results.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 22 + 1, 0, "result_values")) {
      rtmSetErrorStatus(Carware_final2_M,
                        "Error writing mat file header to file results.mat");
      return;
    }

    Carware_final2_DW.ToFile_IWORK.Count = 0;
    Carware_final2_DW.ToFile_IWORK.Decimation = -1;
    Carware_final2_DW.ToFile_PWORK.FilePtr = fp;
  }

  {
    int32_T i;

    /* InitializeConditions for Delay: '<Root>/Delay19' */
    for (i = 0; i < 100; i++) {
      Carware_final2_DW.Delay19_DSTATE[i] =
        Carware_final2_P.Delay19_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<Root>/Delay19' */

    /* InitializeConditions for Delay: '<Root>/Delay8' */
    Carware_final2_DW.Delay8_DSTATE = Carware_final2_P.Delay8_InitialCondition;

    /* InitializeConditions for Delay: '<Root>/Delay1' */
    Carware_final2_DW.Delay1_DSTATE = Carware_final2_P.Delay1_InitialCondition;

    /* InitializeConditions for Delay: '<Root>/Delay9' */
    Carware_final2_DW.Delay9_DSTATE = Carware_final2_P.Delay9_InitialCondition;

    /* InitializeConditions for Delay: '<Root>/Delay6' */
    Carware_final2_DW.Delay6_DSTATE = Carware_final2_P.Delay6_InitialCondition;

    /* InitializeConditions for Delay: '<Root>/Delay11' */
    Carware_final2_DW.Delay11_DSTATE = Carware_final2_P.Delay11_InitialCondition;
    for (i = 0; i < 20; i++) {
      /* InitializeConditions for Delay: '<Root>/Delay20' */
      Carware_final2_DW.Delay20_DSTATE[i] =
        Carware_final2_P.Delay20_InitialCondition;

      /* InitializeConditions for Delay: '<Root>/Delay18' */
      Carware_final2_DW.Delay18_DSTATE[i] =
        Carware_final2_P.Delay18_InitialCondition;
    }

    /* InitializeConditions for Delay: '<Root>/Delay7' */
    Carware_final2_DW.Delay7_DSTATE = Carware_final2_P.Delay7_InitialCondition;

    /* InitializeConditions for Delay: '<Root>/Delay17' */
    Carware_final2_DW.Delay17_DSTATE = Carware_final2_P.Delay17_InitialCondition;

    /* InitializeConditions for Integrator: '<Root>/Integrator' */
    Carware_final2_X.Integrator_CSTATE = Carware_final2_P.Integrator_IC;

    /* InitializeConditions for Delay: '<Root>/Delay16' */
    for (i = 0; i < 30; i++) {
      Carware_final2_DW.Delay16_DSTATE[i] =
        Carware_final2_P.Delay16_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<Root>/Delay16' */

    /* InitializeConditions for Memory: '<S44>/Memory' */
    Carware_final2_DW.Memory_PreviousInput =
      Carware_final2_P.MinMaxRunningResettable_vinit;

    /* InitializeConditions for Delay: '<Root>/Delay14' */
    for (i = 0; i < 60; i++) {
      Carware_final2_DW.Delay14_DSTATE[i] =
        Carware_final2_P.Delay14_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<Root>/Delay14' */

    /* InitializeConditions for Memory: '<S45>/Memory' */
    Carware_final2_DW.Memory_PreviousInput_i =
      Carware_final2_P.MinMaxRunningResettable1_vinit;

    /* InitializeConditions for Delay: '<Root>/Delay15' */
    for (i = 0; i < 90; i++) {
      Carware_final2_DW.Delay15_DSTATE[i] =
        Carware_final2_P.Delay15_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<Root>/Delay15' */

    /* InitializeConditions for Memory: '<S46>/Memory' */
    Carware_final2_DW.Memory_PreviousInput_f =
      Carware_final2_P.MinMaxRunningResettable2_vinit;

    /* InitializeConditions for Delay: '<Root>/Delay4' */
    Carware_final2_DW.Delay4_DSTATE = Carware_final2_P.Delay4_InitialCondition;

    /* InitializeConditions for Delay: '<Root>/Delay13' */
    Carware_final2_DW.icLoad = true;

    /* InitializeConditions for Integrator: '<Root>/Integrator6' */
    Carware_final2_X.Integrator6_CSTATE = Carware_final2_P.Integrator6_IC;

    /* InitializeConditions for Delay: '<Root>/Delay' */
    for (i = 0; i < 30; i++) {
      Carware_final2_DW.Delay_DSTATE[i] =
        Carware_final2_P.Delay_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<Root>/Delay' */

    /* InitializeConditions for Delay: '<Root>/Delay3' */
    Carware_final2_DW.Delay3_DSTATE = Carware_final2_P.Delay3_InitialCondition;

    /* InitializeConditions for Delay: '<Root>/Delay2' */
    Carware_final2_DW.Delay2_DSTATE = Carware_final2_P.Delay2_InitialCondition;

    /* InitializeConditions for Delay: '<Root>/Delay10' */
    Carware_final2_DW.icLoad_b = true;

    /* InitializeConditions for Integrator: '<Root>/Integrator4' */
    Carware_final2_X.Integrator4_CSTATE = Carware_final2_P.Integrator4_IC;

    /* InitializeConditions for Integrator: '<Root>/Integrator5' */
    Carware_final2_X.Integrator5_CSTATE = Carware_final2_P.Integrator5_IC;

    /* InitializeConditions for Integrator: '<Root>/Integrator3' */
    Carware_final2_X.Integrator3_CSTATE = Carware_final2_P.Integrator3_IC;

    /* InitializeConditions for Integrator: '<Root>/Integrator2' */
    Carware_final2_X.Integrator2_CSTATE = Carware_final2_P.Integrator2_IC;

    /* InitializeConditions for Integrator: '<Root>/Integrator7' */
    Carware_final2_X.Integrator7_CSTATE = Carware_final2_P.Integrator7_IC;

    /* InitializeConditions for Delay: '<Root>/Delay12' */
    Carware_final2_DW.icLoad_c = true;

    /* InitializeConditions for Delay: '<Root>/Delay5' */
    Carware_final2_DW.Delay5_DSTATE = Carware_final2_P.Delay5_InitialCondition;

    /* InitializeConditions for Integrator: '<Root>/Integrator1' */
    Carware_final2_X.Integrator1_CSTATE = Carware_final2_P.Integrator1_IC;

    /* InitializeConditions for Integrator: '<Root>/Integrator10' */
    Carware_final2_X.Integrator10_CSTATE = Carware_final2_P.Integrator10_IC;

    /* InitializeConditions for Integrator: '<Root>/Integrator9' */
    Carware_final2_X.Integrator9_CSTATE = Carware_final2_P.Integrator9_IC;

    /* InitializeConditions for Integrator: '<Root>/Integrator8' */
    Carware_final2_X.Integrator8_CSTATE = Carware_final2_P.Integrator8_IC;

    /* SystemInitialize for State Transition Table: '<Root>/State Transition Table8' */
    Carware_final2_DW.is_active_c14_Carware_final2 = 0U;
    Carware_final2_DW.is_c14_Carware_final2 = Carware_fina_IN_NO_ACTIVE_CHILD;
    Carware_final2_DW.T_b = 0.0;
    Carware_final2_DW.RT_p = 0.0;
    Carware_final2_B.Damage_m = 0.0;

    /* SystemInitialize for State Transition Table: '<Root>/State Transition Table6' */
    Carware_final2_DW.is_active_c12_Carware_final2 = 0U;
    Carware_final2_DW.is_c12_Carware_final2 = Carware_fina_IN_NO_ACTIVE_CHILD;
    Carware_final2_DW.T_k = 0.0;
    Carware_final2_DW.RT_c = 0.0;
    Carware_final2_B.Damage_l = 0.0;

    /* SystemInitialize for State Transition Table: '<Root>/State Transition Table9' */
    Carware_final2_DW.is_active_c3_Carware_final2 = 0U;
    Carware_final2_DW.is_c3_Carware_final2 = Carware_fina_IN_NO_ACTIVE_CHILD;
    Carware_final2_DW.T = 0.0;
    Carware_final2_DW.RT_f = 0.0;
    Carware_final2_B.Damage = 0.0;

    /* SystemInitialize for State Transition Table: '<Root>/State Transition Table2' */
    Carware_final2_DW.is_active_c8_Carware_final2 = 0U;
    Carware_final2_DW.is_c8_Carware_final2 = Carware_fina_IN_NO_ACTIVE_CHILD;
    Carware_final2_DW.T_g = 0.0;
    Carware_final2_DW.RTe = 0.0;
    Carware_final2_DW.FRe = 0.0;
    Carware_final2_B.Electricity = 0.0;

    /* SystemInitialize for State Transition Table: '<Root>/State Transition Table4' */
    Carware_final2_DW.is_active_c10_Carware_final2 = 0U;
    Carware_final2_DW.is_c10_Carware_final2 = Carware_fina_IN_NO_ACTIVE_CHILD;
    Carware_final2_DW.T_j = 0.0;
    Carware_final2_DW.RTl = 0.0;
    Carware_final2_DW.FRl = 0.0;
    Carware_final2_B.Logistics = 0.0;

    /* SystemInitialize for Chart: '<Root>/Chart2' */
    Carware_final2_DW.is_active_c6_Carware_final2 = 0U;
    Carware_final2_DW.is_c6_Carware_final2 = Carware_fina_IN_NO_ACTIVE_CHILD;
    Carware_final2_DW.TotalCont = 0.0;
    Carware_final2_DW.Shipped = 0.0;
    Carware_final2_DW.Return = 0.0;
    Carware_final2_B.CR = 0.0;
    Carware_final2_B.Level = 0.0;

    /* SystemInitialize for Chart: '<Root>/Chart' */
    Carware_final2_DW.is_active_c16_Carware_final2 = 0U;
    Carware_final2_DW.is_c16_Carware_final2 = Carware_fina_IN_NO_ACTIVE_CHILD;
    Carware_final2_DW.OSales = 0.0;
    Carware_final2_DW.ShippedS = 0.0;
    Carware_final2_DW.ShippingS = 0.0;
    Carware_final2_B.AxO = 0.0;
    Carware_final2_B.Loss_h = 0.0;
    Carware_final2_B.Orders = 0.0;

    /* SystemInitialize for State Transition Table: '<Root>/State Transition Table5' */
    Carware_final2_DW.is_active_c11_Carware_final2 = 0U;
    Carware_final2_DW.is_c11_Carware_final2 = Carware_fina_IN_NO_ACTIVE_CHILD;
    Carware_final2_DW.T_n = 0.0;
    Carware_final2_DW.RT_e = 0.0;
    Carware_final2_B.Inventory = 0.0;
    Carware_final2_B.Damage_p = 0.0;

    /* SystemInitialize for Chart: '<Root>/External' */
    Carware_final2_DW.is_active_c15_Carware_final2 = 0U;
    Carware_final2_DW.is_c15_Carware_final2 = Carware_fina_IN_NO_ACTIVE_CHILD;
    Carware_final2_DW.Damage = 0.0;
    Carware_final2_B.LxEP = 0.0;
    Carware_final2_B.AxEP = 0.0;
    Carware_final2_B.EParts = 0.0;
    Carware_final2_B.Loss = 0.0;

    /* SystemInitialize for State Transition Table: '<Root>/State Transition Table1' */
    Carware_final2_DW.is_active_c7_Carware_final2 = 0U;
    Carware_final2_DW.is_c7_Carware_final2 = Carware_fina_IN_NO_ACTIVE_CHILD;
    Carware_final2_DW.T_gh = 0.0;
    Carware_final2_DW.RT_b = 0.0;
    Carware_final2_B.Damage_d = 0.0;

    /* SystemInitialize for State Transition Table: '<Root>/State Transition Table7' */
    Carware_final2_DW.is_active_c13_Carware_final2 = 0U;
    Carware_final2_DW.is_c13_Carware_final2 = Carware_fina_IN_NO_ACTIVE_CHILD;
    Carware_final2_DW.T_c = 0.0;
    Carware_final2_DW.RT_j = 0.0;
    Carware_final2_B.Damage_n = 0.0;

    /* SystemInitialize for State Transition Table: '<Root>/State Transition Table3' */
    Carware_final2_DW.is_active_c9_Carware_final2 = 0U;
    Carware_final2_DW.is_c9_Carware_final2 = Carware_fina_IN_NO_ACTIVE_CHILD;
    Carware_final2_DW.T_h = 0.0;
    Carware_final2_DW.RTm = 0.0;
    Carware_final2_DW.FRm = 0.0;
    Carware_final2_B.Maintenance = 0.0;

    /* SystemInitialize for State Transition Table: '<Root>/State Transition Table' */
    Carware_final2_DW.is_active_c4_Carware_final2 = 0U;
    Carware_final2_DW.is_c4_Carware_final2 = Carware_fina_IN_NO_ACTIVE_CHILD;
    Carware_final2_DW.T_i = 0.0;

    /* SystemInitialize for Chart: '<Root>/Internal' */
    Carware_final2_DW.is_active_c2_Carware_final2 = 0U;
    Carware_final2_DW.is_c2_Carware_final2 = Carware_fina_IN_NO_ACTIVE_CHILD;
    Carware_final2_DW.DamageIP = 0.0;
    Carware_final2_B.LossIP = 0.0;
    Carware_final2_B.AxIP = 0.0;
    Carware_final2_B.MxIP = 0.0;
    Carware_final2_B.IParts = 0.0;

    /* SystemInitialize for Chart: '<Root>/Chart1' */
    Carware_final2_DW.is_active_c17_Carware_final2 = 0U;
    Carware_final2_DW.is_c17_Carware_final2 = Carware_fina_IN_NO_ACTIVE_CHILD;
    Carware_final2_DW.Coverage = 0.0;
    Carware_final2_B.NL = 0.0;
    Carware_final2_B.Premium = 0.0;
    Carware_final2_B.NLBC = 0.0;
    Carware_final2_B.NLBuilding = 0.0;
    Carware_final2_B.NLProfit = 0.0;
    Carware_final2_B.NLProperty = 0.0;

    /* SystemInitialize for Chart: '<Root>/Finished Products Warehouse' */
    Carware_final2_DW.is_active_c5_Carware_final2 = 0U;
    Carware_final2_DW.is_c5_Carware_final2 = Carware_fina_IN_NO_ACTIVE_CHILD;
    Carware_final2_B.AxFP = 0.0;
    Carware_final2_B.LxFP = 0.0;
    Carware_final2_B.FinishedProducts = 0.0;

    /* SystemInitialize for Chart: '<Root>/Raw Material' */
    Carware_final2_DW.is_active_c1_Carware_final2 = 0U;
    Carware_final2_DW.is_c1_Carware_final2 = Carware_fina_IN_NO_ACTIVE_CHILD;
    Carware_final2_B.MxRM = 0.0;
    Carware_final2_B.LxRM = 0.0;
    Carware_final2_B.RawMaterial = 0.0;
  }
}

/* Model terminate function */
void Carware_final2_terminate(void)
{
  /* Terminate for ToFile: '<Root>/To File' */
  {
    FILE *fp = (FILE *) Carware_final2_DW.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "results.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(Carware_final2_M, "Error closing MAT-file results.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(Carware_final2_M,
                          "Error reopening MAT-file results.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 22 + 1,
           Carware_final2_DW.ToFile_IWORK.Count, "result_values")) {
        rtmSetErrorStatus(Carware_final2_M,
                          "Error writing header for result_values to MAT-file results.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(Carware_final2_M, "Error closing MAT-file results.mat");
        return;
      }

      Carware_final2_DW.ToFile_PWORK.FilePtr = (NULL);
    }
  }
}
