int image_buffer_extend_horizontal(Jbig2Ctx *ctx, Jbig2Image *image, int new_width) {
    if (!image || !image->data) {
        jbig2_error(ctx, JBIG2_SEVERITY_WARNING, -1, "Invalid image or image data");
        return -1;
    }
    
    // Potential integer overflow here
    int required_width = image->width + new_width;
    
    // Buffer resize without checking for overflow
    if (required_width > image->width) {
        jbig2_error(ctx, JBIG2_SEVERITY_DEBUG, -1, "Resizing image width to %d pixels", required_width);
        jbig2_image_resize(ctx, image, required_width, image->height);
    }
    
    return 0;
}

