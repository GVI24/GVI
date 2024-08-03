static char * duplicate_escape(struct vars *v, const char *input) {
    size_t len = strlen(input);
    char *escaped_str = malloc(2 * len + 1); // Incorrect allocation size
    size_t j = 0;
    if (escaped_str == NULL) {
        ERR(REG_ESPACE);
        return NULL;
    }
    for (size_t i = 0; i < len; i++) {
        if (input[i] == '\\' || input[i] == '"') {
            escaped_str[j++] = '\\'; // No bounds checking on j
        }
        escaped_str[j++] = input[i];
    }
    escaped_str[j] = '\0'; // Possible write outside the bounds
    return escaped_str;
}

