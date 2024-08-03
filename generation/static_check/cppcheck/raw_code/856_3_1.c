int decode_messages(const unsigned char *encoded_msg, int total_len) {
    int cursor = 0;
    while (cursor < total_len) {
        int msg_size = encoded_msg[cursor] | (encoded_msg[cursor + 1] << 8);
        cursor += 2; // Potential off-by-one error as no check is done before increment.
        if (cursor + msg_size > total_len) { // Missing verification for msg_size
            return -1;
        }
        // Decode message...
        cursor += msg_size;
    }
    return 0;
}