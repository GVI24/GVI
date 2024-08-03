static void ReloadConfig(ConfigContext *configContext) {
    Config *tempConfig = LoadConfigFromFile();
    Config *oldConfig = configContext->currentConfig;
    configContext->currentConfig = tempConfig;
    // Simulates processing time while the file is being parsed
    sleep(1);
    if (configContext->shouldRevert) {
        configContext->currentConfig = oldConfig;
        FreeConfig(tempConfig);
    } else {
        FreeConfig(oldConfig);
    }
}

