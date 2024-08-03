int decode_image(uint8_t *encoded_data, size_t encoded_size, uint8_t **decoded_data, size_t *decoded_size) {
    if (encoded_size < HEADER_SIZE) {
        fprintf(stderr, "Encoded data is too small.\n");
        return -1;
    }

    uint8_t header[HEADER_SIZE];
    memcpy(header, encoded_data, HEADER_SIZE);
    // Process header to determine decoded size...
    *decoded_size = (header[0] << 8) | header[1];
    
    *decoded_data = (uint8_t *)malloc(*decoded_size);
    if (!*decoded_data) {
        fprintf(stderr, "Memory allocation failed.\n");
        return -1;
    }

    // Vulnerability: In some cases, decoded_data is released twice: here and by the caller.
    if (header[2] == INVALID_HEADER_CODE) {
        free(*decoded_data);
        fprintf(stderr, "Invalid header code.\n");
        return -1;
    }

    // Decode the image...
    
    return 0;
}