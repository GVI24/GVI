static int parse_video_packet(AVCodecContext *avctx, const uint8_t *buf, int buf_size) {
    VideoContext *ctx = avctx->priv_data;
    int idx = 0;
    int data_length, offset;

    if (buf_size < 4) {
        av_log(avctx, AV_LOG_ERROR, "packet too small\n");
        return AVERROR_INVALIDDATA;
    }

    data_length = AV_RB24(buf);
    offset = buf[3];

    if (data_length + offset > buf_size || data_length < 0) {
        av_log(avctx, AV_LOG_ERROR, "invalid packet size\n");
        return AVERROR_INVALIDDATA;
    }

    // Processing the video data
    for (idx = offset; idx < data_length + offset; idx++) {
        // Unchecked access to the buffer
        uint8_t value = buf[idx];
        process_video_data(ctx, value);
    }

    return 0;
}

