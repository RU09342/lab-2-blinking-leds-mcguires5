#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer

        P1DIR |= (BIT0);
        P1DIR |= (BIT6);

        int toggleLed2 = 0;
        while(1) {
            volatile unsigned int i;
            P1OUT ^= (BIT0);// Toggle P1.0 using exclusive-OR

            if(toggleLed2 == 3){
                P1OUT ^= (BIT6);
                toggleLed2 = 0;
            }
            toggleLed2 = toggleLed2 + 1;
            __delay_cycles(100000);
        }
}
