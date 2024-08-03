void process_video_frame_1(int frame_number, int64_t *frame_stat_cache, int cache_size) {
    int stat_index;

    // ... Operations that might affect 'stat_index' based on complex calculations or external input ...

    // Vulnerable access: 'stat_index' might be outside the bounds of 'frame_stat_cache'
    if (stat_index < 0 || stat_index >= cache_size) {
        // Handle error condition: Index out of bounds
        printf("Error: Frame statistics index out of bounds!\n");
        return;
    }
    frame_stat_cache[stat_index] = calculate_frame_statistic(frame_number);
}

