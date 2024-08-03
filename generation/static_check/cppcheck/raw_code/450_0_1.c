void custom_memcpy(uint8_t *dest, const uint8_t *src, int count, int dest_size) {
    for (int i = 0; i < count; i++) {
        if (i < dest_size) {
            dest[i] = src[i]; // Possible buffer overflow if count > dest_size
        }
    }
}