#include <msp430.h> 


/**
 * main.c
 */
void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;
    P1DIR |= (BIT0);
    P9DIR |= (BIT7);

    int toggleLed2 = 0;
    while(1) {
        volatile unsigned int i;
        P1OUT ^= (BIT0);// Toggle P1.0 using exclusive-OR

        if(toggleLed2 == 3){
            P9OUT ^= (BIT7);
            toggleLed2 = 0;
        }
        toggleLed2 = toggleLed2 + 1;
        __delay_cycles(100000);
    }

}
