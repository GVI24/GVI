static void parse_disposition(struct mail_attachment *attachment, const struct message_header_line *hdr) {
    struct rfc822_parser_context parser;
    char disposition[128];

    if (attachment->content_disposition != NULL) return;

    rfc822_parser_init(&parser, hdr->full_value, hdr->full_value_len, NULL);
    rfc822_skip_lwsp(&parser);

    T_BEGIN {
        rfc822_parse_content_disposition(&parser, disposition, sizeof(disposition));
        attachment->content_disposition = strdup(disposition);
    } T_END;
}