extern int stack_errno;
enum constants {
    EMPTY,              ///< Stack is empty.
    ERR_MEM,            ///< There is no enough memory to allocate.
    OUT_OF_STACK,       ///< Counter point at the segment is out of stack
    OK                 ///< Successful action.
};
const double CANT_POP = -9999;
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
/*! \fn     void stack_ctor (STACK_t* new_stack);
    \brief  Creates new stack.
*/
void stack_ctor (STACK_t* new_stack);
//==================================================================

//==================================================================
/*! \fn     void push (STACK_t* Stack, double element);
    \brief  Pushes the value onto the stack.

    \param      Stack       Stack pointer
    \param      element     Value to be pushed
*/
void push (STACK_t* Stack, double element);
//==================================================================

//==================================================================
/*! \fn     double pop (STACK_t* Stack);
    \brief  Gets the number from the stack.

    \param      Stack       Stack pointer
*/
double pop (STACK_t* Stack);
//==================================================================

//==================================================================
/*! \fn     void insrt (STACK_t* Stack, long int position, double element);
    \brief  Puts the number in any part of the stack.

    \param      Stack       Stack pointer
    \param      position    Position to insert
    \param      element     Value to be pushed
*/
void insrt (STACK_t* Stack, long int position, double element);
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
void stack_dtor(STACK_t* Stack);
