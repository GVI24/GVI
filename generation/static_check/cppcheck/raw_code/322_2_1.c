static int process_external_data(uint8_t *data, size_t size, size_t offset, uint8_t value) {
    if (data == NULL) {
        return EINVAL;
    }

    for (size_t i = 0; i < size; i++) {
        size_t idx = i + offset; // No bounds check on `idx`
        data[idx] = value;
    }

    return 0;
}

