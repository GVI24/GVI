static void copy_row(AVCodecContext *avctx, int src_row, int dst_row) {
    AnsiContext *s = avctx->priv_data;
    if (src_row >= 0 && src_row < avctx->height && dst_row >= 0 && dst_row < avctx->height) {
        memcpy(s->frame.data[0] + dst_row * s->frame.linesize[0], s->frame.data[0] + src_row * s->frame.linesize[0], avctx->width); // No check on linesize[0]
    }
}

