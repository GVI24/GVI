#include <stdio.h>
#include <stdlib.h>

void free_memory(void *ptr) {
    free(ptr);
}

void use_memory(char *ptr) {
    printf("Using memory: %s\n", ptr);
}

int main() {
    char *data = (char *)malloc(100);
    sprintf(data, "Sample data");
    free_memory(data); // Memory is freed here
    use_memory(data); // Use after free vulnerability, as the memory was already freed
    return 0;
}