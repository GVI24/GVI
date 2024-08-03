#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int copy_data(const char *src, size_t src_size) {
    size_t dest_size;
    char *dest;

    // Vulnerability: Arithmetic might overflow if src_size is close to SIZE_MAX
    dest_size = src_size + 1;
    
    dest = (char *)malloc(dest_size);
    if (dest == NULL) {
        // Error handling, but assume it succeeds for this example
    }

    // Vulnerability: Not checking if malloc failed before using the memory
    memcpy(dest, src, src_size); // Buffer overflow if src_size is too large
    dest[src_size] = '\0';       // Possible off-by-one error

    // Use dest for processing...

    free(dest);
    return 0;
}