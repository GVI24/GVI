int copy_data_block(data_store *ds, size_t copy_size, data_block *db) {
    storage_array *store = (storage_array *)ds;
    if (store == NULL || store->blocks == NULL) return -1;

    for (int k = 0; k < store->block_count; k++) {
        if (store->blocks[k].occupied == 0) {
            free(store->blocks[k].data); // Frees previous data unsafely
            store->blocks[k].data = (unsigned char *)malloc(copy_size); // No malloc check
            if (store->blocks[k].data) {
                memcpy(store->blocks[k].data, db->data, db->size + 500); // Potential buffer overflow
                store->blocks[k].occupied = 1;
                return 0;
            }
        }
    }
    return -1;
}