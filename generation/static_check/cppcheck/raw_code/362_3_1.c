// Example 4: A function to clean up a hashtable and execute a cleanup function on each payload
typedef struct {
    void *payload;
} HashEntry;

typedef struct {
    HashEntry *entries;
    int size;
} HashTable;

void hash_table_cleanup(HashTable *hash_table, void (*cleanup_func)(void *)) {
    for (int i = 0; i < hash_table->size; ++i) {
        if (hash_table->entries[i].payload) {
            cleanup_func(hash_table->entries[i].payload); // Vulnerable: cleanup_func might free the payload
            // After cleanup_func, payload might be a dangling pointer
            hash_table->entries[i].payload = NULL;
        }
    }
}