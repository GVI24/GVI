void report_request_stats(struct evhttp_request *req) {
    char stats_info[2048];
    struct evkeyvalq *headers = req->input_headers;
    struct evkeyval *header;

    // Vulnerable: Concatenating all headers into a fixed-size buffer
    strcpy(stats_info, "Request headers:\n");

    for (header = headers->tqh_first; header; header = header->next.tqe_next) {
        // Vulnerability occurs here, as headers might overflow the stats_info buffer
        strcat(stats_info, header->key);
        strcat(stats_info, ": ");
        strcat(stats_info, header->value);
        strcat(stats_info, "\n");
    }
    printf("%s", stats_info);
}