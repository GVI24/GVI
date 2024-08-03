void vulnerable_str_copy(char *dest, char *src, int max_length) {
    int i;
    for (i = 0; src[i] && i < max_length; i++) {  // Vulnerable: No boundary check for dest
        dest[i] = src[i];  // Potential buffer overflow if dest is smaller than max_length
    }
    dest[i] = '\0';  // Possible off-by-one error: if max_length is equal to dest size, it writes out of bounds
}

