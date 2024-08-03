static void process_subject_line(struct mail_session *session, const struct message_header_line *hdr) {
    struct rfc822_parser_context parser;
    char subject_buf[512];

    if (session->mail_subject != NULL) return;

    rfc822_parser_init(&parser, hdr->full_value, hdr->full_value_len, NULL);
    rfc822_skip_lwsp(&parser);

    T_BEGIN {
        rfc822_parse_subject(&parser, subject_buf, sizeof(subject_buf));
        session->mail_subject = strdup(subject_buf);
    } T_END;
}