static int parse_image_pixels(AVCodecContext *avctx, AVPacket *avpkt) {
    uint8_t *pixels;
    int pixel_count = avctx->width * avctx->height;
    const uint8_t *src = avpkt->data;

    if (avpkt->size < pixel_count) {
        av_log(avctx, AV_LOG_ERROR, "packet too small\n");
        return AVERROR_INVALIDDATA;
    }
    
    pixels = (uint8_t*)malloc(pixel_count);
    if (!pixels) return AVERROR(ENOMEM);
    
    for (int i = 0; i < pixel_count; i++) {
        pixels[i] = *src++; // No bounds checking on 'pixels' array
    }
    
    // Process pixels...
    
    free(pixels);
    return avpkt->size;
}

