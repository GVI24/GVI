int find_terminating_quote(char **params, int count) {
    int pos;
    for (pos = 0; pos < count; pos++) {
        if (params[pos][0] == '"' && params[pos][strlen(params[pos]) - 1] == '"') {
            return pos;
        }
    }
    // If no matching parameter is found, return an error code
    return -1;
}

