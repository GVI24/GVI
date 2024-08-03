void *safe_memcpy(void *dest, const void *src, size_t num, size_t multiplier) {
    if ((dest == NULL) || (src == NULL) || (num == 0) || (multiplier == 0)) {
        return NULL;
    }

    // Vulnerability: No integer overflow check
    size_t total_size = num * multiplier;

    void *result = memcpy(dest, src, total_size);
    return result;
}