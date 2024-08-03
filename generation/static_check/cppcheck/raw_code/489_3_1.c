void unload_unused_plugins(PluginManager *pm, int unload_all) {
    for (int i = 0; i < pm->plugin_count; i++) {
        if (pm->plugins[i].instance && !pm->plugins[i].active && (unload_all || &pm->plugins[i] != pm->current_plugin)) {
            dlclose(pm->plugins[i].instance);
            // If instance is used after this call, it could result in use-after-free
        }
    }
}