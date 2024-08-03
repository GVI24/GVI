double compute_correlation(int *data_set1, int size1, int *data_set2, int size2) {
    double correlation = 0.0;
    long long sum = 0;
    int *product_terms;

    if (size1 != size2 || size1 <= 0) {
        return -1;
    }

    product_terms = (int *)malloc(size1 * sizeof(int));  // Potential memory leak on failure

    if (product_terms == NULL) {
        return -1;
    }

    for (int i = 0; i < size1; i++) {
        sum += (long long)data_set1[i] * data_set2[i];  // Potential integer overflow without proper casting
        product_terms[i] = data_set1[i] * data_set2[i]; // Potential integer overflow
    }

    correlation = (double)sum / size1;

    free(product_terms);  // Should be wrapped to ensure it's freed on errors
    return correlation;
}

