#include "stdint.h"
#define SYSCTL_BASE 0x400FE000
#define GPIOF_BASE 0x40025000
typedef union{
				uint32_t all_pins;
				struct{
					uint32_t pin0:1;
					uint32_t pin1:1;
					uint32_t pin2:1;
					uint32_t pin3:1;
					uint32_t pin4:1;
                    uint32_t pin5:1;
                    uint32_t pin6:1;
					uint32_t pin7:1;
					uint32_t pin8:1;
					uint32_t pin9:1;
					uint32_t pin10:1;
                    uint32_t pin11:1;
                    uint32_t pin12:1;
					uint32_t pin13:1;
					uint32_t pin14:1;
					uint32_t pin15:1;
					uint32_t pin16:1;
                    uint32_t pin17:1;
                    uint32_t pin18:1;
					uint32_t pin19:1;
					uint32_t pin20:1;
					uint32_t pin21:1;
					uint32_t pin22:1;
                    uint32_t pin23:1;
                    uint32_t pin24:1;
		    uint32_t pin25:1;
		    uint32_t pin26:1;
					uint32_t pin27:1;
					uint32_t pin28:1;
                    uint32_t pin29:1;
                    uint32_t pin30:1;
                    uint32_t pin31:1;

				      };

} reg_pin;
volatile reg_pin *SYSCTL_RCGC2_R=(volatile reg_pin*)(SYSCTL_BASE+0x108); // to enable GPIO clock
volatile reg_pin *GPIO_PORTF_DIR_R=(volatile reg_pin*)(GPIOF_BASE+0X400); // to set direction of port input or output
volatile reg_pin *GPIO_PORTF_DEN_R=(volatile reg_pin*)(GPIOF_BASE+0X51C); // to enable pin
volatile reg_pin *PORTF=(volatile reg_pin*)(GPIOF_BASE+0X3FC); // it is called GPIO_PORTF_DATA_R but we simplfy it 

int main(void)
{    volatile int i ; // volatile to not be deleted by optimizer
	SYSCTL_RCGC2_R->all_pins=0x20;
	// delay to make sure GPIOF is up and running
	for(i=0;i<200;i++){};
	GPIO_PORTF_DIR_R->pin3=1;
	GPIO_PORTF_DEN_R->pin3=1;
	
	while(1)
	{    PORTF->pin3=1;
		for(i=0;i<2000000;i++);
		PORTF->pin3=0 ;
		for(i=0;i<2000000;i++);
	}

}