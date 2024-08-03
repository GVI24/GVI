static int resize_frame(AVCodecContext *avctx, AVPacket *avpkt) {
    uint8_t *resized_frame;
    int new_width = avctx->width / 2;
    int new_height = avctx->height / 2;
    const uint8_t *src = avpkt->data;
    int src_size = avctx->width * avctx->height;
    
    if (avpkt->size < src_size) {
        av_log(avctx, AV_LOG_ERROR, "packet too small\n");
        return AVERROR_INVALIDDATA;
    }
    
    resized_frame = (uint8_t*)malloc(new_width * new_height);
    if (!resized_frame) return AVERROR(ENOMEM);
    
    for (int y = 0; y < new_height; y++) {
        for (int x = 0; x < new_width; x++) {
            resized_frame[y * new_width + x] = src[y * 2 * avctx->width + x * 2]; // No bounds checking
        }
    }
    
    // Process resized frame...
    
    free(resized_frame);
    return avpkt->size;
}