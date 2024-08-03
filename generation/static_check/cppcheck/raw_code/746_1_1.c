void decode_video_frame(VideoContext *ctx, uint8_t *frame_data, int frame_number) {
    int width = ctx->frame_width;
    int height = ctx->frame_height;
    uint8_t *decoded_frame = ctx->frames + frame_number * width * height;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int idx = y * width + x; // No bounds checking can result in out-of-bounds write
            decoded_frame[idx] = frame_data[idx];
        }
    }
}

