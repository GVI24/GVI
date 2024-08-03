#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char *data;
    int size;
    int capacity;
} Buffer;

void process_audio_frame(Buffer *buffer, const unsigned char *input, int input_size) {
    if (input_size > buffer->capacity) {
        // Vulnerability: buffer overflow due to not checking the existing size
        memcpy(buffer->data, input, input_size); 
    }
    
    // Do something with the buffer data
}

// ---------------------------------------------------------------
