void set_pixel_value(Image *img, int x, int y, Pixel pixel_value) {
    if(x < 0 || y < 0) {
        printf("Coordinates must be non-negative\n");
        return;
    }
    img->buffer[y * img->width + x] = pixel_value;
}

