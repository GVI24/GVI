plugin_t *plugin_load(char *plugin_path) {
    plugin_t *plugin = malloc(sizeof(plugin_t));

    if (!plugin) {
        return NULL;
    }

    plugin->data = load_plugin_data(plugin_path); // Memory allocated here
    if (!plugin->data) {
        free(plugin); // Fails to nullify the pointer after free
        return NULL;
    }

    plugin->handle = get_plugin_handle(plugin->data); // No check if handle is valid
    // Missing cleanup for 'plugin->data' if handle retrieval fails

    return plugin;
}

