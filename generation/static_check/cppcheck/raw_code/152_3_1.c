void load_config_options(const char *config_string) {
    char options[3][30];
    int opt_index = 0;
    const char *current = config_string;

    while (*current != '\0' && opt_index < N_ELEMENTS(options)) {
        int len = strchr(current, '\n') - current;
        strncpy(options[opt_index], current, len);
        options[opt_index][len] = '\0'; // No proper boundary check
        current += len + 1;
        opt_index++;
    }

    printf("Configuration options loaded.\n");
}


