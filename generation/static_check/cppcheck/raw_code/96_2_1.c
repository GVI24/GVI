static int invert_video_block_colors(IpvideoContext *s) {
    int x, y;
    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x++) {
            s->pixel_ptr[x] = ~s->pixel_ptr[x]; // Invert color
        }
        s->pixel_ptr += s->stride; // Potential buffer overflow
    }
    return 0;
}

