static int unwrap_video_frame(VideoContext *v_ctx, AVFrame *frame, AVPacket *pkt) {
    int frame_size;
    uint8_t *payload;
    
    v_ctx->stream = pkt->data;
    frame_size = bytestream_get_le32(&v_ctx->stream);
    
    if (pkt->size < frame_size + 4) {
        fprintf(stderr, "Frame size exceeds packet size\n");
        return -1;
    }
    
    payload = v_ctx->stream;
    
    if (payload + frame_size > pkt->data + pkt->size) {
        fprintf(stderr, "Frame payload exceeds packet size\n");
        return -1;
    }
    
    memcpy(frame->data[0], payload, frame_size); // Potential overflow
    
    return frame_size;
}