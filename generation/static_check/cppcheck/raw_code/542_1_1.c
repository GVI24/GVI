#include <stdio.h>

typedef struct {
    char *data;
    unsigned int size;
} Buffer;

/* Unsafe function that writes to a buffer without checking for a null pointer */
void write_to_buffer(Buffer *buffer, const char *data) {
    if (data == NULL) {
        // Only checks if the data is null, not the buffer
        return;
    }

    // Null pointer dereference vulnerability: buffer may be NULL
    for (unsigned int i = 0; i < buffer->size; i++) {
        buffer->data[i] = data[i]; // Potential null pointer dereference if buffer is NULL
    }
}

// Usage example
int main() {
    Buffer *buf = NULL; // buf is not allocated
    const char *data = "Sample data";

    write_to_buffer(buf, data); // This will cause a null pointer dereference

    return 0;
}