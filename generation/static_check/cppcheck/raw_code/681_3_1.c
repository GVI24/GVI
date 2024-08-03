#define INFO_HEADER 10

void parse_control_message(uint8_t *msg, uint32_t msg_size) {
    if (msg_size < INFO_HEADER) {
        // Error: Message is too small
        return;
    }

    uint32_t info_size = *(uint32_t *)(msg + 6);
    uint8_t info_data[256];

    // Vulnerability: Using info_size from the message for buffer operations.
    if (info_size > msg_size - INFO_HEADER) {
        // Error: Info size is larger than the remaining message size
        return;
    }

    // Directly copying a large info_size value into a fixed-size array
    memcpy(info_data, msg + INFO_HEADER, info_size);

    // Do something with the info_data...
}