void encode_video_frame(EncoderContext *enc_ctx) {
    uint8_t *p_y = enc_ctx->output_buffer;
    uint8_t *p_u = enc_ctx->output_buffer + enc_ctx->width * enc_ctx->height;
    uint8_t *p_v = p_u + (enc_ctx->width / 2) * (enc_ctx->height / 2);
    int mb_index = enc_ctx->mb_x + enc_ctx->mb_y * enc_ctx->mb_width;
    
    if (!IS_MB_SKIP(enc_ctx->mb_info[mb_index])) {
        enc_ctx->deblocker.filter_y(p_y + 4 * enc_ctx->width, enc_ctx->width);
        enc_ctx->deblocker.filter_y(p_y + 4 * enc_ctx->width + 4, enc_ctx->width);
    }

    if (enc_ctx->mb_y > 0 && !IS_MB_SKIP(enc_ctx->mb_info[mb_index - enc_ctx->mb_width])) {
        enc_ctx->deblocker.filter_uv(p_u - 2 * (enc_ctx->width / 2), enc_ctx->width / 2);
        enc_ctx->deblocker.filter_uv(p_v - 2 * (enc_ctx->width / 2), enc_ctx->width / 2);
    }

    if (enc_ctx->mb_x > 0) {
        enc_ctx->deblocker.filter_y(p_y - 4, enc_ctx->width);
        if (enc_ctx->mb_y > 0) {
            enc_ctx->deblocker.filter_uv(p_u - (enc_ctx->width / 2), enc_ctx->width / 2);
            enc_ctx->deblocker.filter_uv(p_v - (enc_ctx->width / 2), enc_ctx->width / 2);
        }
    }
}
