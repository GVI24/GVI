#define MAX_IMAGE_FRAME_SIZE 8192

typedef struct {
    uint8_t frame_data[MAX_IMAGE_FRAME_SIZE];
} ImageDecoderContext;

int decompress_image_frame(ImageDecoderContext *ctx, uint8_t *compressed_data, size_t compressed_size) {
    if (compressed_size > MAX_IMAGE_FRAME_SIZE * 2) {
        fprintf(stderr, "Compressed data size is unrealistic\n");
        return -1;
    }

    // Vulnerable: Assumes compression would never exceed 2x the size
    // This could be exploited with a specially crafted compressed input
    size_t decompressed_size = uncompressed_size(compressed_data, compressed_size); // Hypothetical decompression function
    if (decompressed_size > MAX_IMAGE_FRAME_SIZE) {
        fprintf(stderr, "Decompressed size exceeds limits\n");
        return -1;
    }
    
    memcpy(ctx->frame_data, compressed_data, decompressed_size); // Vulnerability

    // Additional processing...
    
    return 0;
}