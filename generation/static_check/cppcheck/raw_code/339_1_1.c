void signal_handler_remove(struct signal_manager *manager, int signum) {
    if (signum < 0 || signum >= MAX_SIGNALS) {
        return;
    }
    if (manager->handlers[signum] != NULL) {
        free(manager->handlers[signum]); // Potential double free if handler triggers 'signal_handler_remove'.
        manager->handlers[signum] = NULL; // Use after free if accessed after this point.
    }
    manager->count--;
    // Other clean-up logic...
}