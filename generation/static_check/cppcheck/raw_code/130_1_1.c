void log_user_activity(char *user_data, char *log_buffer) {
    // Format string vulnerability if user_data contains format specifiers
    sprintf(log_buffer, "User activity: %s", user_data);
}

