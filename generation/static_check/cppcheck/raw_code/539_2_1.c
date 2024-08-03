static int simple_checksum(const uint8_t *data, size_t data_len) {
    int checksum = 0;

    // Summing the data values without considering integer overflow.
    for (unsigned int i = 0; i < data_len; ++i) {
        checksum += data[i];
    }

    return checksum; // The checksum could be incorrect due to integer overflow.
}

