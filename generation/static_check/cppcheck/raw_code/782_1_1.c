static gchar * create_status_message(const gchar *status_input) {
    gchar status_msg[512];
    // Wrong: Using user-supplied input directly in snprintf which could contain format specifiers
    snprintf(status_msg, sizeof(status_msg), status_input);
    return g_strdup(status_msg);
}

