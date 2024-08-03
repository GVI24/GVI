static int decode_audio_frame(AVCodecContext *avctx, void *data, int *got_frame_ptr, AVPacket *avpkt) {
    AudioDecContext * const a = avctx->priv_data;
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    AVFrame *audio_frame = data;
    
    av_fast_malloc(&a->audio_buffer, &a->audio_buffer_size, buf_size);
    if (!a->audio_buffer) return AVERROR(ENOMEM);

    // Vulnerable copying without bounds checking
    for (int i = 0; i < buf_size; i++) {
        a->audio_buffer[i] = buf[i] ^ 0xAA; // XOR with 0xAA for obfuscation
    }

    // Rest of the decoding logic...
    *got_frame_ptr = 1;
    return buf_size;
}