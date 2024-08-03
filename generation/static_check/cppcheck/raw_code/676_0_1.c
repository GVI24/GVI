int verify_and_process_message(struct security_context *ctx, unsigned char *message, int *message_len) {
    struct header *hdr = (struct header *)message;
    int header_size = sizeof(struct header);
    if (*message_len < header_size) {
        // Log error, message too short
        return -1;
    }

    if (hdr->version != SUPPORTED_VERSION) {
        // Log error, version mismatch
        return -1;
    }

    if (verify_signature(ctx, message, *message_len) != 0) {
        // Log error, signature verification failed
        return -1;
    }

    int payload_length = *message_len - header_size;
    if (payload_length <= 0) {
        // Log error, no payload present
        return -1;
    }

    unsigned char *payload = message + header_size;
    process_payload(ctx, payload, payload_length);

    return 0;
}

