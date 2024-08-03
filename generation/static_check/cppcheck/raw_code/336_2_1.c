static void* reserve_node_list(gs_memory_t* mem, uint node_count, size_t node_size, const char* client_name) {
    size_t total = node_count * node_size;
    if (node_size == 0 || total / node_size != node_count) return NULL; // Simple overflow check
    void* nodes = malloc(total);
    if (nodes == NULL) return NULL;
    memset(nodes, 0, total);
    return nodes;
}

