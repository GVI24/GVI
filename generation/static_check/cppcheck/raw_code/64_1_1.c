#include <stdio.h>
#include <stdlib.h>

char* escape_quotes(const char *str) {
    size_t i, j = 0;
    size_t len = strlen(str);
    char *result = (char *)malloc(len + 1); // Not enough space allocated
    if (!result) return NULL;

    for (i = 0; i < len; ++i) {
        if (str[i] == '"' || str[i] == '\'') {
            result[j++] = '\\'; // Escape character added without space reservation
        }
        result[j++] = str[i];
    }
    result[j] = '\0';
    return result;
}