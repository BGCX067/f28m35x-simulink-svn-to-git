//###########################################################################
// FILE:   F28M35x_ECap.c
// TITLE:  F28M35x eCAP Initialization & Support Functions.
//###########################################################################
// $TI Release: F28M35x Support Library v200 $
// $Release Date: Wed Apr 17 14:44:24 CDT 2013 $
//###########################################################################

#include "F28M35x_Device.h"     // F28M35x Headerfile Include File
#include "F28M35x_Examples.h"   // F28M35x Examples Include File
#include "MW_c28xx_cap.h"
//---------------------------------------------------------------------------
// InitECap:
//---------------------------------------------------------------------------
// This function initializes the eCAP(s) to a known state.
void InitECap(void)
{
   InitECap1();
   InitECap2();
   InitECap3();
   InitECap4();
   InitECap5();
   InitECap6();
}

/*
 * *********************************
 * Configure eCAP1 register
 * *********************************
 */
void InitECap1(void)
{
	init_CAP1(); //function defined in MW_c28xx_cap.h
}

/*
 * *********************************
 * Configure eCAP2 register
 * *********************************
 */
void InitECap2(void)
{
	ECap2Regs.ECEINT.all = 0x0000;       // Disable all capture interrupts
	ECap2Regs.ECCLR.all = 0xFFFF;        // Clear all CAP interrupt flags
	ECap2Regs.ECCTL1.bit.CAPLDEN = 0;    // Disable CAP1-CAP4 register loads
	ECap2Regs.ECCTL2.bit.TSCTRSTOP = 0;  // Make sure the counter is stopped
	ECap2Regs.CTRPHS = 0U;               // Counter Phase Control
	ECap2Regs.ECCTL2.bit.SYNCO_SEL = 1;  // Select CTR=PRD event
	ECap2Regs.ECCTL2.bit.CAP_APWM = 0;   // Capture mode
	ECap2Regs.ECCTL2.bit.CONT_ONESHT = 0;// One-shot
	ECap2Regs.ECCTL1.bit.PRESCALE = 0U;  //Event prescaler
	ECap2Regs.ECCTL2.bit.STOP_WRAP = 1;  // Stop at 4 events
	ECap2Regs.ECCTL1.bit.CAP1POL = 0;    // Select rising or falling edge
	ECap2Regs.ECCTL1.bit.CTRRST1 = 0;    // Difference operation
	ECap2Regs.ECCTL1.bit.CAP2POL = 1;    // Select rising or falling edge
	ECap2Regs.ECCTL1.bit.CTRRST2 = 1;    // Difference operation
	ECap2Regs.ECEINT.bit.CEVT2 = 1;
	ECap2Regs.ECCLR.all = 0x0FF;         // Clear pending interrupts
	ECap2Regs.ECCTL2.bit.REARM = 1;      // arm one-shot
	ECap2Regs.ECCTL2.bit.TSCTRSTOP = 1;  // Start Counter
	ECap2Regs.ECCTL1.bit.CAPLDEN = 1;    // Enable CAP1-CAP4 register loads
}

/*
 * *********************************
 * Configure eCAP3 register
 * *********************************
 */
