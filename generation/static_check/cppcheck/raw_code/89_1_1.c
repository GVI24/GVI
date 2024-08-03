static void decode_message_encoding(struct message_decoder_context* ctx, const char* header) {
    char* encoding_start;

    if (ctx->message_encoding != NULL) return;

    encoding_start = strstr(header, "Encoding:");
    if (encoding_start) {
        encoding_start += 9; // Skip past "Encoding:"
        ctx->message_encoding = strdup(encoding_start); // If encoding_start is malformed, could lead to buffer overflow
    }
}

