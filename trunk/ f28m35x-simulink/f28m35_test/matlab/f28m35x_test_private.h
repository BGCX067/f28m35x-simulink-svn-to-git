/*
 * File: f28m35x_test_private.h
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

#ifndef RTW_HEADER_f28m35x_test_private_h_
#define RTW_HEADER_f28m35x_test_private_h_
#include "rtwtypes.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C16S16I16L32N16F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C16S16I16L32N16F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

extern void config_ePWMRegs (volatile struct EPWM_REGS * EPwmRegs, EPWMPARAMS
  *EPwmParams);

#endif                                 /* RTW_HEADER_f28m35x_test_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
