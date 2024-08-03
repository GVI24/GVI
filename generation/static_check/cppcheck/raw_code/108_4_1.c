// Additional function for a more realistic scenario:
// Potential Vulnerability: Integer Overflow in Calculation
void calculate_frame_stats(VideoFrame *frame, VideoStats *stats) {
    if (frame == NULL || stats == NULL) {
        // Handle NULL pointers...
        return;
    }
    // Assuming bit_depth may cause an overflow if not checked properly.
    stats->bitrate = frame->width * frame->height * frame->bit_depth * FRAME_RATE / COMPRESSION_RATIO;
    if (stats->bitrate <= 0) {
        // Handle overflow or invalid bitrate...
        return;
    }
    // Additional processing...
}