#ifndef _STACK_FUNCTIONS_INCL_
#define _STACK_FUNCTIONS_INCL_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum constants {
    OK,                 ///< Successful action.
    EMPTY,              ///< Stack is empty.
    FULL,               ///< Stack is full.
    ERR_MEM,            ///< There is no enough memory to allocate.
    OUT_OF_STACK,       ///< Counter point at the segment is out of stack or pointer of stack array = 0.
    TOO_LONG,           ///< The string is too long to be pushed onto the stack.
    TOO_SHORT           ///< The string is too short to accept information from the stack.
};

//==================================================================
/*! \struct STACK_t

    \param  stack_arr   Stack pointer
    \param  counter     Current number of elements in stack
*/
#define STR_LNG 100

typedef struct {
    char String[STR_LNG];
    int last;
} data_t;

struct STACK_t {
    data_t* stack_arr;
    int counter;
    int max_size;
};
//==================================================================
/*! \fn     void stack_ctor (STACK_t* new_stack);
    \brief  Creates new stack.
*/
void stack_ctor ( STACK_t* new_stack );
//==================================================================

//==================================================================
/*! \fn     int push (STACK_t* Stack, data_t* Struct);
    \brief  Pushes the value onto the stack.

    \param      Stack       Stack pointer
    \param      value     Value to be pushed
*/
int push (STACK_t* Stack, data_t* Struct);
//==================================================================

//==================================================================
/*! \fn     int pop (STACK_t* Stack, data_t* Struct);
    \brief  Gets the number from the stack.

    \param      Stack       Stack pointer
*/
int pop (STACK_t* Stack, data_t* Struct);
//==================================================================
//==================================================================
int stack_resize (STACK_t* Stack, int Size);
//==================================================================
//==================================================================
/*! \fn     int insrt (STACK_t* Stack, int position, data_t* Struct);
    \brief  Puts the number in any part of the stack.

    \param      Stack       Stack pointer
    \param      position    Position to insert
    \param      Sting       Value to be pushed
*/
int insrt (STACK_t* Stack, int position, data_t* Struct);
//==================================================================

//==================================================================
/*! \fn     int stack_state (STACK_t* Stack);
    \brief  Checks stack's validity.

    \param      Stack       Stack pointer
*/
int stack_state (STACK_t* Stack);
//==================================================================

//==================================================================
/*! \fn     void stack_dtor(STACK_t* Stack);
    \brief  Erases the content of stack.

    \param      Stack       Stack pointer
*/
void stack_dtor(STACK_t* Stack);
#endif

