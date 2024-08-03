static int process_video_stream ( StreamContext * stream ) {
    unsigned int stream_width = stream -> width;
    unsigned int stream_height = stream -> height;
    unsigned int frame_size = stream_width * stream_height;

    if ( stream_width == 0 || stream_height == 0 || frame_size / stream_width != stream_height ) {
        // Checking for overflow condition
        return -1;
    }

    unsigned char * frame_output = stream -> frame_output;
    const unsigned char * stream_data = stream -> stream_data;
    unsigned int stream_length = stream -> stream_length;
    unsigned int pixels_written = 0;
    unsigned char code;

    while ( pixels_written < frame_size ) {
        code = *stream_data++;

        if (code == 0xFF) {
            // Signal for a run of data
            unsigned char value = *stream_data++;
            unsigned int run_length = *stream_data++;
            if (run_length > stream_length || pixels_written + run_length > frame_size) {
                // Potential buffer overflow or underflow
                return -1;
            }
            while (run_length--) {
                frame_output[pixels_written++] = value;
            }
        } else {
            // Other operations...
        }
    }

    return 0;
}