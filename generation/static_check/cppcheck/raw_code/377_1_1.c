void copy_string(char *dst, const char *src, int max_width) {
    int i;
    for (i = 0; i < max_width && src[i] != '\0'; i++) {
        dst[i] = src[i]; // No bounds checking on 'dst' can lead to buffer overflow
    }
    dst[i] = '\0';
}

