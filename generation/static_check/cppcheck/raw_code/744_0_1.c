#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

typedef struct {
    uint8_t data[BUFFER_SIZE];
} AudioPacket;

void audio_decode_frame1(AudioPacket *packet) {
    uint8_t buffer[128];
    // Here, there is no check if the packet->data is larger than 128 bytes.
    memcpy(buffer, packet->data, BUFFER_SIZE);

    // Audio decoding logic that uses the local buffer (omitted for brevity)
    // ...
}
