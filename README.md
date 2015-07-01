# AlgorithmEngineering
Algorithm Engineering class


Propose three different implementation of the ADT stack in C, writing:
- Header stack.h with the type declaration and functions to manipulate stacks of integers;
- stack-list.c with the complete type definition and the functions that implement the operations using a linked list (simple) to represent the stack;
- stack-array.c with the complete type definition and the functions that implement the operations using an array to represent the stack. The array will have a starting size of 1000 and will be widened by its 50% every time it is full.
- stack-unrolled-list.c contains the type definition and the functions that implement the operations using an unrolled linked list to represent the stack. Every node will have space for 1000 integers.

The implementation must have a stack type which represents stack objects with the following functions:
- stack* stack_new(): creates a new stack object with integers and returns the address;
- void stack_delete(stack* s): de-allocates the previously allocated object;
- void stack_push(stack *s, int item): adds an integer on top of the stack;
- void stack_pop(stack *s): if the stack is not empty, removes the first integer and returns it, otherwise it returns -1;
- int stack_top(stack *s): if the stack is not empty, it returns the first element (without removing it), otherwise returns -1;
- int stack_is_empty(stack *s): returns 1 if the stack is empty, 0 otherwise.

Valgrind's memcheck has been used to test the code and if it's working correctly.
