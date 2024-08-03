static void parse_message_id(struct message_context *msg_ctx, const struct message_header_line *hdr) {
    struct rfc822_parser_context parser;
    char message_id[320];

    if (msg_ctx->message_id != NULL) return;

    rfc822_parser_init(&parser, hdr->full_value, hdr->full_value_len, NULL);
    rfc822_skip_lwsp(&parser);

    T_BEGIN {
        rfc822_parse_msg_id(&parser, message_id, sizeof(message_id));
        msg_ctx->message_id = strdup(message_id);
    } T_END;
}