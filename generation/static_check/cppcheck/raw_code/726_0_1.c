typedef struct {
    uint8_t *meta_data;
    int data_len;
} AudioMetaContext;

int parse_audio_metadata(AudioMetaContext *ctx, const uint8_t *buf, int buf_size) {
    int meta_id;
    unsigned int meta_len;

    if (buf_size < 3) return -1;

    meta_id = bytestream_get_byte(&buf);
    meta_len = bytestream_get_be16(&buf);
    
    if (buf_size < meta_len + 3) return -1;

    if (ctx->data_len < meta_id) return -1;
    
    memcpy(ctx->meta_data + meta_id, buf, meta_len);  // Potential overflow if meta_id is too large

    return 0;
}