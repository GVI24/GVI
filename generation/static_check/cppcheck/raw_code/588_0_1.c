#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

int example1_write_data(const char *filename) {
    char *buffer = (char *)malloc(BUFFER_SIZE);
    FILE *file = fopen(filename, "w");
    if (!file) {
        // Potential Resource Leak: buffer not freed if fopen fails
        return -1;
    }
    if (buffer == NULL) {
        fclose(file); // Correctly handling the file resource
        return -1;
    }

    // Potential Buffer Overflow: No bound checking when writing to the buffer
    for (int i = 0; i <= BUFFER_SIZE; i++) {
        buffer[i] = 'A' + (rand() % 26);
    }

    if (fwrite(buffer, 1, BUFFER_SIZE, file) != BUFFER_SIZE) {
        fclose(file);
        free(buffer); // Should handle errors properly
        return -1;
    }

    fclose(file);
    free(buffer);
    return 0;
}