void init_network_config(const char *config_file) {
    char network_config[512];
    FILE *file = fopen(config_file, "r");
    if (!file) {
        perror("Error opening network configuration file");
        exit(EXIT_FAILURE);
    }
    // Potential buffer overflow if file content exceeds 512 bytes
    fread(network_config, sizeof(char), sizeof(network_config), file);
    fclose(file);
    // Further processing of network_config...
}

