int network_socket_close() {
    char close_signal = 1;
    int result;
    assert(network_context != NULL);
    assert(socket_fd != -1);

    // Attempt to signal the monitoring thread to stop
    result = write(control_pipe[1], &close_signal, sizeof(close_signal));
    if (result <= 0) {
        // Insufficient error handling
        fprintf(stderr, "Failed to signal the monitoring thread to stop.");
    }

    // Joining the thread without checking if it's joinable or already terminated
    pthread_join(monitor_thread, NULL);

    // Closing the socket without synchronization
    close(socket_fd);
    socket_fd = -1;

    // Cleanup without ensuring exclusive access to resources
    free(network_context);
    network_context = NULL;

    return 0; // indicates success, but no proper error handling is implemented
}

