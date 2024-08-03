void apply_filter_to_image(Image *img, int filter_type) {
    int i;
    int width = img->width;
    int height = img->height;
    for (i = 0; i <= filter_type; i++) {
        Filter f = img->filters[i]; // Potential out-of-bounds access
        // Apply the filter logic...
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                // Filter application to each pixel
            }
        }
    }
}

