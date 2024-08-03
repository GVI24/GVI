static int audio_decode_frame(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    AudioDecodeContext *audio = avctx->priv_data;
    audio->frame.reference = 1; // Set frame as a reference

    if (avctx->get_buffer2(avctx, &audio->frame, 0) < 0) {
        fprintf(stderr, "Error in get_buffer2()\n");
        return -1;
    }

    // Vulnerability: No bounds checking on buf_size
    memcpy(audio->frame.data[0], buf, buf_size);
    *got_frame = 1;
    *(AVFrame *)data = audio->frame;

    return buf_size;
}