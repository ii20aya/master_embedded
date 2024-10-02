/*
 * fifo.h
 *
 *  Created on: oct 1, 2024
 *      Author: aya abdulaziz
 */

#ifndef FIFO_H_
#define FIFO_H_
#include "stdio.h"
#include "stdint.h"
#define DPRINTF(...) {fflush(stdin);\
		fflush(stdout);\
		printf(__VA_ARGS__);\
		fflush(stdin);\
		fflush(stdout);}

// User Configuration
// select element type (uint8_t , uint16_t , uint32_t .....)
#define element_type uint8_t
// create buffer
#define width1 5
element_type uart_buffer[width1];

//fifo data types
typedef struct {
	unsigned int length ;
	unsigned int count ;
	element_type* base;
	element_type* head;
	element_type* tail;
}FIFO_Buf_t;
typedef enum{
	fifo_no_error,
	fifo_full,
	fifo_empty,
	fifo_null
}FIFO_buf_status;
// APIs
FIFO_buf_status FIFO_init(FIFO_Buf_t* fifo,element_type* buf,uint32_t length);
FIFO_buf_status FIFO_Enqueue(FIFO_Buf_t* fifo,element_type item);
FIFO_buf_status FIFO_Dequeue(FIFO_Buf_t* fifo,element_type* item);
FIFO_buf_status FIFO_is_full(FIFO_Buf_t* fifo);
void FIFO_print(FIFO_Buf_t* fifo);
#endif /* FIFO_H_ */
