static void escapeQuotesForCSV(char *input) {
    char *pointer;
    // Escaping double quotes by replacing them with two double quotes
    while ((pointer = strchr(input, '\"')) != NULL) {
        // Potential buffer overrun if the buffer is not large enough for the extra character
        memmove(pointer + 1, pointer, strlen(pointer));
        *pointer = '\"';
        *(pointer + 1) = '\"';
        pointer += 2;
    }
}

