void customStrcat(char *dest, const char *src, size_t destSize) {
    while (*dest) dest++;  // Find end of dest
    while ((*dest++ = *src++)) { // Copy src to end of dest
        if ((dest - destSize) >= 0) { // Off by one, should be "dest - destSize > 0"
            break;  // Potential buffer overflow as this condition is checked too late
        }
    }
}