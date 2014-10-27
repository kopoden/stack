#include <stdlib.h>
#include <stdio.h>

#include "stack_functions.h"
//===========================================================
int stack_ctor (STACK_t* new_stack) {

    long int GB2 = 268435456; // 2 GB/8 = 268435456 bytes

    new_stack->stack_arr = (double*) malloc (GB2 * sizeof(double)); // 2GB stack

    if (new_stack->stack_arr == 0) { //Not enough memory to allocate
        free(new_stack->stack_arr);
        return ERR_MEM;
    }
    new_stack->counter = 0; // Empty stack. Counter points to the zero element
    new_stack->max_size = GB2;

    return OK; // Stack constructed
}
//======================================================

//======================================================
int push (STACK_t* Stack, double element) {

    int check = stack_state(Stack);

    if (check == FULL)
        return FULL;

    if (check == OUT_OF_STACK)
        return OUT_OF_STACK;

    Stack->counter++;
    Stack->stack_arr[Stack->counter - 1] = element;

    return OK;
}
//======================================================

//======================================================
int pop (STACK_t* Stack, double* value) {

        int check = stack_state(Stack);

        if (check == EMPTY)
            return EMPTY;

        if (check == OUT_OF_STACK)
            return OUT_OF_STACK;

        Stack->counter--;
        *value = Stack->stack_arr[Stack->counter];

        return OK;
}
//======================================================
int stack_resize (STACK_t* Stack, long int SIZE) {

    int check = stack_state(Stack);
    if (check == OUT_OF_STACK)
        return OUT_OF_STACK;

    Stack->stack_arr = (double*) realloc (Stack->stack_arr, sizeof(double) * SIZE);

    if (Stack->stack_arr == 0) {
        free(Stack->stack_arr);
        return ERR_MEM;
    }

    Stack->max_size = SIZE;

    return OK;
}
//======================================================
//======================================================
int insrt (STACK_t* Stack, long int position, double element) {

    if ((position < 0) && (position >= Stack->max_size))
        return OUT_OF_STACK;

    int check = stack_state(Stack);

    if (check == OUT_OF_STACK)
        return OUT_OF_STACK;

    if (check == FULL)
        return FULL;

    Stack->counter++;

    for (long int END = Stack->counter - 1; END > position; END--)
        Stack->stack_arr[END] = Stack->stack_arr[END - 1];

    Stack->stack_arr[position] = element;

    return OK;
}
//======================================================

//======================================================
int stack_state (STACK_t* Stack) {

    if (Stack->counter == Stack->max_size)
        return FULL;

    if ((Stack->counter < 0) || (Stack->stack_arr == 0) || (Stack->counter > Stack->max_size))
        return OUT_OF_STACK; //Stack is spoiled (can't push and pop)

    if ((Stack->counter == 0) && (Stack->stack_arr > 0))
        return EMPTY;   //Stack is empty(can't pop, but still can push).

        return OK;      //Stack is fully workable.
}
//======================================================

//======================================================

int stack_dtor(STACK_t* Stack) {

    free(Stack->stack_arr);

    Stack->stack_arr = 0;               // Spoil the stack to prevent future incorrect using.
    Stack->counter = -99999999;          //
    Stack->max_size = -1;
    return OK;
}
//=====================================================

