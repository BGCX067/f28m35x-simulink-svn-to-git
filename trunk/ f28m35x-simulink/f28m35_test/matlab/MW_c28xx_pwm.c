#include "F28M35x_Device.h"
#include "F28M35x_Examples.h"
#include "F28M35x_GlobalPrototypes.h"
#include "rtwtypes.h"
#include "f28m35x_test.h"
#include "f28m35x_test_private.h"

void config_ePWMRegs (volatile struct EPWM_REGS * EPwmRegs, EPWMPARAMS *
                      EPwmParams)
{
  /*-- Setup Time-Base (TB) Submodule --*/
  EPwmRegs->TBPRD = EPwmParams->TBPRD;
  EPwmRegs->TBCTL.bit.CTRMODE = EPwmParams->TBCTL_CTRMODE;
  EPwmRegs->TBCTL.bit.SYNCOSEL = EPwmParams->TBCTL_SYNCOSEL;
  EPwmRegs->TBCTL.bit.PHSEN = EPwmParams->TBCTL_PHSEN;
  EPwmRegs->TBCTL.bit.PHSDIR = EPwmParams->TBCTL_PHSDIR;
  EPwmRegs->TBPHS.half.TBPHS = EPwmParams->TBPHS;
  EPwmRegs->TBCTL.bit.HSPCLKDIV = EPwmParams->TBCTL_HSPCLKDIV;
  EPwmRegs->TBCTL.bit.CLKDIV = EPwmParams->TBCTL_CLKDIV;
  EPwmRegs->TBCTR = 0x0000;            // Clear counter

  /*-- Setup Counter_Compare (CC) Submodule --*/
  EPwmRegs->CMPCTL.bit.SHDWAMODE = CC_SHADOW;// Always enable shadow mode, no immediate mode
  EPwmRegs->CMPCTL.bit.SHDWBMODE = CC_SHADOW;// Always enable shadow mode, no immediate mode
  EPwmRegs->CMPCTL.bit.LOADAMODE = EPwmParams->CMPCTL_LOADAMODE;
  EPwmRegs->CMPCTL.bit.LOADBMODE = EPwmParams->CMPCTL_LOADBMODE;
  EPwmRegs->CMPA.half.CMPA = EPwmParams->CMPA;
  EPwmRegs->CMPB = EPwmParams->CMPB;

  /*-- Setup Action-Qualifier (AQ) Submodule --*/
  EPwmRegs->AQCTLA.all = EPwmParams->AQCTLA;
  EPwmRegs->AQCTLB.all = EPwmParams->AQCTLB;
  EPwmRegs->AQSFRC.bit.RLDCSF = EPwmParams->AQCSFRC_RLDCSF;
  EPwmRegs->AQCSFRC.bit.CSFA = EPwmParams->AQCSFRC_CSFA;
  EPwmRegs->AQCSFRC.bit.CSFB = EPwmParams->AQCSFRC_CSFB;

  /*-- Setup Dead-Band Generator (DB) Submodule --*/
  EPwmRegs->DBCTL.bit.OUT_MODE = EPwmParams->DBCTL_OUT_MODE;
  EPwmRegs->DBCTL.bit.IN_MODE = EPwmParams->DBCTL_IN_MODE;
  EPwmRegs->DBCTL.bit.POLSEL = EPwmParams->DBCTL_POLSEL;
  EPwmRegs->DBRED = EPwmParams->DBRED;
  EPwmRegs->DBFED = EPwmParams->DBFED;

  /*-- Setup Event-Trigger (ET) Submodule --*/
  EPwmRegs->ETSEL.bit.SOCAEN = EPwmParams->ETSEL_SOCAEN;
  EPwmRegs->ETSEL.bit.SOCASEL = EPwmParams->ETSEL_SOCASEL;
  EPwmRegs->ETPS.bit.SOCAPRD = EPwmParams->ETPS_SOCAPRD;
  EPwmRegs->ETSEL.bit.SOCBEN = EPwmParams->ETSEL_SOCBEN;
  EPwmRegs->ETSEL.bit.SOCBSEL = EPwmParams->ETSEL_SOCBSEL;
  EPwmRegs->ETPS.bit.SOCBPRD = EPwmParams->ETPS_SOCBPRD;
  EPwmRegs->ETSEL.bit.INTEN = EPwmParams->ETSEL_INTEN;
  EPwmRegs->ETSEL.bit.INTSEL = EPwmParams->ETSEL_INTSEL;
  EPwmRegs->ETPS.bit.INTPRD = EPwmParams->ETPS_INTPRD;

  /*-- Setup PWM-Chopper (PC) Submodule --*/
  EPwmRegs->PCCTL.bit.CHPEN = EPwmParams->PCCTL_CHPEN;
  EPwmRegs->PCCTL.bit.CHPFREQ = EPwmParams->PCCTL_CHPFREQ;
  EPwmRegs->PCCTL.bit.OSHTWTH = EPwmParams->PCCTL_OSHTWTH;
  EPwmRegs->PCCTL.bit.CHPDUTY = EPwmParams->PCCTL_CHPDUTY;

  /*-- Set up Trip-Zone (TZ) Submodule --*/
  EALLOW;
  EPwmRegs->TZSEL.all = EPwmParams->TZSEL;
  EPwmRegs->TZCTL.bit.TZA = EPwmParams->TZCTL_TZA;
  EPwmRegs->TZCTL.bit.TZB = EPwmParams->TZCTL_TZB;
  EPwmRegs->TZEINT.bit.OST = EPwmParams->TZEINT_OST;
  EPwmRegs->TZEINT.bit.CBC = EPwmParams->TZEINT_CBC;
  EPwmRegs->TBCTL.bit.SWFSYNC = EPwmParams->TBCTL_SWFSYNC;
  EPwmRegs->DCACTL.bit.EVT1SYNCE = EPwmParams->DCACTL_EVT1SYNCE;
  EPwmRegs->DCBCTL.bit.EVT1SYNCE = EPwmParams->DCBCTL_EVT1SYNCE;
  EPwmRegs->DCACTL.bit.EVT1SOCE = EPwmParams->DCACTL_EVT1SOCE;
  EPwmRegs->DCBCTL.bit.EVT1SOCE = EPwmParams->DCBCTL_EVT1SOCE;
  EPwmRegs->DBCTL.bit.HALFCYCLE = EPwmParams->DBCTL_HALF;
  EPwmRegs->TZCTL.bit.DCAEVT1 = EPwmParams->TZCTL_DCAEVT1;
  EPwmRegs->TZCTL.bit.DCAEVT2 = EPwmParams->TZCTL_DCAEVT2;
  EPwmRegs->TZCTL.bit.DCBEVT1 = EPwmParams->TZCTL_DCBEVT1;
  EPwmRegs->TZCTL.bit.DCBEVT2 = EPwmParams->TZCTL_DCBEVT2;
  EPwmRegs->TZEINT.bit.DCAEVT1 = EPwmParams->TZEINT_DCAEVT1;
  EPwmRegs->TZEINT.bit.DCAEVT2 = EPwmParams->TZEINT_DCAEVT2;
  EPwmRegs->TZEINT.bit.DCBEVT1 = EPwmParams->TZEINT_DCBEVT1;
  EPwmRegs->TZEINT.bit.DCBEVT2 = EPwmParams->TZEINT_DCBEVT2;
  EPwmRegs->DCACTL.bit.EVT1FRCSYNCSEL = EPwmParams->DCACTL_EVT1FRCSYNCSEL;
  EPwmRegs->DCACTL.bit.EVT1SRCSEL = EPwmParams->DCACTL_EVT1SRCSEL;
  EPwmRegs->DCACTL.bit.EVT2FRCSYNCSEL = EPwmParams->DCACTL_EVT2FRCSYNCSEL;
  EPwmRegs->DCACTL.bit.EVT2SRCSEL = EPwmParams->DCACTL_EVT2SRCSEL;
  EPwmRegs->DCBCTL.bit.EVT1FRCSYNCSEL = EPwmParams->DCBCTL_EVT1FRCSYNCSEL;
  EPwmRegs->DCBCTL.bit.EVT1SRCSEL = EPwmParams->DCBCTL_EVT1SRCSEL;
  EPwmRegs->DCBCTL.bit.EVT2FRCSYNCSEL = EPwmParams->DCBCTL_EVT2FRCSYNCSEL;
  EPwmRegs->DCBCTL.bit.EVT2SRCSEL = EPwmParams->DCBCTL_EVT2SRCSEL;
  EPwmRegs->DCTRIPSEL.bit.DCAHCOMPSEL = EPwmParams->DCTRIPSEL_DCAHCOMPSEL;
  EPwmRegs->DCTRIPSEL.bit.DCALCOMPSEL = EPwmParams->DCTRIPSEL_DCALCOMPSEL;
  EPwmRegs->DCTRIPSEL.bit.DCBHCOMPSEL = EPwmParams->DCTRIPSEL_DCBHCOMPSEL;
  EPwmRegs->DCTRIPSEL.bit.DCBLCOMPSEL = EPwmParams->DCTRIPSEL_DCBLCOMPSEL;
  EPwmRegs->TZDCSEL.bit.DCAEVT1 = EPwmParams->TZDCSEL_DCAEVT1;
  EPwmRegs->TZDCSEL.bit.DCAEVT2 = EPwmParams->TZDCSEL_DCAEVT2;
  EPwmRegs->TZDCSEL.bit.DCBEVT1 = EPwmParams->TZDCSEL_DCBEVT1;
  EPwmRegs->TZDCSEL.bit.DCBEVT2 = EPwmParams->TZDCSEL_DCBEVT2;
  EPwmRegs->DCFCTL.bit.BLANKE = EPwmParams->DCFCTL_BLANKE;
  EPwmRegs->DCFCTL.bit.PULSESEL = EPwmParams->DCFCTL_PULSESEL;
  EPwmRegs->DCFCTL.bit.BLANKINV = EPwmParams->DCFCTL_BLANKINV;
  EPwmRegs->DCFOFFSET = EPwmParams->DCFCTL_DCFOFFSET;
  EPwmRegs->DCFWINDOW = EPwmParams->DCFCTL_DCFWINDOW;
  EPwmRegs->DCFCTL.bit.SRCSEL = EPwmParams->DCFCTL_SRCSEL;
  EPwmRegs->DCCAPCTL.bit.CAPE = EPwmParams->DCFCTL_CAPE;
  EPwmRegs->HRCNFG.bit.SWAPAB = EPwmParams->HRCNFG_SWAP;
  EPwmRegs->HRCNFG.bit.SELOUTB= EPwmParams->HRCNFG_INVERT;
  EDIS;
}

void config_ePWM_GPIO (void)
{
  EALLOW;

  /*-- Configure pin assignments for ePWM1 --*/
  GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1;  // Configure GPIO0 as EPWM1A
  GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1;  // Configure GPIO1 as EPWM1B
  GpioCtrlRegs.GPBMUX1.bit.GPIO33 = 2; // Configure GPIO33 as xSYNCO.

  /*--- Configure pin assignments for TZn ---*/
  EDIS;
}
