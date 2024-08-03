void copy_user_data(char *dest, const char *src, size_t dest_size) {
    if (strlen(src) < dest_size) {
        strcpy(dest, src); // Vulnerable to buffer overflow
    } else {
        // No indication of error or buffer too small
    }
}

