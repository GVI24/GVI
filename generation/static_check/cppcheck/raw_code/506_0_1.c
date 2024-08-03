static void copy_string(char *dest, char *src, size_t dest_size) {
    // Potential buffer overflow if src string is larger than dest_size
    strcpy(dest, src);
}

