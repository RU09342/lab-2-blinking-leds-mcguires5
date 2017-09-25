#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1DIR |= (0x01);    //Sets direction of P1 Bit 0 to Output
	P2DIR &= ~(BIT1);   //Sets direction of P2 Bit 1 to Input
	P2REN |= (BIT1);    //Enables the resistor for P2 Bit 1
	P2OUT |= (BIT1);    //Sets the ressistor for P2 Bit 1 to Pull Up

	int number = P2IN & BIT1;
	while(1){
	   int number = P2IN & BIT1;
	   if(number == 0){
	       P1OUT |= BIT0;
	   }else{
	       P1OUT &= ~BIT0;
	   }

	}
	return 0;
}
