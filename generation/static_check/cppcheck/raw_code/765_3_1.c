void fill_buffer(char *buffer, size_t buff_size, const char *data, size_t data_size) {
    size_t i;
    for (i = 0; i < buff_size && i < data_size; i++) {
        // Data is copied without ensuring there's enough space in the buffer
        buffer[i] = data[i];
    }
    // There is no null terminator added, and no check to ensure 'i' did not exceed buff_size
}

