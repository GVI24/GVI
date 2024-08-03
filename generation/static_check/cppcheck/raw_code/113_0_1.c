static int audio_decode_frame(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    int16_t *audio_buff = (int16_t *)data;
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    uint8_t *end = buf + buf_size;
    int audio_buff_size = avctx->channels * avctx->sample_rate * sizeof(int16_t);

    while (buf < end) {
        if (audio_buff + avctx->channels > audio_buff + audio_buff_size) {
            av_log(avctx, AV_LOG_ERROR, "Buffer overflow\n");
            return -1;
        }
        memcpy(audio_buff, buf, avctx->channels * sizeof(int16_t));
        audio_buff += avctx->channels;
        buf += avctx->channels * sizeof(int16_t);
    }
    
    *got_frame = 1;
    return buf_size;
}