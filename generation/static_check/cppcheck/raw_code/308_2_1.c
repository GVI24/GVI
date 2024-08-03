// Vulnerability pattern: no null-pointer checks after memory operations
unsigned char* copy_mpi_to_buffer_3(gcry_mpi_t a, unsigned int* out_size) {
    unsigned int size = a->nlimbs * BYTES_PER_LIMB;
    unsigned char* buffer = malloc(size); // No error check after malloc
    *out_size = size;
    for (int i = 0; i < a->nlimbs; i++) {
        // Direct memory access without checking if buffer was successfully allocated
        *(buffer + i * BYTES_PER_LIMB) = a->d[i];
    }
    return buffer;
}

