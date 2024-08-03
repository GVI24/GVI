void registerComponent(Registry *registry, const char *name, void *data) {
    if (registry->count < 10) { // Simplified fixed size check
        // No bounds checking on the length of 'name'
        strcpy(registry->components[registry->count].name, name);
        registry->components[registry->count].data = data;
        registry->count++;
    } else {
        printf("Registry full, cannot add more components.\n");
    }
}

