static int unpack_texture(AVCodecContext *avctx, AVFrame *frame, AVPacket *avpkt) {
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    TextureContext *s = avctx->priv_data;
    
    if (buf_size < 8) {
        return AVERROR_INVALIDDATA;
    }
    
    s->texture_width = AV_RL16(buf); // No bounds check for width
    s->texture_height = AV_RL16(buf + 2); // No bounds check for height
    buf += 4;
    
    int pixel_data_size = s->texture_width * s->texture_height * 3; // Potential overflow
    
    if (pixel_data_size > buf_size - 4) { // Check after value is used
        return AVERROR_INVALIDDATA;
    }
    
    frame->data[0] = av_malloc(pixel_data_size); // No NULL check
    memcpy(frame->data[0], buf, pixel_data_size); // No bounds check
    
    // unpack the texture data (omitted for brevity)
    
    return buf_size;
}

