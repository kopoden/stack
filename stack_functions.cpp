#include <stdlib.h>
#include <stdio.h>
#include "stack_functions.h"
//===========================================================
/*! \def    dumper( buf_counter ,  buffer )
    \brief  Crashes program, saving data in "dump.txt", if there is no free memory.
*/
//===========================================================
#define dumper( buf_counter ,  buffer ) do {                                                                 \
    FILE* dump = fopen("dump.txt", "a");                                         \
    fprintf(dump, "\n");\
    if (buffer != 0 ) for (long int i = 0; i < buf_counter; i++) fprintf(dump, "%lg ", buffer[i]);\
    fprintf(dump, "\n");\
                                                                                 \
    switch (stack_errno) {                                                       \
        case ERR_MEM:                                                            \
            fprintf(dump, "%s in %s, %s ( %d )", "NOT ENOUGH MEMORY TO ALOCATE", \
                                   __PRETTY_FUNCTION__,                          \
                                   __FILE__, __LINE__ );                         \
            abort();                                                             \
        case OUT_OF_STACK:                                                       \
            fprintf(dump, "%s in %s, %s ( %d )", "POINTER IS OUT OF STACK",      \
                                   __PRETTY_FUNCTION__,                          \
                                   __FILE__, __LINE__ );                         \
            break;                                                             \
        case EMPTY:                                                              \
            fprintf(dump, "%s in %s, %s ( %d )", "STACK IS EMPTY. IMPOSSIBLE TO POP", \
                                   __PRETTY_FUNCTION__,                               \
                                   __FILE__, __LINE__ );                              \
            break;                                                                  \
        default:                                                                      \
            break;                                                                    \
    }                                                                                 \
    fclose(dump);                                                                     \
    dump = 0;                                                                         \
} while (0);                       \


int stack_errno = OK;
//======================================================
void stack_ctor (STACK_t* new_stack) {

    stack_errno = OK;
    new_stack->stack_arr = (double*) calloc (EMPTY, sizeof(double)); // Empty stack
    new_stack->counter = EMPTY; // Zero element

    if (new_stack->stack_arr == 0) { //Not enough memory to allocate
        free(new_stack->stack_arr);
        double* buffer = 0;
        long int buf_counter = 0;
        stack_errno = ERR_MEM;
        dumper(buf_counter, buffer);
    }

    return;
}
//======================================================

//======================================================
void push (STACK_t* Stack, double element) {

    stack_errno = stack_ok(Stack);
    if (stack_errno == OUT_OF_STACK) {
        return;
    }

    double* buffer = Stack->stack_arr;
    long int buf_counter = Stack->counter;

    Stack->counter++;
    Stack->stack_arr = (double*) realloc (Stack->stack_arr, sizeof(double) * Stack->counter);

    stack_errno = stack_ok(Stack);
    if (stack_errno == OUT_OF_STACK) { //Lack of memory
        free(Stack->stack_arr);
        Stack->stack_arr = 0;
        stack_errno = ERR_MEM;
        dumper(buf_counter, buffer);
    }

    Stack->stack_arr[Stack->counter - 1] = element;

    return;
}
//======================================================

//======================================================
double pop (STACK_t* Stack) {

    stack_errno = stack_ok(Stack);

    if (stack_errno != OK)
        return CANT_POP;

        double output = Stack->stack_arr[Stack->counter - 1];

        double* buffer = Stack->stack_arr;
        long int buf_counter = Stack->counter;

        Stack->counter--;

        //Realloc frees the stack if gets zero size. So after the first push it has a minimal size of 1 element.
        if (Stack->counter == 0)
            Stack->stack_arr = (double*) realloc (Stack->stack_arr, sizeof(double) * (Stack->counter+1));
        else
            Stack->stack_arr = (double*) realloc (Stack->stack_arr, sizeof(double) * Stack->counter);

    stack_errno = stack_ok(Stack);
    if (stack_errno == OUT_OF_STACK) {
        dumper(buf_counter, buffer);
    }

        return output;
}
//======================================================

//======================================================
void insrt (STACK_t* Stack, long int position, double element) {

    stack_errno = stack_ok(Stack);
    if (stack_errno == OUT_OF_STACK) {
        return;
    }

    if ((position > Stack->counter) || (position < 0)) {
        stack_errno = OUT_OF_STACK; // Impossible to insert into these positions.
        return;
    }

    double* buffer = Stack->stack_arr;
    long int buf_counter = Stack->counter;

    Stack->counter++;
    Stack->stack_arr = (double*) realloc (Stack->stack_arr, sizeof(double) * Stack->counter);

    stack_errno = stack_ok(Stack);
    if (stack_errno == OUT_OF_STACK) {
        stack_errno = ERR_MEM;
        dumper(buf_counter, buffer);
        return;
    }

    for (long int END = Stack->counter - 1; END >= position; END--)
        Stack->stack_arr[END] = Stack->stack_arr[END - 1];

    Stack->stack_arr[position] = element;

    return;
}
//======================================================

//======================================================
int stack_ok (STACK_t* Stack) {

    if ((Stack->counter < 0) || (Stack->stack_arr == 0))
        return OUT_OF_STACK; //Stack is spoiled (can't push and pop)

    if ((Stack->counter == 0) && (Stack->stack_arr > 0))
        return EMPTY;   //Stack is empty(can't pop, but still can push).

        return OK;      //Stack is fully workable.
}
//======================================================

//======================================================

void stack_dtor(STACK_t* Stack) {

    free(Stack->stack_arr);

    Stack->stack_arr = 0;               // Spoil the stack to prevent future incorrect using.
    Stack->counter = SPOIL_THE_COUNTER;     //

    return;
}
//=====================================================

