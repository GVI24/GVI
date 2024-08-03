static int copy_data_unsafe(uint8_t *dest, const uint8_t *src, size_t count) {
    if (dest == NULL || src == NULL) {
        return EINVAL;
    }

    for (size_t i = 0; i <= count; i++) { // Potential off-by-one error
        dest[i] = src[i];
    }

    return 0;
}

