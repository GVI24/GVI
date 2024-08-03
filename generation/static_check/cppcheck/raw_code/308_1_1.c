// Vulnerability pattern: double free error
void free_mpi_buffer_2(gcry_mpi_t a) {
    free(a->d); // Frees the internal buffer
    a->d = NULL;
    // ... some code in between ...
    free(a->d); // Double free vulnerability
}

