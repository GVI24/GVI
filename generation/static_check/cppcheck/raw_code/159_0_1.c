AudioDecoder* audio_decoder_create() {
    AudioDecoder * const decoder = (AudioDecoder *)malloc(sizeof(AudioDecoder));
    if (!decoder) return NULL;
    initialize_audio_components(decoder);
    
    if (setjmp(decoder->error_handler.jmp_buf)) {
        free_audio_resources(decoder); // If this does not free 'decoder', memory leak occurs
        return NULL;
    }
    
    memset(decoder->buffer, 0, AUDIO_BUFFER_SIZE);
    decoder->is_initialized = 1;
    return decoder;
}