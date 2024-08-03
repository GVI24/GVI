#include <stdio.h>
#include <stdlib.h>

void resize_video_frame(unsigned char *frame, unsigned int width, unsigned int height) {
    unsigned int new_size = width * height * sizeof(unsigned char);

    // Vulnerability: Integer overflow in new_size calculation
    if (new_size < width || new_size < height) {
        printf("Error: Integer overflow detected\n");
        return;
    }

    unsigned char *new_frame = (unsigned char *)malloc(new_size);
    if (!new_frame) {
        printf("Memory allocation failed\n");
        return;
    }

    // Copy and resize frame...
    free(new_frame);
}

int main() {
    unsigned char *frame = (unsigned char *)malloc(100 * 100);
    resize_video_frame(frame, 50000, 50000); // Calls the vulnerable function
    free(frame);
    return 0;
}