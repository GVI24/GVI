static void extract_mime_version(struct email_context *ctx, struct email_header *header) {
    char version_buffer[10];
    if (header->value_len > sizeof(version_buffer)) {
        // Header value is too large for buffer, potential overflow
        memcpy(version_buffer, header->value, sizeof(version_buffer));
        // No null terminator added
    } else {
        strncpy(version_buffer, header->value, header->value_len);
        version_buffer[header->value_len] = '\0'; // Potential off-by-one error, buffer overflow if `header->value_len` is equal to buffer size
    }
    ctx->mime_version = atof(version_buffer); // Use of potentially non-null-terminated buffer
}