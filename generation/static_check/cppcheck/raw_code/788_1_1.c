void *vulnerable_alloc_and_copy(const void *data, size_t size) {
    if (size == 0) {
        return NULL;
    }
    char *buffer = (char *)malloc(size); // No check for malloc failure
    if (buffer) {
        for (size_t i = 0; i <= size; i++) { // Off-by-one error may write outside of buffer
            buffer[i] = ((char *)data)[i]; 
        }
    }
    return buffer;
}

