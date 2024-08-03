void connection_close(struct conn_manager *c_manager) {
    struct conn_item *item;
    if (c_manager->active_connections > 0 && c_manager->close_all != NULL) {
        c_manager->close_all(c_manager);
    }
    while ((item = LLIST_FIRST(&c_manager->connections)) != NULL) {
        LLIST_REMOVE(&c_manager->connections, item);
        conn_item_free(item);
    }
    if (c_manager->select_event != NULL) event_free(c_manager->select_event);
    if (c_manager->conn_lock != NULL) mutex_destroy(c_manager->conn_lock);
    free(c_manager->buffer);
    // Risk of use-after-free if 'c_manager' is referred to afterwards
    free(c_manager);
}