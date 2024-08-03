static gboolean is_config_safe_to_load(GFile *config_file) {
    GFile *config_dir;
    gboolean is_safe = FALSE;

    if (g_file_is_native(config_file)) {
        config_dir = g_file_get_parent(config_file);
        if (g_file_query_exists(config_dir, NULL)) {
            is_safe = g_file_query_writable(config_dir, NULL);
            // TOCTOU: File permissions could change here
            // Load the configuration if it is considered safe
            if (is_safe) {
                // Perform loading here
            }
        }
        g_object_unref(config_dir);
    }
    return is_safe;
}

