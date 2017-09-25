//***************************************************************************************
//  MSP430 Blink the LED Demo - Software Toggle P1.0
//
//  Description; Toggle P1.0 by xor'ing P1.0 inside of a software loop.
//  ACLK = n/a, MCLK = SMCLK = default DCO
//
//                MSP430x5xx
//             -----------------
//         /|\|              XIN|-
//          | |                 |
//          --|RST          XOUT|-
//            |                 |
//            |             P1.0|-->LED
//
//  Texas Instruments, Inc
//  July 2013
//***************************************************************************************

#include <msp430.h>

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings
    P1DIR |= (0x01);                          // Set P1.0 to output direction
    P2DIR |= (0x01);
    P1OUT = (0x0);
    P2OUT = (0x01);
    int toggleLed2 = 0;
    while(1) {
        volatile unsigned int i;
        P1OUT ^= (0x01);// Toggle P1.0 using exclusive-OR

        if(toggleLed2 == 3){
            P2OUT ^= (0x01);
            toggleLed2 = 0;
        }
        toggleLed2 = toggleLed2 + 1;
        __delay_cycles(100000);
    }


}