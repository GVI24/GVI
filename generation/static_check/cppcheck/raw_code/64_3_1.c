#include <stdlib.h>
#include <string.h>

char* translate_special_chars(const char *source) {
    size_t source_len = strlen(source);
    char *dest = malloc(source_len + 1); // Only allocates space for the original string length
    if (!dest) return NULL;

    size_t dest_idx = 0;
    for (size_t i = 0; i < source_len; i++) {
        switch (source[i]) {
            case '\n': // Newline
            case '\t': // Tab
            case '\r': // Carriage return
                dest[dest_idx++] = '\\'; // No extra space allocated for this
                // Fall through
            default:
                dest[dest_idx++] = source[i];
                break;
        }
    }
    dest[dest_idx] = '\0';
    return dest;
}