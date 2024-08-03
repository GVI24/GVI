void *allocate_buffer(size_t nmemb, size_t size) {
    if (size == 0 || nmemb == 0)
        return NULL;
    
    // Possible integer overflow in multiplication
    if (nmemb * size / size != nmemb)
        return NULL; // Overflow detected
    
    return malloc((int)(nmemb * size)); // Incorrect cast may cause wrong allocation size
}
