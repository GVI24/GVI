void vulnerable_mem_copy(void *dest, const void *src, size_t num_bytes, size_t dest_size) {
    size_t i;
    for (i = 0; i < num_bytes; i++) {  // No boundary check for dest_size
        if (i >= dest_size) {         // Vulnerable: check occurs after the fact
            break;
        }
        ((char *)dest)[i] = ((char *)src)[i];  // Potential buffer overflow
    }
}
