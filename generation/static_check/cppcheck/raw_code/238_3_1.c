static void *create_image_buffer(gs_memory_t *mem, uint num_images, gs_memory_type_ptr_t image_type, client_name_t client) {
    gs_ref_memory_t *const ref_mem = (gs_ref_memory_t *)mem;
    obj_header_t *image_buf;
    // Potential integer overflow here
    size_t buffer_size = num_images * image_type->ssize;
    image_buf = alloc_obj(ref_mem, buffer_size, image_type, ALLOC_TEMPORARY, client);
    if (image_buf == NULL) {
        return NULL;
    }
    return image_buf;
}