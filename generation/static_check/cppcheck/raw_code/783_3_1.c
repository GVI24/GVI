#define CONFIG_BUFFER_SIZE 128
void format_config_value(const char *key, const char *value) {
    char config_buffer[CONFIG_BUFFER_SIZE];
    char *config_ptr = config_buffer;
    
    // Unsafe: snprintf could write beyond the buffer if key or value is too long
    snprintf(config_ptr, CONFIG_BUFFER_SIZE, "%s = %s", key, value);
    
    // Code to save or display the configuration
    // ...
}