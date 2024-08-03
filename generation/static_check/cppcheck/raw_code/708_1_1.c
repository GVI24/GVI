
static int convert_pixel_format(AVFrame *src_frame, AVFrame *dst_frame, int width, int height) {
    uint8_t *src = src_frame->data[0];
    uint8_t *dst = dst_frame->data[0];
    int x, y;

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            // Assuming destination has 2 bytes per pixel (e.g., RGB565), but doesn't check boundaries.
            uint16_t pixel = (src[0] << 8) | src[1];
            *(uint16_t *)(dst + y * dst_frame->linesize[0] + x * 2) = pixel;
            src += 2;
        }
    }

    return 0;
}

