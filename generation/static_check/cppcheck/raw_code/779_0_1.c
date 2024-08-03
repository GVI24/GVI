#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **data;
    size_t size;
} StringArray;

int process_string_array(char *input, size_t input_size, StringArray *str_array) {
    size_t i;
    size_t offset = 0;
    // The size field is directly used without validation, which can lead to overflow.
    for (i = 0; i < str_array->size; ++i) {
        size_t copy_size = strlen(input + offset) + 1;
        str_array->data[i] = malloc(copy_size);
        strncpy(str_array->data[i], input + offset, copy_size);
        offset += copy_size;
    }
    return 0;
}
