typedef struct {
    int width, height;
    int channel_count;
    uint8_t *pixels;
} RawImage;

// Vulnerable: Potential integer overflow when calculating buffer size
int create_image(RawImage *img, int width, int height, int channels) {
    if (width < 0 || height < 0 || channels <= 0) {
        return -1;
    }
    long long size = width * height * channels;
    img->pixels = malloc(size);
    if (img->pixels == NULL) {
        return -2;
    }
    img->width = width;
    img->height = height;
    img->channel_count = channels;
    return 0;
}

// Another vulnerable function
