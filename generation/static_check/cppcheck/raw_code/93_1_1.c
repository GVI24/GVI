/* Vulnerable pattern: Buffer Overflow */
void decode_message(char *src, size_t src_len, char *dest) {
    size_t i;
    for (i = 0; i < src_len; i++) {
        // No bounds checking on dest leads to buffer overflow if src_len > size of dest.
        dest[i] = src[i] ^ 0x5A;
    }
}
