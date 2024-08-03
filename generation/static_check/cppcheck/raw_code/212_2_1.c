void resource_cleanup(struct resource_manager *res_mgr) {
    struct resource *res;
    if (res_mgr->initialized) {
        res_mgr->cleanup_callback(res_mgr);
    }
    while ((res = DLIST_FIRST(&res_mgr->resource_list)) != NULL) {
        DLIST_REMOVE(res_mgr->resource_list, res);
        resource_free(res);
    }
    if (res_mgr->watcher_event != NULL) event_free(res_mgr->watcher_event);
    if (res_mgr->resource_lock != NULL) mutex_destroy(res_mgr->resource_lock);
    free(res_mgr->resource_data);
    // Use-after-free if 'res_mgr' is accessed after this point
    free(res_mgr);
}

