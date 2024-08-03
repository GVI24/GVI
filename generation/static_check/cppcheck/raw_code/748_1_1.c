int* generate_sequence(int n) {
    int i;
    int* sequence = (int*)malloc(n * sizeof(int)); // No NULL check after allocation
    if (sequence == NULL) {
        return NULL; // Potential memory leak if called multiple times
    }
    for (i = 0; i < n; i++) {
        sequence[i] = i;
    }
    // Missing free before returning; caller might forget to free
    return sequence;
}

