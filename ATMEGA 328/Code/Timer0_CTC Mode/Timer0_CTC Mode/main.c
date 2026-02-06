/*
 * Timer0_CTC Mode.c
 *
 * Created: 06-02-2026 21:44:34
 * Author : ashwi
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>

void delay_1ms()
{
	for(int i=0;i<78;i++)              //Repeating the process 78 times to get 1s delay
	{
		while(!(TIFR0&(1<<OCF0A)));   //wait until OCFOA=1
		TIFR0|=(1<<OCF0A);            //Writing 1 to OCFOA bit to make it 0
	}
}
int main(void)
{
	TCNT0=0;                        //initial value of TCNT0=0;
	TCCR0A &=~(1<<WGM00);          //Timer0 CTC Mode
	TCCR0A|=(1<<WGM01);
	
	TCCR0B|=(1<<CS00)|(1<<CS02);  //Configuring timer 0 for prescalar condition(1 0 1)
	TCCR0B&=~(1<<CS01);
	OCR0A=200;                   //Compare value is 200
	
	DDRB|=(1<<PB5);             //configuring pin 5 as output
	
	while (1)
	{
		PORTB|=(1<<PB5);       //PB5 is on
		delay_1ms();
		PORTB&=~(1<<PB5);     //PB5 is off
		delay_1ms();
	}
}

