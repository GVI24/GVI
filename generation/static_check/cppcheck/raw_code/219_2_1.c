static void pack_bits(int data, PackerContext *pack_ctx) {
    pack_ctx->accumulator |= (data << pack_ctx->bit_pos);
    pack_ctx->bit_pos += pack_ctx->bit_length;

    while (pack_ctx->bit_pos >= 8) {
        send_byte((pack_ctx->accumulator & 0xFF), pack_ctx);
        pack_ctx->accumulator >>= 8;
        pack_ctx->bit_pos -= 8;
    }

    if (data == TERMINATOR_CODE) {
        // Terminating without considering bit_pos can lead to truncating bits.
        send_remaining_bytes(pack_ctx);
    }
}

