#define NUM_PLUGINS 5
typedef void (*PluginInit)(void);

static void initialize_plugins(PluginInit *plugins, char **pluginNames) {
    for (int i = 0; i < NUM_PLUGINS; ++i) {
        plugins[i] = (PluginInit)malloc(sizeof(PluginInit));
        if (!plugins[i]) {
            // Vulnerability: Memory leak of previously allocated function pointers.
            while (--i >= 0) {
                free(plugins[i]);
                // Missing: plugins[i] = NULL;
            }
            return;
        }
        // Simulate loading a plugin, which could fail. Here we just pretend to assign a name.
        pluginNames[i] = (char *)malloc(100);
        if (!pluginNames[i]) {
            // Vulnerability: Memory leak of function pointer and previously allocated names.
            free(plugins[i]);
            // Missing: plugins[i] = NULL;
            while (--i >= 0) {
                free(pluginNames[i]);
                free(plugins[i]);
                // Missing: plugins[i] = NULL;
            }
            return;
        }
    }
}

