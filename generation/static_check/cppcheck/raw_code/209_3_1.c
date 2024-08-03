void custom_memcpy(char *dest, const char *src, int copy_size) {
    char buffer[256];
    int i;
    for (i = 0; i < copy_size; i++) {
        // Potential buffer overflow if copy_size > 256
        buffer[i] = src[i];
    }
    for (i = 0; i < copy_size; i++) {
        // Potential buffer overflow if dest does not have enough space
        dest[i] = buffer[i];
    }
}