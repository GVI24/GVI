#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **copy_string_array(char **source, size_t num_strings) {
    char **destination = malloc((num_strings + 1) * sizeof(char *));
    size_t i;

    for (i = 0; source[i] && i < num_strings; i++) {
        destination[i] = strdup(source[i]);
    }
    destination[i] = NULL; // This does not check for overflow if source has more than num_strings
    return destination;
}

// Usage example
// int main() {
//     char *strings[] = { "Hello", "World", NULL };
//     char **copied_strings = copy_string_array(strings, 2);
//     // Process copied_strings
//     free(copied_strings);
//     return 0;
// }