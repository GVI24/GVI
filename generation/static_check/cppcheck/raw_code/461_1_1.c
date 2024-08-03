static int decode_motion_vector(DecodeContext *decode_ctx) {
    short mv_data;
    int mx, my;

    mv_data = bytestream2_get_le16(&decode_ctx->mv_stream);
    mx = (mv_data % 32) - 16; // Potentially unsafe modulus operation
    my = (mv_data / 32) - 16;

    return apply_motion_vector(decode_ctx, &decode_ctx->prev_frame, mx, my);
}