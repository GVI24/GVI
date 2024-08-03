int parse_custom_network_header(const unsigned char *header, int len) {
    int index = 0;
    while (index < len) {
        int field_type = header[index];
        int field_len = header[index + 1];
        if (index + field_len > len) { // Missing bounds check for field_len
            return -1;
        }
        // Process field...
        index += field_len;
    }
    return 0;
}

