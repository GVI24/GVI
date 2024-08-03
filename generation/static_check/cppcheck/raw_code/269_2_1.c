static void decode_video_frame(VideoContext *vctx, int frame_idx, const uint8_t *coefficients) {
    int width = vctx->width, height = vctx->height;
    uint8_t *video_buffer = vctx->video_frames[frame_idx].data;
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int idx = (y * width) + x;
            video_buffer[idx] = decode_coefficient(coefficients[idx]);
        }
    }
}

