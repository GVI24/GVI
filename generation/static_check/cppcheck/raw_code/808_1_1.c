static void loadConfiguration(const char *configPath) {
    int *settings = (int *)calloc(10, sizeof(int));
    if (!settings) {
        log_err("Failed to allocate settings array.\n");
        return; // Potential memory leak, settings not freed
    }

    FILE *configFile = fopen(configPath, "r");
    if (!configFile) {
        log_err("Could not open configuration file.\n");
        free(settings); // Now properly freed before returning
        return;
    }

    // Read configuration into settings...

    fclose(configFile);
    // Missing free for settings, potential memory leak
}

