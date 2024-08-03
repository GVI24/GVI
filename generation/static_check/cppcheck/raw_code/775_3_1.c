static int palette_frame_decode(AVCodecContext *avctx, AVFrame *frame, const uint8_t *buf, int buf_size, const uint8_t *palette) {
    int width = avctx->width;
    int height = avctx->height;
    int has_palette = avctx->pix_fmt == AV_PIX_FMT_PAL8 ? 1 : 0;
    uint8_t *dst = frame->data[0];
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (has_palette) {
                int index = buf[i * width + j];
                // Unsafe if buf is smaller than width * height
                memcpy(dst + (i * frame->linesize[0] + j * 4), palette + index * 4, 4);
            } else {
                dst[i * frame->linesize[0] + j] = buf[i * width + j];
            }
        }
    }

    return 0;
}