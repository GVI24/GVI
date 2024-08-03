int unpack_bits_to_image(const BYTE *packed_bits, size_t packed_size, BYTE *image, int line_stride, int lines) {
    size_t i;
    int line;
    for (line = 0; line < lines; line++) {
        // No check to prevent writing beyond the line_stride * lines in image buffer
        for (i = 0; i < (size_t)line_stride; i++) {
            if (i / 8 >= packed_size) return -1; // Check to avoid reading beyond packed_bits
            // Bit manipulation, potential buffer overflow
            image[line * line_stride + i] = (packed_bits[i / 8] >> (7 - (i % 8))) & 1;
        }
    }
    return 0;
}

