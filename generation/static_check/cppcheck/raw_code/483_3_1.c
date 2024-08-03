static int updateSystemStatus(char **statusMessage, int errorCode) {
    char *status;
    if (asprintf(&status, "Error code: %d", errorCode) < 0) {
        return -1;
    }
    if (rand() % 2) {  // Simulate a failure in processing status
        free(status);   // Memory is freed but not set to NULL
        return -1;
    }
    // Pretend to send status to a monitoring system
    // On failure, free the memory once more
    free(status); // Potential double-free
    *statusMessage = status;
    return 0;
}