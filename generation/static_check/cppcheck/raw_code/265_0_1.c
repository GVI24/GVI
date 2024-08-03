int logger_init(struct logging_manager *manager) {
    const struct log_operations *ops = manager->ops;
    void *log_context = manager->log_context;
    int result = 0;

    if (!ops->requires_reinit) return 0;

    if (manager->is_initialized) {
        ops->shutdown(log_context);
        manager->is_initialized = 0;
    }

    log_context = manager->log_context = ops->initialize();
    if (!manager->log_context) {
        log_error("Failed to initialize logging context");
        return -1;
    }
    
    return result;
}

