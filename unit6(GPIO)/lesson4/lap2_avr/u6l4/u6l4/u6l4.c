/*
 * u6l4.c
 *
 * Created: 10/28/2024 10:55:11 AM
 *  Author: aya abdulaziz
 */ 


#define F_CPU 1000000Ul
#include <avr/io.h>
#include <stdio.h>
#include <stdint.h>
#include <util/delay.h>
#include <avr/interrupt.h>

/*#define	MCUCR *(volatile uint8_t*)(0x35)
#define	MCUCSR *(volatile uint8_t*)(0x34)
#define	GICR *(volatile uint8_t*)(0x3B)
#define	GIFR *(volatile uint8_t*)(0x3A)
#define	SREG *(volatile uint8_t*)(0x3F)
#define	DDRA *(volatile uint8_t*)(0x1A)
#define	DDRD *(volatile uint8_t*)(0x11)
#define	DDRB *(volatile uint8_t*)(0x17)
#define	PORTA *(volatile uint8_t*)(0x1B)
*/

void EXTI_init(void)
{  //INT0 & INT1 at "any logic change mode"
	MCUCR |=(1<<0)|(1<<2);
	//INT2 at rising edge mode
	MCUCSR |=(1<<6);
	// mask the 3 interrupts
	GICR |=(1<<7)|(1<<6)|(1<<5);
	// enable global interrupt
	//SREG |=(1<<7);
	sei();
}
void GPIO_init(void)
{
	DDRD &=~(1<<2);
	DDRD &=~(1<<3);
	DDRB &=~(1<<2);
	
	
	PORTB |=(1<<2); //pull up
	PORTD |=(1<<2); // pull up
	PORTD |=(1<<3); // pull up
	
	//leds out
	DDRA =0XFF;
	PORTA=0X00;
}


int main(void)
{
	EXTI_init();
	GPIO_init();
	while (1);
	
	
}
ISR (INT0_vect)
{
	PORTA |=(1<<0);
	_delay_ms(1000);
	PORTA &= ~(1<<0);
	_delay_ms(10);
}

ISR(INT1_vect)
{
	PORTA |=(1<<1);
	_delay_ms(1000);
	PORTA &= ~(1<<1);
	_delay_ms(10);
}
ISR(INT2_vect)
{
	PORTA |=(1<<2);
	_delay_ms(1000);
	PORTA &= ~(1<<2);
	_delay_ms(10);
}