static void cache_resource(struct resource *res, struct resource_cache *cache, void *meta) {
    struct cache_meta_data *cache_meta = meta;
    int cache_index;
    cache_index = hash_resource(res->identifier) % cache->total_slots;
    if (cache_index >= MAX_CACHE_SIZE)
        die("Cache index is out of bounds for resource: %s\n", res->name);
    place_in_cache(cache->slot[cache_index], res);
    cache_meta->cache_hits++;
}