#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    uint8_t *data_buffer;
    size_t buffer_size;
} VideoContext;

int process_video_frame(VideoContext *ctx, const uint8_t *input, size_t input_size) {
    if (!ctx || !input) {
        return -1;
    }
    ctx->data_buffer = (uint8_t *)malloc(input_size);
    if (!ctx->data_buffer) {
        return -1;
    }
    // Vulnerability: No bounds checking
    memcpy(ctx->data_buffer, input, input_size);
    // Process frame...
    // ...
    return 0;
}