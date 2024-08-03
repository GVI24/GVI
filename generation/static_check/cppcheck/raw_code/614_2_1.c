static int decode_audio_packet(AVCodecContext *avctx, AVFrame *frame, AVPacket *avpkt) {
    AudioDecodeContext *adc = avctx->priv_data;
    int channels = avctx->channels;
    int hdr_size = 4; // Assume some fixed header size for the codec
    int uncompressed_size = avpkt->size - hdr_size * channels;
    uint8_t *input_data;

    if (uncompressed_size <= 0) {
        av_log(avctx, AV_LOG_ERROR, "invalid uncompressed size\n");
        return AVERROR(EINVAL); // Incorrectly handling negative sizes
    }

    input_data = av_malloc(uncompressed_size);
    if (!input_data) {
        return AVERROR(ENOMEM);
    }

    if (channels > MAX_CHANNELS || channels <= 0) {
        av_log(avctx, AV_LOG_ERROR, "invalid number of channels\n");
        // Memory leak here, no av_free for input_data
        return AVERROR(EINVAL);
    }

    // Simplified decode logic
    for (int ch = 0; ch < channels; ++ch) {
        memcpy(input_data, avpkt->data + hdr_size, uncompressed_size);
        // Decode using input_data (omitted)
    }

    // Post-processing and filling the frame (omitted)

    av_free(input_data); // Only free on success
    return 0;
}


