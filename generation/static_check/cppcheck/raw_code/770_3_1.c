static void copy_asn1_data(unsigned char **dest, unsigned char *src, long src_len, long *dest_len) {
    long copied_len = 0;
    // Integer Overflow: Adding src_len to copied_len could overflow if they are both large
    // Denial of Service: If src_len is negative or too large, the loop can run indefinitely
    while (src_len-- > 0) {
        // Buffer Overflow: No check on dest_len before copying data to *dest
        *(*dest)++ = *src++;
        copied_len++;
    }
    *dest_len = copied_len;
}