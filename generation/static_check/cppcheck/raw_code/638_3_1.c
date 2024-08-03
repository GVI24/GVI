static void transform_data(int total_data, int16_t *input_data, int16_t *transformed_data, int16_t *map) {
    int16_t temp_storage[512];
    for (int i = 0; i < total_data; ++i) {
        int16_t data = input_data[i];
        // Vulnerability: no check to ensure 'data' is within the bounds of 'temp_storage'
        temp_storage[data] = map[data] + 1; 
        transformed_data[i] = temp_storage[data] * 3;
    }
}