int process_custom_header(char *packet, size_t packet_len, char *header_buffer, size_t header_buffer_size) {
    char *header_start = strstr(packet, "X-Custom-Header:");
    if (header_start == NULL) return -1;
    header_start += strlen("X-Custom-Header:");
    char *header_end = strchr(header_start, '\r');
    if (header_end == NULL) return -2;
    size_t len = header_end - header_start;
    if (len >= header_buffer_size) return -3; // Not checking the buffer size
    memcpy(header_buffer, header_start, len); // Potential overflow
    header_buffer[len] = '\0';
    return 0;
}

