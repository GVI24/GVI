void denoise_video_sequence(VideoProcessor *proc, int denoise_depth) {
    DenoiseBuffer *denoise_sequence[MAX_SEQ_BUFFERS] = {NULL};
    int k, buffer_spot;

    // Assuming denoise_depth can have a value larger than MAX_SEQ_BUFFERS
    for (k = 0; k < denoise_depth; k++) {
        buffer_spot = proc->playhead + k;
        if (buffer_spot < proc->total_frames) {
            FrameData *frame_data = get_frame_data(proc, buffer_spot);
            denoise_sequence[k] = &frame_data->noise_buffer;
        }
    }

    for (k = 0; k < denoise_depth; k++) {
        if (denoise_frame(proc, denoise_sequence[k], proc->denoise_level) != 0) {
            fprintf(stderr, "Failed to denoise frame at index %d\n", k);
        }
    }
}