void denoise_image(uint8_t *image, int size, uint8_t strength) {
    uint8_t denoised_image[2048]; // Fixed size buffer
    for (int i = 0; i < size; i++) {
        // No bounds checking on size, could lead to a buffer overflow
        denoised_image[i] = (image[i] > strength) ? (image[i] - strength) : 0;
    }
    // Copy the denoised image data back
    for (int i = 0; i < size; i++) {
        image[i] = denoised_image[i];
    }
}