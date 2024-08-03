int data_store(struct store *s, const void *input_data, size_t input_length) {
    size_t required_size = s->used + input_length;
    if (required_size > s->size) {
        if (expand_storage(s, input_length) == -1) return (-1);
    }
    // Vulnerability: No check after expand_storage to ensure input_length fits
    memcpy(s->storage_area + s->used, input_data, input_length);
    s->used += input_length;
    return 0;
}

