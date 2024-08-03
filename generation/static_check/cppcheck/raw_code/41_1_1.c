typedef struct {
    uint8_t *data;
    int size;
    int sample_rate;
} AudioPacket;

typedef struct {
    int16_t *output;
    int output_size;
} DecodedAudio;

static int decode_custom_audio_format(AudioPacket *packet, DecodedAudio *decoded) {
    if (!packet || !decoded) {
        return -1;
    }

    // Vulnerability: No check for packet->size against output_size
    for (int i = 0; i < packet->size; i++) {
        decoded->output[i] = packet->data[i]; // Potential out-of-bounds write
    }

    // Further decoding logic...

    return 0;
}

