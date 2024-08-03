#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEADER_SIZE 128
#define MAX_FRAME_SIZE 1024

typedef struct {
    char header[HEADER_SIZE];
    char frame[MAX_FRAME_SIZE];
} VideoContext;

int process_video_frame(VideoContext *ctx, const char *input, int input_size) {
    if (!ctx || !input) {
        return -1;
    }

    // Vulnerable operation: No check for input_size against MAX_FRAME_SIZE
    memcpy(ctx->frame, input, input_size); // Possible buffer overflow

    // Frame processing goes here...
    // ...

    return 0;
}

int main() {
    VideoContext context;
    char large_input[MAX_FRAME_SIZE * 2]; // Simulated large input that can cause overflow
    memset(large_input, 0xAA, sizeof(large_input));
    
    process_video_frame(&context, large_input, sizeof(large_input));

    return 0;
}