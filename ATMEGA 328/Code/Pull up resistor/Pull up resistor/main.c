/*
 * Pull up resistor.c
 *
 * Created: 31-01-2026 00:04:15
 * Author : ashwi
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRD&=~(1<<DDD4);
	DDRB|=(1<<DDB5);
	while (1)
	{
		if(PIND&(1<<PD4))
		{
			PORTB&=~(1<<PB5);
		}
		else
		{
			PORTB|=(1<<PB5);
		}
	}
}