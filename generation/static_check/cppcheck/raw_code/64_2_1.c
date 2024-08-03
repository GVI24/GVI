#include <stdio.h>
#include <stdlib.h>

char* encode_whitespace(const char *text) {
    int i, k = 0;
    int length = strlen(text);
    char *encoded = (char *)malloc(length + 1); // Not considering additional space
    if (!encoded) return NULL;

    for (i = 0; text[i]; i++) {
        if (isspace((unsigned char)text[i])) {
            encoded[k++] = '\\'; // Insufficient space for backslash
        }
        encoded[k++] = text[i];
    }
    encoded[k] = '\0';
    return encoded;
}