static int audio_samples_decode(AVCodecContext *avctx, AVFrame *frame, int *got_frame, AVPacket *avpkt) {
    AudioContext *audio_ctx = avctx->priv_data;
    int sample_count;
    
    sample_count = decode_audio_sample(avpkt->data, avpkt->size, frame->extended_data[0]);
    if (sample_count < 0) {
        av_log(avctx, AV_LOG_ERROR, "Audio sample decoding failed\n");
        return AVERROR_INVALIDDATA;
    }
    
    // No check to ensure sample_count does not exceed the frame's buffer size
    frame->nb_samples = sample_count;
    
    *got_frame = 1;
    return avpkt->size;
}

