/*
 * File: f28m35x_test.h
 *
 * Code generated for Simulink model 'f28m35x_test'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 8.1 (R2011b) 08-Jul-2011
 * TLC version                    : 8.1 (Jul  9 2011)
 * C/C++ source code generated on : Wed Jul 24 20:58:28 2013
 *
 * Target selection: idelink_ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_f28m35x_test_h_
#define RTW_HEADER_f28m35x_test_h_
#ifndef f28m35x_test_COMMON_INCLUDES_
# define f28m35x_test_COMMON_INCLUDES_
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#include "F28M35x_Device.h"
#include "F28M35x_Examples.h"
#include "IQmathLib.h"
#include "F28M35x_Gpio.h"
#endif                                 /* f28m35x_test_COMMON_INCLUDES_ */

#include "f28m35x_test_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

/* user code (top of header file) */
#include "MW_c28xx_pwm.h"
#include "MW_c28xx_adc.h"
#include "MW_c28xx_cap.h"

/*** PWM Parameter Structure ***/
typedef struct _EPWMPARAMS {
  /*-- Time-Base (TB) Submodule --*/
  Uint16 TBPRD;
  Uint16 TBCTL_CTRMODE;
  Uint16 TBCTL_SYNCOSEL;
  Uint16 TBCTL_PHSEN;
  Uint16 TBCTL_PHSDIR;
  Uint16 TBPHS;
  Uint16 TBCTL_HSPCLKDIV;
  Uint16 TBCTL_CLKDIV;
  Uint16 TBCTL_SWFSYNC;

  /*-- Counter_Compare (CC) Submodule --*/
  Uint16 CMPCTL_LOADAMODE;
  Uint16 CMPCTL_LOADBMODE;
  Uint16 CMPA;
  Uint16 CMPB;

  /*-- Action-Qualifier (AQ) Submodule --*/
  Uint16 AQCTLA;
  Uint16 AQCTLB;
  Uint16 AQCSFRC_CSFA;
  Uint16 AQCSFRC_CSFB;
  Uint16 AQCSFRC_RLDCSF;

  /*-- Dead-Band Generator (DB) Submodule --*/
  Uint16 DBCTL_OUT_MODE;
  Uint16 DBCTL_IN_MODE;
  Uint16 DBCTL_POLSEL;
  Uint16 DBRED;
  Uint16 DBFED;

  /*-- Event-Trigger (ET) Submodule --*/
  Uint16 ETSEL_SOCAEN;
  Uint16 ETSEL_SOCASEL;
  Uint16 ETPS_SOCAPRD;
  Uint16 ETSEL_SOCBEN;
  Uint16 ETSEL_SOCBSEL;
  Uint16 ETPS_SOCBPRD;
  Uint16 ETSEL_INTEN;
  Uint16 ETSEL_INTSEL;
  Uint16 ETPS_INTPRD;

  /*-- PWM-Chopper (PC) Submodule --*/
  Uint16 PCCTL_CHPEN;
  Uint16 PCCTL_CHPFREQ;
  Uint16 PCCTL_OSHTWTH;
  Uint16 PCCTL_CHPDUTY;

  /*-- Trip-Zone (TZ) Submodule --*/
  Uint16 TZSEL;
  Uint16 TZCTL_TZA;
  Uint16 TZCTL_TZB;
  Uint16 TZEINT_OST;
  Uint16 TZEINT_CBC;

  /*--new added ability for 2802x/2803x--*/
  Uint16 DCACTL_EVT1SOCE;
  Uint16 DCBCTL_EVT1SOCE;
  Uint16 DCACTL_EVT1SYNCE;
  Uint16 DCBCTL_EVT1SYNCE;
  Uint16 DBCTL_HALF;
  Uint16 TZCTL_DCAEVT1;
  Uint16 TZCTL_DCAEVT2;
  Uint16 TZCTL_DCBEVT1;
  Uint16 TZCTL_DCBEVT2;
  Uint16 TZEINT_DCAEVT1;
  Uint16 TZEINT_DCAEVT2;
  Uint16 TZEINT_DCBEVT1;
  Uint16 TZEINT_DCBEVT2;
  Uint16 DCACTL_EVT1FRCSYNCSEL;
  Uint16 DCACTL_EVT1SRCSEL;
  Uint16 DCACTL_EVT2FRCSYNCSEL;
  Uint16 DCACTL_EVT2SRCSEL;
  Uint16 DCBCTL_EVT1FRCSYNCSEL;
  Uint16 DCBCTL_EVT1SRCSEL;
  Uint16 DCBCTL_EVT2FRCSYNCSEL;
  Uint16 DCBCTL_EVT2SRCSEL;
  Uint16 DCTRIPSEL_DCAHCOMPSEL;
  Uint16 DCTRIPSEL_DCALCOMPSEL;
  Uint16 DCTRIPSEL_DCBHCOMPSEL;
  Uint16 DCTRIPSEL_DCBLCOMPSEL;
  Uint16 TZDCSEL_DCAEVT1;
  Uint16 TZDCSEL_DCAEVT2;
  Uint16 TZDCSEL_DCBEVT1;
  Uint16 TZDCSEL_DCBEVT2;
  Uint16 DCFCTL_BLANKE;
  Uint16 DCFCTL_PULSESEL;
  Uint16 DCFCTL_BLANKINV;
  Uint16 DCFCTL_DCFOFFSET;
  Uint16 DCFCTL_DCFWINDOW;
  Uint16 DCFCTL_SRCSEL;
  Uint16 DCFCTL_CAPE;
  Uint16 HRCNFG_SWAP;
  Uint16 HRCNFG_INVERT;
} EPWMPARAMS;

/* Block signals (auto storage) */
typedef struct {
  uint16_T ADC0;                       /* '<Root>/ADC0' */
  uint16_T GPIO20;                     /* '<Root>/GPIO 20' */
} BlockIO_f28m35x_test;

/* Real-time Model Data Structure */
struct RT_MODEL_f28m35x_test {
  const char_T *errorStatus;
};

/* Block signals (auto storage) */
extern BlockIO_f28m35x_test f28m35x_test_B;

/* Model entry point functions */
extern void f28m35x_test_initialize(void);
extern void f28m35x_test_step(void);
extern void f28m35x_test_terminate(void);

/* Real-time Model object */
extern struct RT_MODEL_f28m35x_test *const f28m35x_test_M;

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
 * '<Root>' : 'f28m35x_test'
 * '<S1>'   : 'f28m35x_test/Target Preferences'
 */
#endif                                 /* RTW_HEADER_f28m35x_test_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
