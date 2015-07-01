#ifndef _STACK_H
#define _STACK_H

typedef struct node node;
typedef struct stack stack;


stack* stack_new();
void stack_delete(stack* s);
void stack_push(stack* s, int item);
int stack_pop(stack* s);
int stack_top(stack* s);
int stack_is_empty(stack* s);

#endif
