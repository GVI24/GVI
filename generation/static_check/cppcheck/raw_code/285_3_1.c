void encode_subtitles(SUBTITLE_TRACK *track, int track_length) {
    char subtitle_buffer[MAX_SUBTITLE_LENGTH];
    for (int i = 0; i < track_length; i++) {
        // No validation of track_length against MAX_SUBTITLE_COUNT
        SUBTITLE subtitle = track->subtitles[i];

        // Potential buffer overflow when encoding long subtitles
        int encoded_length = encode_subtitle(subtitle, subtitle_buffer, sizeof(subtitle_buffer));
        
        if (encoded_length > 0) {
            // Display or process the encoded subtitle
            process_subtitle(subtitle_buffer, encoded_length);
        }
    }
}