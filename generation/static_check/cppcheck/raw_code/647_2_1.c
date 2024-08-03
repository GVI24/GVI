static int adjust_frame_brightness(VideoContext *v_ctx, int brightness) {
    int i;
    const int frame_size = v_ctx->width * v_ctx->height;
    
    if (!is_decoder_initialized(v_ctx)) {
        fprintf(stderr, "Decoder is not initialized for brightness adjustment\n");
        return -1;
    }
    
    for (i = 0; i < frame_size; ++i) {
        // Vulnerable pattern: 'i' could be manipulated to exceed 'pixels' array size
        Pixel *px = &v_ctx->current_frame.pixels[i];
        px->brightness += brightness;
        
        // Assume pixel values are clamped correctly so the vulnerability is on buffer access
    }
    
    return 0;
}