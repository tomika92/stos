#ifndef MY_MESS_AD__H
#define MY_MESS_AD__H

enum MY_MESS
{
	MY_MESS_MEM_ALOC,			//0
	MY_MESS_LASTNAME,			//1
	MY_MESS_STUDY,				//2
	MY_MESS_YEAR,				//3
	MY_MESS_STUD_PROB,			//4
	MY_MESS_FIND,				//5
	MY_MESS_FULL_STACK,			//6
	MY_MESS_OPEN_FILE_ERR,		//7
	MY_MESS_NUMBER_ERR,			//8
	MY_MESS_TOTAL				//9
};

void my_mess_fun(enum MY_MESS mess);

#endif