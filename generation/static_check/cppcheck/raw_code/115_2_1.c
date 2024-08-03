#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint8_t *buffer;
    size_t size;
} AudioBuffer;

int process_audio(FILE *input, AudioBuffer *buffer) {
    // Vulnerability: buffer->size may be controlled by external input without validation
    buffer->buffer = (uint8_t *)malloc(buffer->size);
    if (!buffer->buffer || fread(buffer->buffer, buffer->size, 1, input) != 1) {
        // Handle error
        return -1;
    }
    
    // Process audio data...
    
    free(buffer->buffer);
    return 0;
}
