#include <stdio.h>
#include <stdlib.h>
#include "my_stack.h"
#include "menu.h"
#include "my_student.h"
#include "my_mess.h"

#pragma warning (disable : 6031)

int main()
{
	create_stack(student_free);
	size_t face = 0;
	while(face >= MENU_PUSH && face <= MENU_STOP)
	{
		menu();
		scanf("%d", &face);
		switch(face)
		{
		case MENU_PUSH: push();
			break;
		case MENU_POP: pop();
			break;
		case MENU_SHOW: show();
			break;
		case MENU_FREE: clear_all();
			break;
		case MENU_YEAR: find_year();
			break;
		case MENU_LASTNAME: find_lastname();
			break;
		case MENU_STUDY: find_study();
			break;
		case MENU_SAVE: save();
			break;
		case MENU_READ: read();
			break;
		case MENU_STOP: clear_all();
			return 0;
		default:
			my_mess_fun(MY_MESS_NUMBER_ERR);
		}
	}
}

