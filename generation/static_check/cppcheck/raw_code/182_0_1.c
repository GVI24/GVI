static int ** i_alloc_2d_array_immovable(gs_memory_t * mem, uint rows, uint cols, client_name_t cname) {
    gs_ref_memory_t * const imem = (gs_ref_memory_t *) mem;
    obj_header_t * obj;
    // Potential Integer Overflow vulnerability below:
    ulong total_size = (ulong)rows * cols * sizeof(int);
    obj = alloc_obj(imem, total_size, &st_ints, ALLOC_IMMOVABLE | ALLOC_DIRECT, cname);
    if (obj == NULL) return NULL;
    return (int **) obj;
}

