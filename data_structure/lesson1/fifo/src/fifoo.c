/*
 * fifo.c
 *
 *  Created on: oct 1, 2024
 *      Author: aya abdulaziz
 */
#include "fifoo.h"
FIFO_buf_status FIFO_init(FIFO_Buf_t* fifo,element_type* buf,uint32_t length)
{
	if(buf == NULL)
		return fifo_null;
	fifo->base = buf ;
	fifo->head = buf ;
	fifo->tail = buf ;
	fifo->length = length;
	fifo->count = 0 ;
	return fifo_no_error;

}
FIFO_buf_status FIFO_Enqueue(FIFO_Buf_t* fifo,element_type item)
{
	if(!fifo->base || !fifo->head || !fifo->tail )
	return fifo_null;
	if(FIFO_is_full(fifo)== fifo_full)
		return fifo_full;
	*(fifo->head)=item;
	fifo->count++;
// circular fifo
	if(fifo->head == (fifo->base + (fifo->length * sizeof( element_type))))
	fifo->head=fifo->base;
	else
		fifo->head++;

	return fifo_no_error;

}
FIFO_buf_status FIFO_Dequeue(FIFO_Buf_t* fifo,element_type* item)
{
	if(!fifo->base || !fifo->head || !fifo->tail )
		return fifo_null;
// check is empty or not
if(fifo->count == 0)
 return fifo_empty;
*item=*(fifo->tail);
fifo->count--;
// circular fifo
if(fifo->tail == (fifo->base + (fifo->length * sizeof( element_type))))
	fifo->tail=fifo->base;
else
	fifo->tail++;
return fifo_no_error;



}
FIFO_buf_status FIFO_is_full(FIFO_Buf_t* fifo)
{
	if(!fifo->base || !fifo->head || !fifo->tail )
		return fifo_null;
	if(fifo->count == fifo->length)
		return fifo_full;
	return fifo_no_error;
}
void FIFO_print(FIFO_Buf_t* fifo)
{
element_type* temp;
int i;
if(fifo->count == 0)
	{
	DPRINTF("fifo is empty");
	}
else
{
temp = fifo->tail;
DPRINTF("\n =======fifo_print====\n");
for(i=0;i<fifo->count;i++)
{
	DPRINTF("\t %x \n",*temp);
temp++;
}
DPRINTF("\n========end==========\n");
}
}



