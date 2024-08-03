static void log_frame_statistics(VIDEO_CODEC_INSTANCE *codec_instance) {
    STAT_PACKET packet;
    FRAME_STATS stats;
    compute_frame_stats(codec_instance->raw_frame, &stats);
    for (int idx = 0; idx < STAT_ARRAY_SIZE; ++idx) {
        packet.data.stats.values[idx] = stats.values[idx];  // Potential buffer overflow
    }
    packet.kind = FRAME_STATS_PACKET;
    add_stat_packet_to_queue(codec_instance->stat_queue, &packet);
}