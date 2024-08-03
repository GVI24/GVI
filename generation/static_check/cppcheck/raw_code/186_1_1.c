void custom_strcat(char *dest, const char *src) {
    while (*dest) dest++; // Find end of dest
    while ((*dest++ = *src++)) { // Concatenate strings
        // No bounds checking, could lead to buffer overflow
    }
}

