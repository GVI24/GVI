// Example 1: Vulnerable Function Parsing Environment Variables
char *get_env_var(char *env_line) {
    char *cursor, *start;
    char env_delimiter = '=';
    cursor = env_line;

    while (*cursor && *cursor != env_delimiter) {
        cursor++;
    }

    if (*cursor == env_delimiter) {
        cursor++;
    } else {
        return NULL; // No delimiter found, not a valid env line
    }

    // Skip any whitespace after the delimiter
    while (*cursor == ' ') {
        cursor++;
    }

    if (*cursor == '\"' || *cursor == '\'') {
        char quote_char = *cursor;
        cursor++; // Skip the quote
        start = cursor;

        // Vulnerable part: No bounds checking
        while (*cursor && *cursor != quote_char) {
            if (*cursor == '\\' && *(cursor + 1)) {
                strcpy(cursor, cursor + 1); // Unsafe use of strcpy without bounds checking
            }
            cursor++;
        }
    } else {
        start = cursor;
        while (*cursor && *cursor != ' ') {
            cursor++;
        }
    }

    // Null-terminate the value
    if (*cursor) *cursor = '\0';
    return start;
}