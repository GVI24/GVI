static char *i_alloc_char_buffer_immovable(gs_memory_t *mem, uint length, client_name_t cname) {
    gs_ref_memory_t * const imem = (gs_ref_memory_t *) mem;
    obj_header_t * obj;
    // Potential Integer Overflow vulnerability below:
    ulong buffer_size = (ulong)length * sizeof(char);
    obj = alloc_obj(imem, buffer_size, &st_chars, ALLOC_IMMOVABLE | ALLOC_DIRECT, cname);
    if (obj == NULL) return NULL;
    return (char *) obj;
}

