/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */


#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>



#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif



typedef volatile unsigned int vuint32_t ;



//RCC Register address
#define RCC_BASE  0X40021000
#define RCC_APB2ENR *(volatile uint32_t *)(RCC_BASE + 0x18)
#define RCC_CR    *(volatile uint32_t *)(RCC_BASE + 0x00)
#define RCC_CFGR    *(volatile uint32_t *)(RCC_BASE + 0x04)


// GPIO Register address
#define GPIOA_BASE 0x40010800
#define GPIOA_CRH *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOx_CRL *(volatile uint32_t *)(GPIOA_BASE + 0x00)
#define GPIOA_ODR *(volatile uint32_t *)(GPIOA_BASE + 0x0C)


void GPIO_Init(void)
{

	//Enable RCC_CLOCK PORTA
	RCC_APB2ENR |= (1 << 2);

	//Init PORTA P13 as Output Pin
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;

	//Init PORTA P0 as Input Pin
	//01: Floating input (reset state)
	GPIOx_CRL &= ~(0b01 << 2);
	GPIOx_CRL |= (0b01 << 2);

}


// EXTI Register address
#define AFIO_BASE 0x40010000
#define AFIO_EXTICR1 *(volatile uint32_t *)(AFIO_BASE + 0x08)

#define EXTI_BASE 0x40010400
#define EXTI_IMR *(volatile uint32_t *)(EXTI_BASE + 0x00)
#define EXTI_RTSR *(volatile uint32_t *)(EXTI_BASE + 0x08)
#define EXTI_PR *(volatile uint32_t *)(EXTI_BASE + 0x14)


#define NVIC_BASE
#define NVIC_ISER0 *(volatile uint32_t *)(0xE000E100)


void EXTI0_Init(void)
{

	//Bit 0 AFIOEN: Alternate function IO clock enable
	RCC_APB2ENR |= (1 << 0);

	//External interrupt configuration register 1 (AFIO_EXTICR1)
	//Address offset: 0x08  For Mapping PA0 with EXTI0
	AFIO_EXTICR1 |= (0b0000 << 0);

	// 1: Interrupt request from Line x is not masked
	EXTI_IMR |= ( 1<< 0);

	//1: Rising trigger enabled (for Event and Interrupt) for input line.
	EXTI_RTSR |= (1 << 0);

	// Enable NVIC IRQn of This EXTI0 From IVT [Vector Table] IRQ is Number 6
	NVIC_ISER0 |= (1 << 6);


}



int main(void)
{

	GPIO_Init();
	EXTI0_Init();

	while(1)
	{



	}


}


/*void EXTI0_IRQHandler(void)
{
	//Toggle Pin13---------> PortA
	GPIOA_ODR ^= (1<<13) ;


	//PRx: Pending bit, This bit is set when the selected edge event arrives on the external interrupt line. This bit is
	//cleared by writing a ‘1’ into the bit.
	EXTI_PR |= (1 << 0);

}*/
