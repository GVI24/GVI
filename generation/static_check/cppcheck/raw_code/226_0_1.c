static void decode_huffman_data(DecodeContext *ctx, BitStream *bs, int *bit_count) {
    if(*bit_count < 0) {
        av_log(ctx->avctx, AV_LOG_ERROR, "Invalid bit count.\n");
        return;
    }
  
    while (*bit_count > 0) {
        int symbol = read_huffman_symbol(bs, &ctx->huff_table);
        if (symbol < 0) {
            av_log(ctx->avctx, AV_LOG_ERROR, "Error reading Huffman symbol.\n");
            break;
        }
        process_symbol(ctx, symbol);
        *bit_count -= ctx->huff_table.bits_per_symbol; // Potential underflow vulnerability
    }
}

