#include <msp430.h>				


/**
 * blink.c
 */
 int Thresh = 1;
 int toggleLed2 = 0;
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;		// stop watchdog timer
	P1DIR |= (BIT0 + BIT4);					// configure P1.0 as output
	P1DIR |= BIT4;
	P1REN |= (BIT5);    //Enables the resistor for P1 Bit 3
	P1OUT |= (BIT5);    //Sets resistor to pull up
	P1IN &= 0;


	P1IFG &= ~(BIT5);
	P1IE |= (BIT5);
	P1IES |= BIT5;

	volatile unsigned int i;		// volatile to prevent optimization
	__bis_SR_register(GIE);       // Enter LPM4 w/interrupt
	while(1) {
	        volatile unsigned int i;
	        __delay_cycles(500000);
	        P1OUT ^= (BIT0);// Toggle P1.0 using exclusive-OR

	        if(toggleLed2 == Thresh){
	            P1OUT ^= (BIT4);
	            toggleLed2 = 0;
	        }
	        toggleLed2 = toggleLed2 + 1;

	    }

}
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
    if(Thresh >= 8){
         Thresh = 1;
         toggleLed2 = 0;
         P1OUT &= (BIT4+BIT0);
         __delay_cycles(1000);
    }else{
         Thresh = Thresh * 2;
         __delay_cycles(1000);
    }
    P1IFG &= ~BIT5;

}
