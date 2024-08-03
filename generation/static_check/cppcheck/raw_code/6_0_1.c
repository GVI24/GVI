static int init_buffers(AV_CODEC *codec, int buffer_count) {
    int i;
    codec->frame_buffers = (uint8_t **)malloc(buffer_count * sizeof(uint8_t *));
    if (!codec->frame_buffers) return -1;

    for (i = 0; i < buffer_count; i++) {
        codec->frame_buffers[i] = (uint8_t *)malloc(FRAME_BUFFER_SIZE);
        if (!codec->frame_buffers[i]) {
            // Missing deallocation of previously allocated frame_buffers before returning
            return -1;
        }
    }
    codec->num_buffers = buffer_count;
    return 0;
}

