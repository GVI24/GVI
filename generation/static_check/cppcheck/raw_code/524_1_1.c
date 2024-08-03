typedef struct {
    unsigned char *pixels;
    int width;
    int height;
} Image;

void decode_image_frame(Image *image, const unsigned char *encoded_data, int data_length) {
    int required_size = image->width * image->height * 3;
    if (data_length < required_size) {
        // Vulnerable: may underflow if data_length is manipulated
        unsigned char *decoded_pixels = (unsigned char *)malloc(required_size - data_length);
        memcpy(decoded_pixels, encoded_data, data_length);
        image->pixels = decoded_pixels;
    }
    // Process decoded pixels
}

// ---------------------------------------------------------------
