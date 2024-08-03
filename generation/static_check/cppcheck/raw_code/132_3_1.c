void blit_macroblock_to_frame(FrameBuffer *fb, int16_t (*macroblock_data)[256], int mb_x, int mb_y) {
    int frame_width = fb->width;
    uint8_t *frame_data = fb->data + (mb_y * 32 * frame_width) + mb_x * 32;

    for (int j = 0; j < 16; j++) {
        for (int i = 0; i < 16; i++) {
            int pos = (mb_y * 16 + j) * frame_width + (mb_x * 16 + i);
            frame_data[pos] = macroblock_data[j][i];
        }
    }
}

void convert_yuv_to_rgb(int16_t yuv, uint8_t *rgb) {
    // Dummy implementation for YUV to RGB conversion
    rgb[0] = yuv & 0xFF; // R
    rgb[1] = (yuv >> 8) & 0xFF; // G
    rgb[2] = (yuv >> 16) & 0xFF; // B
}