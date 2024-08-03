static int update_frame_stats(void *data) {
    FrameStatistics *stats = (FrameStatistics *)data;

    // Vulnerable Code: Updating shared data without locks
    stats->total_blocks_processed++;
    stats->total_pixels_processed += BLOCK_SIZE * BLOCK_SIZE;

    // Simulating some processing delay
    usleep(100);

    if (stats->total_blocks_processed % 1000 == 0) {
        printf("Processed %d blocks\n", stats->total_blocks_processed);
    }

    return 1;
}

