void update_tb_cache(tb_page_addr_t addr, int data) {
    TranslationBlockCache *cache = get_global_cache();
    int index = addr % CACHE_SIZE;

    // Unsafe access to a shared cache without any synchronization mechanism
    cache->blocks[index].data = data;
    cache->blocks[index].addr = addr;
    cache->blocks[index].is_valid = 1;
}

