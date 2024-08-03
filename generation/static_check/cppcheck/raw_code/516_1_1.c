#include <stdint.h>

int transform_image_pixels(uint8_t *image_data, int width, int height, int16_t *transformed_data) {
    if (image_data == NULL || transformed_data == NULL || width <= 0 || height <= 0) {
        return -1;
    }

    int index = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Vulnerability: index could get out of bounds of transformed_data buffer
            transformed_data[index++] = image_data[y * width + x] * 2;
        }
    }

    return 0;
}