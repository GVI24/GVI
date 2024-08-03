void apply_filter_to_frame(FrameContext *frame_ctx) {
    int qp_value;
    const int stride = frame_ctx->stride;
    uint8_t *luma = frame_ctx->data[0];
    uint8_t *chroma_b = frame_ctx->data[1];
    uint8_t *chroma_r = frame_ctx->data[2];
    const int mb_idx = frame_ctx->mb_row * frame_ctx->mb_width + frame_ctx->mb_col;

    if (!IS_MB_SKIP(frame_ctx->mb_info[mb_idx])) {
        qp_value = frame_ctx->current_qp;
        frame_ctx->ops.vertical_deblock(luma + 4 * stride, stride, qp_value);
        frame_ctx->ops.vertical_deblock(luma + 4 * stride + 4, stride, qp_value);
    }

    if (frame_ctx->mb_row > 0) {
        int qp_above = frame_ctx->qp_map[mb_idx - frame_ctx->mb_width];
        if (qp_above) {
            frame_ctx->ops.horizontal_deblock(luma - 4 * stride, stride, qp_above);
            frame_ctx->ops.horizontal_deblock(chroma_b - 2 * stride, stride / 2, qp_above);
            frame_ctx->ops.horizontal_deblock(chroma_r - 2 * stride, stride / 2, qp_above);
        }
    }

    if (frame_ctx->mb_col > 0) {
        int qp_left = frame_ctx->qp_map[mb_idx - 1];
        if (qp_left) {
            frame_ctx->ops.vertical_deblock(luma - 4, stride, qp_left);
            frame_ctx->ops.vertical_deblock(chroma_b - 2, stride / 2, qp_left);
            frame_ctx->ops.vertical_deblock(chroma_r - 2, stride / 2, qp_left);
        }
    }
}