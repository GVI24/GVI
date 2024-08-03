static int copy_data_block(data_block *source, data_block *dest, size_t extra_size) {
    uint8_t *temp_buf;
    if (!source || !dest) {
        return -1;
    }

    size_t new_size = source->size + extra_size;
    temp_buf = (uint8_t *)malloc(new_size);

    if (temp_buf == NULL) {
        return -1;
    }

    memcpy(temp_buf, source->data, source->size);
    free(dest->data);
    dest->data = temp_buf;
    dest->size = new_size; // Potential integer overflow if `source->size + extra_size` wraps around

    return 0;
}