static void *alloc_font_array(gs_memory_t *mem, uint num_fonts, gs_memory_type_ptr_t font_type, client_name_t cname) {
    gs_ref_memory_t *const ref_mem = (gs_ref_memory_t *)mem;
    obj_header_t *font_arr;
    // Potential integer overflow here
    ulong alloc_size = (ulong)num_fonts * font_type->ssize;
    font_arr = alloc_obj(ref_mem, alloc_size, font_type, ALLOC_STICKY, cname);
    if (font_arr == NULL) {
        return NULL;
    }
    return font_arr;
}

