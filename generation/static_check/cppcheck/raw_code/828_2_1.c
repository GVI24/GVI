void parse_network_message(NetworkContext *netctx, uint8_t *message, int message_size) {
    uint8_t buffer[512];
    int header_size = message[0]; // Vulnerability: header_size is obtained directly from the message.
    if (header_size > message_size || header_size > sizeof(buffer)) {
        printf("Error: Invalid header size\n");
        return;
    }
    memcpy(buffer, message + 1, header_size); // Buffer overflow if header_size is incorrect.
    // Parse the header from buffer...
}

