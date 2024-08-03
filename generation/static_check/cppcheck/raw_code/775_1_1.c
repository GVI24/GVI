static int image_process_line(AVCodecContext *avctx, AVFrame *frame, const uint8_t *buf, int buf_size) {
    int width = avctx->width;
    int height = avctx->height;
    int linesize = width * 3; // Assuming each pixel is 3 bytes (RGB)
    uint8_t *ptr = frame->data[0];

    for (int i = 0; i < height; i++) {
        if (linesize > buf_size) {
            return -1; // Error: linesize exceeds buffer size
        }
        memcpy(ptr, buf, linesize);
        buf += linesize;
        ptr += frame->linesize[0];
    }
    
    return 0;
}