void yuv_to_rgb(uint8_t *yuv, uint8_t *rgb, int width, int height) {
    int uv_index, rgb_index;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            uv_index = y / 2 * width + x / 2; // Vulnerable to integer overflow and out-of-bounds read
            rgb_index = y * width * 3 + x * 3; // Potential out-of-bounds write if `rgb` buffer is not large enough
            // YUV to RGB conversion and write to 'rgb' array
        }
    }
}