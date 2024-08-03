#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void copy_data(const char *src, size_t count) {
    // Vulnerability: count can be larger than MAX_BUFFER_SIZE
    char *buffer = (char *)malloc(count);
    if (buffer == NULL) {
        // Handle allocation failure
        return;
    }

    // Vulnerability: No bounds checking on count, can lead to buffer overflow
    memcpy(buffer, src, count); 

    // ... Do something with the buffer ...

    free(buffer);
}