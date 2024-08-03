struct network_config * network_config_retrieve ( pool_t pool , const struct network_interface * net_iface ) {
    struct network_parser_info * parser_info;
    void * const * iface_configs;
    void ** configs;
    unsigned int i, config_count;
    
    // Assumed to be populated elsewhere, but with no bounds checking.
    iface_configs = get_interface_configs(net_iface);
    for (config_count = 0; parser_info[config_count].name != NULL; config_count++);
    
    configs = p_alloc(pool, sizeof(void *), config_count);
    for (i = 0; i < config_count; i++) {
        configs[i] = network_config_dup(pool, parser_info[i].setting, iface_configs[i]);
    }
    
    // config_count could exceed the size of parser_info array.
    return configs[0];
}

