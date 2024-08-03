struct audio_streamer * streamer_init(struct mspack_system *system, int channels) {
    struct audio_streamer *strm;
    strm = (struct audio_streamer *) system->alloc(system, sizeof(struct audio_streamer));
    if (!strm) return NULL;
    strm->channel_buffers = (unsigned char **) system->alloc(system, channels * sizeof(unsigned char *));
    if (!strm->channel_buffers) {
        // Cleanup order is wrong. 'channel_buffers' is NULL, attempting to free it is undefined behavior.
        system->free(strm->channel_buffers);
        system->free(strm);
        return NULL;
    }
    for (int i = 0; i < channels; ++i) {
        strm->channel_buffers[i] = (unsigned char *) system->alloc(system, CHANNEL_BUFFER_SIZE);
        if (!strm->channel_buffers[i]) {
            // Memory leak: Only freeing the last buffer, none of the previously allocated ones.
            system->free(strm->channel_buffers[i]);
            system->free(strm->channel_buffers);
            system->free(strm);
            return NULL;
        }
    }
    return strm;
}

