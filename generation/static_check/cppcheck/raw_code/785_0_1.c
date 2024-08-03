#define MAX_KERNEL_SIZE 10

void sharpen_image(uint8_t *image, int width, int height, int kernel_size) {
    if (kernel_size > MAX_KERNEL_SIZE) return; // Basic error check, but not sufficient

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int sum = 0;
            for (int ky = -kernel_size; ky <= kernel_size; ky++) {
                for (int kx = -kernel_size; kx <= kernel_size; kx++) {
                    int idx = (y + ky) * width + (x + kx); // Potential buffer overflow
                    sum += image[idx]; // No bounds checking for image[idx]
                }
            }
            image[y * width + x] = (uint8_t)(sum / ((kernel_size * 2 + 1) * (kernel_size * 2 + 1)));
        }
    }
}