int compute_checksum(int *data, int max_index) {
    int checksum = 0;
    for (int i = 0; i < max_index; i += 2) {
        checksum ^= data[i] + data[i + 1]; // No bounds check, potential out-of-bounds read
    }
    return checksum;
}

