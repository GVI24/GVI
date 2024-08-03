#include <string.h>

void parse_http_header(char *header_buffer, int header_size, char *output, int max_output_size) {
    int header_length;
    char *header_end;

    // Find the end of the HTTP header assuming header ends with "\r\n\r\n"
    header_end = strstr(header_buffer, "\r\n\r\n");
    if (header_end) {
        header_length = header_end - header_buffer + 4; // Including the "\r\n\r\n"
    } else {
        header_length = header_size; // Assume entire buffer is the header if no end found
    }

    // Vulnerability: no check to ensure header_length is less than max_output_size
    memcpy(output, header_buffer, header_length);
    output[header_length] = '\0'; // Null-terminate the string
}