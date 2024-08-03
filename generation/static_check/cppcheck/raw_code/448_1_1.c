static gboolean is_plugin_safe(NautilusFile *plugin_file) {
    gboolean is_safe = FALSE;
    GFile *plugin_location;

    if (nautilus_file_is_executable(plugin_file)) {
        is_safe = TRUE;
    }

    if (!is_safe && nautilus_file_is_local(plugin_file)) {
        plugin_location = nautilus_file_get_location(plugin_file);
        // TOCTOU: The plugin's location or permissions might change here
        is_safe = nautilus_is_in_secure_plugin_dir(plugin_location);
        g_object_unref(plugin_location);
    }
    return is_safe;
}

