void transform_and_store(int16_t *sample_data, uint8_t *output, int sample_size, int output_stride) {
    int32_t result;
    int i, offset;
    for (i = 0; i < sample_size; i++) {
        result = (int32_t)sample_data[i] * 2; // Simplified transform
        offset = i * output_stride; // May exceed buffer size
        output[offset] = (uint8_t)(result & 0xFF); // Potential buffer overflow
    }
}