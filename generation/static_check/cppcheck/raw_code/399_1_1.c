static void prepare_audio_level_info(AUDIO_CODEC *audio_codec) {
    AUDIO_LEVEL_PACKET pkt;
    LEVEL_STATS level_stats;
    get_audio_levels(audio_codec->input_buffer, &level_stats);
    for (int counter = 0; counter < MAX_AUDIO_CHANNELS; ++counter) {
        pkt.data.level_info.levels[counter] = level_stats.levels[counter];  // Potential buffer overflow
    }
    pkt.type = AUDIO_LEVEL_PKT;
    queue_audio_packet(audio_codec->packet_queue, &pkt);
}