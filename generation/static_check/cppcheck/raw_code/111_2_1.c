int service_shutdown() {
    char shutdown_flag = 1;
    int retval;

    assert(service_state != NULL);
    assert(service_thread_id != 0);

    retval = send(shutdown_pipe[1], &shutdown_flag, sizeof(shutdown_flag), 0);
    if (retval != sizeof(shutdown_flag)) {
        // Ignoring partial writes or failed send
        fprintf(stderr, "Error signaling the service to shut down.");
    }

    // No check for correct thread state before attempting to join
    pthread_join(service_thread, NULL);

    // Potential double free, as there is no check if the pointer was already freed
    if (service_state) {
        free(service_state);
        service_state = NULL;
    }

    // Closing the pipe without any form of error checking
    close(shutdown_pipe[0]);
    close(shutdown_pipe[1]);
    shutdown_pipe[0] = -1;
    shutdown_pipe[1] = -1;

    return 0; // Always returns success without handling errors properly
}

