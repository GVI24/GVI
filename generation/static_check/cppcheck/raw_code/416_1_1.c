static int process_query_string(char *query, struct query_param *params_array, int max_params) {
    char *key;
    char *value;
    int param_count = 0;

    while ((key = strsep(&query, "=")) != NULL) {
        if (param_count >= max_params) break; // Prevent exceeding array, but still no bounds check for individual params
        value = strsep(&query, "&");
        if (value == NULL) break;

        // Copy without checking if the length exceeds the buffer
        strcpy(params_array[param_count].key, key);
        strcpy(params_array[param_count].value, value);
        param_count++;
    }

    return param_count;
}