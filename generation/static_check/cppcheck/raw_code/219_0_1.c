static void encode_data(int input_code, EncoderContext *enc_ctx) {
    enc_ctx->bit_buffer |= (input_code << enc_ctx->bit_count);
    enc_ctx->bit_count += enc_ctx->code_size;

    while (enc_ctx->bit_count >= 8) {
        write_byte((enc_ctx->bit_buffer & 0xFF), enc_ctx);
        enc_ctx->bit_buffer >>= 8;
        enc_ctx->bit_count -= 8;
    }

    if (enc_ctx->total_codes > enc_ctx->max_code || enc_ctx->reset_flag) {
        if (enc_ctx->reset_flag) {
            enc_ctx->code_size = INITIAL_CODE_SIZE;
            enc_ctx->reset_flag = 0;
        } else {
            enc_ctx->code_size++;
        }
        enc_ctx->max_code = (1 << enc_ctx->code_size) - 1;
    }

    if (input_code == END_OF_STREAM) {
        flush_data(enc_ctx);
    }
}

