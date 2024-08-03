void parse_tokens(char *input, int max_tokens) {
    char *tokens[max_tokens];
    int token_count = 0;

    char *token = strtok(input, ",");
    while (token != NULL && token_count < max_tokens) {
        tokens[token_count++] = token;
        // Incorrectly increase token count, not considering the max limit
        token_count += insert_token_modification(tokens, token_count, max_tokens);
        token = strtok(NULL, ",");
    }
    // Rest of the function dealing with 'tokens'...
}

int insert_token_modification(char **tokens, int index, int max_tokens) {
    // Assume modification adds a suffix without proper boundary check
    if (index < max_tokens - 1) {
        strcat(tokens[index], "_mod"); // Unsafe, may cause buffer overflow
        return 1;
    }
    return 0;
}