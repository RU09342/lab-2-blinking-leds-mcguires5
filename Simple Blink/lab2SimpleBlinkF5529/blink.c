#include <msp430.h>				


/**
 * blink.c
 */
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;		// stop watchdog timer
	P1DIR |= (PIN0);					// configure P1.0 as output

	while(1)
	{
		P1OUT ^= (PIN0);				// toggle P1.0
		__delay_cycles(100000);     // delay
	}
}
