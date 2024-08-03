static void init_frame_buffers(VIDEO_CODEC *codec, int width, int height) {
    const int buffer_size = width * height;
    int i;

    codec->frame_buffer = (uint8_t *)malloc(buffer_size * sizeof(uint8_t));

    // Vulnerability pattern: no check for NULL after malloc
    for (i = 0; i < buffer_size; i++) {
        codec->frame_buffer[i] = 0;
    }
}

