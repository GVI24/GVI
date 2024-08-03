static int vid_frame_decode ( VidContext * ctx ) {
    int frame_width = ctx -> codec_ctx -> frame_width;
    int frame_height = ctx -> codec_ctx -> frame_height;
    int frame_buffer_size = frame_width * frame_height;

    if ( frame_width <= 0 || frame_height <= 0 || frame_buffer_size / frame_width != frame_height ) {
        return -1; // Integer overflow check
    }

    unsigned char * frame_buffer = ctx -> temp_buffer;
    unsigned char * frame_buffer_end = ctx -> temp_buffer + ctx -> temp_buffer_size;
    int frame_data_size = ctx -> frame_data_size;
    const unsigned char * frame_data = ctx -> frame_data;
    int x = 0, y = 0;
    unsigned char pixel_opcode;

    while ( frame_buffer_size && frame_buffer < frame_buffer_end ) {
        pixel_opcode = *frame_data++;

        if (pixel_opcode & 0x80) {
            int run_length = pixel_opcode & 0x7F;
            if (frame_data_size < run_length || run_length > frame_buffer_size) {
                // Byte underflow or buffer overflow possible
                break;
            }
            memcpy(frame_buffer, frame_data, run_length);
            frame_data += run_length;
            frame_buffer += run_length;
            frame_data_size -= run_length;
            frame_buffer_size -= run_length;
            y += (x + run_length) / frame_width;
            x = (x + run_length) % frame_width;
        } else {
            // Other operations...
        }
    }

    return 0;
}