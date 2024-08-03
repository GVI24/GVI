void processMapEntries(MapEntry *map, int numEntries, void (*entryProcessor)(void *)) {
    for (int i = 0; i < numEntries; i++) {
        if (map[i].value && map[i].key) {
            entryProcessor(map[i].value); // Potential arbitrary function execution
        }
    }
}