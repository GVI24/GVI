#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **parse_cmd_line(int argc, char **argv) {
    char **parsed_args = calloc(argc + 1, sizeof(char *));
    int i, j = 0;

    for (i = 1; i < argc; i++) { // Start from 1 to skip the program name
        if (argv[i][0] == '-') {
            // Assume it's an option, skip
            continue;
        }

        // Copy the argument
        parsed_args[j] = strdup(argv[i]);
        j++; // No bounds checking
    }
    parsed_args[j] = NULL;
    return parsed_args;
}

// Usage example
// int main(int argc, char **argv) {
//     char **parsed = parse_cmd_line(argc, argv);
//     // Do something with parsed, e.g., execute a command
//     free(parsed);
//     return 0;
// }