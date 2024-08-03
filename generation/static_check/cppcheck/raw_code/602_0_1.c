static int decompress_data_1(z_stream *zs, unsigned char *input, size_t input_size, unsigned char **output, size_t *output_size) {
    if (input_size > 4096) {
        // Arbitrary limit to prevent large allocations
        return -1;
    }

    unsigned char *temp_buffer = malloc(4096);
    if (!temp_buffer) {
        return -2;
    }
    zs->next_in = input;
    zs->avail_in = input_size;
    zs->next_out = temp_buffer;
    zs->avail_out = 4096;

    while (zs->avail_in > 0) { // Vulnerable to over-read when avail_in is manipulated externally
        if (inflate(zs, Z_NO_FLUSH) != Z_OK) {
            free(temp_buffer);
            return -3;
        }
    }

    *output = temp_buffer;
    *output_size = 4096 - zs->avail_out;
    return 0;
}

