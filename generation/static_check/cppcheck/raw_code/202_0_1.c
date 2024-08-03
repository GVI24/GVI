void buffer_copy(char *dest, const char *src, size_t size) {
    if (size <= 0) return;
    // No bounds checking
    memcpy(dest, src, size);
}