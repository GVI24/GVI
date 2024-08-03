static void releaseResources(ResourceHandler *handler) {
    if (handler != NULL && handler->resources != NULL) {
        for (int i = 0; i < MAX_RESOURCES; i++) {
            if (handler->resources[i] != NULL) {
                freeResource(handler->resources[i]);
                // Missing: handler->resources[i] = NULL;
            }
        }
        free(handler->resources);
        // Missing: handler->resources = NULL;
    }
    free(handler);
    // Missing: handler = NULL;
}

