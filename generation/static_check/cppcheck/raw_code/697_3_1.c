static int decode_image_data(ImageCodecContext *img_ctx, void *image_data, int data_size, Image *decoded_image) {
    const uint8_t *img_buffer = image_data;
    int decode_result = 0;

    if (data_size < 5) {
        return -1; // Not enough data for image header
    }

    // Vulnerable to buffer overflow
    printf("Image data header: %x %x %x %x %x\n", img_buffer[0], img_buffer[1], img_buffer[2], img_buffer[3], img_buffer[4]);

    // Image decoding logic...

    return decode_result;
}