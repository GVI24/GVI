#include <stdint.h>

#define MAX_WIDTH 640
#define MAX_HEIGHT 480

typedef struct {
    uint8_t *data;
    int width;
    int height;
} Image;

int apply_image_filter(Image *img, uint8_t *filter_values) {
    uint8_t *pixel_data = img->data;
    uint8_t *new_data = (uint8_t *)malloc(img->width * img->height);
    int8_t *filter_table = (int8_t *)(filter_values + 10);
    int x, y, filter_index;

    if (!new_data) {
        // Error handling would go here
        return -1;
    }

    for (y = 0; y < img->height; ++y) {
        for (x = 0; x < img->width; ++x) {
            filter_index = pixel_data[y * img->width + x] & 0xF;
            new_data[y * img->width + x] = filter_table[filter_index];
        }
    }

    // Further processing would go here
    free(new_data);
    return 0;
}