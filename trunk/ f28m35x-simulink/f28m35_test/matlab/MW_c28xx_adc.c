#include "F28M35x_Device.h"
#include "F28M35x_Examples.h"
#include "F28M35x_GlobalPrototypes.h"
#include "rtwtypes.h"
#include "f28m35x_test.h"
#include "f28m35x_test_private.h"

void config_ADC_SOC0()
{
  EALLOW;
  AdcRegs.ADCSOC0CTL.bit.CHSEL = 0;    //set SOC0 channel select to ADCINA0
  AdcRegs.ADCSOC0CTL.bit.TRIGSEL = 0;  //set SOC0 start trigger on Software
  AdcRegs.ADCSOC0CTL.bit.ACQPS = 6;    //set SOC0 S/H Window to 7 ADC Clock Cycles
  AdcRegs.ADCINTSOCSEL1.bit.SOC0 = 0;  //SOCx No ADCINT Interrupt Trigger Select.
  AdcRegs.ADCSAMPLEMODE.bit.SIMULEN0 = 0;//Single sample mode set for SOC0.
  AdcRegs.ADCOFFTRIM.bit.OFFTRIM = 0;  // Set Offset Error Correctino Value
  AdcRegs.ADCCTL1.bit.ADCREFSEL = 0 ;  // Set Reference Voltage
  AdcRegs.ADCCTL1.bit.INTPULSEPOS = 0; //Late interrupt pulse trips AdcResults latch
  AdcRegs.SOCPRICTL.bit.SOCPRIORITY = 0;//All in round robin mode.
  EDIS;
}
