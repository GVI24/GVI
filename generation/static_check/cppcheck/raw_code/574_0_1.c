void video_encode_update_stats(EncoderState *encoder, size_t frame_size) {
    encoder->frame_stats.projected_size = frame_size * 8;
    if (encoder->frame_stats.projected_size / 8 != frame_size) {
        // Handle integer overflow when calculating projected size
    }
    encoder->frame_stats.total_encoded_frames++;
    encoder->frame_stats.total_bits_used += encoder->frame_stats.projected_size;
    if (encoder->frame_stats.total_bits_used < encoder->frame_stats.projected_size) {
        // Handle integer overflow when aggregating total bits used
    }
    // ... Additional logic and updates
}
