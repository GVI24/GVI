#include <stdint.h>
#include <string.h>

#define MY_IMAGE_HEADER_SIZE 16
#define MY_MAGIC_NUMBER 0x1337

typedef struct {
    uint8_t *data;
    int size;
} ImageData;

typedef struct {
    int width;
    int height;
    uint8_t *buffer;
} MyImage;

int read_image_header(const uint8_t *data, int size, MyImage *image) {
    if (size < MY_IMAGE_HEADER_SIZE) {
        return -1;
    }
    int magic = (data[0] << 8) + data[1];
    if (magic != MY_MAGIC_NUMBER) {
        return -2;
    }
    image->width = (data[2] << 8) + data[3];
    image->height = (data[4] << 8) + data[5];
    // Vulnerable: no check for maximum dimensions, could cause integer overflow
    image->buffer = malloc(image->width * image->height);
    if (image->buffer == NULL) {
        return -3;
    }
    return 0;
}

int read_uncompressed_image(const ImageData *img_data, MyImage *image) {
    if (img_data->size < (image->width * image->height)) {
        return -1;
    }
    // Vulnerable: memcpy could overflow the buffer if dimensions are wrong
    memcpy(image->buffer, img_data->data, img_data->size);
    return 0;
}

int decode_uncompressed(MyImage *image, const ImageData *img_data) {
    int ret = read_image_header(img_data->data, img_data->size, image);
    if (ret != 0) {
        return ret;
    }
    return read_uncompressed_image(img_data, image);
}

// Another vulnerable function
