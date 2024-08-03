static int load_configuration_file(ConfigContext *config_ctx, const uint8_t *cfg_data, size_t cfg_size) {
    unsigned cfg_length;
    if (cfg_size < 2) {
        printf("Configuration data too small\n");
        return -1;
    }
    cfg_length = cfg_data[0] | cfg_data[1] << 8;

    if (cfg_length > cfg_size - 2) {
        printf("Configuration length exceeds buffer size\n");
        return -1;
    }
    if (cfg_length > CONFIG_MAX_SIZE) {
        printf("Configuration data too large\n");
        return -1;
    }
    memcpy(config_ctx->data, cfg_data + 2, cfg_length); // Potential buffer overflow if CONFIG_MAX_SIZE is not respected
    return 0;
}