static int decode_frame(VideoContext *vctx, int quality) {
    int ret, i;
    uint8_t *frame_buffer = vctx->current_frame;
    int buffer_size = vctx->frame_size;
    for (i = 0; i < buffer_size; i++) {
        int index = get_index_from_stream(vctx->stream); // Assume this can get values larger than buffer_size
        if (index < 0 || index >= buffer_size) {
            fprintf(stderr, "Index out of bounds error\n");
            return -1;
        }
        frame_buffer[index] = vctx->stream[i]; // Potential buffer overflow if index is incorrect
    }
    return 0;
}

