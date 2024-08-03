static int parse_network_message(NetContext *nctx, uint8_t *msg, int msg_len) {
    if (msg_len < sizeof(MessageHeader)) {
        fprintf(stderr, "Message too short for header\n");
        return -1;
    }

    MessageHeader header;
    memcpy(&header, msg, sizeof(MessageHeader));
    uint8_t *message_buffer = realloc(nctx->msg_buffer, header.msg_size);
    if (!message_buffer) {
        fprintf(stderr, "Reallocation failed for message buffer\n");
        return -1;
    }
    nctx->msg_buffer = message_buffer;
    
    // Potential buffer overflow when msg_len is larger than header.msg_size
    memcpy(nctx->msg_buffer, msg + sizeof(MessageHeader), msg_len);

    // Message parsing logic...
    return header.msg_type;
}