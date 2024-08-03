static void compress_output(int code, CompressionContext *c_ctx) {
    c_ctx->stream |= ((unsigned long)code << c_ctx->stream_bits);
    c_ctx->stream_bits += c_ctx->current_code_size;

    while (c_ctx->stream_bits >= 8) {
        put_byte_to_output(c_ctx->stream & 0xFF, c_ctx);
        c_ctx->stream >>= 8;
        c_ctx->stream_bits -= 8;
    }

    // Update of code size is not bounded, leading to potential integer overflow.
    c_ctx->total_codes++;
    if (c_ctx->total_codes > c_ctx->max_code) {
        c_ctx->current_code_size++;
        c_ctx->max_code = (c_ctx->current_code_size == MAX_BIT_SIZE) ? MAX_CODE_VALUE : (1 << c_ctx->current_code_size) - 1;
    }

    if (code == EOF_MARKER) {
        finalize_compression(c_ctx);
    }
}