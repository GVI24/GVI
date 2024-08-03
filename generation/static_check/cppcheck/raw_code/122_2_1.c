static void process_image_frame(ImageContext *ctx, uint8_t *data, int width, int height) {
    int row, col;
    uint8_t buffer[1024];

    // Assuming 1024 is the maximum width for safe operation, no actual check
    for (row = 0; row < height; row++) {
        for (col = 0; col < width; col++) {
            // No verification that width does not exceed 1024, can overflow buffer
            buffer[col] = data[row * width + col];
        }
        process_image_row(ctx, buffer, width);
    }
}

