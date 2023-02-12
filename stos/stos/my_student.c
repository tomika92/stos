#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "my_stack.h"
#include "menu.h"
#include "my_student.h"
#include "my_mess.h"
#pragma warning (disable : 4996)

static const char* different_study[] =
{
	"0 - informatyka",							//STUDY_MENU_INFOR
	"1 - matematyka",							//STUDY_MENU_MATM
	"2 - matematyka stosowana",					//STUDY_MENU_MATM_STOS
	"3 - architektura",							//STUDY_MENU_ARCHI
	"4 - architektura krajobrazu",				//STUDY_MENU_ARCHI_KRAJ
	"5 - elektrotechnika i automatyka",			//STUDY_MENU_ELEKTRO
	"6 - informatyka w inzynierii komputerowej",//STUDY_MENU_INFOR_INZY
	"7 - budownictwo",							//STUDY_MENU_BUDOW
	"8 - transport",							//STUDY_MENU_TRANSP
	"9 - biotechnologia"						//STUDY_MENU_BIOTECHNO
};

void study_menu()
{
	size_t iter;
	for (iter = 0; iter <= STUDY_MENU_BIOTECHNO; iter++)
	{
		printf("%s\n", different_study[iter]);
	}
}

void* student_create(int yyear, char *llastname, enum Study sstudy)
{
	struct MY_STUDENT* person = (struct MY_STUDENT*)malloc(sizeof(struct MY_STUDENT));
	if (!person)
	{
		my_mess_fun(MY_MESS_MEM_ALOC);
	}
	if (person)
	{
		person->year = yyear;
		strcpy(person->lastname, llastname);
		person->study = sstudy;
	}
	return (void*)(person);
}

void student_free(void *fr_st)
{
	struct MY_STUDENT* Person = (struct MY_STUDENT*)fr_st;
	if (Person)
		free(Person);
}

char* student_lastname(void* pt_lastname)
{
	struct MY_STUDENT* p_lastname = (struct MY_STUDENT*)pt_lastname;
	return p_lastname->lastname;
}

int student_year(void* pt_year)
{
	struct MY_STUDENT* p_year = (struct MY_STUDENT*)pt_year;
	return p_year->year;
}

enum Study student_study(void* pt_study)
{
	struct MY_STUDENT *p_study = (struct MY_STUDENT*)pt_study;
	return p_study->study;
}

void *student_push(int year, char *lastname, enum Study study)
{
	return student_create(year, lastname, study);
}

void student_print(void *fr_st)
{
	struct MY_STUDENT* person_data = (struct MY_STUDENT*)fr_st;
	if (person_data)
	{
		printf("\nnazwisko        : %s\n", person_data->lastname);
		printf("kierunek studiow: %s\n", d_study[person_data->study]);
		printf("rok urodzenia   : %u\n", person_data->year);
	}
}

int student_search_year(void* current_year, void* search_year)
{
	struct MY_STUDENT* pcurrent_year = (struct MY_STUDENT*)current_year;
	struct MY_STUDENT* psearch_year = (struct MY_STUDENT*)search_year;
	if (pcurrent_year->year == psearch_year->year)
	{
		return 1;
	}
	return 0;
}

int student_search_lastname(void* current_lastname, void* search_lastname)
{
	struct MY_STUDENT *pcurrent_lastname = (struct MY_STUDENT*)current_lastname;
	struct MY_STUDENT *psearch_lastname = (struct MY_STUDENT*)search_lastname;
	if (strcmp(pcurrent_lastname->lastname, psearch_lastname->lastname) == 0)
	{
		return 1;
	}
	return 0;

}

int student_search_study(void* current_study, void* search_study)
{
	struct MY_STUDENT *pcurrent_study = (struct MY_STUDENT*)current_study;
	struct MY_STUDENT* psearch_study = (struct MY_STUDENT*)search_study;
	if (pcurrent_study->study == psearch_study->study)
	{
		return 1;
	}
	return 0;
}