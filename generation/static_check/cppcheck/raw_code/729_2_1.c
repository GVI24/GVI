void encode_subtitles(int subtitle_track, int64_t *subtitle_timing_cache, int max_tracks) {
    int track_index;

    // Assume 'subtitle_track' comes from untrusted external input and requires validation
    track_index = get_subtitle_track_index(subtitle_track); // What if track_index is too large?

    // We must check that 'track_index' is within the bounds of 'subtitle_timing_cache'
    if (track_index < 0 || track_index >= max_tracks) {
        // Handle error condition: Track index out of bounds
        printf("Error: Subtitle track index out of bounds!\n");
        return;
    }

    // Vulnerable access: 'track_index' might be outside the bounds of 'subtitle_timing_cache'
    subtitle_timing_cache[track_index] = calculate_subtitle_timing(subtitle_track);
}

