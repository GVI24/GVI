#include <stdio.h>
#include <stdlib.h>

typedef struct {
    FILE *file;
    char *buffer;
    int bufferSize;
} SimpleFileWrapper;

SimpleFileWrapper* createSimpleFileWrapper(const char *filePath, int bufferSize) {
    SimpleFileWrapper *wrapper = (SimpleFileWrapper *)malloc(sizeof(SimpleFileWrapper));
    if (wrapper == NULL) {
        return NULL;
    }

    wrapper->file = fopen(filePath, "r");
    if (wrapper->file == NULL) {
        // Missing: free(wrapper);
        return NULL;
    }

    wrapper->buffer = (char *)malloc(bufferSize);
    if (wrapper->buffer == NULL) {
        // Missing: fclose(wrapper->file); free(wrapper);
        return NULL;
    }
    wrapper->bufferSize = bufferSize;

    return wrapper;
}
