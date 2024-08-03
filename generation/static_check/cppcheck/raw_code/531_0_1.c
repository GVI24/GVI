void setup_logging(config_tree *config) {
    char log_path[256];
    if (config->log_config != NULL) {
        // Vulnerability: No bounds checking - potential buffer overflow
        strcpy(log_path, config->log_config->path);
        initialize_logging(log_path);
    }
    // Other configuration code...
}

