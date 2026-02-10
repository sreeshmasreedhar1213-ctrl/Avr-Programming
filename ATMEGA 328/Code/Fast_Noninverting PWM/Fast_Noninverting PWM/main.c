/*
 * Fast_Noninverting PWM.c
 *
 * Created: 07-02-2026 21:50:09
 * Author : ashwi
 */ 
#define f_cpu 16000000UL
#include <avr/io.h>


int main(void)
{
	DDRD|=(1<<PD6); // Configuring PD6 as o/p
    TCCR0A|=(1<<WGM00)|(1<<WGM01);  //Configuring fast pwm mode
	TCCR0A|=(1<<COM0A1);  //Non-inverting PWM
	TCCR0A&=~(1<<COM0A0);
	TCCR0B|=(1<<CS00)|(1<<CS01);  //prescalar 64
	TCCR0B&=~(1<<CS02);
	OCR0A=102; //For 40% duty cycle
	
    while (1) 
    {
    }
}

