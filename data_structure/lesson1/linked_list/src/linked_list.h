/*
 /*
 * linked_list.h
 *
 *  Created on: oct 1, 2024
 *      Author: aya abdulaziz
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include<conio.h>
extern struct Sstudent* gPFirstStudent;
extern int Rcount;
// this macro to overcome a bug in eclipse
#define DPRINTF(...) {fflush(stdin);\
		fflush(stdout);\
		printf(__VA_ARGS__);\
		fflush(stdin);\
		fflush(stdout);}
//effective data
typedef struct Sdata {

	unsigned int  ID;
	char name[40];
	float height;

}Sdata;
// linked list node
typedef struct Sstudent{
	struct Sdata student;
	struct Sstudent* PNextStudent;

}Sstudent;
                    // counter to calculate length using recursive way
//APIs
void AddStudent();
int Delete_Student();
void view_Students();
void Delete_All();
int GetNth();
int Num_of_nodes();
int GetNth_Reverse_order();
int middle_list();
int Reverse_list();
int Num_of_nodes_recursive(struct Sstudent* PCurrentStudent_recursive);
#endif /* LINKED_LIST_H_ */
