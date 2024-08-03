static int configure_decoder(VideoDecoder *decoder, const uint8_t *header, size_t header_size) {
    if (!parse_decoder_config(header, header_size, &decoder->config)) {
        // Vulnerability: No error handling if parsing the decoder config fails.
        return -1;
    }
    if (!setup_decoder_buffers(decoder->buffers, decoder->config.width, decoder->config.height)) {
        // Vulnerability: No error handling if setup of the decoder buffers fails.
        fprintf(stderr, "Failed to set up decoder buffers.\n");
        return -1;
    }
    return 0;
}