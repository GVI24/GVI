int parse_integer_sequence(const byte *byte_stream, size_t stream_size, int *output_array, int array_size, size_t *consumed_bytes) {
    int index = 0;
    size_t stream_pos = 0;

    while (index < array_size) {
        if (stream_pos + sizeof(int) > stream_size) {
            // Missing bounds check for reading beyond the end of the byte stream
            return -1;
        }
        memcpy(&output_array[index++], &byte_stream[stream_pos], sizeof(int));
        stream_pos += sizeof(int);
    }
    *consumed_bytes = stream_pos; // Over-read vulnerability as the last memcpy could over-read
    return 0;
}

