static int decode_audio_frame(AVCodecContext *avctx, void *data, int *got_frame_ptr, AVPacket *avpkt) {
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    AudioDecodeContext *ctx = avctx->priv_data;
    AVFrame *frame = data;
    int audio_buf_size = ctx->audio_buf_size;
    unsigned char *audio_buf = (unsigned char *)av_malloc(audio_buf_size);

    if (buf_size < 10) {
        av_log(avctx, AV_LOG_ERROR, "Invalid audio packet size.\n");
        return AVERROR_INVALIDDATA;
    }

    unsigned long uncompressed_len = audio_buf_size;
    if (uncompress(audio_buf, &uncompressed_len, buf, buf_size) != Z_OK) {
        av_log(avctx, AV_LOG_ERROR, "Error uncompressing audio.\n");
        av_free(audio_buf);
        return AVERROR_EXTERNAL;
    }

    // Vulnerability: no boundary check for the uncompressed_len
    memcpy(frame->data[0], audio_buf, uncompressed_len);
    
    *got_frame_ptr = 1;

    av_free(audio_buf);
    return buf_size;
}

