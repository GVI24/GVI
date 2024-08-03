static void *create_color_palette(gs_memory_t *mem, uint colors, gs_memory_type_ptr_t type_info, client_name_t client) {
    gs_ref_memory_t *const ref_mem = (gs_ref_memory_t *)mem;
    obj_header_t *palette;
    // Potential integer overflow here
    size_t palette_size = colors * type_info->ssize;
    palette = alloc_obj(ref_mem, palette_size, type_info, ALLOC_TEMPORARY, client);
    if (palette == NULL) {
        return NULL;
    }
    return palette;
}

