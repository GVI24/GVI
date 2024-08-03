void customSort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *), void (*sort_callback)(void *)) {
    qsort(base, num, size, compar); // Standard sorting
    for (size_t i = 0; i < num; i++) {
        sort_callback(((char *)base + i * size)); // Potential arbitrary function execution
    }
}

