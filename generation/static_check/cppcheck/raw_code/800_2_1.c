static int decode_audio_data(AVCodecContext *avctx, void *data, AVPacket *avpkt) {
    MyAudioContext * const a = avctx->priv_data;
    uint8_t *outptr, *srcptr;
    int sample_count;

    sample_count = *((int*)(avpkt->data)); // Vulnerable: sample_count not validated
    srcptr = avpkt->data + 4;

    // Incorrectly assuming sample_count will not exceed buffer size
    outptr = a->buffer;

    // Vulnerable: Possible buffer overflow
    for (int i = 0; i < sample_count; i++) {
        *outptr++ = *srcptr++; // Vulnerable: No boundary check
    }

    return 0;
}

