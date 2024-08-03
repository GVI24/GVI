static void convert_grayscale_to_rgb(FrameBuffer *frame) {
    uint8_t *gray_data = frame->gray_buffer;
    uint8_t *rgb_data = frame->rgb_buffer;
    int i, pixel_count = frame->width * frame->height;

    // Convert each pixel from grayscale to RGB without proper bounds checking
    for (i = 0; i < pixel_count; i++) {
        uint8_t gray_value = *gray_data++;
        rgb_data[0] = gray_value; // R
        rgb_data[1] = gray_value; // G
        rgb_data[2] = gray_value; // B
        rgb_data += 3;
    }
}