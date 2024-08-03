static int video_overlay_block(IpvideoContext *s) {
    unsigned char overlay_info = bytestream2_get_byte(&s->stream_ptr);
    int overlay_x, overlay_y; 
    
    overlay_x = overlay_info / 16;
    overlay_y = overlay_info % 16;
    
    // Vulnerability: No boundary check on overlay_x and overlay_y
    return blend_overlay(s, &s->current_frame, overlay_x, overlay_y);
}

