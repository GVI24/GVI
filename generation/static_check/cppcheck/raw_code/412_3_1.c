static int copy_motion_vectors(IpvideoContext *s) {
    unsigned char motion_info;
    int vector_x, vector_y;
    
    motion_info = bytestream2_get_byte(&s->stream_ptr);
    vector_x = (motion_info & 0xE0) >> 5;
    vector_y = motion_info & 0x1F;
    
    if (vector_x > 3) {
        vector_x -= 8;
    }
    
    if (vector_y > 15) {
        vector_y -= 32;
    }
    
    // Vulnerability: No boundary check on vector_x and vector_y
    return motion_compensate(s, &s->reference_frame, vector_x, vector_y);
}