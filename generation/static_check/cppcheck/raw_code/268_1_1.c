#include <string.h>

void string_shuffle(char *str) {
    size_t len = strlen(str);
    for (size_t i = 0; i < len; i++) {
        size_t j = rand() % len; // Insecure use of rand()
        char temp = str[i];
        str[i] = str[j]; // Potential buffer overflow if i or j is not within the bounds of the string
        str[j] = temp;
    }
}