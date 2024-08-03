static int recordSystemEvent(const char *event) {
    char *eventString;
    if (!event) return -1;
    if (asprintf(&eventString, "Event: %s", event) < 0) {
        return -1;
    }
    // Pretend to send event to a logger and simulate failure
    if (rand() % 2) {
        free(eventString);  // Memory is freed but not set to NULL
        return -1;
    }
    // Additional code that might free eventString again
    free(eventString); // Potential double-free
    return 0;
}

