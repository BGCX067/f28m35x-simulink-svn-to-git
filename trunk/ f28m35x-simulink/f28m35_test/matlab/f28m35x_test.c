/*
 * File: f28m35x_test.c
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

#include "f28m35x_test.h"
#include "f28m35x_test_private.h"

/* Block signals (auto storage) */
BlockIO_f28m35x_test f28m35x_test_B;

/* Real-time model */
RT_MODEL_f28m35x_test f28m35x_test_M_;
RT_MODEL_f28m35x_test *const f28m35x_test_M = &f28m35x_test_M_;

/* Model step function */
void f28m35x_test_step(void)
{
  /* S-Function Block: <Root>/ADC0 (c2802xadc) */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    AdcRegs.ADCSOCFRC1.bit.SOC0 = 1;
    asm(" RPT #22 || NOP");
    f28m35x_test_B.ADC0 = (AdcResult.ADCRESULT0);
  }

  /* S-Function (c2802xpwm): '<Root>/ePWM1 ' */

  /*-- Update CMPA value for ePWM1 --*/
  {
    EPwm1Regs.CMPA.half.CMPA = (uint16_T)(f28m35x_test_B.ADC0);
  }

  /* S-Function Block: <Root>/GPIO 20 (c280xgpio_di) */
  {
    f28m35x_test_B.GPIO20 = GpioDataRegs.GPADAT.bit.GPIO20;
  }

  /* S-Function Block: <Root>/GPIO 23 (c280xgpio_do) */
  {
    GpioDataRegs.GPASET.bit.GPIO23 = (f28m35x_test_B.GPIO20 != 0);
    GpioDataRegs.GPACLEAR.bit.GPIO23 = !(f28m35x_test_B.GPIO20 != 0);
  }
}

