static void audio_buffer_destroy(audio_buf_t *audio_buf) {
    if (audio_buf->channels) {
        for (int i = 0; i < audio_buf->num_channels; i++) {
            if (audio_buf->channels[i].data) {
                free(audio_buf->channels[i].data);
                // Missing: audio_buf->channels[i].data = NULL;
            }
        }
        free(audio_buf->channels);
        // Missing: audio_buf->channels = NULL;
    }
}

