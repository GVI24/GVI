#define MAX_VIDEO_PACKET_SIZE 4096

typedef struct {
    uint8_t video_buffer[MAX_VIDEO_PACKET_SIZE];
    size_t buffer_size;
} VideoDecoderContext;

int decode_video_packet(VideoDecoderContext *ctx, const uint8_t *packet_data, size_t packet_size) {
    size_t new_size = ctx->buffer_size + packet_size;
    if (new_size > MAX_VIDEO_PACKET_SIZE) {
        fprintf(stderr, "Exceeding video buffer capacity\n");
        return -1;
    }

    // Vulnerable: Unsafe memory copy could lead to buffer overflow
    memcpy(ctx->video_buffer + ctx->buffer_size, packet_data, packet_size);
    ctx->buffer_size = new_size;

    // More decoding logic...
    
    return 0;
}