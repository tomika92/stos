#ifndef MY_STUDENT_AD__H
#define MY_STUDENT_AD__H

enum Study 
{
	STUDY_MENU_INFOR = 0,
	STUDY_MENU_MATM = 1,
	STUDY_MENU_MATM_STOS = 2,
	STUDY_MENU_ARCHI = 3,
	STUDY_MENU_ARCHI_KRAJ = 4,
	STUDY_MENU_ELEKTRO = 5,
	STUDY_MENU_INFOR_INZY = 6,
	STUDY_MENU_BUDOW = 7,
	STUDY_MENU_TRANSP = 8,
	STUDY_MENU_BIOTECHNO = 9,
	STUDY_MENU_STOP = 10
};

static const char* d_study[] =
{
	"informatyka",							//0 STUDY_MENU_INFOR
	"matematyka",							//1 STUDY_MENU_MATM
	"matematyka stosowana",					//2 STUDY_MENU_MATM_STOS
	"architektura",							//3 STUDY_MENU_ARCHI
	"architektura krajobrazu",				//4 STUDY_MENU_ARCHI_KRAJ
	"elektrotechnika i automatyka",			//5 STUDY_MENU_ELEKTRO
	"informatyka w inzynierii komputerowej",//6 STUDY_MENU_INFOR_INZY
	"budownictwo",							//7 STUDY_MENU_BUDOW
	"transport",							//8 STUDY_MENU_TRANSP
	"biotechnologia"						//9 STUDY_MENU_BIOTECHNO
};

struct MY_STUDENT
{
	char lastname[512];
	enum Study study;
	int year;
};

void* student_create(int yyear, char* llastname, enum Study sstudy);
void student_free(void *fr_st);
void* student_push(int year, char* lastname, enum Study study);
void student_print(void* fr_st);
char* student_lastname(void* pt_lastname);
int student_year(void* pt_year);
enum Study student_study(void* pt_study);
int student_search_year(void* current_year, void* search_year);
int student_search_lastname(void* current_lastname, void* search_lastname);
int student_search_study(void* current_study, void* search_study);
void study_menu();

#endif