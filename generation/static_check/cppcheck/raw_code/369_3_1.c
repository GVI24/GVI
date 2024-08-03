// Function to apply a simple kernel filter to an image
static void apply_kernel_filter(uint8_t *dest, const uint8_t *src, int width, int height, const int *kernel, int kernel_size) {
    int i, j, k, l;
    // Vulnerability: No bounds checking for src access based on kernel_size
    for (i = kernel_size / 2; i < height - kernel_size / 2; i++) {
        for (j = kernel_size / 2; j < width - kernel_size / 2; j++) {
            int value = 0;
            for (k = -kernel_size / 2; k <= kernel_size / 2; k++) {
                for (l = -kernel_size / 2; l <= kernel_size / 2; l++) {
                    value += src[(i + k) * width + (j + l)] * kernel[(k + kernel_size / 2) * kernel_size + (l + kernel_size / 2)];
                }
            }
            dest[i * width + j] = (uint8_t)(value / (kernel_size * kernel_size));
            // dest potentially overflows if its allocation does not consider the kernel size
        }
    }
}