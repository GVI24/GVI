// Example 2: Vulnerable Function for Handling File Paths
char *extract_filename(char *path) {
    char *cursor, *start;
    cursor = path;

    // Find the last directory separator
    while (*cursor) {
        if (*cursor == '/' || *cursor == '\\') {
            start = cursor + 1;
        }
        cursor++;
    }

    // Check if the filename starts with a special char
    if (*start == '.' || *start == '~') {
        start++;
    }

    // Vulnerable part: No bounds checking when removing escape characters
    cursor = start;
    while (*cursor) {
        if (*cursor == '\\' && *(cursor + 1)) {
            memmove(cursor, cursor + 1, strlen(cursor)); // Unsafe use of memmove without bounds checking
        }
        cursor++;
    }

    return start;
}