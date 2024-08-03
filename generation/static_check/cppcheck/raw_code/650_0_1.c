void decode_data(unsigned char *source, unsigned char *destination, int source_size) {
    unsigned char *src_ptr = source;
    unsigned char *dst_ptr = destination;
    unsigned char *src_end = source + source_size;

    while (src_ptr < src_end) {
        unsigned int length = *src_ptr++;
        if (src_ptr + length > src_end) break;  // Vulnerable: No bounds check for destination
        while (length--) {
            *dst_ptr++ = *src_ptr++;  // Potential buffer overflow if destination is not large enough
        }
    }
}

