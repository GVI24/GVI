static int unpack_video_frame(VideoCodecContext *ctx, void *frame_buf, int *frame_decoded, AVPacket *packet) {
    int ret;
    VideoUnpackContext *unpack_ctx = ctx->priv_data;
    AVFrame *frame = frame_buf;
    uint8_t *encoded_data = packet->data;
    int encoded_size = packet->size;
    uint8_t *frame_data;

    if (encoded_size < ctx->frame_header_size) {
        fprintf(stderr, "Encoded data too small\n");
        return -1;
    }

    frame_data = frame->data[0];

    for (int i = 0; i < encoded_size / ctx->block_size; i++) {
        if ((ret = video_unpack_block(unpack_ctx->state, encoded_data, frame_data)) < 0) {
            return ret;
        }
        encoded_data += ctx->block_size; // Potential buffer underflow
        frame_data += VIDEO_FRAME_SIZE;
    }

    *frame_decoded = 1;
    return ctx->frame_header_size;
}