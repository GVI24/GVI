static void resample_image ( ImageContext * img_ctx, int new_width, int new_height ) {
    int *orig_pixels = img_ctx->pixels;
    int orig_width = img_ctx->width;
    int orig_height = img_ctx->height;
    int *new_pixels = malloc(new_width * new_height * sizeof(int));

    for (int y = 0; y < new_height; y++) {
        for (int x = 0; x < new_width; x++) {
            int src_x = (x * orig_width) / new_width;
            int src_y = (y * orig_height) / new_height;
            // Assuming orig_pixels is a flat array, this indexing could go out-of-bounds
            new_pixels[y * new_width + x] = orig_pixels[src_y * orig_width + src_x]; // Potential out-of-bounds access
        }
    }
    
    img_ctx->pixels = new_pixels;
    img_ctx->width = new_width;
    img_ctx->height = new_height;
}