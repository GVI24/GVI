static void* allocate_widget_array(gs_memory_t* mem, uint count, size_t struct_size, const char* client_name) {
    if (struct_size == 0 || count == 0) return NULL;
    size_t total_size = count * struct_size;
    void* widgets = malloc(total_size);
    if (!widgets) return NULL;
    memset(widgets, 0, total_size);
    return widgets;
}

