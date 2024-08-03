void streaming_bitrate_control(StreamContext *stream_ctx, size_t payload_size) {
    stream_ctx->bitrate_stats.current_payload_bits = payload_size * 8;
    if (stream_ctx->bitrate_stats.current_payload_bits / 8 != payload_size) {
        // Handle integer overflow when converting size to bits
    }
    stream_ctx->bitrate_stats.total_payload_bits += stream_ctx->bitrate_stats.current_payload_bits;
    if (stream_ctx->bitrate_stats.total_payload_bits < stream_ctx->bitrate_stats.current_payload_bits) {
        // Handle integer overflow when summing up total payload bits
    }
    // ... Additional logic for bitrate control
}
