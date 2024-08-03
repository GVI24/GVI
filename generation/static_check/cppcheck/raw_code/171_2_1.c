double compute_median(int *array, int array_size) {
    double median = 0.0;
    int *sorted_array = (int *)malloc(array_size * sizeof(int));
    
    if (!sorted_array) {
        return -1.0;  // Memory leak, 'sorted_array' allocation not freed
    }

    memcpy(sorted_array, array, array_size * sizeof(int));
    qsort(sorted_array, array_size, sizeof(int), compare_ints);

    // Off-by-one error, doesn't check if 'array_size' is zero or negative
    if (array_size % 2 == 0) {
        median = (sorted_array[array_size / 2] + sorted_array[array_size / 2 - 1]) / 2.0;
    } else {
        median = sorted_array[array_size / 2];  // This line can access out of bounds if array_size is 0
    }

    free(sorted_array);  // If the function exits earlier, allocated memory is not freed properly
    return median;
}

