#include <stdio.h>
#include <stdlib.h>
#include "my_stack.h"
#include "menu.h"
#include "my_student.h"
#include "my_mess.h"

int max_size = 10;
static struct stack* top = NULL;
FreeData p_free_data;

void create_stack(FreeData Free)
{
	top = NULL;
	p_free_data = Free;
}

int stack_size(struct stack* top)
{
	int record = 0;
	struct stack* actual = top;
	while (actual != NULL)
	{
		record++;
		actual = actual->next;
	}
	return record;
}

void *stack_push(void* pdata)
{
	if (stack_size(top) == max_size)
	{
		my_mess_fun(MY_MESS_MEM_ALOC);
	}
	else if (top == NULL)
	{
		top=(struct stack*)malloc(sizeof(struct stack));
		if (!top)
		{
			my_mess_fun(MY_MESS_MEM_ALOC);
		}
		top->data = pdata;
		(*top).next = NULL;
	}
	else
	{
		struct stack* new_element = (struct stack*)malloc(sizeof(struct stack));
		if (!new_element)
		{
			my_mess_fun(MY_MESS_MEM_ALOC);
		}
		new_element->data = pdata;
		new_element->next = top;
		top = new_element;
	}
	return top;
}

struct stack stack_pop()
{
		struct stack x;
		if (!top)
		{
			x.data = NULL;
			x.next = NULL;
		}
		else
		{
			struct stack* ptrr = top->next;
			x.data = top->data;
			x.next = NULL;
			free(top);
			top = ptrr;
		}
		return x;
}

void free_stack()
{
	struct stack* p = top;
	struct stack* dsg = NULL;
	while (p)
	{
		(*p_free_data)(p->data);
		dsg = p;
		p = p->next;
		free(dsg);
	}
	top = NULL;
}

void *search_stack(void *search_data, comp_data comp_fun, int first_entry)
{
	static struct stack* p;
	struct stack* mp = NULL;
	if (first_entry)
	{
		p = top;
	}
	while (p)
	{
		if (!(*comp_fun)(p->data, search_data))
		{
			p = p->next;
		}
		else
		{
			mp = p;
			p = p->next;
			return mp->data;
		}
	}
	return NULL;
}

void *stack_show(int first_entry)

{
	static struct stack* show_ele;
	struct stack* z = NULL;
	if (first_entry)
	{
		show_ele = top;
	}
	while (show_ele)
	{
		z = show_ele;
		show_ele = show_ele->next;
		return z->data;
	}
	return NULL;
}

void save_stack()
{
	struct stack* p = top;
	struct stack* psave = NULL;
	int iter=0;

	while (p)
	{
		psave = p;
		p = p->next;
		iter++;
	}

	remove("stos.bin");
	FILE* f;
	f = fopen("stos.bin", "wb");
	if (!f)
	{
		my_mess_fun(MY_MESS_OPEN_FILE_ERR);
		return;
	}
	fwrite(&iter, sizeof(int), 1, f);
	
	int iter2 = 0;
	p = top;
	while (iter2 < iter)
	{
		const char* lastname = student_lastname(p->data);
		int year = student_year(p->data);
		enum Study study = student_study(p->data);

		fwrite(lastname, 128 * sizeof(char), 1, f);
		fwrite(&year, sizeof(int), 1, f);
		fwrite(&study, sizeof(enum Study), 1, f);
		p = p->next;
		iter2++;
	}
	fclose(f);
}

void inverse_stack()
{
	struct stack* p_last = NULL;
	struct stack* trp = top;

	while (trp)
	{
		struct stack* element = (struct stack*)malloc(sizeof(struct stack));
		if (!element)
		{
			my_mess_fun(MY_MESS_MEM_ALOC);
		}
		element->next = p_last;
		element->data = trp->data;
		p_last = element;
		trp = trp->next;
	}
	top = p_last;
}

void read_stack()
{
	free_stack();
	FILE* f;
	f = fopen("stos.bin", "rb");
	if (!f)
	{
		my_mess_fun(MY_MESS_OPEN_FILE_ERR);
		return;
	}
	int iter, iter2 = 0;
	fread(&iter, sizeof(int), 1, f);

	while (iter2 < iter)
	{
		char lastname[128];
		int year;
		enum Study study;
		fread(lastname, 128 * sizeof(char), 1, f);
		fread(&year, sizeof(int), 1, f);
		fread(&study, sizeof(enum Study), 1, f);

		void* p_data = student_push(year, lastname, study);
		if (!stack_push(p_data))
		{
			my_mess_fun(MY_MESS_STUD_PROB);
		}
		iter2++;
	}
	fclose(f);
	inverse_stack();
}