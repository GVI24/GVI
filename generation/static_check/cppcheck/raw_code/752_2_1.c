static void ConvertToLowercase(const char *source, char *dest, int destSize, UErrorCode *err) {
    int i = 0;
    while (source[i] != '\0') {
        if (i >= destSize) {
            *err = U_BUFFER_OVERFLOW_ERROR;
            return;
        }
        if (source[i] >= 'A' && source[i] <= 'Z') {
            dest[i] = source[i] + ('a' - 'A');
        } else {
            dest[i] = source[i];
        }
        ++i;
    }
    if (i < destSize) {
        dest[i] = '\0';
    } else {
        // No space left for null-terminator in dest
        *err = U_MISSING_TERMINATOR_ERROR;
        return;
    }
}