void InitECap3(void)
{
	ECap3Regs.ECEINT.all = 0x0000;       // Disable all capture interrupts
	ECap3Regs.ECCLR.all = 0xFFFF;        // Clear all CAP interrupt flags
	ECap3Regs.ECCTL1.bit.CAPLDEN = 0;    // Disable CAP1-CAP4 register loads
	ECap3Regs.ECCTL2.bit.TSCTRSTOP = 0;  // Make sure the counter is stopped
	ECap3Regs.CTRPHS = 0U;               // Counter Phase Control
	ECap3Regs.ECCTL2.bit.SYNCO_SEL = 1;  // Select CTR=PRD event
	ECap3Regs.ECCTL2.bit.CAP_APWM = 0;   // Capture mode
	ECap3Regs.ECCTL2.bit.CONT_ONESHT = 0;// One-shot
	ECap3Regs.ECCTL1.bit.PRESCALE = 0U;  //Event prescaler
	ECap3Regs.ECCTL2.bit.STOP_WRAP = 1;  // Stop at 4 events
	ECap3Regs.ECCTL1.bit.CAP1POL = 0;    // Select rising or falling edge
	ECap3Regs.ECCTL1.bit.CTRRST1 = 0;    // Difference operation
	ECap3Regs.ECCTL1.bit.CAP2POL = 1;    // Select rising or falling edge
	ECap3Regs.ECCTL1.bit.CTRRST2 = 1;    // Difference operation
	ECap3Regs.ECEINT.bit.CEVT2 = 1;
	ECap3Regs.ECCLR.all = 0x0FF;         // Clear pending interrupts
	ECap3Regs.ECCTL2.bit.REARM = 1;      // arm one-shot
	ECap3Regs.ECCTL2.bit.TSCTRSTOP = 1;  // Start Counter
	ECap3Regs.ECCTL1.bit.CAPLDEN = 1;    // Enable CAP1-CAP4 register loads

}

/*
 * *********************************
 * Configure eCAP4 register
 * *********************************
 */
void InitECap4(void)
{
	ECap4Regs.ECEINT.all = 0x0000;       // Disable all capture interrupts
	ECap4Regs.ECCLR.all = 0xFFFF;        // Clear all CAP interrupt flags
	ECap4Regs.ECCTL1.bit.CAPLDEN = 0;    // Disable CAP1-CAP4 register loads
	ECap4Regs.ECCTL2.bit.TSCTRSTOP = 0;  // Make sure the counter is stopped
	ECap4Regs.CTRPHS = 0U;               // Counter Phase Control
	ECap4Regs.ECCTL2.bit.SYNCO_SEL = 1;  // Select CTR=PRD event
	ECap4Regs.ECCTL2.bit.CAP_APWM = 0;   // Capture mode
	ECap4Regs.ECCTL2.bit.CONT_ONESHT = 0;// One-shot
	ECap4Regs.ECCTL1.bit.PRESCALE = 0U;  //Event prescaler
	ECap4Regs.ECCTL2.bit.STOP_WRAP = 1;  // Stop at 4 events
	ECap4Regs.ECCTL1.bit.CAP1POL = 0;    // Select rising or falling edge
	ECap4Regs.ECCTL1.bit.CTRRST1 = 0;    // Difference operation
	ECap4Regs.ECCTL1.bit.CAP2POL = 1;    // Select rising or falling edge
	ECap4Regs.ECCTL1.bit.CTRRST2 = 1;    // Difference operation
	ECap4Regs.ECEINT.bit.CEVT2 = 1;
	ECap4Regs.ECCLR.all = 0x0FF;         // Clear pending interrupts
	ECap4Regs.ECCTL2.bit.REARM = 1;      // arm one-shot
	ECap4Regs.ECCTL2.bit.TSCTRSTOP = 1;  // Start Counter
	ECap4Regs.ECCTL1.bit.CAPLDEN = 1;    // Enable CAP1-CAP4 register loads
}

/*
 * *********************************
 * Configure eCAP5 register
 * *********************************
 */
