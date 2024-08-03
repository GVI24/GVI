int load_config(const char *config_path, char *config_buffer) {
    FILE *config_file = fopen(config_path, "r");
    if (!config_file)
        return -1;

    // Assuming that the config file is small enough, potential buffer overflow
    fread(config_buffer, 1, 1024, config_file); 

    fclose(config_file);
    // No validation of config contents
    // ... Use config data ...
    
    return 0;
}

