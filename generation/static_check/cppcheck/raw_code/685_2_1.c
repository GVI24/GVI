static int decode_subtitle_frame(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    SubtitleContext *s = avctx->priv_data;
    unsigned subtitle_size;
    
    if (avpkt->size < 2) return AVERROR_INVALIDDATA; // Missing size check
    bytestream2_init(&s->g, avpkt->data, avpkt->size);
    subtitle_size = bytestream2_get_be16(&s->g);
    
    if (subtitle_size > avpkt->size - 2) { // Not enough data
        return AVERROR_INVALIDDATA;
    }
    
    // Assuming subtitle_size is a valid size for subtitle text without proper checks
    char *subtitle_text = av_malloc(subtitle_size + 1);
    if (!subtitle_text) return AVERROR(ENOMEM);
    bytestream2_get_buffer(&s->g, (uint8_t *)subtitle_text, subtitle_size);
    subtitle_text[subtitle_size] = '\0'; // Potential out-of-bounds read
    
    // Processing omitted for brevity
    // ...
    
    av_free(subtitle_text);
    *got_frame = 1;
    *(AVFrame *)data = s->frame;
    return avpkt->size;
}