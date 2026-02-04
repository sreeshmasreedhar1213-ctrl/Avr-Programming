/*
 * Timer0_Normal mode.c
 *
 * Created: 04-02-2026 21:03:19
 * Author : ashwi
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>

void delay_1ms()
{
	for(int i=0;i<61;i++)
	   {
		   while(!(TIFR0&(1<<TOV0)));
		   TIFR0|=(1<<TOV0);
	   }
}
int main(void)
{
  TCNT0=0;
  TCCR0A &=~(1<<WGM00);
  TCCR0A &=~(1<<WGM01);
  
  TCCR0B|=(1<<CS00)|(1<<CS02);
  TCCR0B&=~(1<<CS01);
   
 DDRB|=(1<<PB5); 
  
    while (1) 
    {
		PORTB|=(1<<PB5);
		delay_1ms();
		PORTB&=~(1<<PB5);
		delay_1ms();
    }
}

