networkResourcePtr acquireNetworkResource(const char *resourceName) {
    networkResourcePtr resource;
    resource = (networkResourcePtr)malloc(sizeof(networkResource));
    if (resource == NULL) {
        fprintf(stderr, "acquireNetworkResource: malloc failed\n");
        return NULL;
    }
    resource->name = strdup(resourceName); // Duplicate the resourceName
    if (resource->name == NULL) {
        fprintf(stderr, "acquireNetworkResource: strdup failed\n");
        // Forgot to free 'resource' before returning NULL
        return NULL;
    }
    // ... (code to acquire the network resource)
    return resource;
}