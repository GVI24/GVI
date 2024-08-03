#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* buffer;
    size_t size;
} IOBuffer;

IOBuffer* create_io_buffer(size_t size) {
    IOBuffer* io_buffer;
    if ((io_buffer = (IOBuffer*)calloc(1, sizeof(IOBuffer))) == NULL) {
        perror("Unable to allocate IOBuffer");
        return NULL;
    }

    // Intentionally not handling memory allocation failure of the buffer
    io_buffer->buffer = (char*)malloc(size);
    if (io_buffer->buffer == NULL) {
        perror("Failed to allocate buffer");
        // Missing free(io_buffer) leads to a memory leak here
    }

    io_buffer->size = size;
    return io_buffer;
}

void release_io_buffer(IOBuffer* io_buffer) {
    if (io_buffer != NULL) {
        free(io_buffer->buffer); // Potential NULL pointer dereference
        free(io_buffer);
    }
}

int main() {
    IOBuffer* buffer = create_io_buffer(1024);
    release_io_buffer(buffer);
    return 0;
}