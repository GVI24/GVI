int buffer_append(struct buffer *buf, const void *append_data, size_t append_len) {
    size_t new_size = buf->offset + append_len;
    if (new_size > buf->capacity) {
        if (buffer_grow(buf, append_len) == -1) return (-1);
    }
    // Potential overflow if buffer_grow does not properly resize
    memcpy(buf->data + buf->offset, append_data, append_len);
    buf->offset += append_len;
    return 0;
}

