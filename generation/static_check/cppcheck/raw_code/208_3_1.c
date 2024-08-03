static int dtls_concat_fragments(unsigned char *dest, size_t dest_size, unsigned char *frag1, size_t frag1_len, unsigned char *frag2, size_t frag2_len) {
    if (frag1_len + frag2_len > dest_size) {
        return -1; // Combined size of fragments exceeds destination buffer size
    }
    memcpy(dest, frag1, frag1_len); // Vulnerable: No check if frag1_len is greater than dest_size
    memcpy(dest + frag1_len, frag2, frag2_len); // Vulnerable: No check if frag2_len exceeds the remaining space in dest
    return 0;
}