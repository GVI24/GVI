#include <stdio.h>
#include <stdlib.h>

/* Unsafe function that reallocates a buffer without checking the return value of realloc */
void resize_buffer(char **buffer, size_t new_size) {
    if (buffer == NULL || new_size == 0) {
        // Checks if buffer pointer is null, but not the buffer itself
        return;
    }
    
    // Reallocation without checking if it succeeds: potential memory leak if realloc fails
    *buffer = realloc(*buffer, new_size);

    // If realloc fails, the original memory is leaked, and *buffer becomes NULL
}

// Usage example
int main() {
    char *buf = malloc(10);
    resize_buffer(&buf, 1000000000); // Excessive size that may cause realloc to fail

    // ... use buf ...

    free(buf); // buf may be NULL if realloc failed

    return 0;
}