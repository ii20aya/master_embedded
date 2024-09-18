#include <stdio.h>

typedef volatile unsigned int vuint32_t;
#define RCC_BASE 0x40021000
#define PORT_A   0x40010800

#define RCC_APB2ENR     *((volatile uint32_t *) (RCC_BASE +0x18))
#define GPIO_CRH        *((volatile uint32_t *) (PORT_A +0x04))
#define GPIO_ODR        *((volatile uint32_t *) (PORT_A +0x0C))

//proffissional method
typedef union
{
	vuint32_t all;
	struct //bit field
	{
		vuint32_t reserved: 13; //not using the first 12 bit
		vuint32_t P_13: 1;
	} pins;
} R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*) (PORT_A + 0x0C);
unsigned char g_variable[3]={1,2,3};
unsigned char const const_variable[3]={1,2,3};

int main (void)
{
	int i;
	RCC_APB2ENR |= (1 << 2);
	GPIO_CRH &= 0xFF0FFFFF;
	GPIO_CRH |= 0x00200000;

	while (1)
	{
		R_ODR -> pins.P_13 = 1;
		for (i = 0; i < 5000; i++);
		R_ODR -> pins.P_13 = 0;
		for (i = 0; i < 5000; i++);
	}
	return 0;
}