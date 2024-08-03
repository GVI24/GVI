static void file_header_parse_init(FileParseCtx *parse_ctx, const byte *header_data, size_t header_size) {
    uint16_t header_code = 0;
    parse_ctx->header_data = header_data;
    parse_ctx->header_size = header_size;
    parse_ctx->header_index = 0;
    
    for (int i = 0; i < header_size && i < 2; i++) {
        header_code |= (header_data[i] << ((1 - i) * 8));
    }
    parse_ctx->header_code = header_code;
}

