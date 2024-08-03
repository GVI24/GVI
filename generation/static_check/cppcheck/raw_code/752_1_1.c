static void ConvertAsciiToHex(const char *input, char *output, int outputSize, UErrorCode *err) {
    const char *source = input;
    char *target = output;
    char *targetLimit = output + outputSize - 1; // Reserve space for NULL terminator

    while (*source && target < targetLimit) {
        unsigned char c = (unsigned char)(*source++);
        if (target + 2 >= targetLimit) {
            *err = U_BUFFER_OVERFLOW_ERROR;
            return;
        }
        sprintf(target, "%02X", c);
        target += 2;
    }

    if (*source) { // Input not fully converted due to insufficient space
        *err = U_BUFFER_OVERFLOW_ERROR;
    } else {
        *target = '\0'; // Proper null-termination if successful
    }
}