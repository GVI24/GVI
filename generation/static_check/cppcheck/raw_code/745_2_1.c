typedef struct {
    uint8_t *data;
    int size;
} VideoPacket;

void process_codec_tag(VideoPacket *packet, uint32_t codec_tag) {
    uint8_t buffer[1024];

    if (codec_tag == 0x12345678) {
        for (int i = 0; i < packet->size; i += 2) {
            // Vulnerability: Potential buffer overflow if packet->size is too large
            buffer[i / 2] = (packet->data[i] + packet->data[i + 1]) / 2;
        }
    }
    // ... handle other codec tags
}