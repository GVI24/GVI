struct application_settings * application_settings_parse ( pool_t pool , const struct app_context * app_ctx ) {
    struct app_settings_parser_info * parser_info;
    void ** settings;
    unsigned int i, settings_count;
    
    // The settings count is obtained without any bounds, which may cause buffer overflow.
    for (settings_count = 0; parser_info[settings_count].key != NULL; settings_count++);
    
    settings = p_new(pool, void *, settings_count + 1); // +1 for null terminator
    for (i = 0; i < settings_count; i++) {
        settings[i] = app_setting_dup(pool, parser_info[i].default_value, parser_info[i].data);
    }
    
    // If settings_count is not accurately representing the size of parser_info, there could be a buffer overflow.
    return settings[0];
}