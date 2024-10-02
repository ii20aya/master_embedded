/*
 * linked_list.c
 *
 *  Created on: oct 1, 2024
 *      Author: aya abdulaziz
 */
#include "linked_list.h"
struct Sstudent* gPFirstStudent = NULL;
int Rcount =0;
void AddStudent()
{
	struct Sstudent* PNewStudent;
	struct Sstudent* PLastStudent;
	char temp_text[40];
	if( gPFirstStudent == NULL) // the first element will be added no records before
	{	//create new record
		PNewStudent = (struct Sstudent* )malloc(sizeof(struct Sstudent)) ;
		gPFirstStudent=PNewStudent;
		PNewStudent->PNextStudent=NULL;
	}
	else // if there are records before
	{
		PLastStudent=gPFirstStudent;
		while(PLastStudent->PNextStudent)// if it points to NULL condition will not match,
			// navigate to reach the last record
		{
			PLastStudent=PLastStudent->PNextStudent;
		}

		//create new record
		PNewStudent = (struct Sstudent* )malloc(sizeof(struct Sstudent)) ;
		PLastStudent->PNextStudent=PNewStudent;
		PNewStudent->PNextStudent=NULL;
	}
	//fill the new record
	DPRINTF("\n Enter student ID :");
	gets(temp_text);
	PNewStudent->student.ID = atoi(temp_text);
	DPRINTF("\n Enter student full name  :");
	gets(PNewStudent->student.name);
	DPRINTF("\n Enter student height :");
	gets(temp_text);
	PNewStudent->student.height = atof(temp_text);
	PNewStudent->PNextStudent=NULL;
}
int Delete_Student()
{
	char temp_text[40];
	unsigned int Selected_ID;
	DPRINTF("\n Enter student ID to be deleted");
	gets(temp_text);
	Selected_ID=atoi(temp_text);
	if(gPFirstStudent) // list is not empty
	{
		struct Sstudent* PSelectedStudent=gPFirstStudent;
		struct Sstudent* PPreviousStudent = NULL;
		while(PSelectedStudent) // navigate till reach the end of list
		{
			// compare IDs
			if(PSelectedStudent->student.ID == Selected_ID )
			{
				if(PPreviousStudent) // means that it is not the first element
				{
					PPreviousStudent->PNextStudent=PSelectedStudent->PNextStudent;
				}
				else // the target element is the first element
				{
					gPFirstStudent=PSelectedStudent->PNextStudent;
				}
				free(PSelectedStudent);
				return 1;
			}
			PPreviousStudent=PSelectedStudent;
			PSelectedStudent=PSelectedStudent->PNextStudent;
		}
	}
	DPRINTF("\n cannot find student ID"); // if the selected ID didn't matched any of list IDs
	return 0;
}
void view_Students()
{
	struct Sstudent* PCurrentStudent=gPFirstStudent;
	int count = 0 ;
	// check if list is empty
	if (gPFirstStudent == NULL)
	{
		DPRINTF("\n list is empty ");
	}
	else
	{
		while(PCurrentStudent)
		{
			DPRINTF("\n record number %d : ",count+1);
			DPRINTF("\n\t ID : %d",PCurrentStudent->student.ID);
			DPRINTF("\n\t Name : %s",PCurrentStudent->student.name);
			DPRINTF("\n\t Height : %f",PCurrentStudent->student.height);
			PCurrentStudent=PCurrentStudent->PNextStudent;
			count++;

		}
	}
}
void Delete_All()
{
	struct Sstudent* PCurrentStudent=gPFirstStudent;
	// check if list is empty
	if (gPFirstStudent == NULL)
	{
		DPRINTF("\n list is empty ");
	}
	else
	{
		while(PCurrentStudent)
		{
			struct Sstudent* PTemptStudent=PCurrentStudent;
			PCurrentStudent=PCurrentStudent->PNextStudent;
			free(PTemptStudent);
		}
		gPFirstStudent=NULL; // because we deleted whole list
	}
}
int GetNth() // print student info with respect to Index number
{	int index;
char temp_text[40];
struct Sstudent* PCurrentStudent=gPFirstStudent;
int count=0;
DPRINTF("Enter index :");
gets(temp_text);
index = atoi(temp_text);
if(gPFirstStudent == NULL) // check if empty
{
	DPRINTF("\n list is empty ");

	return 0;
}
else{
	while(PCurrentStudent)
	{
		if(count == index)
		{
			DPRINTF("\n index number %d : ",index);
			DPRINTF("\n\t ID : %d",PCurrentStudent->student.ID);
			DPRINTF("\n\t Name : %s",PCurrentStudent->student.name);
			DPRINTF("\n\t Height : %f",PCurrentStudent->student.height);
			return 1;
		}
		PCurrentStudent=PCurrentStudent->PNextStudent;
		count++;
	}
	DPRINTF("\n index not exist ");
	return 0;
}

}
int Num_of_nodes()
{   int count = 0;
struct Sstudent* PCurrentStudent=gPFirstStudent;
if(gPFirstStudent == NULL) // check if empty
{
	DPRINTF("\n list is empty ");

	return 0;
}
else{
	while(PCurrentStudent)
	{
		PCurrentStudent=PCurrentStudent->PNextStudent;
		count++;
	}
	DPRINTF("\n Number of students : %d ",count);
	return 1;
}
}
int GetNth_Reverse_order() // get node number N from the last using 2 pointers method
{   char temp_text[40];
int index,temp;

struct Sstudent* Pmain=gPFirstStudent;
struct Sstudent* Pref=gPFirstStudent;
DPRINTF("Enter index :");
gets(temp_text);
index = atoi(temp_text);
temp=index;
if(gPFirstStudent == NULL) // check if empty
{
	DPRINTF("\n list is empty ");
	return 0;
}
else
{
	while(Pmain && temp)     // this condition to push Pmain away from Pref by N steps
	{                        // and make sure that number of students is bigger than N
		Pmain=Pmain->PNextStudent;
		temp--;

	}
	if(temp>0)   // that means the pmain reached to end of list before N steps , in other words
	{            // number of students is smaller than the Nth element user gave so there is no
		// element with this index if we started in reverse order
		// example total number is =5 and you want the 6th element from the end of list
		DPRINTF("\n element with that index is not exist ");
		return 0;
	}
	while(Pmain)
	{
		Pmain=Pmain->PNextStudent;  // navigate to the end of list and Pref will point to Nth
		Pref=Pref->PNextStudent;    // elements before the end (Pmain)

	}
	DPRINTF("\n index number %d : ",index);
	DPRINTF("\n\t ID : %d",Pref->student.ID);
	DPRINTF("\n\t Name : %s",Pref->student.name);
	DPRINTF("\n\t Height : %f",Pref->student.height);
	return 1;
}
}
int middle_list()
{   int flag=0,count=0;
struct Sstudent* PFast=gPFirstStudent;
struct Sstudent* PSlow=gPFirstStudent;
if(gPFirstStudent == NULL) // check if empty
{
	DPRINTF("\n list is empty ");

	return 0;
}
else{

	while(PFast)  // 2 Pointers pFast increment by 2 and PSlow increment by 1
	{
		PFast=PFast->PNextStudent;

		if(PFast==NULL)  // if the length is odd number this condition will occur,after the
		{                // first step of PFast pointer and flag will be 1
			flag=1;
			break;
		}
		PFast=PFast->PNextStudent;
		PSlow=PSlow->PNextStudent;
		count++;
	}
	if(flag==0)   // length is even number
	{
		DPRINTF("\n list is even, the second middle is :");
	}
	DPRINTF("\n index number %d : ",count);
	DPRINTF("\n\t ID : %d",PSlow->student.ID);
	DPRINTF("\n\t Name : %s",PSlow->student.name);
	DPRINTF("\n\t Height : %f",PSlow->student.height);
	return 1;
}
}
int Reverse_list()
{
	struct Sstudent* Phead=gPFirstStudent;
	struct Sstudent* PCurrent=gPFirstStudent;
	struct Sstudent* PPrevious=gPFirstStudent;
	if(gPFirstStudent == NULL) // check if empty
	{
		DPRINTF("\n list is empty ");

		return 0;
	}
	else{
		  if(gPFirstStudent->PNextStudent == NULL) // one element only
		  {
			  DPRINTF("\n there is only one element in list :");
			  return 1;
		  }
		  else if(gPFirstStudent->PNextStudent->PNextStudent == NULL) // only two elements in list
		  {
			  PCurrent = gPFirstStudent->PNextStudent;
			  gPFirstStudent->PNextStudent= NULL;
			  gPFirstStudent=PCurrent;
			  gPFirstStudent->PNextStudent=Phead;
			  return 1;

		  }
		  else{   // more than 2 elements

			  Phead =gPFirstStudent->PNextStudent->PNextStudent;
			  PCurrent=gPFirstStudent->PNextStudent;
			  PPrevious->PNextStudent=NULL;
			  while(Phead)
			  {
				  PCurrent->PNextStudent=PPrevious;
				  PPrevious=PCurrent;
				  PCurrent=Phead;
				  Phead=Phead->PNextStudent;
			  }
			  PCurrent->PNextStudent=PPrevious;
			  gPFirstStudent=PCurrent;
			  return 1;
		    }

	   }

}
 int Num_of_nodes_recursive(struct Sstudent* PCurrentStudent_recursive)
{
	if(PCurrentStudent_recursive == NULL ) // check if empty
	   {
		if( Rcount == 0 )
		  {
			DPRINTF("\n list is empty ");
		   return 0;
		  }
		else       // end of navigation
		{
			DPRINTF("\n Number of students : %d ",Rcount);
			return 1;
		}
	}
	else{
		PCurrentStudent_recursive =	PCurrentStudent_recursive->PNextStudent;
		Rcount ++;
		Num_of_nodes_recursive(PCurrentStudent_recursive);
	    }


}
