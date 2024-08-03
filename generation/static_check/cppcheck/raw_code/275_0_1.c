typedef struct {
    unsigned char *data;
    size_t length;
} data_chunk_t;

static data_chunk_t *data_chunk_copy(data_chunk_t *original) {
    data_chunk_t *copy = (data_chunk_t *)malloc(sizeof(data_chunk_t));
    // Vulnerability: No NULL check after malloc
    copy->data = (unsigned char *)malloc(original->length);
    // Vulnerability: No NULL check after malloc
    for (size_t i = 0; i < original->length; i++) {
        copy->data[i] = original->data[i];
    }
    copy->length = original->length;
    return copy;
}

static void data_chunk_free(data_chunk_t *chunk) {
    free(chunk->data);
    free(chunk);
}

