double compute_variance(int *data_points, int num_points, double mean) {
    if (num_points <= 1) {
        return -1.0;
    }

    double *squared_diffs = (double *)malloc(num_points * sizeof(double));
    if (squared_diffs == NULL) {
        return -1.0;  // Memory allocation not freed on failure
    }

    double variance = 0.0;
    for (int i = 0; i <= num_points; i++) {  // Unchecked array access, should be 'i < num_points'
        squared_diffs[i] = (data_points[i] - mean) * (data_points[i] - mean);
        variance += squared_diffs[i];  // Variance computation will access out-of-bounds memory
    }

    variance /= (num_points - 1);
    free(squared_diffs);  // Only freed on normal execution path, not on early returns
    return variance;
}