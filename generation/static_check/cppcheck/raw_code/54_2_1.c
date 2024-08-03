int image_merge_vertical(Jbig2Ctx *ctx, Jbig2Image *top_image, Jbig2Image *bottom_image) {
    if (!top_image || !top_image->data || !bottom_image || !bottom_image->data) {
        jbig2_error(ctx, JBIG2_SEVERITY_WARNING, -1, "Invalid image data");
        return -1;
    }
    
    // Potential integer overflow here
    int new_height = top_image->height + bottom_image->height;
    
    // Allocate a buffer for the new image without checking for overflow
    Jbig2Image *merged_image = jbig2_image_new(ctx, top_image->width, new_height);
    if (!merged_image) {
        jbig2_error(ctx, JBIG2_SEVERITY_FATAL, -1, "Failed to allocate memory for merged image");
        return -1;
    }
    
    // ... code to merge the images ...
    
    return 0;
}

