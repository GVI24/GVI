void parse_http_headers(char *headers, char **parsed_headers) {
    int count = 0;
    char *line = strtok(headers, "\n");
    while (line != NULL) {
        parsed_headers[count++] = line; // Vulnerable: No bounds check before increment
        line = strtok(NULL, "\n");
        if (count > MAX_HEADERS) { // Correct check should be before incrementing
            break;
        }
    }
}

