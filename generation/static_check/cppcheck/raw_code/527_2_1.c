void parse_log_entry(const char *log_entry) {
    char *token;
    char token_buffer[100];
    char delimiter = '|';

    // Tokenize the log entry using a delimiter
    token = strtok((char *)log_entry, &delimiter);

    while (token != NULL) {
        // Unsafe copy into a fixed-size buffer
        strcpy(token_buffer, token);
        // Process token here...

        token = strtok(NULL, &delimiter);
    }
}

