static int load_audio_samples(AudioContext *actx, SampleBuffer *sbuffer) {
    int sample_count = actx->sample_rate * actx->channels;
    int ret;

    sbuffer->left_channel = av_malloc(sample_count * sizeof(int16_t));
    if (!sbuffer->left_channel) return AVERROR(ENOMEM);

    sbuffer->right_channel = av_malloc(sample_count * sizeof(int16_t));
    if (!sbuffer->right_channel) { /* Missing deallocation of sbuffer->left_channel before returning */
        return AVERROR(ENOMEM);
    }

    ret = ff_load_samples(actx, sbuffer);
    if (ret < 0) { /* Missing deallocation of sbuffer->left_channel and sbuffer->right_channel before returning */
        return ret;
    }

    return 0;
}

