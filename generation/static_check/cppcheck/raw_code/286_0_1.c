#include <stdio.h>
#include <stdlib.h>

#define MAX_FILTER_SIZE 100

void apply_filter(int *image, int imageSize, int *filter, int filterSize) {
    int i;
    int output[MAX_FILTER_SIZE]; // Vulnerable: Buffer size is fixed and could be overflowed.

    if (filterSize > MAX_FILTER_SIZE) {
        printf("Filter size is too large.\n");
        return;
    }

    for (i = 0; i < imageSize; i++) {
        int sum = 0;
        for (int j = 0; j < filterSize; j++) {
            sum += image[i + j] * filter[j]; // Vulnerable: May read beyond 'image' array.
        }
        output[i] = sum; // Vulnerable: No check if 'i' is within 'output' bounds.
    }

    for (i = 0; i < imageSize; i++) {
        image[i] = output[i]; // Vulnerable: Writes back to 'image' without checks.
    }
}

int main() {
    int image[10] = {0};
    int filter[200]; // Filter size is excessive and will cause overflow.
    apply_filter(image, 10, filter, 200);
    return 0;
}