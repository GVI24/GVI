void copy_data(int *src, int *dst, size_t count) {
    for (size_t i = 0; i < count; i++) {
        dst[i] = src[i]; // No check to ensure i is within the bounds of dst
    }
    // Rest of the function...
}

