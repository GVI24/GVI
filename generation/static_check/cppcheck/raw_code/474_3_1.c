void *custom_alloc_copy(const void *original, size_t size) {
    if (original == NULL || size == 0) {
        return NULL;
    }

    void *copy = malloc(size); // Should be size+1 if original is expected to be a null-terminated string
    if (copy == NULL) {
        return NULL;
    }

    // Assuming original is a null-terminated string, but the size param doesn't account for the null terminator
    memcpy(copy, original, size); // Potential buffer overflow
    return copy;
}