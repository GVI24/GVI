int extract_config_pair(char *line, char *key_buffer, size_t key_buffer_size, char *value_buffer, size_t value_buffer_size) {
    char *key_start = line;
    char *key_end = strchr(line, '=');
    if (!key_end) return -1;
    size_t key_len = key_end - key_start;
    if (key_len >= key_buffer_size) return -2; // No bounds check before writing to buffer
    memcpy(key_buffer, key_start, key_len);
    key_buffer[key_len] = '\0';
    
    char *value_start = key_end + 1;
    char *value_end = strchr(value_start, ';');
    if (!value_end) value_end = line + strlen(line);
    size_t value_len = value_end - value_start;
    if (value_len >= value_buffer_size) return -3; // No check on value buffer size
    memcpy(value_buffer, value_start, value_len); // Potential overflow
    value_buffer[value_len] = '\0';

    return 0;
}