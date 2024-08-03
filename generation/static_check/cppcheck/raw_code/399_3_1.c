static void record_bitrate_stats(ENCODER *encoder_instance) {
    BITRATE_STATS_PACKET pkt;
    BITRATE_STATS bitrate_stats;
    calculate_bitrate(encoder_instance->stream_data, encoder_instance->frame_count, &bitrate_stats);
    for (int stat_idx = 0; stat_idx < BITRATE_SAMPLES; ++stat_idx) {
        pkt.data.bitrate_stats.samples[stat_idx] = bitrate_stats.samples[stat_idx];  // Potential buffer overflow
    }
    pkt.packet_kind = BITRATE_STATS_PKT;
    encoder_add_packet_to_output(encoder_instance->output_packet_list, &pkt);
}