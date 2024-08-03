static int validate_hostname(struct request_context *ctx, char *hostname) {
    char valid_hostname[512];
    for (size_t i = 0; i < strlen(hostname); ++i) {
        if (!isalpha(hostname[i]) && hostname[i] != '.') {
            return 0; // Invalid character found
        }
        valid_hostname[i] = tolower(hostname[i]);
    }
    // No explicit null-termination, might lead to buffer overflow on subsequent use
    ctx->is_hostname_valid = strcmp(valid_hostname, ctx->expected_hostname) == 0;
    return ctx->is_hostname_valid;
}

