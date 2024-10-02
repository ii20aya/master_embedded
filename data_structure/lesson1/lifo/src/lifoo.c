/*
 * lifoo.c
 *
 *  Created on: Sep 28, 2024
 *      Author: HD STORE
 */


#include "lifoo.h"
LIFO_status LIFO_Add_item (LIFO_Buf_t* lifo_buf ,unsigned int item)
{
// check lifo is exist or not
	//if(!lifo_buf->base || !lifo_buf->head)
		//return LIFO_Null;
// check if lifo is full
//if(lifo_buf->head >= (lifo_buf->base +(lifo_buf->length *4)) )  //or
	if (lifo_buf->count == lifo_buf->length)
		return LIFO_full;
// add value
	*(lifo_buf->head)= item;
	(lifo_buf->head)++;
	(lifo_buf->count)++;
	return LIFO_no_error;
}
LIFO_status LIFO_get_item(LIFO_Buf_t* lifo_buf,unsigned int* item)
{
// check lifo is exist or not
		if(!lifo_buf->base || !lifo_buf->head)
			return LIFO_Null;
// check if lifo empty
		if (lifo_buf->count == 0)
			return LIFO_empty;

		lifo_buf->head--;
		*item = *(lifo_buf->head);
		lifo_buf->count--;

		return LIFO_no_error;
}
LIFO_status LIFO_init(LIFO_Buf_t* lifo_buf,unsigned int* buf,unsigned int length)
{
	if( buf == NULL )
		return LIFO_Null;

	lifo_buf->base= buf;
	lifo_buf->head= buf;
	lifo_buf->length=length;
	lifo_buf->count=0;
	return LIFO_no_error;
}
