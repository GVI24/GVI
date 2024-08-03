// Vulnerable Function Example 2
void * buffer_alloc_and_copy(void *src, size_t size) {
    if (!src || size == 0) {
        return NULL;
    }
    void *buffer = malloc(size);
    if (!buffer) {
        return NULL;
    }
    memcpy(buffer, src, size); // No bounds checking, potential buffer overflow
    return buffer;
}