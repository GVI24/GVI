static void _ResourceCleaner(UResource *resource) {
    if (resource->internalData != NULL) {
        for (int idx = 0; idx < RESOURCE_LIMIT; idx++) {
            if (resource->internalData->dataEntries[idx] != NULL) {
                dataUnload(resource->internalData->dataEntries[idx]);
            }
        }
        if (!resource->isInternalLocal) {
            free(resource->internalData); // Resource is freed here.
            // Missing: resource->internalData = NULL;
        }
    }
    // Dangerous: other code might still use resource->internalData here.
}