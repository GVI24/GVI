typedef struct {
    uint8_t *frame_buffer;
    int buffer_size;
} VideoFrame;

void process_frame_diff(VideoFrame *prev_frame, VideoFrame *curr_frame, int *frame_diff_value) {
    int diff;

    // Vulnerable: 'diff' is used uninitialized if 'buffer_size' conditions aren't met.
    if (prev_frame->buffer_size == curr_frame->buffer_size && prev_frame->buffer_size > 0) {
        diff = 0;
        for (int i = 0; i < prev_frame->buffer_size; ++i) {
            diff += abs(prev_frame->frame_buffer[i] - curr_frame->frame_buffer[i]);
        }
    }

    // 'diff' could be used without being initialized
    *frame_diff_value = diff;
}