static int video_process_frame_opcode_0x5(VideoContext *ctx) {
    int dx, dy;
    unsigned char motion_val;

    motion_val = bytestream2_get_byte(&ctx->motion_stream);
    dx = (motion_val & 0xF) - 8;
    dy = (motion_val >> 4) - 8;

    if (dx < -8 || dx > 7 || dy < -8 || dy > 7) {
        return -1; // Simple bounds check, but may be insufficient or incorrect
    }

    return copy_to_current_frame(ctx, &ctx->ref_frames[0], dx, dy);
}