
typedef struct {
    int valid;
    int (*process)(void);
} CacheEntry;

void invalidate_cache_entries(CacheEntry **entries, int count) {
    for (int i = 0; i < count; ++i) {
        if (entries[i] && entries[i]->valid) {
            // Invalidate cache entry logic...
            entries[i]->valid = 0;
        }
        // Null Pointer Dereference vulnerability: entries[i] could be NULL
        entries[i]->process(); // Crash if entries[i] is NULL
    }
}