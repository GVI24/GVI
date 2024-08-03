#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_user_data(FILE *input) {
    char *data_buffer;
    size_t buffer_length = 1024;
    size_t data_size;

    data_buffer = (char *)malloc(buffer_length); // No check for malloc failure
    if (fgets(data_buffer, buffer_length, input)) {
        // Unsafe string manipulation leading to potential overflow
        strcat(data_buffer, " processed");
        printf("%s\n", data_buffer);
    }
    free(data_buffer);
}