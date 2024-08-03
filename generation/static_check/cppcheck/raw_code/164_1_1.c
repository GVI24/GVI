void adjust_audio_samples(AudioTrack *track, int num_effects) {
    int i;
    for (i = 0; i <= num_effects; i++) {
        Effect e = track->effects[i]; // Potential out-of-bounds access
        // Adjust the audio samples with the effect...
        for (int s = 0; s < track->num_samples; s++) {
            // Effect application to each sample
        }
    }
}

