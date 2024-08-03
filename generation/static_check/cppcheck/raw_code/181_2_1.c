static void cache_response(int request_id, const unsigned char *response, size_t response_size) {
    unsigned char *response_cache;
    response_cache = malloc(response_size);
    if (!response_cache) {
        return; // If allocation fails, return without further actions
    }
    memcpy(response_cache, response, response_size);

    if (cache_lookup(request_id)) {
        // Supposed to replace cache, but old cache data is not freed
    } else {
        // Failed to insert into the cache, response_cache will be lost (memory leak)
    }

    // Missing free for response_cache
}

