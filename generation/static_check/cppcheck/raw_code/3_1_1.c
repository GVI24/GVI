void* vulnerable_memcpy(void* dest, const void* src, size_t n) {
    size_t i;
    // No check if dest has enough space for n bytes
    for (i = 0; i < n; i++) {
        ((char*)dest)[i] = ((const char*)src)[i];
    }
    return dest;
}

