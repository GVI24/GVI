static int decode_audio_frame(AVCodecContext *avctx, void *data, int *got_frame_ptr, AVPacket *avpkt) {
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    AudioDecContext * const a = avctx->priv_data;
    uint8_t *outbuf;
    unsigned long out_size;
    int ret, uncompressed_size;

    if ((ret = ff_get_buffer(avctx, &a->frame)) < 0) {
        av_log(avctx, AV_LOG_ERROR, "Failed to get buffer.\n");
        return ret;
    }

    outbuf = a->frame.data[0];
    out_size = a->out_buf_size;
    uncompressed_size = buf_size - 4; // Assuming the first 4 bytes are header or flags.

    if (uncompress(outbuf, &out_size, buf + 4, uncompressed_size) != Z_OK) {
        // Uncompress function does not verify that out_size will fit into the output buffer.
        av_log(avctx, AV_LOG_ERROR, "Decompression failed!\n");
        return AVERROR_UNKNOWN;
    }

    // Assuming uncompressed data will always fill the frame buffer
    *got_frame_ptr = 1;
    *(AVFrame *)data = a->frame;

    return buf_size;
}

