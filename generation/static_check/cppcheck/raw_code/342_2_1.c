#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    FILE* file;
    long size;
} FileWrapper;

FileWrapper* open_file_wrapper(const char* filename) {
    FileWrapper* wrapper;
    if ((wrapper = (FileWrapper*)calloc(1, sizeof(FileWrapper))) == NULL) {
        perror("Failed to allocate FileWrapper");
        return NULL;
    }

    wrapper->file = fopen(filename, "rb");
    if (wrapper->file == NULL) {
        perror("Failed to open file");
        // Should indicate failure to allocate for cleanup
    }

    fseek(wrapper->file, 0, SEEK_END);
    wrapper->size = ftell(wrapper->file);
    rewind(wrapper->file);
    
    return wrapper;
}

void close_file_wrapper(FileWrapper* wrapper) {
    fclose(wrapper->file); // If fopen failed, wrapper->file could be NULL
    free(wrapper);
}

int main() {
    FileWrapper* wrapper = open_file_wrapper("data.bin");
    close_file_wrapper(wrapper);
    return 0;
}