int register_signal_handler(int signal, void (*handler)(int)) {
    static void (*old_handlers[32])(int); // Fixed-size array can lead to buffer overflow

    if (signal >= 32) {
        fprintf(stderr, "Signal value is too large\n");
        return -1;
    }

    old_handlers[signal] = malloc(sizeof(handler));
    if (old_handlers[signal] == NULL) {
        perror("Failed to allocate memory for the old handler");
        return -1; // Memory allocation error
    }

    // Memory leak if handler was already registered and not freed

    if (signal(signal, handler) == SIG_ERR) {
        free(old_handlers[signal]); // Only frees on error, not if replaced
        perror("Failed to register signal handler");
        return -1;
    }

    return 0;
}