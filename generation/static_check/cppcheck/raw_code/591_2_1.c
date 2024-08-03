#include <stdlib.h>

void use_after_free_example() {
    int *ptr = (int *)malloc(sizeof(int));
    *ptr = 10;
    free(ptr); // The pointer is freed here
    
    printf("%d\n", *ptr); // Using the pointer after it's freed
    // The above line may cause undefined behavior, including potential security vulnerabilities
}