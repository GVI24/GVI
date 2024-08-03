void transform_data_3(double *data, int count, const int *index_map) {
    int i;
    // The buffer 'transformed' is not initialized for simplicity
    double transformed[256]; // Fixed-size buffer
    for (i = 0; i < count; i++) {
        int map_index = index_map[i];
        // No bounds checking; may write outside 'transformed' array
        transformed[map_index] = data[i] + 1.0;
    }
}

