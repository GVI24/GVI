#define HEADER_SIZE 8
#define MAX_FRAME_SIZE 1024

void decode_frame(const uint8_t *frame_data, size_t frame_size) {
    if (frame_size < HEADER_SIZE) {
        // Error: Incomplete frame header
        return;
    }

    uint16_t payload_size = ntohs(*(uint16_t *)(frame_data + 6));
    uint8_t payload[MAX_FRAME_SIZE];

    // Vulnerability: payload_size might be greater than MAX_FRAME_SIZE.
    if (payload_size + HEADER_SIZE != frame_size) {
        // Error: Frame size mismatch
        return;
    }

    // Unsafe copy of the payload into the local buffer
    memcpy(payload, frame_data + HEADER_SIZE, payload_size);

    // Process payload...
}