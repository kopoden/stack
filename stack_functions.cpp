#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

#include "stack_managment.h"


//======================================================
int stack_ctor (STACK_t* new_stack) {

    new_stack->stack_arr = (double*) malloc (EMPTY * sizeof(double));
    new_stack->counter = EMPTY;
    if (new_stack->stack_arr == 0)
        return ENOMEM;

    return CONSTRUCTED; // Empty stack constructed.
}
//======================================================

//======================================================
int push (STACK_t* Stack, double element) {
    errno = 0;
    Stack->counter++;
    Stack->stack_arr = (double*) realloc (Stack->stack_arr, sizeof(double) * Stack->counter);
    if (errno == ENOMEM)
        return ENOMEM;  // Lack of memory.
    Stack->stack_arr[Stack->counter - 1] = element;

    return PUSH_OK; // Value has been successfully pushed.
}
//======================================================

//======================================================
double pop (STACK_t* Stack) {
    errno = 0;
    if (Stack->counter > 0) {

        double output = Stack->stack_arr[Stack->counter - 1];
        Stack->counter--;
        Stack->stack_arr = (double*) realloc (Stack->stack_arr, sizeof(double) * Stack->counter);
        return output;

    }
    errno = EACCES; // Out of array, or there are no available elements.
    return CANT_POP;// Stack is empty. Nothing is able to pop.
}
//======================================================

//======================================================
int insrt (STACK_t* Stack, long int position, double element) {
    errno = 0;

    if ((position > Stack->counter) || (position < 0)) {
        errno = EACCES; // Impossible to insert into these positions.
        return EACCES;
    }

    Stack->counter++;
    Stack->stack_arr = (double*) realloc (Stack->stack_arr, sizeof(double) * Stack->counter);

    for (long int END = Stack->counter - 1; END >= position; END--)
        Stack->stack_arr[END] = Stack->stack_arr[END - 1];

    Stack->stack_arr[position - 1] = element;

    return INSRT_OK; // Function was made correctly.
}
//======================================================

//======================================================
int stack_ok (STACK_t* Stack) {
    errno = 0;
    if ((Stack->counter < 0) || (Stack->stack_arr < 0))
        return SPOILED; //Stack is spoiled (can't push and spoil)
    if (Stack->counter == 0)
        return EMPTY;   //Stack is empty(can't pop, but still can push).

        return OK;      //Stack is fully workable.
}
//======================================================

//======================================================

int stack_dtor(STACK_t* Stack) {

    free(Stack->stack_arr);

    Stack->stack_arr = 0;                   // Spoil the stack to prevent future incorrect using.
    Stack->counter = SPOIL_THE_COUNTER;     //

    int check = stack_ok(Stack); //Check the result of stack_dtor.

    if ((check == EMPTY) || (check == OK))
        return STILL_WORKS; // Stack is OK. Destructor does not work.

    return DESTRUCTED; //Stack is successfully cleared and blocked.
}
