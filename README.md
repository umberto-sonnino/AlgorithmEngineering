# AlgorithmEngineering
Algorithm Engineering class

HOMEWORK I:

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

stack-perf.c takes as input a number n and a seed for the random number generator and will do the following things:
- creates an empty stack
- inserts n integers into the newly created stack
- random insertion/removal of 3n integers from the stack
- deletion of the stack with removal of all its elements 
 
Time of execution has been checked:
> gcc stack-perf.c stack-list.c -o stack-list-perf-O0
> time ./stack-list-perf-O0 10000000 971

A makefile is also present to satisfy the following:
- compile the test program in different version, in particular it produces two different executables for each of three implementations compiling with -O0 and -O3;
- make test: executes each test on three stacks with various million elements generated starting from the same seed (try to choose the highest possible number before the machine will resort to swapping of memory onto the disk).

HOMEWORK II:

Build an algorithm that, given a square n x n matrix in row-major in a file, modifies the file transposing the matrix. The algorithm mustn't use temporary files and must perform with a number of I/Os IO(n,b,m) = O(n^2/b) with n the size of the matrix, b is the block dimension and m is the dimension of internal memory (assuming that m = Theta(b^2)).

Implement everything in C with the function:

void mat_transp(FILE* f, long n, long b) which given a pointer to a file containing the n x n matrix in row-major order, and a parameter b which defines the block size as the number of items to read from disk, modifies the file transposing the matrix. n should be a multiple of b. Manage eventual internal errors killing the program with an error message.

Test everything and the performance of the code using:
- mat-transp.h 
- mat-transp-Sonnino.c contains the implementation of the functions developed
- make-matrix-file.c contains the code to generate the file with squadre matrices in row-major
- mat-transp-perf.c is the file to test the performance of the transpositions
- check-mat-tansp.c will verify if a matrix created with make-matrix-file has been successfully transposed with mat-transp-perf
- makefile is the script which compiles and runs all the tests.
 
A number of tests can be found inside the makefile:
make test20000: measure transposition times for a 20000x20000(~1.5GB) file with block size b=2500,5000,10000,20000
make test30000: file ~3.4GB and b=2500,5000,10000,15000
and so on.

The tests must conducted in order to have a file that is bigger or slightly smaller than the current machine physical memory. The test must be conduceted to produce results that reflect real IO performance, avoiding buffered reads into RAM. If the test runs in RAM, the results won't be significant.
Moroever modify the b parameters according once again to the system's physical memory, in order to test appropriately without incurring into disk swapping for the block. If needed modify the b sizes, with the only requirement that n must be a multiple of b.
