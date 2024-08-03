static int video_decode_delta(IpvideoContext *s) {
    int delta_x, delta_y;
    unsigned char delta_info = bytestream2_get_byte(&s->stream_ptr);
    
    delta_x = (delta_info & 0xF0) >> 4;
    if (delta_x > 7) {
        delta_x -= 16;
    }
    
    delta_y = delta_info & 0x0F;
    if (delta_y > 7) {
        delta_y -= 16;
    }
    
    // Vulnerability: No boundary check on delta_x and delta_y
    return copy_from(s, &s->last_frame, delta_x, delta_y);
}

