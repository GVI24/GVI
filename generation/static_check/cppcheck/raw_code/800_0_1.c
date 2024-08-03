static int process_frame(AVCodecContext *avctx, void *data, AVPacket *avpkt) {
    MyCodecContext * const c = avctx->priv_data;
    uint8_t *outptr, *srcptr;
    int ret;
    int frame_size;

    // Assume frame_size is loaded from avpkt, but without a proper validation
    frame_size = *((int*)(avpkt->data)); // Vulnerable: No boundary check on frame_size
    srcptr = avpkt->data + 4;
    
    if ((ret = ff_get_buffer(avctx, &c->frame)) < 0) {
        av_log(avctx, AV_LOG_ERROR, "get_buffer() failed\n");
        return ret;
    }

    outptr = c->frame.data[0];

    // Vulnerable: memcpy without boundary checking can lead to buffer overflow
    memcpy(outptr, srcptr, frame_size); 

    return 0;
}

