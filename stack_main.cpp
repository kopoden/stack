#include <stdio.h>
#include <stdlib.h>

#include "stack_functions.h"

int main() {

    STACK_t numbers;
    printf("%d - check says stack was constructed successfully.\n", stack_ctor(&numbers));
    //Check push and pop in ordinary situation.
    push(&numbers, 19.96);
    printf("push <- 19.96\n");
    printf("%d - check says stack is not empty and is able to work.\n", stack_ok(&numbers));
    printf("pop -> %lg\n", pop(&numbers));
    //Check insert, and pop, when
    push(&numbers, 10);
    printf("push <- 10\n");
    push(&numbers, 20);
    printf("push <- 20\n");
    insrt(&numbers, 2, 7);
    printf("insrt 2 <- 7\n");
    printf("pop -> %lg\n", pop(&numbers));
    printf("pop -> %lg\n", pop(&numbers));
    printf("pop -> %lg\n", pop(&numbers));
    //Now, stack is empty.
    printf("%ld - counter\n", numbers.counter);
    printf("%d - stack_ok, stack is empty.\n", stack_ok(&numbers));
    printf("%d - insert in incorrect place (=EACCESS)\n", insrt(&numbers, -1, 123));
    double a = 111;
    a = pop(&numbers);
    printf("%lg - result of getting value from empty stack\n", a);

    return 0;
}
