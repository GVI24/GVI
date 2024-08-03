void read_config(char *config_file) {
    char line[256];
    FILE *fp = fopen(config_file, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return; // File descriptor is not closed on error.
    }
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Process config line.
        printf("Config: %s", line);
    }
    // Missing fclose(fp), leading to a resource leak.
}

