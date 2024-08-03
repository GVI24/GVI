void generateComponentReport(Registry *registry, char *outputBuffer, int bufferSize) {
    snprintf(outputBuffer, bufferSize, "Component Report:\n");
    for (int i = 0; i < registry->count; ++i) {
        // Unsafe concatenation: no check for remaining buffer space
        strcat(outputBuffer, registry->components[i].name);
        strcat(outputBuffer, "\n");
    }
}

