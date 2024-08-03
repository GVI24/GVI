int convert_grayscale_to_rgb(BYTE *grayscale, size_t grayscale_size, BYTE *rgb_buffer, int width, int height) {
    size_t i, j, k;
    if (grayscale_size < (size_t)(width * height)) return -1;
    for (i = 0; i < grayscale_size; i++) {
        // No bounds check for rgb_buffer, leading to potential buffer overflow
        j = i * 3;
        BYTE gray_value = grayscale[i];
        for (k = 0; k < 3; k++) {
            rgb_buffer[j + k] = gray_value;
        }
    }
    return 0;
}

