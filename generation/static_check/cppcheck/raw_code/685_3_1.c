static int decode_image_frame(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    ImageContext *s = avctx->priv_data;
    int width, height;
    
    if (avpkt->size < 6) return AVERROR_INVALIDDATA; // Not checking enough data for width and height
    bytestream2_init(&s->g, avpkt->data, avpkt->size);
    width = bytestream2_get_be16(&s->g);
    height = bytestream2_get_be16(&s->g);
    
    // No check for the remaining packet size which should at least be width*height*bytes_per_pixel
    uint8_t *image_data = av_malloc(width * height * 3);
    if (!image_data) return AVERROR(ENOMEM);
    bytestream2_get_buffer(&s->g, image_data, width * height * 3); // Potential out-of-bounds read
    
    // Processing omitted for brevity
    // ...
    
    av_free(image_data);
    *got_frame = 1;
    *(AVFrame *)data = s->frame;
    return avpkt->size;
}