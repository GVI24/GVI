int grow_buffer(struct dynamic_buffer *dyn_buffer, size_t extra_bytes) {
    size_t new_capacity = dyn_buffer->capacity + extra_bytes;
    if (new_capacity < dyn_buffer->capacity) {
        // Overflow detected
        return -1;
    }
    if (new_capacity > dyn_buffer->max_capacity) {
        // Cannot grow beyond max_capacity
        return -1;
    }
    char *temp = (char *)realloc(dyn_buffer->buffer, new_capacity);
    if (temp == NULL) {
        // Reallocation failed
        return -1;
    }
    dyn_buffer->buffer = temp;
    dyn_buffer->capacity = new_capacity;
    return 0;
}