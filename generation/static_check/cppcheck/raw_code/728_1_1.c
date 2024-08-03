static void load_image_properties(ImageProperties *img, GetBitContext *gb) {
    char format[16];
    int width, height;

    width = get_bits(gb, 16); // Assume width is 16 bits
    height = get_bits(gb, 16); // Assume height is 16 bits

    // Vulnerability: No check if size of format is within bounds
    // Could lead to buffer overflow
    memcpy(format, gb->buffer + gb->index, 16);
    gb->index += 16;

    img->width = width;
    img->height = height;
    strcpy(img->format, format); // Assuming format is a null-terminated string

    // Other processing
    // ...
}

