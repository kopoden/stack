#include <stdio.h>
#include <stdlib.h>

#include "stack_functions.h"

int main() {
    STACK_t numbers;
    printf("%d - RES\n", stack_ctor(&numbers));
    printf("%d - POINTER\n", numbers.stack_arr);
    printf("%ld - COUNTER\n", numbers.counter);
    printf("%ld - MAX_SIZE\n", numbers.max_size);

    printf("%d - RES\n", stack_resize(&numbers, 100));
    printf("%d - NEW_POINTER\n", numbers.stack_arr);
    printf("%ld - COUNTER\n", numbers.counter);
    printf("%ld - NEW_MAX_SIZE\n", numbers.max_size);

    printf("%d\n", insrt(&numbers, 0, 0.123));
    insrt(&numbers, 0, 0.123);
    insrt(&numbers, 0, 0.123);
    push(&numbers, 689);
    insrt(&numbers, 0, 0.123);

    double value = -9;

    pop(&numbers, &value);
    printf("%lg\n", value);

    pop(&numbers, &value);
    printf("%lg\n", value);

    pop(&numbers, &value);
    printf("%lg\n", value);

    pop(&numbers, &value);
    printf("%lg\n", value);

    printf("%d\n", pop(&numbers, &value));
    printf("%lg\n", value);

    printf("%d\n", pop(&numbers, &value));
    printf("%lg\n", value);

    return 0;
}
