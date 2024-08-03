char* copy_string(char* dest, const char* src, size_t dest_size) {
    size_t i;
    for (i = 0; src[i] != '\0' && i < dest_size; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0'; // Potential buffer overflow if i == dest_size
    return dest;
}

