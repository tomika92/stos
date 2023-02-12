#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "my_mess.h"
#include "menu.h"
#include "my_stack.h"
#include "my_student.h"

static const char* my_mess_tab[] =
{
	"EBlad alkowania pamieci",				//0 MY_MESS_MEM_ALOC
	"WPodaj nazwisko",						//1 MY_MESS_LASTNAME
	"WPodaj kierunek studiow",				//2 MY_MESS_STUDY
	"WPodaj rok urodzenia",					//3 MY_MESS_YEAR
	"WTworzenie studenta sie nie powiodlo",	//4 MY_MESS_STUD_PROB
	"WZnaleziono studenta",					//5 MY_MESS_FIND
	"WStos jest pelny",						//6 MY_MESS_FULL_STACK
	"WNie udalo sie otworzyc pliku",		//7 MY_MESS_OPEN_FILE_ERR
	"WNie ma takiego kodu"					//8 MY_MESS_NUMBER_ERR
};

void my_mess_fun(enum MY_MESS mess)
{
	puts(my_mess_tab[mess] + 1);
	if (my_mess_tab[mess][0] == 'E')
	{
		system("pause");
		free_stack();
		exit(1);
	}
}
