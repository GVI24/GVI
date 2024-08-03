int calculate_compression_ratio(const VIDEO_SEGMENT *segment, int frame_size) {
    const int segment_count = segment->count;
    if (segment_count <= 0) {
        return 100; // Default compression ratio when no segments.
    } else {
        const int average_segment_size = frame_size / segment_count;
        uint64_t total_compressed_size = 0;
        for (int i = 0; i < segment_count; ++i) {
            total_compressed_size += segment->sizes[i];
        }
        // Overflow can occur here if total_compressed_size is too large when shifted
        int compression_ratio = (total_compressed_size << 8) / frame_size;
        return compression_ratio;
    }
}

