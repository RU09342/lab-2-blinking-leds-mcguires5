#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    P1DIR |= (0x01);    //Sets direction of P1 Bit 0 to Output
    P1DIR &= ~(BIT3);   //Sets direction of P1 Bit 1 to Input
    P1REN |= (BIT3);    //Enables the resistor for P1 Bit 1
    P1OUT |= (BIT3);    //Sets the ressistor for P1 Bit 1 to Pull Up


    while(1){
       int number = P1IN & BIT3;
       if(number == 0){
           P1OUT |= BIT0;
       }else{
           P1OUT &= ~BIT0;
       }

    }
    return 0;
}
