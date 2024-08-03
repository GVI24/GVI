static int unpack_image_data_0xC_16(IpvideoContext *s) {
    int x, y;
    uint16_t color_a, color_b;
    uint16_t *output = (uint16_t *)s->output_buffer;
    for (y = 0; y < s->height; y++) {
        for (x = 0; x < s->width; x += 2) {
            // Get two colors but no check to ensure we don't read past the stream buffer.
            color_a = bytestream2_get_le16(&s->stream_ptr);
            color_b = bytestream2_get_le16(&s->stream_ptr);
            *output++ = color_a;
            *output++ = color_b; // Potential buffer overflow here.
        }
        output += s->line_skip; // Assuming line_skip is some form of line stride.
    }
    return 0;
}

