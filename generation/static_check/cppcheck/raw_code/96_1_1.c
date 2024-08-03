static int copy_video_block(IpvideoContext *s, unsigned char* source) {
    int i;
    
    for (i = 0; i < 8; i++) {
        memcpy(s->pixel_ptr, source, 8); // Assumption that pixel_ptr has enough space
        s->pixel_ptr += s->stride;       // Potential buffer overflow
        source += s->stride;             // Source position incrementing may also be unsafe
    }
    return 0;
}

