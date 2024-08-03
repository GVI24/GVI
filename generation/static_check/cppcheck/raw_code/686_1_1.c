void image_filter(Pixel *image, int width, int height, Filter *filter) {
    int x, y, f_width = filter->width, f_height = filter->height;
    Pixel *filtered_image = malloc(width * height * sizeof(Pixel));

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            // Potential out-of-bounds read
            Pixel *pixel = &image[(y + f_height/2) * width + (x + f_width/2)];
            Pixel result = apply_filter(pixel, filter, width);
            // Potential out-of-bounds write
            filtered_image[y * width + x] = result;
        }
    }
    // More processing...
}