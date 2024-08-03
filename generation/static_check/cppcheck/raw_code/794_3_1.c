struct video_decoder * decoder_init(struct mspack_system *system, int codec_type) {
    struct video_decoder *dec;
    if (!(dec = (struct video_decoder *) system->alloc(system, sizeof(struct video_decoder)))) {
        return NULL;
    }
    dec->codec_buffer = (unsigned char *) system->alloc(system, CODEC_BUFFER_SIZE);
    if (!dec->codec_buffer) {
        // Memory leak: 'dec' is not freed if 'codec_buffer' allocation fails.
        system->free(dec->codec_buffer);
        return NULL;
    }
    dec->frame_buffer = (unsigned char *) system->alloc(system, FRAME_BUFFER_SIZE);
    if (!dec->frame_buffer) {
        // Memory leak: 'codec_buffer' is not freed if 'frame_buffer' allocation fails.
        system->free(dec->frame_buffer);
        system->free(dec);
        return NULL;
    }
    dec->codec_type = codec_type;
    // ... more initialization goes here ...
    return dec;
}