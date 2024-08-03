#include <stdlib.h>

void image_noise_addition(unsigned char *image, int width, int height, int intensity) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int index = i * width + j;
            int noise = rand() % intensity;
            image[index] += noise; // Potential buffer overflow if index is out-of-bounds
        }
        // Improper use of rand(), should be replaced with a more secure random function
    }
}