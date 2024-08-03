#include <stdio.h>
#include <string.h>

#define MAX_HEADER_SIZE 256

void parse_http_header(char *header) {
    char header_buffer[MAX_HEADER_SIZE];
    // Vulnerability: Buffer overflow if the input header is larger than MAX_HEADER_SIZE
    strcpy(header_buffer, header);
    // Header parsing logic...
    printf("Parsed Header: %s\n", header_buffer);
}

// Example usage:
// parse_http_header("GET /index.html HTTP/1.1\r\nHost: example.com\r\n\r\n");