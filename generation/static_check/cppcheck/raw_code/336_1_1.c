static void* create_gadget_buffer(gs_memory_t* mem, uint num_gadgets, size_t gadget_size, const char* client_name) {
    size_t buffer_size = num_gadgets * gadget_size;
    if (gadget_size == 0 || num_gadgets == UINT_MAX / gadget_size) return NULL;
    void* buffer = calloc(num_gadgets, gadget_size);
    if (!buffer) return NULL;
    return buffer;
}

