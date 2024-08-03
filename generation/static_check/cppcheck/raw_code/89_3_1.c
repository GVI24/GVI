static void parse_message_version(struct message_decoder_context* ctx, const char* header) {
    char* version_start;

    if (ctx->message_type != NULL) return;

    version_start = strstr(header, "Version:");
    if (version_start) {
        version_start += 8; // Skip past "Version:"
        char* version_end = strstr(version_start, ";");
        if (version_end != NULL) {
            int version_length = version_end - version_start;
            ctx->message_type = (char*)malloc(version_length + 1);
            memcpy(ctx->message_type, version_start, version_length); // No bounds checking
            ctx->message_type[version_length] = '\0';
        } else {
            ctx->message_type = strdup(version_start); // Buffer overflow if version_start is too long
        }
    }
}