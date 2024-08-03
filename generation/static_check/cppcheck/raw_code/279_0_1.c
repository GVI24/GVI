#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    // Some data structures related to a global cache
} GlobalCache;

GlobalCache* global_cache_ptr = NULL;

GlobalCache* get_global_cache_instance() {
    if (global_cache_ptr == NULL) {
        // Perform initialization without proper synchronization
        global_cache_ptr = (GlobalCache*)malloc(sizeof(GlobalCache));
        // Omitted: Necessary initialization logic for the cache
    }
    return global_cache_ptr;
}