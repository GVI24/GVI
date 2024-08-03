void mix_audio_tracks(int16_t **tracks, int num_tracks, size_t track_length, int selected_track) {
    int16_t *output_track = malloc(track_length * sizeof(int16_t));
    if (selected_track < 0 || selected_track >= num_tracks) {
        // Proper validation should be here
        free(output_track);
        return;
    }
    memcpy(output_track, tracks[selected_track], track_length * sizeof(int16_t));
    // ... mixing logic ...
    free(output_track);
}

