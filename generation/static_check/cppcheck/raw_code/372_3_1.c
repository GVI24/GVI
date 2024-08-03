void color_space_conversion(const uint8_t* rgb_data, uint8_t* yuv_data, int pixel_count) {
    int k;
    int32_t conversion_buffer[1024];
    for (k = 0; k < pixel_count; k++) {
        int r = rgb_data[k * 3 + 0];
        int g = rgb_data[k * 3 + 1];
        int b = rgb_data[k * 3 + 2];
        
        // Coefficients are simplified for illustration
        conversion_buffer[k] = (r * 299 + g * 587 + b * 114) / 1000; // Convert to Y (luminance)
        
        yuv_data[k] = (uint8_t)conversion_buffer[k];
    }
}