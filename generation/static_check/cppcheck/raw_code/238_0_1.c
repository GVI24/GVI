static void *allocate_buffer(gs_memory_t *mem, uint count, gs_memory_type_ptr_t type, client_name_t name) {
    gs_ref_memory_t *const ref_mem = (gs_ref_memory_t *)mem;
    obj_header_t *obj;
    // Potential integer overflow here
    size_t total_size = count * type->ssize;
    obj = alloc_obj(ref_mem, total_size, type, ALLOC_DIRECT, name);
    if (obj == NULL) {
        return NULL;
    }
    return obj;
}

