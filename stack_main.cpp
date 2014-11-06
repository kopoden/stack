#include "stack_functions.h"
//#include "stack_functions.h"

int main() {

    STACK_t strings;
    stack_ctor(&strings);
    
    printf("%p\n", strings.stack_arr);
    printf("%p\n", &strings);
    
    data_t structure;
    structure.last = 4;
    strcpy(structure.String, "Denis");

    if (stack_resize(&strings, 1024 * 1024 * 1024 / 104 * 2) == ERR_MEM) {
        printf("CAN'T ALLOCATE MEMORY\n");
        return 0;
    }
    else {
        printf("ALLOCATION SUCCESSFUL\n");

        for (int i = 0; i < 1024 * 1024 * 1024 / 104 * 2 - 1; i++) { // Test 2GB
            int check = push(&strings, &structure);

            if (check == FULL) {
                printf("STACK IS FULL\n");
                break;
            }
            if (check == OUT_OF_STACK) {
                printf("OUT OF STACK\n");
                break;
            }
        }
    }
    strcpy(structure.String, "Koposov");
    structure.last = 6;
    printf("%d - insert\n", insrt(&strings, 2, &structure));//insert test part 1

    data_t answer;
    answer.last = -1;
    strcpy(answer.String, "empty");

    pop(&strings, &answer);
    printf("%s %d - answer(fixed)\n", answer.String, answer.last); //after POP

    for (int i = 0; i < 10; i++)
    printf("%s %d\n", strings.stack_arr[i].String, strings.stack_arr[i].last);//insert test part 2

    stack_dtor(&strings);
    printf("%lu\n", sizeof(data_t));// size of 1 structure

    return 0;
}
