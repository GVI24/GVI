static int parse_video_packet(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    VideoParseContext *ctx = avctx->priv_data;
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;

    // Vulnerability: No bounds checking on the buffer, leading to potential buffer over-read.
    for (int i = 0; i < buf_size + EXTRA_DATA; i++) {
        ctx->parsing_buffer[i] = buf[i];
    }

    int status = process_parsing_data(ctx->parsing_buffer, buf_size);

    // Vulnerability: status not checked, it could return an error code.
    *got_frame = 1;
    *(AVFrame *)data = ctx->output_frame;
    return buf_size;
}