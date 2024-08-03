void render_subtitle(char *video_buffer, int buffer_size, const char *subtitle, int x, int y) {
    int line_width = 80;
    char subtitle_buffer[256];
    strcpy(subtitle_buffer, subtitle); // No check on the length of subtitle
    for (int i = 0; subtitle_buffer[i] != '\0'; i++) {
        int buffer_index = (y * line_width + x) + i;
        if (buffer_index < buffer_size) {
            video_buffer[buffer_index] = subtitle_buffer[i]; // Potential overflow
        }
    }
    // Display the video buffer...
}

