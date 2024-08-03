void inflate_rle(unsigned char *compressed, int comp_size, unsigned char *decompressed, int decomp_size) {
    unsigned char *comp_ptr = compressed;
    unsigned char *decomp_ptr = decompressed;
    unsigned char *decomp_end = decompressed + decomp_size;

    while (comp_ptr < compressed + comp_size) {
        unsigned char value = *comp_ptr++;
        unsigned int run_length = *comp_ptr++;

        if (decomp_ptr + run_length > decomp_end) break; // Vulnerable: Should check before writing

        while (run_length--) {
            *decomp_ptr++ = value;  // Buffer overflow if decomp_size is too small
        }
    }
}