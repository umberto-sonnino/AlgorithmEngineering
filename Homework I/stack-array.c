#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct stack {
	int top;
	int* pila;
	int maxSize;
	};

stack* stack_new(){
	stack* s;
	
	s = (stack*)malloc(sizeof(stack));
	if(s==NULL){
		fprintf(stderr, "Non ho abbastanza memoria!.\n");
		exit(1);
	}
	
	s->maxSize = 1000;
	s->pila = calloc(s->maxSize, sizeof(int));
	s->top = -1; //pila vuota
	
	return s;
}

void stack_delete(stack* s){
	if(s != NULL){
		free(s->pila);
		free(s);
	}
}
void stack_push(stack* s, int item){
	if(s->top+1 == s->maxSize){
		//~ printf("maxSize sta cambiando da %d", s->maxSize);
		s->maxSize = (s->maxSize)+((s->maxSize)/2);
		//~ printf(" a %d\n", s->maxSize);
		s->pila = realloc(s->pila, s->maxSize*sizeof(int));
	}
	//~ printf("inizio a push\n");
	s->top++;
	s->pila[s->top] = item;
		
}
int stack_pop(stack* s){
	int item = s->pila[s->top];
	s->top--;
	return item;
}
int stack_top(stack* s){
	if(s->top >= 0){
		return s->pila[s->top];
	}
	else
		return -1;
}
int stack_is_empty(stack* s){
	if(s->top == -1){
		return 1;
	}
	else{
	return 0;
	}
}

