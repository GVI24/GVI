#include <stddef.h>

void unsafe_copy(char *dest, const char *src, size_t dest_size) {
    size_t i;
    for (i = 0; src[i] != '\0'; i++) {
        if (i == dest_size) {
            break; // Break at the size limit but no space for null-terminator
        }
        dest[i] = src[i];
    }
    dest[i] = '\0'; // Possible buffer overflow here if i == dest_size
}