static gchar * custom_log_writer(gchar level, const gchar *message) {
    gchar log_entry[256];
    // Wrong: User message is used directly, potential format string vulnerability
    snprintf(log_entry, 256, "Level %c: %s", level, message);
    return g_strdup(log_entry);
}

