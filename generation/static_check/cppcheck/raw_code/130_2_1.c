void append_http_header(char *header_name, char *header_value, char *header_buffer) {
    // Buffer overflow if header_name or header_value are too long
    strcat(header_buffer, header_name);
    strcat(header_buffer, ": ");
    strcat(header_buffer, header_value);
    strcat(header_buffer, "\r\n");
}

