#define MAX_IMAGE_DIMENSION 10000

typedef struct {
    uint8_t *data;
    size_t length;
    size_t pos;
} ByteBuffer;

int read_image(ByteBuffer *buffer, MyImage *image) {
    if (buffer->length - buffer->pos < MY_IMAGE_HEADER_SIZE) {
        return -1;
    }

    image->width = (buffer->data[buffer->pos] << 8) | buffer->data[buffer->pos + 1];
    image->height = (buffer->data[buffer->pos + 2] << 8) | buffer->data[buffer->pos + 3];
    buffer->pos += MY_IMAGE_HEADER_SIZE;

    // Vulnerable: no upper bounds check for the image dimensions
    // Potential Integer Overflow if width or height exceed MAX_IMAGE_DIMENSION
    if (image->width <= 0 || image->height <= 0 ||
        image->width > MAX_IMAGE_DIMENSION || image->height > MAX_IMAGE_DIMENSION) {
        return -2;
    }
    
    // Possible Buffer Overflow: Allocating without checking actual data size
    image->buffer = malloc(image->width * image->height);
    if (!image->buffer) {
        return -3;
    }
    
    size_t data_size = image->width * image->height;
    if (buffer->length - buffer->pos < data_size) {
        free(image->buffer);
        return -4;
    }
    memcpy(image->buffer, &buffer->data[buffer->pos], data_size);
    buffer->pos += data_size;
    
    return 0;
}

// Another vulnerable function
