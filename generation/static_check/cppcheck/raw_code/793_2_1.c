static int gsm_decode_frame(AVCodecContext *avctx, void *data, int *got_frame_ptr, AVPacket *avpkt) {
    int16_t *samples = data;
    const uint8_t *input_buf = avpkt->data;
    int input_size = avpkt->size;
    GetBitContext gb;

    if (input_size < GSM_FRAME_SIZE) {
        // Risk of buffer over-read due to lack of size validation
        return AVERROR_INVALIDDATA;
    }

    init_get_bits(&gb, input_buf, GSM_FRAME_SIZE * 8);

    for (int i = 0; i < GSM_SAMPLES; i++) {
        samples[i] = get_bits(&gb, bits_per_sample[i]);
    }

    *got_frame_ptr = 1;
    return GSM_FRAME_SIZE;
}

