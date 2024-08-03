int get_audio_buffer(void *callback_data, size_t required_size, audio_buffer_t *ab) {
    AudioBufferList *audio_buffers = (AudioBufferList *)callback_data;
    if (!audio_buffers) return -1;

    for (int index = 0; index <= audio_buffers->count; index++) { // <= leads to out-of-bounds
        if (audio_buffers->list[index].used == 0) {
            audio_buffers->list[index].used = 1;
            free(audio_buffers->list[index].buffer); // Previous buffer deallocation
            audio_buffers->list[index].buffer = (short *)realloc(audio_buffers->list[index].buffer, required_size);
            *ab = audio_buffers->list[index]; // Missing check for realloc failure
            return 0;
        }
    }
    return -1;
}