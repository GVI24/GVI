#include <stdio.h>

typedef struct {
    int width, height;
    int current_x, current_y;
} VideoContext;

int process_video_frame(VideoContext *ctx, int x_offset, int y_offset) {
    int position;
    // Potential integer overflow when calculating position.
    position = (ctx->current_y + y_offset) * ctx->width + (ctx->current_x + x_offset);

    if(position >= ctx->width * ctx->height) {
        printf("Frame position out of bounds\n");
        return -1;
    }
    // Process frame...

    return 0;
}