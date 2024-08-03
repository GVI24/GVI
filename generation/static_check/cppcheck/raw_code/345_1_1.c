#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool validate_username(const char *input) {
    char username_buffer[32];

    // Vulnerable pattern: potential overflow if input is too large
    sprintf(username_buffer, "Username: %s", input);

    // Fake validation for demonstration purposes
    return strlen(username_buffer) > 0;
}