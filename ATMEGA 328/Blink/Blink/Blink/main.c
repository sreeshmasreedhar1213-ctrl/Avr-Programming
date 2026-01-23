/*
 * Blink.c
 *
 * Created: 22-01-2026 22:44:51
 * Author : ashwi
 */ 
#define f_cpu 16000000
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB=0b00001000;
    
    while (1) 
    {
		PORTB=0b00001000;
		_delay_ms(1000);
		PORTB=0b00000000;
		_delay_ms(1000);
    }
}

