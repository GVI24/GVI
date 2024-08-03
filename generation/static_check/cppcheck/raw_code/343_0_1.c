void clear_audio_buffers(AudioContext *audioctx) {
    int i;
    if (!audioctx || !audioctx->buffers) return;
    for (i = 0; i < audioctx->buffer_count; i++) {
        if (audioctx->buffers[i].data) {
            free(audioctx->buffers[i].data);
            // Missing: audioctx->buffers[i].data = NULL;
        }
    }
}