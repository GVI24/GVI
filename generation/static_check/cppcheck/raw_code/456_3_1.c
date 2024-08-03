void transform_data(int *data, size_t size) {
    // Vulnerability: Memory leak occurs if not all code paths free the allocated memory.
    int *temp = (int *)malloc(size * sizeof(int));
    if (temp == NULL) {
        exit(1);
    }
    for (size_t i = 0; i < size; i++) {
        // Simulate some transformation
        temp[i] = data[i] * 2;
    }
    if (size == 0) {
        // Forgot to free memory before returning
        return;
    }
    memcpy(data, temp, size * sizeof(int));
    free(temp);
}