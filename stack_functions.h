enum stack_states {
    EMPTY,      ///< Stack is empty (function stack_ok)
    SPOILED,    ///< Stack is spoiled (function stack_ok)
    OK         ///< Stack is OK (function stack_ok)
};

enum res_of_deconstruction {
    DESTRUCTED, ///< Stack was destructed (function stack_dtor)
    STILL_WORKS ///< Stack was cleared incorrectly (function stack_dtor)
};

const int INSRT_OK = 0;    ///< Value was inserted without any problems.
const int CONSTRUCTED = 0; ///< Stack was constructed successfully.
const int PUSH_OK = 0;     ///< Element was pushed onto the stack

const double CANT_POP = 1; ///< Stack is empty. Nothing is able to pop.
const long int SPOIL_THE_COUNTER = -9999999; ///< Move the counter to the incorrect position.
//==================================================================
/*! \struct STACK_t

    \param  stack_arr   Stack pointer
    \param  counter     Current number of elements in stack
*/
struct STACK_t {
    double* stack_arr; ///
    long int counter;
};
//==================================================================
/*! \fn     int stack_ctor (STACK_t* new_stack);
    \brief  Creates new stack.
*/
int stack_ctor (STACK_t* new_stack);
//==================================================================

//==================================================================
/*! \fn     int push (STACK_t* Stack, double element);
    \brief  Pushes the value onto the stack.

    \param      Stack       Stack pointer
    \param      element     Value to be pushed
*/
int push (STACK_t* Stack, double element);
//==================================================================

//==================================================================
/*! \fn     double pop (STACK_t* Stack);
    \brief  Gets the number from the stack.

    \param      Stack       Stack pointer
*/
double pop (STACK_t* Stack);
//==================================================================

//==================================================================
/*! \fn     int insrt (STACK_t* Stack, long int position, double element);
    \brief  Puts the number in any part of the stack.

    \param      Stack       Stack pointer
    \param      position    Position to insert
    \param      element     Value to be pushed
*/
int insrt(STACK_t* Stack, long int position, double element);
//==================================================================

//==================================================================
/*! \fn     int stack_ok (STACK_t* Stack);
    \brief  Checks stack's validity.

    \param      Stack       Stack pointer
*/
int stack_ok (STACK_t* Stack);
//==================================================================

//==================================================================
/*! \fn     int stack_dtor(STACK_t* Stack);
    \brief  Erases the content of stack.

    \param      Stack       Stack pointer
*/
int stack_dtor(STACK_t* Stack);
