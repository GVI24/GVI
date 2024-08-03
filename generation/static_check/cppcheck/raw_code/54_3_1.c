int image_scale(Jbig2Ctx *ctx, Jbig2Image *image, float scale_factor) {
    if (!image || !image->data) {
        jbig2_error(ctx, JBIG2_SEVERITY_WARNING, -1, "Invalid image or image data");
        return -1;
    }
    
    // Potential for integer overflow when scaling
    int new_width = (int)(image->width * scale_factor);
    int new_height = (int)(image->height * scale_factor);
    
    // Resizing the image without proper bounds check could lead to buffer overflow
    if (new_width > image->width || new_height > image->height) {
        jbig2_error(ctx, JBIG2_SEVERITY_DEBUG, -1, "Scaling image to %d by %d pixels", new_width, new_height);
        jbig2_image_resize(ctx, image, new_width, new_height);
    }
    
    return 0;
}

// Helper function: Common resizing function that may be reused in the examples above
void jbig2_image_resize(Jbig2Ctx *ctx, Jbig2Image *image, int new_width, int new_height) {
    // Assume this function reallocates the `image->data` buffer
    // to fit the new width and height, potentially leading to a buffer overflow
    // if `new_width` or `new_height` have overflowed.
    // ...
}