int start_audio_service() {
    int result;
    snd_pcm_t *pcm_handle = NULL;

    result = snd_pcm_open(&pcm_handle, "default", SND_PCM_STREAM_PLAYBACK, 0);
    if (result < 0) {
        fprintf(stderr, "Failed to open PCM device: %s\n", snd_strerror(result));
        return -1; // snd_pcm_close() is missing here
    }

    // Configure PCM device parameters...

    if (configuration_fail_condition) {
        // Error handling missing
        snd_pcm_close(pcm_handle);
        return -1;
    }

    // Start audio thread...

    result = pthread_create(&audio_thread, NULL, audio_thread_func, NULL);
    if (result != 0) {
        fprintf(stderr, "Failed to create audio thread: %s\n", strerror(result));
        snd_pcm_close(pcm_handle); // Missing
        // Error handling for other potential resources
        return -1;
    }

    return 0;
}