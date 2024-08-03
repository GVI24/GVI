typedef struct {
    uint8_t *image_data;
    int block_size;
} ImageContext;

int decompress_image_block(ImageContext *ctx, const uint8_t *data, int data_size) {
    unsigned int block_id, uncompressed_size;

    if (data_size < 5) return -1;

    block_id = bytestream_get_be16(&data);
    uncompressed_size = bytestream_get_be24(&data);
    
    if (data_size - 5 < uncompressed_size) return -1;

    if (block_id > ctx->block_size) return -1;  // No bounds checking for block_id
    
    memcpy(ctx->image_data + block_id, data, uncompressed_size);  // Potential overflow

    return 0;
}