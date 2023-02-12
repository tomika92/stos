#ifndef MY_STACK_AD__H
#define MY_STACK_AD__H

typedef struct stack
{
	void *data;
	struct stack* next;
};

typedef int (comp_data)(void* cur_data, void* search_data);
typedef void (*FreeData)(void* pdat);

void create_stack(FreeData Free);
//int stack_size(struct stack* top);
void *stack_push(void* pdata);
struct stack stack_pop();
void free_stack();
void* search_stack(void* search_data, comp_data comp_fun, int first_entry);
void *stack_show(int first_entry);
void save_stack();
//void inverse_stack();
void read_stack();
#endif