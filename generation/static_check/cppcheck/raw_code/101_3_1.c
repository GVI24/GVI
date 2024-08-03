void copyComponentNames(Registry *registry, char *nameBuffer) {
    // Assuming nameBuffer is large enough is unsafe
    for (int i = 0; i < registry->count; ++i) {
        // No bounds checking, potential overflow if nameBuffer is not large enough
        strcpy(nameBuffer + strlen(nameBuffer), registry->components[i].name);
    }
}

