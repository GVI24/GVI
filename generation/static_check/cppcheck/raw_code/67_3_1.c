typedef struct CacheItem {
    void* data;
    struct CacheItem* next;
} CacheItem;

void clearCache(CacheItem* head) {
    CacheItem* item;
    while (head) {
        item = head;
        head = head->next;
        free(item->data); // Free the cached data
        free(item);
        // Vulnerability: Pointer 'item' is not set to NULL after being freed. Subsequent use of 'item' is dangerous.
    }
}