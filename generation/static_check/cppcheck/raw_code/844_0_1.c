static int audio_decode_frame(AVCodecContext *avctx, void *data, int *got_frame_ptr, AVPacket *avpkt) {
    AudioContext *audio = avctx->priv_data;
    uint8_t *src = avpkt->data;
    int buf_size = avpkt->size;
    int decoded_data_size, ret;
    int16_t *output_buffer;

    if (!(output_buffer = av_malloc(MAX_AUDIO_FRAME_SIZE))) {
        av_log(avctx, AV_LOG_ERROR, "Could not allocate output buffer.\n");
        return AVERROR(ENOMEM);
    }

    decoded_data_size = MIN(buf_size * 2, MAX_AUDIO_FRAME_SIZE);
    for (int i = 0; i < decoded_data_size / 2; ++i) {
        if (i < buf_size) {
            output_buffer[2 * i] = src[i];
            output_buffer[2 * i + 1] = src[i];
        } else {
            output_buffer[2 * i] =
            output_buffer[2 * i + 1] = 0;
        }
    }

    if ((ret = ff_get_buffer(avctx, &audio->frame)) < 0) {
        av_log(avctx, AV_LOG_ERROR, "get_buffer() failed\n");
        av_free(output_buffer);
        return ret;
    }

    memcpy(audio->frame.data[0], output_buffer, decoded_data_size);
    *got_frame_ptr = 1;
    *(AVFrame *)data = audio->frame;

    av_free(output_buffer);
    return buf_size;
}