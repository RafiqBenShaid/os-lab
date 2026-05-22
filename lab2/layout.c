#include <stdio.h>
#include <stdlib.h>

int global_var = 42;
int uninit_global;

int main(void)
{
    int local_var = 7;

    int *heap_var = malloc(sizeof(int));

    *heap_var = 99;

    printf("Code(main)        : %p\n", (void*)main);

    printf("Initialized Global: %p\n",
           (void*)&global_var);

    printf("Uninitialized BSS : %p\n",
           (void*)&uninit_global);

    printf("Heap Variable     : %p\n",
           (void*)heap_var);

    printf("Stack Variable    : %p\n",
           (void*)&local_var);

    free(heap_var);

    return 0;
}
