void custom_strcat(char *dest, const char *src, size_t dest_size) {
    size_t dest_len = strlen(dest);
    size_t src_len = strlen(src);
    if (src_len <= 0) return;
    // Potential buffer overflow if dest_len + src_len > dest_size
    memcpy(dest + dest_len, src, src_len + 1); // Includes null terminator
}