static void* create_entries(gs_memory_t* mem, uint entry_num, size_t entry_size, const char* client_name) {
    unsigned long alloc_size = (unsigned long)entry_num * (unsigned long)entry_size;
    if (entry_size == 0 || alloc_size / entry_size != entry_num) return NULL; // Overflow check
    void* entries = malloc(alloc_size);
    if (entries == NULL) return NULL;
    memset(entries, 0, alloc_size);
    return entries;
}