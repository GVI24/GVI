static int render_subtitle_frame(AVCodecContext *avctx, AVFrame *frame) {
    SubtitleDecContext *sd = avctx->priv_data;
    SubtitleContext *sc = &sd->sc;
    int subtitle_ready = 0;

    if (!sc->current_subtitle_frame) {
        return subtitle_ready;  // Early return without proper cleanup or notification
    }

    *frame = *sc->current_subtitle_frame;  // No check for thread safety
    clear_subtitle_buffer(sc);
    subtitle_ready = 1;

    return subtitle_ready;
}
