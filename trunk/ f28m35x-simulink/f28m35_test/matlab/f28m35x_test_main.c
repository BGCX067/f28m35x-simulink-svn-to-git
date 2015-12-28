/*
 * File: f28m35x_test_main.c
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
#include "rtwtypes.h"
#include "f28m35x_test_private.h"
#include "c2000_main.h"
#include "F28M35x_Device.h"
#include "F28M35x_Examples.h"
#include <stdlib.h>
#include <stdio.h>

void init_board(void);
void enable_interrupts(void);
void config_schedulerTimer(void);
void disable_interrupts(void);
volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;

/* Function: rt_OneStep -------------------------------------------
 *
 * Abstract:
 *      Perform one step of the model.  Single-tasking implementation.
 */
void rt_OneStep(void)
{
  // Check for overrun. Protect OverrunFlag against
  // preemption.
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

  asm(" SETC INTM");
  PieCtrlRegs.PIEIER1.all |= (1 << 6);
  asm(" CLRC INTM");
  f28m35x_test_step();

  /* Get model outputs here */
  asm(" SETC INTM");
  PieCtrlRegs.PIEIER1.all &= ~(1 << 6);
  asm(" RPT #5 || NOP");
  IFR &= 0xFFFE;
  PieCtrlRegs.PIEACK.all = 0x1;
  asm(" CLRC INTM");
  OverrunFlag--;
}

/* Function: main -------------------------------------------
 *
 * Abstract:
 *      Entry point into the code.
 */
void main(void)
{
  volatile boolean_T noErr;
  init_board();
  rtmSetErrorStatus(f28m35x_test_M, 0);
  f28m35x_test_initialize();
  config_schedulerTimer();
  noErr =
    rtmGetErrorStatus(f28m35x_test_M) == (NULL);
  enable_interrupts();
  while (noErr ) {
    if (IsrOverrun) {
      /* ISR overrun - base sample time is too fast */
    }

    noErr =
      rtmGetErrorStatus(f28m35x_test_M) == (NULL);
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  f28m35x_test_terminate();
  disable_interrupts();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
