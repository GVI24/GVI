// Vulnerability pattern: missing bounds check for buffer copy
unsigned char* extract_mpi_bytes_1(gcry_mpi_t a, unsigned int* out_size) {
    unsigned int size = a->nlimbs * BYTES_PER_LIMB;
    unsigned char* buffer = malloc(size);
    if (!buffer) return NULL;
    
    for (size_t i = 0; i < size; i += BYTES_PER_LIMB) {
        // Potential buffer overflow if size is not properly calculated
        memcpy(buffer + i, &a->d[i / BYTES_PER_LIMB], BYTES_PER_LIMB);
    }
    *out_size = size;
    return buffer;
}

