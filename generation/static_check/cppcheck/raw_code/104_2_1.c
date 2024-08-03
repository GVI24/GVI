void set_frame_dimensions(MpegEncContext *ctx, int width, int height) {
    if (width > 0 && height > 0) {
        // Vulnerability: Missing null check for ctx could lead to dereferencing a null pointer
        ctx->width = width;
        ctx->height = height;
    }
}

// Usage Example:
// MpegEncContext *context = NULL;
// set_frame_dimensions(context, 640, 480); // Dereferences a null pointer