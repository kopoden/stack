#include <stdio.h>
#include <stdlib.h>

#include "stack_functions.h"

int main() {
    STACK_t numbers;
    stack_ctor(&numbers);
    insrt(&numbers, 0, 0.123);
    insrt(&numbers, 0, 0.123);
    insrt(&numbers, 0, 0.123);
    push(&numbers, 1);
    insrt(&numbers, 0, 0.123);
    printf("%lg\n", pop(&numbers));
    printf("%lg\n", pop(&numbers));
    printf("%d == SUCCESSFUL ACTION\n", stack_errno);
    printf("%lg\n", pop(&numbers));
    printf("%lg\n", pop(&numbers));
    printf("%lg\n", pop(&numbers));
    push(&numbers, 890);
    //printf("%lg\n", pop(&numbers));
    stack_dtor(&numbers);
    printf("%d == OUT OF STACK", stack_ok(&numbers));
    return 0;
}
