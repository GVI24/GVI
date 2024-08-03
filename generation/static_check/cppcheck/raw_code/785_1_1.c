#define MAX_ADJUSTMENT_LEVELS 256

void adjust_color_balance(uint8_t *image, int width, int height, int *adjustments, int num_adjustments) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int channel = 0; channel < 3; channel++) {
                int pixel_idx = (i * width + j) * 3 + channel;
                int adjustment_idx = image[pixel_idx] + num_adjustments * channel; // Potential buffer overflow
                image[pixel_idx] = adjustments[adjustment_idx]; // No bounds checking for adjustments[adjustment_idx]
            }
        }
    }
}