static void apply_video_effect(VideoEffectContext *effect_ctx) {
    int x, y;
    uint8_t *effect_buffer = effect_ctx->effect_buffer;
    // Assuming effect_ctx->effect_map_stride correctly reflects the buffer's width
    for (y = 0; y < effect_ctx->frame_height; y += 3) {
        for (x = 0; x < effect_ctx->frame_width; x += 3) {
            uint32_t effect_value = fetch_effect_value(&effect_ctx->effect_stream);
            // Writing a 3x3 block with the same effect value
            effect_buffer[x] = effect_buffer[x + 1] = effect_buffer[x + 2] =
            effect_buffer[x + effect_ctx->effect_map_stride] = effect_buffer[x + 1 + effect_ctx->effect_map_stride] = effect_buffer[x + 2 + effect_ctx->effect_map_stride] =
            effect_buffer[x + 2 * effect_ctx->effect_map_stride] = effect_buffer[x + 1 + 2 * effect_ctx->effect_map_stride] = effect_buffer[x + 2 + 2 * effect_ctx->effect_map_stride] =
            (uint8_t)effect_value;
        }
        effect_buffer += effect_ctx->effect_map_stride * 3;
    }
}

