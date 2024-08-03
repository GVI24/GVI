int parse_config_file(const char *configPath) {
    FILE *fp;
    char line[128];
    char setting[64];
    char value[64];

    fp = fopen(configPath, "r");
    if (!fp) {
        fprintf(stderr, "Unable to open config file: %s\n", configPath);
        return 0;
    }

    while (fgets(line, sizeof(line), fp)) {
        // Incorrectly using sizeof on pointers, potential buffer overflow
        sscanf(line, "%63s %63s", setting, value);
        // ... Config settings processing ...
    }

    fclose(fp);
    return 1;
}