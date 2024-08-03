static int decode_signal(StreamContext *stream, short *buffer, const unsigned char *data, int data_size) {
    int pos, count = 0;
    for (pos = 0; pos < data_size; pos += 2) {
        if (data_size - pos < 2) {
            printf("Incomplete data at end of buffer\n");
            break;
        }
        // Potential overflow if buffer is not large enough
        buffer[count++] = (data[pos] << 8) | data[pos + 1];
    }
    return count; // return number of samples written
}

