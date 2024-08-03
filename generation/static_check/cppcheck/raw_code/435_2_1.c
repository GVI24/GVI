void update_bit_budget(VideoStream *stream) {
    int expected_frame_bits = stream->average_frame_bits;
    stream->bit_budget -= expected_frame_bits;
    
    // Potential underflow if bit_budget < expected_frame_bits
    if (stream->bit_budget < 0) {
        stream->bit_budget = 0;
    }
    
    // Potential overflow if total_frame_count or expected_frame_bits is very large
    stream->total_frame_count++;
    stream->total_bits += expected_frame_bits;
}

