/*
 * Fast_Inverting PWM.c
 *
 * Created: 10-02-2026 20:41:21
 * Author : ashwi
 */ 
#define f_cpu 16000000UL
#include <avr/io.h>


int main(void)
{
   DDRD|=(1<<PD6);                     // Configuring PD6 AS O/P
   TCCR0A|=(1<<WGM00)|(1<<WGM01);     // Fast PWM
   TCCR0A|=(1<<COM0A1)|(1<<COM0A0);  // Inverting PWM
   TCCR0B|=(1<<CS01);               // Prescalar is 8, ie 7.4 KHZ frequency
   TCCR0B&=~(1<<CS02)|(1<<CS00);
   OCR0A=102;
    while (1) 
    {
    }
}

