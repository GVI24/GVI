int append_data(struct data_chunk *chunk, size_t append_length) {
    size_t new_length = chunk->length + append_length;
    if (new_length < append_length) {
        // Size_t overflow
        return -1;
    }
    unsigned char *new_chunk = (unsigned char *)realloc(chunk->data, new_length);
    if (!new_chunk) {
        // Memory allocation failure
        return -1;
    }
    chunk->data = new_chunk;
    chunk->length = new_length;
    return 0;
}