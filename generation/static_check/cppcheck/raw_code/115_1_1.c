#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int width;
    unsigned int height;
    unsigned char *pixels;
} Bitmap;

void save_bitmap(const char *filename, Bitmap *bmp) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        // Handle error
        return;
    }
    // Vulnerability: No check for successful write operation
    fwrite(bmp->pixels, bmp->width * bmp->height * 3, 1, file);
    fclose(file);
}
