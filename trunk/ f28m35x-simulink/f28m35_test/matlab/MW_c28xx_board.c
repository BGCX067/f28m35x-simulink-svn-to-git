#include "F28M35x_Device.h"
#include "F28M35x_Examples.h"
#include "F28M35x_GlobalPrototypes.h"
#include "rtwtypes.h"
#include "f28m35x_test.h"
#include "f28m35x_test_private.h"

void init_board ()
{
  InitSysCtrl();

  /* Disable and clear all CPU interrupts */
  DINT;
  IER = 0x0000;
  IFR = 0x0000;
  InitPieCtrl();
  InitPieVectTable();

  /* initial SPI function.... */
  InitCpuTimers();

  /* initial ePWM GPIO assignment... */
  config_ePWM_GPIO();

  /* initial GPIO qualification settings.... */
  EALLOW;
  GpioCtrlRegs.GPAQSEL1.all = 0U;
  GpioCtrlRegs.GPAQSEL2.all = 0U;
  GpioCtrlRegs.GPBQSEL1.all = 0U;
  EDIS;
}
