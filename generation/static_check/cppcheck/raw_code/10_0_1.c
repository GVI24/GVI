void unsafe_buffer_copy(char *src, size_t src_size, char *dst, size_t dst_size, size_t count) {
    if (count > src_size) {
        count = src_size;
    }
    if (count > dst_size) {
        count = dst_size;
    }
    // Improper bounds checking can lead to buffer overflow
    memcpy(dst, src, count);
}

