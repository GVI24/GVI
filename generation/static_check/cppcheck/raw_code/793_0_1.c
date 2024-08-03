static int ra144_process_block(AVCodecContext *avctx, void *data, int *got_frame_ptr, AVPacket *avpkt) {
    RA144Context * ractx = avctx->priv_data;
    int8_t *block_data = avpkt->data;
    int block_size = avpkt->size;
    int16_t *output_samples = data;
    GetBitContext gb;

    if (block_size < BLOCK_MIN_SIZE) {
        // Insufficient bounds checking may lead to buffer over-read
        return AVERROR_INVALIDDATA;
    }

    init_get_bits(&gb, block_data, block_size * 8);

    for (int i = 0; i < NUM_COEFFS; i++) {
        output_samples[i] = get_bits(&gb, coeff_bit_sizes[i]);
        if (output_samples[i] == -1) {
            // End of buffer reached unexpectedly
            return AVERROR_INVALIDDATA;
        }
    }
    
    *got_frame_ptr = 1;
    return BLOCK_MIN_SIZE;
}

