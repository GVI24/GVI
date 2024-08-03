static void quantize_pixels(int num_pixels, int16_t *pixel_values, int16_t *quantized_values, int16_t *thresholds) {
    int16_t quantization_buffer[256];
    for (int i = 0; i < num_pixels; ++i) {
        int16_t pixel = pixel_values[i];
        // Vulnerability: no check to ensure 'pixel' is within bounds of 'quantization_buffer'
        quantization_buffer[pixel] = pixel / thresholds[i]; 
        quantized_values[i] = quantization_buffer[pixel];
    }
}

