void save_audio_samples_info(AUDIO_STREAM *stream, const char *fname) {
    SAMPLE *samples = stream->samples;
    int num_samples = stream->num_samples;
    FILE *file_ptr = fopen(fname, "w");
    if (!file_ptr) {
        return; // Should handle error properly
    }
    for (int i = 0; i < num_samples; i++) {
        fprintf(file_ptr, "Sample %d: %d\n", i, samples[i].value);
    }
    fclose(file_ptr);
}

