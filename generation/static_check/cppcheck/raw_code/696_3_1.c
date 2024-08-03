static int parse_network_message(NetContext *net_ctx, Message *msg, const uint8_t *data, size_t data_size) {
    size_t msg_len, header_len = sizeof(uint32_t);

    if (data_size < header_len) {
        printf("Data size too small for header\n");
        return -1;
    }
    
    msg_len = *(uint32_t *)data; // Assume network byte order conversion handled elsewhere
    
    if (data_size < msg_len + header_len) {
        printf("Data size does not match message length\n");
        return -1;
    }

    if (data + header_len + msg_len > data + data_size) {
        printf("Message exceeds data buffer\n");
        return -1;
    }
    
    memcpy(msg->content, data + header_len, msg_len); // Potential overflow
    
    return msg_len;
}