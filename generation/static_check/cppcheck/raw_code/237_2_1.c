void extract_token_value(const char *input, char **token) {
    const char *separator = "=";
    char *value;

    // If input is NULL or does not contain '=', *token may remain uninitialized
    char *key = strtok((char *)input, separator);
    value = strtok(NULL, separator);

    if (value != NULL) {
        *token = (char *)malloc(strlen(value) + 1);
        strcpy(*token, value); // Unsafe if *token is NULL
    }
}

