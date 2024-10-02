/*
 * main.c
 *
 *  Created on: oct 1, 2024
 *      Author: aya abdulaziz
 */

#include "linked_list.h"

int main(void) {
	char temp_text[40];
	while(1)
	{
		Rcount=0;
		DPRINTF("\n==================================================");
		DPRINTF("\n \t choose one of the following options \n ");
		DPRINTF("\n 1 : Add Student");
		DPRINTF("\n 2 : Delete Student");
		DPRINTF("\n 3 : View Students");
		DPRINTF("\n 4 : Delete all Students");
		DPRINTF("\n 5 : Get by index");
		DPRINTF("\n 6 : Number of students");
		DPRINTF("\n 7 : Get Nth from the end of list");
		DPRINTF("\n 8 : Get middle of the list");
		DPRINTF("\n 9 : reverse linked list");
		DPRINTF("\n 10 : NUmber of students (recursive way)");
		DPRINTF("\n Enter option number");
		gets(temp_text);
		switch(atoi(temp_text))
		{
		case 1 :
			AddStudent();
			break;
		case 2 :
			Delete_Student();
			break;
		case 3 :
			view_Students();
			break;
		case 4 :
			Delete_All();
			break;
		case 5 :
			GetNth();
			break;
		case 6 :
			Num_of_nodes();
			break;
		case 7 :
			GetNth_Reverse_order();
			break;
		case 8 :
			middle_list();
			break;
		case 9 :
			Reverse_list();
			break;
		case 10 :
			Num_of_nodes_recursive(gPFirstStudent);
			break;
		default :
			DPRINTF("\n wrong option");
		}
	}
}
