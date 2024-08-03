static int decode_video_frame_0xA_16(IpvideoContext *s) {
    uint16_t *frame_buffer = (uint16_t *)s->frame_buffer;
    uint16_t color_value;
    int i, j, run_length;

    for (i = 0; i < s->frame_height; i++) {
        for (j = 0; j < s->frame_width; ) {
            // Get the run length and color value, but no bounds check is done
            color_value = bytestream2_get_le16(&s->stream_ptr);
            run_length = bytestream2_get_byte(&s->stream_ptr);

            // Write 'color_value' 'run_length' times to the frame_buffer
            while (run_length--) {
                *frame_buffer++ = color_value;
            }
            j += run_length;
        }
        frame_buffer += s->line_stride;
    }
    return 0;
}