void InitECap5(void)
{
	ECap5Regs.ECEINT.all = 0x0000;       // Disable all capture interrupts
	ECap5Regs.ECCLR.all = 0xFFFF;        // Clear all CAP interrupt flags
	ECap5Regs.ECCTL1.bit.CAPLDEN = 0;    // Disable CAP1-CAP4 register loads
	ECap5Regs.ECCTL2.bit.TSCTRSTOP = 0;  // Make sure the counter is stopped
	ECap5Regs.CTRPHS = 0U;               // Counter Phase Control
	ECap5Regs.ECCTL2.bit.SYNCO_SEL = 1;  // Select CTR=PRD event
	ECap5Regs.ECCTL2.bit.CAP_APWM = 0;   // Capture mode
	ECap5Regs.ECCTL2.bit.CONT_ONESHT = 0;// One-shot
	ECap5Regs.ECCTL1.bit.PRESCALE = 0U;  //Event prescaler
	ECap5Regs.ECCTL2.bit.STOP_WRAP = 1;  // Stop at 4 events
	ECap5Regs.ECCTL1.bit.CAP1POL = 0;    // Select rising or falling edge
	ECap5Regs.ECCTL1.bit.CTRRST1 = 0;    // Difference operation
	ECap5Regs.ECCTL1.bit.CAP2POL = 1;    // Select rising or falling edge
	ECap5Regs.ECCTL1.bit.CTRRST2 = 1;    // Difference operation
	ECap5Regs.ECEINT.bit.CEVT2 = 1;
	ECap5Regs.ECCLR.all = 0x0FF;         // Clear pending interrupts
	ECap5Regs.ECCTL2.bit.REARM = 1;      // arm one-shot
	ECap5Regs.ECCTL2.bit.TSCTRSTOP = 1;  // Start Counter
	ECap5Regs.ECCTL1.bit.CAPLDEN = 1;    // Enable CAP1-CAP4 register loads
}

/*
 * *********************************
 * Configure eCAP6 register
 * *********************************
 */
void InitECap6(void)
{
	ECap6Regs.ECEINT.all = 0x0000;       // Disable all capture interrupts
	ECap6Regs.ECCLR.all = 0xFFFF;        // Clear all CAP interrupt flags
	ECap6Regs.ECCTL1.bit.CAPLDEN = 0;    // Disable CAP1-CAP4 register loads
	ECap6Regs.ECCTL2.bit.TSCTRSTOP = 0;  // Make sure the counter is stopped
	ECap6Regs.CTRPHS = 0U;               // Counter Phase Control
	ECap6Regs.ECCTL2.bit.SYNCO_SEL = 1;  // Select CTR=PRD event
	ECap6Regs.ECCTL2.bit.CAP_APWM = 0;   // Capture mode
	ECap6Regs.ECCTL2.bit.CONT_ONESHT = 0;// One-shot
	ECap6Regs.ECCTL1.bit.PRESCALE = 0U;  //Event prescaler
	ECap6Regs.ECCTL2.bit.STOP_WRAP = 1;  // Stop at 4 events
	ECap6Regs.ECCTL1.bit.CAP1POL = 0;    // Select rising or falling edge
	ECap6Regs.ECCTL1.bit.CTRRST1 = 0;    // Difference operation
	ECap6Regs.ECCTL1.bit.CAP2POL = 1;    // Select rising or falling edge
	ECap6Regs.ECCTL1.bit.CTRRST2 = 1;    // Difference operation
	ECap6Regs.ECEINT.bit.CEVT2 = 1;
	ECap6Regs.ECCLR.all = 0x0FF;         // Clear pending interrupts
	ECap6Regs.ECCTL2.bit.REARM = 1;      // arm one-shot
	ECap6Regs.ECCTL2.bit.TSCTRSTOP = 1;  // Start Counter
	ECap6Regs.ECCTL1.bit.CAPLDEN = 1;    // Enable CAP1-CAP4 register loads

}


//---------------------------------------------------------------------------
// Example: InitECapGpio:
//---------------------------------------------------------------------------
// This function initializes GPIO pins to function as ECAP pins
// Each GPIO pin can be configured as a GPIO pin or up to 3 different
// peripheral functional pins. By default all pins come up as GPIO
// inputs after reset.
// Caution:
// For each eCAP peripheral
// Only one GPIO pin should be enabled for ECAP operation.
// Comment out other unwanted lines.

void InitECapGpio()
{

    InitECap1Gpio();
    InitECap2Gpio();
    InitECap3Gpio();
    InitECap4Gpio();
    InitECap5Gpio();
    InitECap6Gpio();
}

