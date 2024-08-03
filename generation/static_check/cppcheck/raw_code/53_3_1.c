void aggregate_error_codes(OperationResult *results, int num_results, int error_histogram[MAX_ERROR_CODE]) {
    for (int i = 0; i < num_results; i++) {
        int code = results[i].error_code;
        // Potential out-of-bounds array access.
        error_histogram[code]++;
    }
}