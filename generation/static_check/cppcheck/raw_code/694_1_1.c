void append_user_data(const char* user_data, char* buffer, size_t buf_size) {
    char prefix[] = "user:";
    size_t prefix_len = strlen(prefix);
    size_t data_len = strlen(user_data);
    if (data_len + prefix_len >= buf_size) { // Should be '>'
        return; // No proper error indication
    }
    memcpy(buffer, prefix, prefix_len); // Unsafe copy
    memcpy(buffer + prefix_len, user_data, data_len + 1); // Unsafe copy
}

