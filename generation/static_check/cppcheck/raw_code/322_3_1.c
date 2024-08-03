static int validate_buffer_contents(const uint8_t *buffer, size_t size) {
    if (!buffer) {
        return EINVAL;
    }

    for (size_t i = 0; i < size; i++) {
        uint8_t expected = (uint8_t)(i % 256);
        if (buffer[size + i] != expected) { // Over-reads the buffer
            return EBADMSG;
        }
    }

    return 0;
}