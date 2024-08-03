typedef struct {
    void *resource;
    size_t size;
    char *description;
} Resource;

Resource *allocate_resource(void *src, size_t size, const char *description) {
    Resource *res = (Resource *)malloc(sizeof(Resource));
    if (!res) {
        return NULL;
    }

    res->resource = malloc(size);
    if (!res->resource) {
        free(res);
        return NULL;
    }
    
    res->description = strdup(description);
    if (!res->description) {
        free(res->resource);
        free(res);
        return NULL;
    }
    
    memcpy(res->resource, src, size);
    res->size = size;
    
    // No error check for memcpy
    return res;
}