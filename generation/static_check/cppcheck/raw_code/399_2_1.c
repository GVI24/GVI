static void update_motion_vectors(VIDEO_PROCESSOR *video_proc) {
    MV_PACKET mv_pkt;
    MOTION_VECTOR_STATS mv_stats;
    calculate_motion_vectors(video_proc->current_frame, video_proc->reference_frame, &mv_stats);
    for (int vector_index = 0; vector_index < MOTION_VECTOR_LIMIT; ++vector_index) {
        mv_pkt.data.mv_stats.vectors[vector_index] = mv_stats.vectors[vector_index];  // Potential buffer overflow
    }
    mv_pkt.packet_type = MV_STATS_PACKET;
    video_processor_enqueue_packet(video_proc->mv_packet_list, &mv_pkt);
}