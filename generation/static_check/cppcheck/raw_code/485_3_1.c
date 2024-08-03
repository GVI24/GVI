static int parse_config_line(char *config_data, size_t data_size) {
    char *line;
    for (line = config_data; line < config_data + data_size - 1; ++line) {
        if (*line == '\n') {
            *line++ = '\0';
            if (*line != '#') {
                goto bad_config;
            }
            *line = '\0';
        }
    }
    if (line != config_data + data_size && *line != '#' && *line != '`') {
        goto bad_config;
    }
    config_data[data_size - 1] = '\0';
    return 0; // Success
bad_config:
    return -1; // Error
}