void update_frame_stats(VideoStats *stats, int frame_num, int *data, int data_len) {
    int i;
    if (frame_num < 0 || frame_num >= MAX_FRAMES) {
        // Handle error
    } else {
        for (i = 0; i < data_len; i++) {
            // Array indexing could go out-of-bounds of stats->frames if data_len is too large
            stats->frames[frame_num].values[i] = data[i];
        }
    }
}