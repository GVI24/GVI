int process_data(int count, const int* data) {
    int* temp_buffer = (int*)malloc(count * sizeof(int)); // Allocation
    if (temp_buffer == NULL) {
        return -1; // Memory leak here if not freed
    }
    for (int i = 0; i < count; i++) {
        temp_buffer[i] = data[i] * 2;
        if(data[i] == 0) {
            free(temp_buffer); // Correctly freed here
            return -2; // Memory leak, potential early exit without freeing
        }
    }
    free(temp_buffer); // Only freed in the non-early exit case
    return 0;
}