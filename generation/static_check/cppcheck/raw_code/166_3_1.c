#define MAX_TRACKS 5
#define MAX_SAMPLES 4096

typedef struct {
    int num_samples;
    int *samples;
} AudioTrack;

void mix_audio_tracks(AudioTrack tracks[], int num_tracks, int *output_buffer) {
    int mix_buffer[MAX_SAMPLES];
    for (int i = 0; i < num_tracks; i++) {
        // Vulnerable: No bounds checking for tracks[i].num_samples
        for (int j = 0; j < tracks[i].num_samples; j++) {
            // Vulnerable: Potential integer overflow in accumulation
            mix_buffer[j] += tracks[i].samples[j];
        }
    }

    // Copy mixed audio to output buffer
    // Vulnerable: Does not check if mix_buffer exceeds output_buffer size
    memcpy(output_buffer, mix_buffer, sizeof(mix_buffer));
}

// Usage of the function that could cause multiple vulnerabilities
void encode_audio_session() {
    AudioTrack tracks[MAX_TRACKS];
    int output_buffer[MAX_SAMPLES];
    // Assume initialize_tracks properly sets up tracks with num_samples and samples
    initialize_tracks(tracks, MAX_TRACKS);
    mix_audio_tracks(tracks, MAX_TRACKS, output_buffer);
    // More processing...
}