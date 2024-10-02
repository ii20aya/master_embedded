/*
 ============================================================================
 Name        : fifo2.c
 Author      : aya abdulaziz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "fifoo.h"

int main(void) {
	element_type temp=0, i;
		FIFO_Buf_t FIFO_UART;
		if (FIFO_init(&FIFO_UART,uart_buffer,5) == fifo_no_error )
		{
			DPRINTF("fifo_init is done\n");

		}

		for(i=0;i<7;i++)
		{
			DPRINTF("FIFO Enqueue (%X) \ n",i);
			if (FIFO_Enqueue(& FIFO_UART,i) == fifo_no_error )
				{DPRINTF("\t fifo_enqueue.... is done\n");}
			else
				{DPRINTF("\t fifo_enqueue.... failed\n");}
		}

		FIFO_print(&FIFO_UART);
		if(FIFO_Dequeue(& FIFO_UART,&temp) == fifo_no_error )
			{DPRINTF("\t fifo_dequeue %x .... is done\n",temp);}
		else
			{DPRINTF("\t fifo_dequeue.... failed\n");}

		if(FIFO_Dequeue(& FIFO_UART,&temp) == fifo_no_error )
		{	DPRINTF("\t fifo_dequeue %x .... is done\n",temp);}
			else
				{DPRINTF("\t fifo_dequeue.... failed\n");}
		FIFO_print(&FIFO_UART);
	}
