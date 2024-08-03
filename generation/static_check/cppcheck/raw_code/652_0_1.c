static int custom_decode_frame(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    CustomContext *s = avctx->priv_data;
    int frame_size, ret;
    
    if (buf_size < 10) { // Insufficient header check
        return AVERROR_INVALIDDATA;
    }
    
    frame_size = AV_RB32(buf); // Potential integer overflow
    buf += 4;
    
    if (frame_size > buf_size) {
        return AVERROR_INVALIDDATA; // Buffer size check after usage
    }
    
    s->frame_data = av_malloc(frame_size); // Potential overflow in av_malloc
    if (!s->frame_data) {
        return AVERROR(ENOMEM);
    }
    
    memcpy(s->frame_data, buf, frame_size); // Potential overflow if frame_size is corrupted
    
    // decode the frame data (omitted for brevity)
    
    *got_frame = 1;
    *data = s->frame_data; // Direct assignment without validation
    
    return buf_size;
}

