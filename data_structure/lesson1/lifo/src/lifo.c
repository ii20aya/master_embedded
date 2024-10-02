/*
 ============================================================================
 Name        : lifo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "lifoo.h"
//static allocation in data memory
unsigned int buffer1[5]; // we reserved 5*4 bytes = 20 bytes

int main(void) {
	 int i,temp=0;
	LIFO_Buf_t uart_lifo,I2C_lifo;

	LIFO_init(&uart_lifo,buffer1,5);
	//dynamic allocation in heap
	unsigned int* buffer2 = (unsigned int*) malloc (5 * sizeof(unsigned int ));
	LIFO_init(&I2C_lifo,buffer2,5);
	for(i=0;i<5;i++)
	{
		if(LIFO_Add_item(&uart_lifo,i) == LIFO_no_error)
		{


		DPRINTF("UART LIFO add : %d\n",i);
	}
	}

	for(i=0;i<5;i++)
		{
	if(  LIFO_get_item(&uart_lifo , &temp) == LIFO_no_error)
			{

			DPRINTF("UART LIFO get : %d\n",temp);
		    }
		}


	//for(i=0;i<5;i++)
	//{
	//	DPRINTF("UART LIFO get : %d\n",buffer1[i]);
	//}
	return 0;
	}
