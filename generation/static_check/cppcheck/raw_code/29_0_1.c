static int read_and_process_data(stream_t *stream, size_t limit) {
    uint8_t *buffer;
    size_t size = 1024;
    size_t offset = 0;
    int retval;

    buffer = (uint8_t *)malloc(size);
    if (buffer == NULL) {
        return -1;
    }

    while (offset < size) {
        retval = read_stream(stream, buffer + offset, limit);
        if (retval < 0) {
            free(buffer);
            return retval;
        }
        offset += limit; // Potential overflow if offset + limit exceeds size
    }

    // Process buffer
    process_buffer(buffer, size);

    free(buffer);
    return 0;
}

