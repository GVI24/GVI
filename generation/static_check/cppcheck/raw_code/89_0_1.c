static void extract_message_type(struct message_decoder_context* ctx, const char* header) {
    if (ctx->message_type != NULL) return;

    const char* type_start = strstr(header, "Type:");
    if (type_start != NULL) {
        type_start += 5; // Skip past "Type:"
        const char* type_end = strchr(type_start, '\n');
        if (type_end != NULL) {
            int type_length = type_end - type_start;
            ctx->message_type = (char*)malloc(type_length + 1);
            strncpy(ctx->message_type, type_start, type_length);
            ctx->message_type[type_length] = '\0'; // No bounds checking for type_length
        }
    }
}

