static void sanitizeInputForSQL(char *input) {
    char *iter;
    // Replacing single quotes with two single quotes to prevent SQL injection
    // (This is an overly simplistic approach and should not be used for real SQL sanitization)
    while ((iter = strchr(input, '\'')) != NULL) {
        // Potential buffer overrun if not enough space for additional character
        memmove(iter + 1, iter, strlen(iter));
        *iter = '\'';
        *(iter + 1) = '\'';
        iter += 2;
    }
}