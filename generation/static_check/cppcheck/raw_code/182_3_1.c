static float * i_alloc_float_array_immovable(gs_memory_t * mem, uint num_elements, client_name_t cname) {
    gs_ref_memory_t * const imem = (gs_ref_memory_t *) mem;
    obj_header_t * obj;
    // Potential Integer Overflow vulnerability below:
    ulong total_size = (ulong)num_elements * sizeof(float);
    obj = alloc_obj(imem, total_size, &st_floats, ALLOC_IMMOVABLE | ALLOC_DIRECT, cname);
    if (obj == NULL) return NULL;
    return (float *) obj;
}