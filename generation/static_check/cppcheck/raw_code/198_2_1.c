static int adjust_brightness_worker(void *buffer_data, int adjustment) {
    VideoBuffer *buffer = (VideoBuffer *)buffer_data;

    // Vulnerable Code: Adjusting brightness on the shared buffer without locks
    for (int i = 0; i < buffer->height; i++) {
        for (int j = 0; j < buffer->width; j++) {
            buffer->data[i][j] = clamp(buffer->data[i][j] + adjustment, 0, 255);
        }
    }

    return 1;
}

