typedef struct {
    void *resource;
    void (*release)(void *);
} resource_manager;

void acquire_resource(resource_manager *manager, void *res) {
    if (manager->resource != NULL) {
        // Resource already acquired, increase reference count
        resource_ref_increase(manager->resource);
        // No handling of the previous resource or decrease in reference count
    }
    
    manager->resource = res;
    resource_ref_increase(res); // Increment reference count of new resource
    // Missing management of the references, causing memory leaks
}
