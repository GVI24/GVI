#include <stdint.h>
#include <stdlib.h>

typedef struct {
    uint16_t *audio_samples;
    size_t num_samples;
} AudioContext;

int process_audio_frame(AudioContext *audio_ctx, const uint16_t *audio_data, size_t data_length) {
    if (!audio_ctx || !audio_data) {
        return -1;
    }
    audio_ctx->num_samples = data_length;
    // Vulnerability: No checks for data_length before allocating
    audio_ctx->audio_samples = (uint16_t *)malloc(audio_ctx->num_samples * sizeof(uint16_t));
    if (!audio_ctx->audio_samples) {
        return -1;
    }

    // Unsafe copy of audio data
    for (size_t i = 0; i < audio_ctx->num_samples; i++) {
        audio_ctx->audio_samples[i] = audio_data[i]; // Possible buffer overflow
    }
    
    // Audio processing...
    // ...
    return 0;
}