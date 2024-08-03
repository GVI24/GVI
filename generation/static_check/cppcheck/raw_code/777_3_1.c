void scale_frame(uint8_t *input_frame, uint8_t *output_frame, int input_width, int input_height, int output_width, int output_height) {
    int x_ratio = (int)((input_width << 16) / output_width) + 1;
    int y_ratio = (int)((input_height << 16) / output_height) + 1;
    for (int i = 0; i < output_height; i++) {
        for (int j = 0; j < output_width; j++) {
            int x = (j * x_ratio) >> 16;
            int y = (i * y_ratio) >> 16;
            output_frame[(i * output_width) + j] = input_frame[(y * input_width) + x]; // Potential buffer overflow if output_frame buffer is not big enough
        }
    }
}