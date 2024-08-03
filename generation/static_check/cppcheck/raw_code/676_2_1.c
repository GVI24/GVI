int process_incoming_data(struct channel *chan, unsigned char *input_data, int *input_len) {
    if (*input_len < sizeof(struct message_header)) {
        // Log error, input length too small
        return -1;
    }

    struct message_header *mh = (struct message_header *)input_data;

    if (!is_supported_protocol(mh->protocol_id)) {
        // Log error, protocol not supported
        return -1;
    }

    unsigned char *message_body = input_data + sizeof(struct message_header);
    int message_body_length = *input_len - sizeof(struct message_header);

    if (unscramble_message(chan, message_body, message_body_length) != 0) {
        // Log error, message unscrambling failed
        return -1;
    }

    if (!validate_checksum(message_body, message_body_length)) {
        // Log error, checksum invalid
        return -1;
    }

    return 0;
}

