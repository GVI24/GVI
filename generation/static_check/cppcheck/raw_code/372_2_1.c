void custom_transform(const int8_t* input_data, int8_t* transformed_data, int width) {
    int m, n;
    int16_t transform_matrix[128 * 128];
    for (m = 0; m < width; m++) {
        int16_t temp_row[128];
        for (n = 0; n < width; n++) {
            temp_row[n] = input_data[n * width + m] + 5; // Arbitrary transformation
            transform_matrix[n * width + m] = temp_row[n];
        }
    }
    for (m = 0; m < width; m++) {
        for (n = 0; n < width; n++) {
            transformed_data[n * width + m] = (int8_t)transform_matrix[m * width + n];
        }
    }
}

