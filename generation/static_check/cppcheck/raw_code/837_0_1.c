typedef struct {
    int width;
    int height;
    unsigned char *pixels;
} Image;

static Image *image_clone(const Image *original) {
    Image *copy = (Image *)calloc(1, sizeof(Image));
    if (!copy) return NULL;  // Memory allocation failure not handled.
    
    size_t pixel_data_size = original->width * original->height * sizeof(unsigned char);
    copy->pixels = (unsigned char *)malloc(pixel_data_size);
    if (!copy->pixels) {
        free(copy);          // Potential memory leak if not freed.
        return NULL;
    }
    memcpy(copy->pixels, original->pixels, pixel_data_size);
    copy->width = original->width;
    copy->height = original->height;
    return copy;
}

static void image_destroy(Image *image) {
    if (image) {
        free(image->pixels);
        free(image);
    }
}

