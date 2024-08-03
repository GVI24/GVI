#define MAX_FILTER_SIZE 5

void apply_convolution_filter(uint8_t *image, int width, int height, int filter_width, int filter_height, const float *filter) {
    uint8_t *buffer = (uint8_t *)malloc(width * height * sizeof(uint8_t));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            float sum = 0.0f;
            for (int fw = 0; fw < filter_width; fw++) {
                for (int fh = 0; fh < filter_height; fh++) {
                    int image_idx = (i + fh - filter_height / 2) * width + (j + fw - filter_width / 2); // Potential buffer overflow
                    sum += image[image_idx] * filter[fw + fh * filter_width]; // No bounds checking for image[image_idx]
                }
            }
            buffer[i * width + j] = (uint8_t)sum;
        }
    }
    memcpy(image, buffer, width * height * sizeof(uint8_t));
    free(buffer);
}