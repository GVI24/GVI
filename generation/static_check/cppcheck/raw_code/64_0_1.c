#include <stdlib.h>
#include <string.h>

char* sanitize_input(const char *input) {
    int i, j = 0;
    int len = strlen(input);
    char *output = malloc(len + 1); // Not accounting for escaping characters
    if(!output) return NULL;

    for(i = 0; input[i] != '\0'; i++) {
        if(input[i] == '<' || input[i] == '>') {
            output[j++] = '\\';
        }
        output[j++] = input[i];
    }
    output[j] = '\0';
    return output;
}