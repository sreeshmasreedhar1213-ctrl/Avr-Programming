/*
 * Motor_driving.c
 *
 * Created: 27-01-2026 21:48:05
 * Author : ashwi
 */ 
#define f_cpu 16000000UL
#include <avr/io.h>
#include<util/delay.h>


int main(void)
{
    DDRB|=(1<<DDB5);
	DDRB|=(1<<DDB4);
    while (1) 
    {
		PORTB|=(1<<PB5);
		PORTB&=~(1<<PB4);
		_delay_ms(2000);
		
		PORTB&=~(1<<PB4);
		PORTB&=~(1<<PB5);
		_delay_ms(2000);
		
		PORTB|=(1<<PB4);
		PORTB&=~(1<<PB5);
		_delay_ms(2000);
		
		PORTB&=~(1<<PB4);
		PORTB&=~(1<<PB5);
		_delay_ms(2000);
		
    }
}

