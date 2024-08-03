static int convert_audio_samples(AVCodecContext *avctx, AVPacket *avpkt) {
    int16_t *samples, sample_val;
    const uint8_t *src = avpkt->data;
    int sample_count = avctx->sample_rate * avctx->channels;
    
    if (avpkt->size < sample_count * 2) {
        av_log(avctx, AV_LOG_ERROR, "packet too small\n");
        return AVERROR_INVALIDDATA;
    }
    
    samples = (int16_t*)malloc(sample_count * sizeof(int16_t));
    if (!samples) return AVERROR(ENOMEM);
    
    for (int i = 0; i < sample_count; i++) {
        sample_val = *((int16_t *)src)++;
        samples[i] = sample_val; // No bounds checking on 'samples' array
    }
    
    // Process samples...
    
    free(samples);
    return avpkt->size;
}

