int decode_run_length_image(byte *encoded_data, size_t data_length, byte *decoded_image, int image_width, int image_height, size_t *consumed_bytes) {
    int x, y;
    size_t data_pos = 0;
    byte *dst = decoded_image;

    for (y = 0; y < image_height; y++) {
        for (x = 0; x < image_width; ) {
            if (data_pos >= data_length) {
                // Missing bounds check could cause buffer over-read
                return -1;
            }
            byte pixel = encoded_data[data_pos++];
            byte count = encoded_data[data_pos++];
            while (count-- > 0) {
                *dst++ = pixel;
                if (++x > image_width) break; // Incorrect bounds check, should be >=
            }
        }
        dst += image_width - x; // Incorrectly assumes x resets at the end of each row
    }
    // Over-read vulnerability: no check to ensure data_pos doesn't exceed data_length
    *consumed_bytes = data_pos;
    return 0;
}

