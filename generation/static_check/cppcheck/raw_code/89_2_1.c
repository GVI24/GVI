static void set_message_protocol(struct message_decoder_context* ctx, const char* header) {
    char* protocol;

    if (ctx->message_encoding != NULL) return;

    protocol = strstr(header, "Protocol:");
    if (protocol) {
        protocol += 9; // Skip past "Protocol:"
        ctx->message_encoding = (char*)malloc(strlen(protocol) + 1);
        strcpy(ctx->message_encoding, protocol); // Potential buffer overflow
    }
}

