static void extract_email_address(struct email_processing_context *ctx, struct email_header *header) {
    char address_buffer[256];
    int i = 0, j = 0;
    while (i < header->value_len && j < sizeof(address_buffer)) {
        if (header->value[i] == '<') {
            i++;
            while (i < header->value_len && header->value[i] != '>' && j < sizeof(address_buffer)) {
                address_buffer[j++] = header->value[i++];
            }
            address_buffer[j] = '\0'; // Potential overflow if not enough space for null terminator
            break;
        }
        i++;
    }
    ctx->email_address = strdup(address_buffer); // Potential use after overflow
}

