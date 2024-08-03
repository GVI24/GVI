int decode_channel(int32_t *channel_data, size_t data_size, size_t max_size) {
    size_t i = 0;
    int32_t sample = 0;
    // No check if data_size exceeds max_size, leading to possible buffer overflow
    while (i < data_size) {
        channel_data[i] = sample;
        i++;
    }
    return 0;
}