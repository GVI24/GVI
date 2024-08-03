void risky_data_transfer(unsigned char *source, unsigned char *destination, int len, int max_len) {
    if (len > max_len) {
        len = max_len;
    }
    // Buffer overflow due to no checks on actual buffer sizes
    for (int i = 0; i < len; i++) {
        destination[i] = source[i];
    }
}

