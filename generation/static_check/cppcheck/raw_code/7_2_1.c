static int compressStreamData(struct stream_state *state, unsigned char *data, unsigned int length) {
    unsigned int offset = 0;
    int compressResult;

    while (offset < length) {
        // Vulnerable line: No check for underflow in subtraction
        compressResult = compressData(state->compressor, data + offset, length - offset);
        if (compressResult < 0) {
            fprintf(stderr, "Compression failed\n");
            return -1;
        }
        // Vulnerable line: No check for overflow when incrementing offset
        offset += compressResult;
    }
    return 0;
}

