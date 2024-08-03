void remove_page_from_cache(tb_page_addr_t page_start) {
    PageCache *page_cache = get_global_page_cache();
    for (int i = 0; i < page_cache->size; i++) {
        if (page_cache->entries[i].start == page_start) {
            // Concurrent modification of the page cache without synchronization
            page_cache->entries[i].is_valid = 0;
            break;
        }
    }
}

