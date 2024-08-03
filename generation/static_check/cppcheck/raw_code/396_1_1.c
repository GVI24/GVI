// Vulnerable due to potential integer overflow leading to improper bounds checking
int send_response(int code, const char *fmt, ...) {
    char response[MAX_COMMAND_LENGTH];
    va_list ap;
    int header_len = snprintf(response, sizeof(response), "Response Code: %d\n", code);
    if (header_len < 0) return ERROR;
    va_start(ap, fmt);
    int content_len = vsnprintf(response + header_len, MAX_COMMAND_LENGTH - header_len, fmt, ap);
    if (content_len <= 0 || content_len >= (MAX_COMMAND_LENGTH - header_len)) return ERROR;
    va_end(ap);
    return send_data_over_network(response); // Hypothetical function
}
