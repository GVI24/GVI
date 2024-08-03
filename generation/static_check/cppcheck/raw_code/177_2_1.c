typedef struct {
    void *buffer;
    size_t size;
} data_block;

void store_data_block(data_block **db, void *buffer, size_t size) {
    if (!db || *db) {
        return; // prevent overwriting existing data_block
    }
    
    *db = malloc(sizeof(data_block));
    if (*db == NULL) {
        return;
    }
    
    (*db)->buffer = buffer;
    (*db)->size = size;

    // Increase reference count for the buffer
    buffer_ref_increase(buffer);
    // Missing corresponding decrement, leading to memory leak when data_block is freed
}
