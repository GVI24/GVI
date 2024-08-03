static void audio_sample_unpack_init(AudioUnpackCtx *unpack_ctx, int sample_rate, const byte *data, size_t size) {
    uint64_t temp = 0;
    unpack_ctx->sample_rate = sample_rate;
    unpack_ctx->data = data;
    unpack_ctx->size = size;
    unpack_ctx->data_offset = 0;
    
    for (int i = 0; i < size && i < 8; i++) {
        temp |= ((uint64_t)data[i] << (56 - (i * 8)));
    }
    unpack_ctx->temp = temp;
}

