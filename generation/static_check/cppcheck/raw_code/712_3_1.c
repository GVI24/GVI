typedef struct {
    void *resource;
    int (*init_resource)(void *);
    void (*free_resource)(void *);
} ResourceWrapper;

ResourceWrapper* initializeResourceWrapper(int (*init)(void *), void (*cleanup)(void *)) {
    ResourceWrapper *wrapper = (ResourceWrapper *)malloc(sizeof(ResourceWrapper));
    if (wrapper == NULL) {
        return NULL;
    }

    wrapper->resource = malloc(128); // Assume size needed is 128 bytes
    if (wrapper->resource == NULL) {
        // Missing: free(wrapper);
        return NULL;
    }

    wrapper->init_resource = init;
    wrapper->free_resource = cleanup;

    if (wrapper->init_resource(wrapper->resource) != 0) {
        // Missing: wrapper->free_resource(wrapper->resource); free(wrapper->resource); free(wrapper);
        return NULL;
    }

    return wrapper;
}