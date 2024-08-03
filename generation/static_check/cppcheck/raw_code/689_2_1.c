#include <stdint.h>
#include <stdlib.h>

typedef struct {
    uint8_t *image_data;
    int width;
    int height;
} ImageContext;

int decompress_image(ImageContext *img_ctx, const uint8_t *compressed_data, size_t data_size) {
    if (!img_ctx || !compressed_data) {
        return -1;
    }
    // Vulnerability: Assuming data_size is valid for width*height
    img_ctx->image_data = (uint8_t *)malloc(data_size);
    if (!img_ctx->image_data) {
        return -1;
    }

    // Unsafe decompression based on unverified size
    for (size_t i = 0; i < data_size; i++) {
        img_ctx->image_data[i] = compressed_data[i]; // Potential buffer overflow
    }

    // Further processing...
    // ...
    return 0;
}