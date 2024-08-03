#include <stdio.h>
#include <stdlib.h>

bool read_file_data(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        // Error opening file
        return false;
    }

    unsigned long file_length;
    fread(&file_length, sizeof(file_length), 1, file);

    // Vulnerability: No validation of file_length
    char *content = (char *)malloc(file_length);
    if(content == NULL) {
        // Memory allocation failed
        fclose(file);
        return false;
    }

    fread(content, 1, file_length, file);

    // Process content...
    // ...

    free(content);
    fclose(file);
    return true;
}