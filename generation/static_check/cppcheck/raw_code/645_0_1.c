#define MAX_AUDIO_FRAME_SIZE 2048

typedef struct {
    uint8_t audio_data[MAX_AUDIO_FRAME_SIZE];
} AudioDecoderContext;

int process_audio_frame(AudioDecoderContext *ctx, uint8_t *input, size_t input_size) {
    if (input_size > MAX_AUDIO_FRAME_SIZE) {
        fprintf(stderr, "Input buffer exceeds the maximum frame size\n");
        return -1;
    }
    
    // Vulnerable: directly copies input buffer without checks
    memcpy(ctx->audio_data, input, input_size); 
    
    // Further processing...
    
    return 0;
}