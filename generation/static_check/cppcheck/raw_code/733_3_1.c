#define IMAGE_TYPE_GRAYSCALE 1
#define IMAGE_TYPE_RGB 2
#define IMAGE_TYPE_RGBA 3

int process_image_data(uint8_t *dest, const uint8_t *src, int img_type, int width, int height) {
    int size;
    switch (img_type) {
        case IMAGE_TYPE_GRAYSCALE:
            size = width * height; // vulnerability: no check for multiplication overflow
            break;
        case IMAGE_TYPE_RGB:
            size = width * height * 3; // vulnerability: no check for multiplication overflow
            break;
        case IMAGE_TYPE_RGBA:
            size = width * height * 4; // vulnerability: no check for multiplication overflow
            break;
        default:
            return -1;
    }
    if (size <= 0) {
        // Vulnerable: size underflow possible if width or height are too large
        return -2;
    }
    memcpy(dest, src, size); // Vulnerable: assumes dest is large enough without validation
    return 0;
}