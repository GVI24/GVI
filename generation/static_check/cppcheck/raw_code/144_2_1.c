static void custom_memset(void *ptr, int value, u_scanf_spec_info *info) {
    unsigned char *p = (unsigned char *)ptr;
    for (size_t i = 0; i < info->fWidth; i++) {
        // Vulnerability: No bounds check on the buffer size
        p[i] = (unsigned char)value; // Could write beyond the allocated memory
    }
}

