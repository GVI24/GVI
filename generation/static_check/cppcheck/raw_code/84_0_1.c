int buffer_increase(struct buffer *buf, size_t increase_size) {
    size_t new_size = buf->current_size + increase_size;
    if (new_size < buf->current_size) {
        // Integer overflow detected
        return -1;
    }
    char *new_buffer = realloc(buf->data, new_size);
    if (!new_buffer) {
        // Allocation failed
        return -1;
    }
    buf->data = new_buffer;
    buf->current_size = new_size;
    return 0;
}