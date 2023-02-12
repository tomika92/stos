#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "my_stack.h"
#include "my_student.h"
#include "my_mess.h"

#pragma warning( disable : 6031 )

static const char* menu_tab[] =
{
	"0 - push",							//MENU_PUSH
	"1 - pop",							//MENU_POP
	"2 - pokaz elementy",				//MENU_SHOW
	"3 - zwolnienie pamieci",			//MENU_FREE
	"4 - wyszukaj rok urodzenia",		//MENU_YEAR
	"5 - wyszukaj nazwisko",			//MENU_LASTNAME
	"6 - wyszukaj kierunek studiow",	//MENU_STUDY
	"7 - zapisz do pliku",				//MENU_SAVE
	"8 - odczytaj z pliku",				//MENU_READ		
	"9 - koniec"						//MENU_STOP
};

void menu()
{
	size_t iter;
	for (iter = 0; iter <= MENU_STOP; iter++)
	{
		printf("%s\n", menu_tab[iter]);
	}
}

void push()
{
	char* lastname = NULL;
	lastname = (char*)malloc(sizeof(char));
	if (!lastname)
	{
		my_mess_fun(MY_MESS_MEM_ALOC);
	}
	int year;
	enum Study study;

	my_mess_fun(MY_MESS_LASTNAME);
	scanf("\n%s", lastname);
	my_mess_fun(MY_MESS_STUDY);
	study_menu();
	scanf("%d", &study);
	my_mess_fun(MY_MESS_YEAR);
	scanf("%d", &year);

	void *pdata = student_push(year, lastname, study);
	if (!stack_push(pdata))
	{
		my_mess_fun(MY_MESS_STUD_PROB);
	}
}

void pop()
{
	struct stack tmp = stack_pop();
	student_free(tmp.data);
}

void clear_all()
{
	free_stack();
}

void show()
{
	void *show_d = stack_show(1);
	if (show_d)
	{
		student_print(show_d);
	}
	while (show_d)
	{
		show_d = stack_show(0);
		if (show_d)
		{
			student_print(show_d);
		}
		else
		{
			break;
		}
	}
}

void find_lastname()
{
	char str[512];
	my_mess_fun(MY_MESS_LASTNAME);
	scanf("%s", str);
	struct MY_STUDENT search_lastname;
	memset(&search_lastname, 0, sizeof(struct MY_STUDENT));
	strcpy_s(search_lastname.lastname, sizeof(search_lastname.lastname), str);
	void* p_data = search_stack(&search_lastname, student_search_lastname, 1);

	if (p_data)
	{
		my_mess_fun(MY_MESS_FIND);
		student_print(p_data);
	}
	while (p_data)
	{
		p_data = search_stack(&search_lastname, student_search_lastname, 0);
		if (p_data)
		{
			my_mess_fun(MY_MESS_FIND);
			student_print(p_data);
		}
	}
}

void find_year()
{
	int str;
	my_mess_fun(MY_MESS_YEAR);
	scanf("%d", &str);
	struct MY_STUDENT search_year;
	memset(&search_year, 0, sizeof(struct MY_STUDENT));
	search_year.year = str;
	void* p_data = search_stack(&search_year, student_search_year, 1);
	if (p_data)
	{
		my_mess_fun(MY_MESS_FIND);
		student_print(p_data);
	}
	while (p_data)
	{
		p_data = search_stack(&search_year, student_search_year, 0);
		if (p_data)
		{
			my_mess_fun(MY_MESS_FIND);
			student_print(p_data);
		}
	}
}

void find_study()
{
	enum Study str;
	my_mess_fun(MY_MESS_STUDY);
	study_menu();
	scanf("%d", &str);
	struct MY_STUDENT search_study;
	memset(&search_study, 0, sizeof(struct MY_STUDENT));
	search_study.study = str;
	void* p_data = search_stack(&search_study, student_search_study, 1);
	if (p_data)
	{
		my_mess_fun(MY_MESS_FIND);
		student_print(p_data);
	}
	while (p_data)
	{
		p_data = search_stack(&search_study, student_search_study, 0);
		if (p_data)
		{
			my_mess_fun(MY_MESS_FIND);
			student_print(p_data);
		}
	}
}

void save()
{
	save_stack();
}

void read()
{
	read_stack();
}