/* Model initialize function */
void f28m35x_test_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(f28m35x_test_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &f28m35x_test_B), 0,
                sizeof(BlockIO_f28m35x_test));

  /* Start for S-Function (c2802xadc): '<Root>/ADC0' */
  InitAdc();
  config_ADC_SOC0 ();

  /* Start for S-Function (c2802xpwm): '<Root>/ePWM1 ' */

  /*** Initialize ePWM1 modules ***/
  {
    EPWMPARAMS EPwm1Params;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm1Params.TBCTL_SWFSYNC = 0;
    EPwm1Params.TBPRD = 4096;
    EPwm1Params.TBCTL_CTRMODE = 0;
    EPwm1Params.TBCTL_SYNCOSEL = 1;
    EPwm1Params.TBCTL_PHSEN = 1;
    EPwm1Params.TBCTL_PHSDIR = 1;
    EPwm1Params.TBPHS = 0;
    EPwm1Params.TBCTL_HSPCLKDIV = 0;
    EPwm1Params.TBCTL_CLKDIV = 0;

    /*-- Setup Counter_Compare (CC) Submodule --*/
    EPwm1Params.CMPCTL_LOADAMODE = 0;
    EPwm1Params.CMPCTL_LOADBMODE = 0;
    EPwm1Params.CMPA = 1875;
    EPwm1Params.CMPB = 1000;

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm1Params.AQCTLA = 18;
    EPwm1Params.AQCTLB = 32;
    EPwm1Params.AQCSFRC_CSFA = 0;
    EPwm1Params.AQCSFRC_CSFB = 0;
    EPwm1Params.AQCSFRC_RLDCSF = 0;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    EPwm1Params.DBCTL_OUT_MODE = 0;
    EPwm1Params.DBCTL_IN_MODE = 0;
    EPwm1Params.DBCTL_POLSEL = 0;
    EPwm1Params.DBRED = 0.0;
    EPwm1Params.DBFED = 0.0;

    /*-- Setup Event-Trigger (ET) Submodule --*/
    EPwm1Params.ETSEL_SOCAEN = 0;
    EPwm1Params.ETSEL_SOCASEL = 1;
    EPwm1Params.ETPS_SOCAPRD = 1;
    EPwm1Params.ETSEL_SOCBEN = 0;
    EPwm1Params.ETSEL_SOCBSEL = 1;
    EPwm1Params.ETPS_SOCBPRD = 1;
    EPwm1Params.ETSEL_INTEN = 0;
    EPwm1Params.ETSEL_INTSEL = 1;
    EPwm1Params.ETPS_INTPRD = 1;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    EPwm1Params.PCCTL_CHPEN = 0;
    EPwm1Params.PCCTL_CHPFREQ = 0;
    EPwm1Params.PCCTL_OSHTWTH = 0;
    EPwm1Params.PCCTL_CHPDUTY = 0;

    /*-- Setup Trip-Zone (TZ) Submodule --*/
    EPwm1Params.TZSEL = 0;
    EPwm1Params.TZCTL_TZA = 3;
    EPwm1Params.TZCTL_TZB = 3;
    EPwm1Params.TZEINT_OST = 0;
    EPwm1Params.TZEINT_CBC = 0;
    EPwm1Params.DBCTL_HALF = 0;
    EPwm1Params.DCACTL_EVT1SOCE = 0;
    EPwm1Params.DCBCTL_EVT1SOCE = 0;
    EPwm1Params.DCACTL_EVT1SYNCE = 0;
    EPwm1Params.DCBCTL_EVT1SYNCE = 0;
    EPwm1Params.DCACTL_EVT1SRCSEL = 0;
    EPwm1Params.DCACTL_EVT1FRCSYNCSEL = 0;
    EPwm1Params.DCACTL_EVT2SRCSEL = 0;
    EPwm1Params.DCACTL_EVT2FRCSYNCSEL = 0;
    EPwm1Params.DCBCTL_EVT1SRCSEL = 0;
    EPwm1Params.DCBCTL_EVT1FRCSYNCSEL = 0;
    EPwm1Params.DCBCTL_EVT2SRCSEL = 0;
    EPwm1Params.DCBCTL_EVT2FRCSYNCSEL = 0;
    EPwm1Params.TZEINT_DCAEVT1 = 0;
    EPwm1Params.TZEINT_DCAEVT2 = 0;
    EPwm1Params.TZEINT_DCBEVT1 = 0;
    EPwm1Params.TZEINT_DCBEVT2 = 0;
    EPwm1Params.TZCTL_DCAEVT1 = 3;
    EPwm1Params.TZCTL_DCAEVT2 = 3;
    EPwm1Params.TZCTL_DCBEVT1 = 3;
    EPwm1Params.TZCTL_DCBEVT2 = 3;
    EPwm1Params.DCTRIPSEL_DCAHCOMPSEL = 0;
    EPwm1Params.DCTRIPSEL_DCALCOMPSEL = 1;
    EPwm1Params.DCTRIPSEL_DCBHCOMPSEL = 0;
    EPwm1Params.DCTRIPSEL_DCBLCOMPSEL = 1;
    EPwm1Params.TZDCSEL_DCAEVT1 = 0;
    EPwm1Params.TZDCSEL_DCAEVT2 = 0;
    EPwm1Params.TZDCSEL_DCBEVT1 = 0;
    EPwm1Params.TZDCSEL_DCBEVT2 = 0;
    EPwm1Params.DCFCTL_BLANKE = 0;
    EPwm1Params.DCFCTL_PULSESEL = 1;
    EPwm1Params.DCFCTL_BLANKINV = 0;
    EPwm1Params.DCFCTL_DCFOFFSET = 0.0;
    EPwm1Params.DCFCTL_DCFWINDOW = 0.0;
    EPwm1Params.DCFCTL_SRCSEL = 0;
    EPwm1Params.DCFCTL_CAPE = 0;
    EPwm1Params.HRCNFG_SWAP = 0;
    EPwm1Params.HRCNFG_INVERT = 1;

    /*-- Initial ePWM1 --*/
    config_ePWMRegs(&EPwm1Regs, &EPwm1Params);
  }

  /* Start for S-Function (c280xgpio_di): '<Root>/GPIO 20' */
  EALLOW;
  GpioCtrlRegs.GPAMUX2.all &= 4294966527U;
  GpioCtrlRegs.GPADIR.all &= 4293918719U;
  EDIS;

  /* Start for S-Function (c280xgpio_do): '<Root>/GPIO 23' */
  EALLOW;
  GpioCtrlRegs.GPAMUX2.all &= 4294918143U;
  GpioCtrlRegs.GPADIR.all |= 8388608U;
  EDIS;

  /* user code (Initialize function Body) */
  config_ADC_SOC_TRIG1();
}

/* Model terminate function */
void f28m35x_test_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