void InitECap1Gpio(void)
{
    EALLOW;

/* Enable internal pull-up for the selected pins */

// Pull-up enable should be set in the
// GPIO_O_PUR register in the M3 code.

// Inputs are synchronized to SYSCLKOUT by default.
// Comment out other unwanted lines.

//    GpioCtrlRegs.GPAQSEL1.bit.GPIO5 = 0;    // Synch to SYSCLKOUT GPIO5 (CAP1)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO24 = 0;   // Synch to SYSCLKOUT GPIO24 (CAP1)
//  GpioCtrlRegs.GPBQSEL1.bit.GPIO34 = 0;   // Synch to SYSCLKOUT GPIO34 (CAP1)

/* Configure eCAP-1 pins using GPIO regs*/

// This specifies which of the possible GPIO pins will be eCAP1 functional pins.
// Comment out other unwanted lines.

//    GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 3;     // Configure GPIO5 as CAP1
    GpioCtrlRegs.GPAMUX2.bit.GPIO24 = 1;    // Configure GPIO24 as CAP1
//  GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 1;    // Configure GPIO34 as CAP1

// Configure GPIO MUX TRIP Inputs
//    GpioTripRegs.GPTRIP7SEL.bit.GPTRIP7SEL = 5;     // Configure GPIO5 as CAP1
    GpioTripRegs.GPTRIP7SEL.bit.GPTRIP7SEL = 24;    // Configure GPIO24 as CAP1
//  GpioTripRegs.GPTRIP7SEL.bit.GPTRIP7SEL = 34;    // Configure GPIO34 as CAP1

    EDIS;
}

void InitECap2Gpio(void)
{
    EALLOW;

/* Enable internal pull-up for the selected pins */

// Pull-up enable should be set in the
// GPIO_O_PUR register in the M3 code.

// Inputs are synchronized to SYSCLKOUT by default.
// Comment out other unwanted lines.

//    GpioCtrlRegs.GPAQSEL1.bit.GPIO7 = 0;        // Synch to SYSCLKOUT GPIO7
// (CAP2)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO25 = 0;       // Synch to SYSCLKOUT GPIO25
// (CAP2)
//    GpioCtrlRegs.GPBQSEL1.bit.GPIO37 = 0;       // Synch to SYSCLKOUT GPIO37
                                                // (CAP2)

/* Configure eCAP-2 pins using GPIO regs*/

// This specifies which of the possible GPIO pins will be eCAP2 functional pins.
// Comment out other unwanted lines.

//  GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 3;     // Configure GPIO7 as CAP2
    GpioCtrlRegs.GPAMUX2.bit.GPIO25 = 1;    // Configure GPIO25 as CAP2
//    GpioCtrlRegs.GPBMUX1.bit.GPIO37 = 1;    // Configure GPIO37 as CAP2

// Configure GPIO MUX TRIP Inputs
//    GpioTripRegs.GPTRIP8SEL.bit.GPTRIP8SEL = 7;    // Configure GPIO7 as CAP1
    GpioTripRegs.GPTRIP8SEL.bit.GPTRIP8SEL = 25; // Configure GPIO25 as CAP1
//    GpioTripRegs.GPTRIP8SEL.bit.GPTRIP8SEL = 37; // Configure GPIO37 as CAP1

    EDIS;
}

void InitECap3Gpio(void)
{
    EALLOW;

/* Enable internal pull-up for the selected pins */

// Pull-up enable should be set in the
// GPIO_O_PUR register in the M3 code.

// Inputs are synchronized to SYSCLKOUT by default.
// Comment out other unwanted lines.

//    GpioCtrlRegs.GPAQSEL1.bit.GPIO9 = 0;    // Synch to SYSCLKOUT GPIO9 (CAP3)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO26 = 0;   // Synch to SYSCLKOUT GPIO26 (CAP3)

/* Configure eCAP-3 pins using GPIO regs*/

// This specifies which of the possible GPIO pins will be eCAP3 functional pins.
// Comment out other unwanted lines.

//    GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 3;     // Configure GPIO9 as CAP3
    GpioCtrlRegs.GPAMUX2.bit.GPIO26 = 1;    // Configure GPIO26 as CAP3

// Configure GPIO MUX TRIP Inputs
//    GpioTripRegs.GPTRIP9SEL.bit.GPTRIP9SEL = 9;    // Configure GPIO9 as CAP1
    GpioTripRegs.GPTRIP9SEL.bit.GPTRIP9SEL = 26; // Configure GPIO26 as CAP1

    EDIS;
}

