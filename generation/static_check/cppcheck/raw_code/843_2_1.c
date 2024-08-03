#include <string.h>
#include <stdlib.h>

char *custom_strdup(const char *s) {
    size_t len = strlen(s);
    char *copy;

    // Vulnerable to integer overflow
    size_t total_size = len + 1;
    if (total_size <= len) {
        // Total size did not increment as expected
        return NULL;
    }
    
    copy = (char *)malloc(total_size);
    if (copy) {
        strcpy(copy, s);
    }
    return copy;
}