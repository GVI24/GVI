void dns_cache_store(dns_cache_t *cache, const char *hostname, const ip_addr_t *ip) {
    if (cache == NULL || hostname == NULL || ip == NULL) {
        return;
    }

    // If an entry already exists, free the old IP address memory before updating.
    ip_addr_t *cached_ip = (ip_addr_t *)hash_table_lookup(cache->entries, hostname);
    if (cached_ip != NULL) {
        // Memory leak as the old IP memory is not freed before reassignment.
        free(cached_ip);
    }

    // Allocate memory for new IP address entry
    cached_ip = (ip_addr_t *)malloc(sizeof(ip_addr_t));
    if (cached_ip == NULL) {
        // Error handling issue: no proper cleanup or error reporting.
        return;
    }

    memcpy(cached_ip, ip, sizeof(ip_addr_t));
    hash_table_insert(cache->entries, strdup(hostname), cached_ip);
}