void InitECap4Gpio(void)
{
    EALLOW;

/* Enable internal pull-up for the selected pins */

// Pull-up enable should be set in the
// GPIO_O_PUR register in the M3 code.

// Inputs are synchronized to SYSCLKOUT by default.
// Comment out other unwanted lines.

//    GpioCtrlRegs.GPAQSEL1.bit.GPIO11 = 0;    // Synch to SYSCLKOUT GPIO11
// (CAP4)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO27 = 0;    // Synch to SYSCLKOUT GPIO27 (CAP4)

/* Configure eCAP-4 pins using GPIO regs*/

// This specifies which of the possible GPIO pins will be eCAP4 functional pins.
// Comment out other unwanted lines.

//    GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 3;     // Configure GPIO11 as CAP4
    GpioCtrlRegs.GPAMUX2.bit.GPIO27 = 1;     // Configure GPIO27 as CAP4

// Configure GPIO MUX TRIP Inputs
//  GpioTripRegs.GPTRIP10SEL.bit.GPTRIP10SEL = 11;    // Configure GPIO11 as
// CAP1
    GpioTripRegs.GPTRIP10SEL.bit.GPTRIP10SEL = 27;   // Configure GPIO27 as CAP1

    EDIS;
}

void InitECap5Gpio(void)
{
    EALLOW;

/* Enable internal pull-up for the selected pins */

// Pull-up enable should be set in the
// GPIO_O_PUR register in the M3 code.

// Inputs are synchronized to SYSCLKOUT by default.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAQSEL1.bit.GPIO3 = 0;    // Synch to SYSCLKOUT GPIO3 (CAP5)
//    GpioCtrlRegs.GPBQSEL2.bit.GPIO48 = 0;   // Synch to SYSCLKOUT GPIO48 (CAP5)

/* Configure eCAP-5 pins using GPIO regs*/

// This specifies which of the possible GPIO pins will be eCAP5 functional pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 2;     // Configure GPIO3 as CAP5
//    GpioCtrlRegs.GPBMUX2.bit.GPIO48 = 1;    // Configure GPIO48 as CAP5

// Configure GPIO MUX TRIP Inputs
    GpioTripRegs.GPTRIP11SEL.bit.GPTRIP11SEL = 3;    // Configure GPIO3 as
// CAP1
//    GpioTripRegs.GPTRIP11SEL.bit.GPTRIP11SEL = 48;   // Configure GPIO48 as CAP1

    EDIS;
}

void InitECap6Gpio(void)
{
    EALLOW;

/* Enable internal pull-up for the selected pins */

// Pull-up enable should be set in the
// GPIO_O_PUR register in the M3 code.

// Inputs are synchronized to SYSCLKOUT by default.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAQSEL1.bit.GPIO1 = 0;    // Synch to SYSCLKOUT GPIO1 (CAP6)
//    GpioCtrlRegs.GPBQSEL2.bit.GPIO49 = 0;   // Synch to SYSCLKOUT GPIO49 (CAP6)

/* Configure eCAP-6 pins using GPIO regs*/

// This specifies which of the possible GPIO pins will be eCAP6 functional pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 2;     // Configure GPIO1 as CAP6
//    GpioCtrlRegs.GPBMUX2.bit.GPIO49 = 1;    // Configure GPIO49 as CAP6

// Configure GPIO MUX TRIP Inputs
    GpioTripRegs.GPTRIP12SEL.bit.GPTRIP12SEL = 1;    // Configure GPIO1 as
// CAP1
//    GpioTripRegs.GPTRIP12SEL.bit.GPTRIP12SEL = 49;   // Configure GPIO49 as CAP1

    EDIS;
}



