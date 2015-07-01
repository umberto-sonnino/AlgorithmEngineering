#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char** argv) {

	unsigned i, n;
	stack* q;

	/* check command line parameters */
	if (argc < 2) exit((printf("usage: %s num-items seed\n", argv[0]), 1));

	/* get command line parameter */
	n = atoi(argv[1]);

	/* set random generator seed */
	srand(atoi(argv[2]));

	/* create empty stack */
	q = stack_new();

	/* add n items to stack */
	for (i=0; i<n; i++) stack_push(q, i);

	/* perform random sequence of 3n push/pop operations on stack */
	for (i=0; i<3*n; i++)
	    if (rand() % 2)
	         stack_push(q, i);   
	    else stack_pop(q);

	/* deallocate stack */
	stack_delete(q);

	return 0;
}