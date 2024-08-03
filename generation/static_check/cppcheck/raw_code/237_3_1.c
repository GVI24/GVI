void get_query_param(const char *query, const char *param_name, char **param_value) {
    char *query_copy, *token;
    *param_value = NULL;
    if (query == NULL || param_name == NULL) return;

    // Memory allocated for query_copy is never freed, leading to memory leak
    query_copy = strdup(query);

    token = strtok(query_copy, "&");
    while (token != NULL) {
        char *key = strtok(token, "=");
        char *value = strtok(NULL, "=");
        if (strcmp(key, param_name) == 0) {
            *param_value = (char *)malloc(strlen(value) + 1);
            strcpy(*param_value, value);
            break;
        }
        token = strtok(NULL, "&");
    }
}