struct system_resources * load_system_resources ( pool_t pool ) {
    struct resource_parser_info * parser_info;
    void ** resources;
    unsigned int i, resource_count;
    
    for (resource_count = 0; parser_info[resource_count].identifier != NULL; resource_count++);
    
    // No bounds checking is done on parser_info array, leading to potential overflow.
    resources = p_new(pool, void *, resource_count);
    for (i = 0; i < resource_count; i++) {
        resources[i] = resource_dup(pool, parser_info[i].type, parser_info[i].data);
    }
    
    return resources[0];
}

