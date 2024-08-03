void custom_deblocking_filter(MpegVideoContext *ctx) {
    int qp;
    const int line_size = ctx->line_size;
    const int uv_line_size = ctx->uv_line_size;
    const int index = ctx->mb_y * ctx->mb_stride + ctx->mb_x;
    uint8_t *y_plane = ctx->frame_buffer[0];
    uint8_t *cb_plane = ctx->frame_buffer[1];
    uint8_t *cr_plane = ctx->frame_buffer[2];

    if (!IS_MACROBLOCK_SKIP(ctx->mb_types[index])) {
        qp = ctx->quality_scale;
        ctx->dsp.deblock_v(y_plane + 16 * line_size, line_size, qp);
        ctx->dsp.deblock_v(y_plane + 16 * line_size + 16, line_size, qp);
    } else {
        qp = 0;
    }

    if (ctx->mb_y > 0) {
        int qp_top;
        if (IS_MACROBLOCK_SKIP(ctx->mb_types[index - ctx->mb_stride])) {
            qp_top = 0;
        } else {
            qp_top = ctx->qp_table[index - ctx->mb_stride];
        }
        if (qp_top) {
            ctx->dsp.deblock_h(y_plane - line_size, line_size, qp_top);
            ctx->dsp.deblock_h(cb_plane - uv_line_size, uv_line_size, qp_top);
            ctx->dsp.deblock_h(cr_plane - uv_line_size, uv_line_size, qp_top);
        }
    }

    if (qp) {
        ctx->dsp.deblock_h(y_plane, line_size, qp);
        if (ctx->mb_y + 1 == ctx->mb_height) {
            ctx->dsp.deblock_h(y_plane + line_size, line_size, qp);
            ctx->dsp.deblock_h(cb_plane, uv_line_size, qp);
            ctx->dsp.deblock_h(cr_plane, uv_line_size, qp);
        }
    }

    if (ctx->mb_x > 0) {
        int qp_left = ctx->qp_table[index - 1];
        ctx->dsp.deblock_v(y_plane - 1, line_size, qp_left);
        ctx->dsp.deblock_v(cb_plane - 1, uv_line_size, qp_left);
        ctx->dsp.deblock_v(cr_plane - 1, uv_line_size, qp_left);
    }
}
