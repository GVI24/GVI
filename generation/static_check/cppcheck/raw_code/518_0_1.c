int parse_network_message(char *buffer, int buf_length) {
    char header[64];
    char *ptr = buffer;
    int header_length = 0;
    while (*ptr != ';' && header_length < buf_length) {
        header[header_length++] = *ptr++;
        if (header_length >= sizeof(header)) {
            // Vulnerable to buffer overflow if header part of the buffer is too long
            break;
        }
    }
    // The rest of the message processing code would go here...
    return 0;
}