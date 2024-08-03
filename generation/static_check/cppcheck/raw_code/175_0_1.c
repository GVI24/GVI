int decode_bitmap_rle(BYTE *encoded_data, size_t encoded_size, BYTE *decoded_bitmap, int width, int height) {
    int x, y;
    size_t index = 0;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width;) {
            if (index >= encoded_size) return -1; // Check to prevent reading beyond encoded_data
            BYTE value = encoded_data[index++];
            if (value > 0) {
                // Possible buffer overflow if decoded_bitmap is not large enough
                memset(decoded_bitmap + (y * width) + x, value, value);
                x += value;
            } else {
                x++;
            }
        }
    }
    return 0;
}

