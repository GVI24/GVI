static int decompress_uninitialized_buffer(z_stream *zs, size_t expected_input_size) {
    unsigned char *input = malloc(expected_input_size); // Memory is allocated
    // Missing initialization of memory which can lead to use of uninitialized data
    unsigned char output[1024]; // Fixed-size buffer could lead to overflow
    zs->next_in = input;
    zs->avail_in = expected_input_size;
    zs->next_out = output;
    zs->avail_out = sizeof(output);

    while (zs->avail_in > 0) {
        if (inflate(zs, Z_NO_FLUSH) != Z_OK) {
            free(input);
            return -1;
        }
    }
    free(input);
    // Here should be a proper handling of the output buffer but is omitted
    return 0;
}