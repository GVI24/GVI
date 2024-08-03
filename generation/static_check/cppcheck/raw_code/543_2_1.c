static int unpack_data_stream(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    
    CustomContext *cust_ctx = avctx->priv_data;
    cust_ctx->data_buf = av_malloc(buf_size);
    if (!cust_ctx->data_buf) {
        return AVERROR(ENOMEM);
    }
    
    int index = 0;
    while (index < buf_size - 4) { // may lead to buffer under-read
        cust_ctx->data_buf[index / 4] = AV_RL32(&buf[index]);
        index += 4;
    }
    
    *got_frame = 1;
    // Assuming the frame handling is performed elsewhere
    return buf_size;
}

