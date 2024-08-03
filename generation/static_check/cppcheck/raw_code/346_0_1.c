static void extract_email_address(struct email_processor *proc, const struct message_header_line *hdr) {
    struct rfc822_parser_context parser;
    char email_addr[256];

    if (proc->sender_email != NULL) return;

    rfc822_parser_init(&parser, hdr->full_value, hdr->full_value_len, NULL);
    rfc822_skip_lwsp(&parser);

    T_BEGIN {
        rfc822_parse_email_address(&parser, email_addr, sizeof(email_addr));
        proc->sender_email = strdup(email_addr);
    } T_END;
}