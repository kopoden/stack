#include "stack_functions.h"

//===========================================================
void stack_ctor (STACK_t* new_stack) {
    new_stack->stack_arr = NULL;
    new_stack->counter = 0; // Empty stack. Counter points to the zero element
    new_stack->max_size = 0;

    return; // Stack constructed
}
//======================================================

//======================================================
int push (STACK_t* Stack, data_t* Struct) {

    int check = stack_state(Stack);

    if (check == FULL)
        return FULL;

    if (check == OUT_OF_STACK)
        return OUT_OF_STACK;

    memcpy(&Stack->stack_arr[Stack->counter], Struct, sizeof(data_t));
    Stack->counter++;
    return OK;
}
//======================================================

//======================================================
int pop (STACK_t* Stack, data_t* Struct) {

    int check = stack_state(Stack);

    if (check == EMPTY)
        return EMPTY;

    if (check == OUT_OF_STACK)
       return OUT_OF_STACK;

    Stack->counter--;
    memcpy(Struct, &Stack->stack_arr[Stack->counter], sizeof(data_t));
    
    return OK;
}
//======================================================
int stack_resize (STACK_t* Stack, int Size) {
    
    if (Stack->stack_arr == NULL && (Stack->max_size != 0 || Stack->counter != 0))
        return OUT_OF_STACK;

    if (Stack->stack_arr == NULL)
        Stack->stack_arr = (data_t*) calloc (Size, sizeof(data_t));
    else
        Stack->stack_arr = (data_t*) realloc (Stack->stack_arr, sizeof(data_t) * Size);
        
    if (Stack->stack_arr == NULL && Size != 0) {
        free(Stack->stack_arr);
        return ERR_MEM;
    }

    Stack->max_size = Size;

    return OK;
}
//======================================================
//======================================================
int insrt (STACK_t* Stack, int position, data_t* Struct) {

    if ((position < 0) && (position >= Stack->max_size))
        return OUT_OF_STACK;

    int check = stack_state(Stack);

    if (check == OUT_OF_STACK)
        return OUT_OF_STACK;

    if (check == FULL)
        return FULL;

    Stack->counter++;

    for (int END = Stack->counter - 1; END > position; END--) {
        strcpy(Stack->stack_arr[END].String, Stack->stack_arr[END - 1].String);
        Stack->stack_arr[END].last = Stack->stack_arr[END - 1].last;
    }

    memcpy(&Stack->stack_arr[position], Struct, sizeof(data_t));
    
    return OK;
}
//======================================================

//======================================================
int stack_state (STACK_t* Stack) {

    if ((Stack->counter < 0) || (Stack->stack_arr == 0) || (Stack->counter > Stack->max_size))
        return OUT_OF_STACK;//Stack is spoiled (can't push and pop)

    if (Stack->counter == Stack->max_size)
        return FULL;

    if ((Stack->counter == 0) && (Stack->stack_arr > 0))
        return EMPTY;//Stack is empty(can't pop, but still can push).

    return OK;//Stack is fully workable.
}
//======================================================

//======================================================

void stack_dtor(STACK_t* Stack) {

    free(Stack->stack_arr);
    Stack->stack_arr = NULL;

    return;
}
//=====================================================

