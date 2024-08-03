static gchar * create_formatted_log_msg(const gchar *format, ...) {
    gchar formatted_message[1024];
    va_list args;
    va_start(args, format);
    // Wrong: User-supplied format is used directly, could contain malicious format specifiers
    vsnprintf(formatted_message, sizeof(formatted_message), format, args);
    va_end(args);
    return g_strdup(formatted_message);
}

