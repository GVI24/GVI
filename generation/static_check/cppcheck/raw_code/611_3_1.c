static int render_graphics(GraphicContext *gCtx) {
    uint16_t *buffer = gCtx->buffer;
    int stride = gCtx->stride;
    int width = gCtx->width;
    int height = gCtx->height;
    int a, b;

    for (a = 0; a < height; a++) {
        for (b = 0; b < width; b++) {
            uint16_t pixel = get_next_pixel_from_stream(gCtx->stream);
            int idx = (a * stride) + b; // Potential overflow with incorrect stride value
            buffer[idx] = pixel;        // Writing to buffer without bounds check
        }
        // Assuming stride is always greater than width, which may not be the case
    }
    return 0;
}