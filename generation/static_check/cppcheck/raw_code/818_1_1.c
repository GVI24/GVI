void apply_kernel_filter(uint8_t *image, uint8_t *output, int width, int height, int kernel[3][3]) {
    int i, j, m, n, mm, nn;
    int ii, jj, sum;
    
    for (i = 0; i < height; ++i) {
        for (j = 0; j < width; ++j) {
            sum = 0;
            for (m = 0; m < 3; ++m) {
                for (n = 0; n < 3; ++n) {
                    mm = i + m - 1;
                    nn = j + n - 1;
                    if (mm >= 0 && nn >= 0 && mm < height && nn < width) {
                        sum += image[mm * width + nn] * kernel[m][n];
                    }
                }
            }
            // Potential out-of-bounds write
            output[i * width + j] = (uint8_t)(sum / 9);
        }
    }
}