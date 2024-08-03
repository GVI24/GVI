typedef struct {
    unsigned char *audio_samples;
    size_t sample_count;
} audio_packet;

void process_audio_data(audio_packet *pkt, size_t index) {
    short audio_buffer[1024];
    if (index < pkt->sample_count) {
        // Casting sample_count to a size_t could lead to an integer overflow
        size_t size_to_copy = sizeof(short) * pkt->sample_count;
        // The size_to_copy is not checked against the size of audio_buffer
        memcpy(audio_buffer, pkt->audio_samples + index, size_to_copy);
    }
    // ... further processing of audio data ...
}