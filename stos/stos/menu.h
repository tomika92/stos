#ifndef MY_MENU_AD__H
#define MY_MENU_AD__H

enum menu_com
{
	MENU_PUSH = 0,
	MENU_POP = 1,
	MENU_SHOW = 2,
	MENU_FREE = 3,
	MENU_YEAR = 4,
	MENU_LASTNAME = 5,
	MENU_STUDY = 6,
	MENU_SAVE = 7,
	MENU_READ = 8,
	MENU_STOP = 9,
	MENU_TOT = 10
};

void menu();
void push();
void pop();
void clear_all();
void show();
void find_lastname();
void find_year();
void find_study();
void save();
void read();

#endif