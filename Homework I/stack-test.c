#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char** argv) {

	stack* s;

	/* create empty stack */
	s = stack_new();

	/* add items to stack */
	stack_push(s, 10);
	stack_push(s, 20);
	stack_push(s, 30);

	/* print first item (should print 30) */
	printf("%d\n", stack_top(s));

	/* remove items from stack (should print 30 20 10) */
	while (!stack_is_empty(s)) {
	    int item = stack_pop(s);
	    printf("%d\n", item);
	}

	/* deallocate stack */
	stack_delete(s);

	return 0;
}