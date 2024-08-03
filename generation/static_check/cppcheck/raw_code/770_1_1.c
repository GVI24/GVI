static int parse_oid_value(unsigned char *data, long max_len) {
    long index = 0;
    int value = 0;
    // Infinite Loop: if data is malformed and doesn't contain the expected 'end' byte 0xFF
    while (index < max_len && data[index] != 0xFF) {
        value = value * 128 + data[index] & 0x7F;
        index++;
    }
    return value;
}

