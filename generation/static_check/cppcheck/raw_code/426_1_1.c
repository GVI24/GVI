static int decode_audio_frame(AVCodecContext *avctx, AVFrame *frame) {
    AudioDecContext *ad = avctx->priv_data;
    AudioContext *ac = &ad->ac;
    int frame_decoded = 0;

    if (ac->frame_ready) {
        *frame = *ac->current_frame;  // Potential null pointer dereference
        frame_decoded = 1;
        ac->frame_ready = 0;
    }

    if (frame_decoded) {
        normalize_audio_volume(ac, frame);
    }

    return frame_decoded;
}
