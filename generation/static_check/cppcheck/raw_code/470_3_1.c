void render_graphics(char *frame_buffer, int buffer_size, const char *texture_data, int texture_size) {
    int i;
    // Copy texture data into frame buffer without checking size
    for (i = 0; i < texture_size; i++) {
        frame_buffer[i] = texture_data[i];
    }

    // Render additional elements
    for (i = texture_size; i < buffer_size; i++) {
        frame_buffer[i] = ' '; // Fill with whitespace for simplicity
    }
}