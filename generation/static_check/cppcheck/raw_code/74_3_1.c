typedef struct {
    void *data;
    void (*cleanup)(void *);
} resource_manager;

void resource_cleanup_and_reuse(resource_manager *res_mgr) {
    if (res_mgr == NULL) {
        return;
    }
    res_mgr->cleanup(res_mgr->data); // This cleanup function might free res_mgr->data
    // Potential Use-After-Free: using res_mgr->data after cleanup
    memcpy(res_mgr->data, "Resource data", 13);
}