void store_parsed_tokens(const char *input) {
    const char *delimiters = " ,;";
    char tokens[20][100];
    int num_tokens = 0;
    char *token = strtok((char *)input, delimiters);

    while (token != NULL) {
        strcpy(tokens[num_tokens++], token); // No boundary check on num_tokens
        token = strtok(NULL, delimiters);
    }

    printf("Storing parsed tokens completed.\n");
}

