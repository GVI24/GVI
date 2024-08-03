void write_to_memory_page(tb_page_addr_t page_address, int data) {
    MemoryPage *page = find_memory_page(page_address);
    
    if (page != NULL) {
        // Other threads could manipulate the same page simultaneously
        memcpy(page->data, &data, sizeof(data));
        page->last_write_timestamp = get_current_time();
    }
}

