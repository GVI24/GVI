void adjust_bitrate_target(StreamConfig *cfg, int frame_count) {
    int target_bitrate = cfg->target_bitrate;
    cfg->bitrate_allocation += target_bitrate;
    
    // Potential overflow if bitrate_allocation or target_bitrate is very large
    cfg->bitrate_allocation -= cfg->used_bits;
    if (frame_count % cfg->refresh_interval == 0) {
        cfg->used_bits = 0;
    }
}

