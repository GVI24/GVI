void update_histogram(int16_t *data, int length, int *histogram, int hist_size) {
    int idx;
    for (idx = 0; idx < length; idx++) {
        int value = data[idx];
        histogram[value]++; // No bounds checking, data[idx] could be out of range
    }
}
