/*
 * lifoo.h
 *
 *  Created on: Sep 28, 2024
 *      Author: HD STORE
 */

#ifndef LIFO_H_
#define LIFO_H_
#include <stdio.h>
#include <stdlib.h>
#define DPRINTF(...) {fflush(stdin);\
		fflush(stdout);\
		printf(__VA_ARGS__);\
		fflush(stdin);\
		fflush(stdout);}
//type definitions
typedef struct{
	unsigned int length ;
	unsigned int count ;
	unsigned int* base;
	unsigned int* head;
}LIFO_Buf_t;

typedef enum{
	LIFO_no_error,    // first element equivalent to 0
	LIFO_full,       // first element equivalent to 1
	LIFO_empty,     // and so on
	LIFO_Null     // t mean that this lifo not exist
}LIFO_status;

// APIs
LIFO_status LIFO_Add_item (LIFO_Buf_t* lifo_buf ,unsigned int item);
LIFO_status LIFO_get_item(LIFO_Buf_t* lifo_buf,unsigned int* item);
LIFO_status LIFO_init(LIFO_Buf_t* lifo_buf,unsigned int* buf,unsigned int length);
#endif /* LIFO_H_ */
