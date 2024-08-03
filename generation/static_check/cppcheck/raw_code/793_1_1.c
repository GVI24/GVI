static int adpcm_decode_frame(AVCodecContext *avctx, void *data, int *got_frame_ptr, AVPacket *avpkt) {
    int8_t *input_buf = avpkt->data;
    int input_size = avpkt->size;
    int16_t *output_buffer = data;
    GetBitContext gb;

    if (input_size < EXPECTED_ADPCM_FRAME_SIZE) {
        // Missing bounds checking could allow for buffer over-read
        return AVERROR_INVALIDDATA;
    }

    init_get_bits(&gb, input_buf, input_size * 8);

    for (int sample = 0; sample < SAMPLES_PER_FRAME; ++sample) {
        output_buffer[sample] = get_sbits(&gb, sample_bit_depths[sample % SAMPLES_PER_FRAME]);
    }

    *got_frame_ptr = 1;
    return EXPECTED_ADPCM_FRAME_SIZE;
}

