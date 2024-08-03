#include <stdio.h>

void format_string_vulnerability_example(char *user_input) {
    char buffer[100];
    snprintf(buffer, sizeof(buffer), user_input); // Unsafe use of user input in format string
    // The code should use a format specifier like snprintf(buffer, sizeof(buffer), "%s", user_input);
}