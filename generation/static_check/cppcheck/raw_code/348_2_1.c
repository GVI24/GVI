serverConfigPtr loadServerConfig(const char *configFile) {
    serverConfigPtr config;
    FILE *fp;
    config = (serverConfigPtr)malloc(sizeof(serverConfig));
    if (config == NULL) {
        fprintf(stderr, "loadServerConfig: malloc failed\n");
        return NULL;
    }
    fp = fopen(configFile, "r"); // Open configuration file
    if (fp == NULL) {
        fprintf(stderr, "loadServerConfig: failed to open config file\n");
        // Memory leak, 'config' is not freed before returning
        return NULL;
    }
    // ... (code to parse the configuration file and populate 'config')
    fclose(fp);
    return config;
}

