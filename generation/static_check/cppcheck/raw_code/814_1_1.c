void allocate_buffer_for_bitrate(VIDEO_STREAM *stream, int duration_seconds) {
    const int average_bitrate_kbps = stream->bitrate_kbps;
    // Overflow can occur here when multiplying before division
    uint64_t buffer_size = (uint64_t)average_bitrate_kbps * duration_seconds / 8;
    stream->buffer = (char *)malloc(buffer_size);
    if (stream->buffer == NULL) {
        // Handle allocation failure
    }
}

