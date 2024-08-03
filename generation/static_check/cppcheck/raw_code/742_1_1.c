void audio_frame_copy(short *dest_buf, short *src_buf, int dest_size, int src_size, int start, int count) {
    if (start < 0 || start >= src_size) return;
    
    // No bounds checking for src_buf and dest_buf sizes
    memcpy(dest_buf, src_buf + start, count * sizeof(short));
}

