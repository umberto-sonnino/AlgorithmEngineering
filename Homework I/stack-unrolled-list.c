#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define MAX 10


struct stack {
	stack* next;//puntatore al prossimo elemento
	int num;//intero che tiene traccia della casella dell'array all'interno di questo nodo in cui ci troviamo
	int *pila; //array di interi contenente gli elementi
};
stack* top;

stack* stack_new(){
	stack* s;
	s = malloc(sizeof(stack));
	s->pila = calloc(MAX, sizeof(int));
	s->num = -1; //array vuoto
	top = s;
	
	return s;
}
void stack_delete(stack* s){
	stack* temp;
	while(top != NULL){
		temp = top;
		top = top->next;
		free(temp->pila);
		free(temp);
	}
}
void stack_push(stack* s, int item){
	stack* nodo;
	
	if(top->num == MAX-1){
		nodo = malloc(sizeof(stack));
		nodo->pila = calloc(MAX, sizeof(int));
		nodo->next = top;
		top = nodo;
		
		top->num = 0;
		top->pila[0] = item;
		
	}else{
		(top->num)++;
		top->pila[top->num] = item;
	}
	
}
int stack_pop(stack* s){
	int ris; 
	stack* aux;
	
	if(top == NULL){
		return -1;
	}
	ris = top->pila[top->num];
	top->num--;
	if(top->num < 0){
		aux = top;
		top = top->next;
		free(aux->pila);
		free(aux);
		return ris;
	}		
	return ris;
	
}
int stack_top(stack* s){
	return top->pila[top->num];
}
int stack_is_empty(stack* s){
	if(top==NULL || top->num < 0){
		return 1;
	}
	return 0;
}
