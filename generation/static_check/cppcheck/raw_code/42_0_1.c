static void image_data_process_init(ImageProcessCtx *ctx, int width, const byte *data, size_t size) {
    uint32_t buffer = 0;
    ctx->width = width;
    ctx->data = data;
    ctx->size = size;
    ctx->index = 0;
    
    for (int i = 0; i < size && i < 8; i++) {
        buffer |= (data[i] << ((7 - i) * 8));
    }
    ctx->buffer = buffer;
}

