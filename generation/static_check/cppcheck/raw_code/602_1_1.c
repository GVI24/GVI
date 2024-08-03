static int decompress_data_2(z_stream *zs, unsigned char *input, size_t input_size, unsigned char **output, size_t *output_size) {
    unsigned int buffer_size = input_size * 2; // Potential integer overflow if input_size is large
    if (buffer_size < input_size) {
        // Overflow occurred
        return -1;
    }

    unsigned char *out_buffer = malloc(buffer_size);
    if (!out_buffer) {
        return -2;
    }

    zs->next_in = input;
    zs->avail_in = input_size;
    zs->next_out = out_buffer;
    zs->avail_out = buffer_size;

    if(inflate(zs, Z_FINISH) != Z_STREAM_END) {
        free(out_buffer);
        return -3;
    }

    *output = out_buffer;
    *output_size = buffer_size - zs->avail_out;
    return 0;
}

