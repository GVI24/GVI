int parse_header(const unsigned char *packet, size_t length) {
    unsigned int header_length;
    unsigned char header[128];

    // Assume the header length is the first 4 bytes of the packet
    memcpy(&header_length, packet, sizeof(header_length));

    // Vulnerability: No check if header_length exceeds the length of the header buffer
    if (header_length > length - sizeof(header_length)) {
        return -1; // Insufficient packet size but not for header buffer
    }

    memcpy(header, packet + sizeof(header_length), header_length);
    // Process header...

    return 0;
}

