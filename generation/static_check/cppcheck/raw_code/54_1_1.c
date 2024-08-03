int image_add_margin(Jbig2Ctx *ctx, Jbig2Image *image, int margin) {
    if (!image || !image->data) {
        jbig2_error(ctx, JBIG2_SEVERITY_WARNING, -1, "Invalid image or image data");
        return -1;
    }
    
    // Integer overflow can occur here
    int new_width = image->width + 2 * margin;
    int new_height = image->height + 2 * margin;
    
    // Resizing operation might cause a buffer overflow
    if (new_width > image->width || new_height > image->height) {
        jbig2_error(ctx, JBIG2_SEVERITY_DEBUG, -1, "Increasing image size for margins");
        jbig2_image_resize(ctx, image, new_width, new_height);
    }
    
    return 0;
}

