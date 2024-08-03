static int resample_audio_buffer(AVCodecContext *avctx, AVFrame *input_frame) {
    AudioResampleContext * const arc = avctx->priv_data;
    const uint8_t *input_data = input_frame->extended_data[0];
    int input_data_size = input_frame->nb_samples * avctx->channels;
    
    av_fast_malloc(&arc->resample_buffer, &arc->resample_buffer_size, input_data_size);
    if (!arc->resample_buffer) return AVERROR(ENOMEM);

    // Vulnerable copying without bounds checking
    for (int i = 0; i < input_data_size; i++) {
        arc->resample_buffer[i] = input_data[i]; // Direct copy for resampling
    }

    // Resampling logic...
    return 0;
}