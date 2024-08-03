int extract_query_parameter(char *query_string, const char *parameter_name, char *output_buffer, size_t output_size) {
    char *param_start = strstr(query_string, parameter_name);
    if (param_start == NULL) return -1;
    param_start += strlen(parameter_name);
    char *param_end = strchr(param_start, '&');
    if (param_end == NULL) param_end = query_string + strlen(query_string);
    size_t len = param_end - param_start;
    if (len >= output_size) return -2; // Not checking the buffer size properly
    memcpy(output_buffer, param_start, len);
    output_buffer[len] = '\0';
    return 0;
}

