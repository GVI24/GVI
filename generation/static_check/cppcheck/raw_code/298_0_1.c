static void add_to_hashtable(struct item *item, struct hash_table *table, void *context) {
    struct context_data *ctx_data = context;
    unsigned int hash_index;
    hash_index = compute_hash(item->data) % table->size;
    if (hash_index >= MAX_TABLE_SIZE) 
        die("Hash index out of bounds for item: %s\n", item->description);
    insert_into_table(table->buckets[hash_index], item);
    ctx_data->items_processed++;
}

