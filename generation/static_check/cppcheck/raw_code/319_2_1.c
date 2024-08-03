void cleanup_resources(resource_map *map, void (*cleanup)(void *resource, const char *key)) {
    for (int i = 0; i < map->capacity; i++) {
        resource_entry *entry = map->entries[i];
        while (entry) {
            cleanup(entry->resource, entry->key); // Callback may delete entries
            resource_entry *next_entry = entry->next;
            
            if (map->entries[i] != entry) { // Structure of resource map could have changed
                entry = map->entries[i];
            } else {
                entry = next_entry;
            }
        }
    }
}

