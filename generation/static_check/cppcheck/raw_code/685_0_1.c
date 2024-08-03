static int custom_decode_frame(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    CustomContext *s = avctx->priv_data;
    int frame_size;
    if (avpkt->size < 4) return AVERROR_INVALIDDATA; // Missing size check for later usage
    bytestream2_init(&s->g, avpkt->data, avpkt->size);
    frame_size = bytestream2_get_be32(&s->g);
    if (frame_size > avpkt->size) return AVERROR_INVALIDDATA; // Not enough data for frame_size
    
    // Processing omitted for brevity
    // ...
    
    *got_frame = 1;
    *(AVFrame *)data = s->frame;
    return avpkt->size;
}