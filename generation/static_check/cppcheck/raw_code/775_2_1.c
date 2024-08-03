static int grayscale_to_rgb(AVCodecContext *avctx, AVFrame *frame, const uint8_t *buf, int buf_size) {
    int width = avctx->width;
    int height = avctx->height;
    uint8_t *ptr = frame->data[0];

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            uint8_t gray_val = buf[y * width + x];
            // Unsafe if buf is smaller than width * height
            ptr[(y * frame->linesize[0]) + x * 3 + 0] = gray_val;
            ptr[(y * frame->linesize[0]) + x * 3 + 1] = gray_val;
            ptr[(y * frame->linesize[0]) + x * 3 + 2] = gray_val;
        }
    }
    
    return 0;
}