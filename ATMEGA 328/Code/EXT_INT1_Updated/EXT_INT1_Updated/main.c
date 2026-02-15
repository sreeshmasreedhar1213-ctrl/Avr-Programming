/*
 * EXT_INT1_Updated.c
 *
 * Created: 15-02-2026 16:30:24
 * Author : ashwi
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
uint8_t flag=0;

ISR(INT1_vect)//Interrupt vector table
{
	flag=1;
}

int main(void)
{
	DDRB|=(1<<PB5);  //PB5 as o/p
	DDRB|=(1<<PB4); //PB4 as o/p
	DDRD&=~(1<<PD3);//PD3 as input(INT1)
	PORTD|=(1<<PD3);//Enabling pullup resistor
	EIMSK|=(1<<INT1);//Enabling INT1
	EICRA|=(1<<ISC01);//Interrupt on falling edge
	EICRA&=~(1<<ISC00);
	sei();//Enabling global interrupt

	while (1)
	{
		PORTB|=(1<<PB5);//
		_delay_ms(1000);
		PORTB&=~(1<<PB5);
		_delay_ms(1000);
		if(flag==1)
		{
			PORTB|=(1<<PB4);
			_delay_ms(5000);
			PORTB&=~(1<<PB4);
			flag=0;
		}
	}
}

