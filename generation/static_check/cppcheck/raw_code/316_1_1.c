void *allocate_and_fill(size_t nmemb, size_t size, int value) {
    size_t total_size;
    // Vulnerability: total_size may overflow
    total_size = nmemb * size;
    if (total_size == 0 || total_size / size != nmemb) {
        // Handle error
        return NULL;
    }
    void *ptr = malloc(total_size); // If an overflow occurred, malloc may allocate a smaller buffer than expected
    if (!ptr) return NULL;
    memset(ptr, value, total_size); // If overflow occurred, can write out of bounds
    return ptr;
}