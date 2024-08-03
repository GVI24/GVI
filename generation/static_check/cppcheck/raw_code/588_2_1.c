#include <stdio.h>
#include <stdlib.h>

#define DATA_SIZE 128

int example3_copy_data(void) {
    char *source = (char *)malloc(DATA_SIZE);
    char *destination = (char *)malloc(DATA_SIZE);

    if (source == NULL || destination == NULL) {
        // Resource leak: If one malloc fails after the other succeeds,
        // the successful allocation isn't freed
        free(source); // May be NULL
        free(destination); // May be NULL
        return -1;
    }

    // Buffer Overflow: Writing beyond the buffer size
    for (int i = 0; i <= DATA_SIZE; i++) { 
        source[i] = (char)(rand() % 256);
    }

    memcpy(destination, source, DATA_SIZE);

    free(source);
    free(destination);
    return 0;
}