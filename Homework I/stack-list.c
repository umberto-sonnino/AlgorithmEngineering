#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct stack {
	int data;
	struct stack* next;
	};

int size;
stack* top;

stack* stack_new(){
	stack* s;
	s = malloc(sizeof(stack));
	top = s;
	size = 0;
	
	return s;
}
void stack_delete(stack* s){
	while(top!=NULL)
		stack_pop(s);
}
void stack_push(stack* s, int item){
	static stack* nodo;
	if(size == 0){
		top->data = item;
		size++;
		return;
	}
	nodo = calloc(sizeof(stack), 1);
	nodo->data = item;
	nodo->next = top;
	top = nodo;
	size++;
}
int stack_pop(stack* s){
	stack* fuori;
	int ris;
	
	if(size <= 0){
		return -1;
	}
	
	fuori = top;
	ris = fuori->data;
	top = top->next;
	
	free(fuori);
	size--;
	
	return ris;
	
}
int stack_top(stack* s){
	return top->data;
}
int stack_is_empty(stack* s){
	if(size==0){
		return 1;
	}
	return 0;
}
