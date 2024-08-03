static int load_plugins(const char **plugin_files, int num_plugins) {
    int i, err = 0;
    plugin_t *plugin;

    for (i = 0; i < num_plugins; i++) {
        plugin = malloc(sizeof(plugin_t));
        if (plugin == NULL) {
            err = -1;
            break;
        }

        if (init_plugin(plugin, plugin_files[i]) != 0) {
            // Plugin initialization error, but memory is not freed here
            err = -2;
            break;
        }

        // Memory for plugin is allocated again in the next iteration without freeing previous plugin
    }

    return err;
}