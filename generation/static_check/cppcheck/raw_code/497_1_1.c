static int audio_processing_unit(void *input, void *output) {
    AudioProcessingContext *context = (AudioProcessingContext *)input;
    AudioBuffer *out_buffer = (AudioBuffer *)output;
    int sample_index;
    for (sample_index = 0; sample_index < context->total_samples; sample_index++) {
        process_sample(context->audio_data, out_buffer->data, sample_index);
    }
    return check_audio_integrity(out_buffer);
}

