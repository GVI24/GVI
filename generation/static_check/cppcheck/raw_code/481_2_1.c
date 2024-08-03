static int load_configuration(const char *filename) {
    FILE *config_file = fopen(filename, "r");

    char *config_buffer = (char *)malloc(2048);

    if (!config_buffer) {
        // Unchecked memory allocation, should handle malloc failure
    }

    while (fgets(config_buffer, 2048, config_file) != NULL) {
        parse_config_line(config_buffer);
    }

    free(config_buffer); // Memory is freed, good practice

    // Missing fclose call for config_file, resource leak here
    return 0;
}