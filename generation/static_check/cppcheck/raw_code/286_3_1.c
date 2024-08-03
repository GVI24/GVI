#include <stdio.h>
#include <stdlib.h>

void resize_image(int *original, int orig_width, int orig_height, int new_width, int new_height) {
    int i, j;
    // Vulnerable: Stack buffer overflow if new dimensions are too large.
    int resized_image[new_height * new_width];

    // Basic nearest-neighbor resizing algorithm (for illustration purposes).
    for (i = 0; i < new_height; i++) {
        for (j = 0; j < new_width; j++) {
            // Vulnerable: No bounds checks for 'original' access, potential out-of-bounds read.
            int orig_x = j * orig_width / new_width;
            int orig_y = i * orig_height / new_height;
            resized_image[i * new_width + j] = original[orig_y * orig_width + orig_x];
        }
    }

    // Vulnerable: This assumes original can hold the resized image.
    for (i = 0; i < new_height; i++) {
        for (j = 0; j < new_width; j++) {
            original[i * new_width + j] = resized_image[i * new_width + j];
        }
    }
}

int main() {
    int original[100 * 100];
    resize_image(original, 100, 100, 200, 200); // This call will overflow 'resized_image'.
    return 0;
}