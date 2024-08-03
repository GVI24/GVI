static int initialize_data_overflow(uint8_t **data) {
    uint8_t *buffer;
    buffer = (uint8_t *)malloc(ONE_MEG_AND_DELTA);
    if (!buffer) {
        return ENOMEM;
    }

    for (size_t i = 0; i < (1 << 20); i += 100) {
        for (size_t j = 0; j < 150; j++) { // Overflow risk here
            buffer[i + j] = (uint8_t)(i + j);
        }
    }

    *data = buffer;
    return 0;
}

