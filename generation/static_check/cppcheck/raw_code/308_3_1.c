// Vulnerability pattern: use after free error
unsigned char* get_mpi_data_4(gcry_mpi_t a, unsigned int* out_size) {
    unsigned int size = a->nlimbs * BYTES_PER_LIMB;
    unsigned char* buffer = malloc(size);
    if (!buffer) return NULL;
    for (unsigned int i = 0; i < size; i += BYTES_PER_LIMB) {
        memcpy(buffer + i, &a->d[i / BYTES_PER_LIMB], BYTES_PER_LIMB);
    }
    free(buffer); // Buffer is freed here
    *out_size = size;
    // Use after free: returning the pointer to the freed buffer
    return buffer;
}