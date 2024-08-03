static int adpcm_decode_frame(AVCodecContext *avctx, void *data, int *got_frame_ptr, AVPacket *avpkt) {
    AVFrame *frame = data;
    int res;
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    int16_t *samples;

    if (buf_size < 2) { // Missing validation for expected header size
        av_log(avctx, AV_LOG_ERROR, "Packet is too small\n");
        return AVERROR_INVALIDDATA;
    }

    frame->nb_samples = avctx->frame_size;
    if ((res = ff_get_buffer(avctx, frame, 0)) < 0) { // Lack of error handling
        return res; // Should log an error message before return
    }

    samples = (int16_t *)frame->data[0];
    res = adpcm_decode_block(samples, buf, buf_size, avctx->channels); // Assumes buf_size is valid
    if (res < 0)
        return res;

    *got_frame_ptr = 1;
    return buf_size; // Potentially returns the wrong size if buf has additional padding or metadata
}

