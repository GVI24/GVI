void copy_image_buffers(uint8_t *dest_buffer, uint8_t *src_buffer, size_t src_size, size_t dest_capacity) {
    // Potential buffer overflow if src_size is greater than dest_capacity
    if (dest_buffer && src_buffer) {
        memcpy(dest_buffer, src_buffer, src_size);
    }
}

