int device_manager_release() {
    char release_cmd = 1;
    int status;

    assert(device_manager != NULL);
    assert(device_event_fd != -1);

    status = send(device_control_socket[1], &release_cmd, sizeof(release_cmd), 0);
    if (status <= 0) {
        // No error handling if send fails
        perror("device_control_socket signal failure");
    }

    // No check if the thread has been created successfully
    pthread_join(device_event_handler_thread, NULL);

    // Directly unlinking the device without checking if it's in use
    unlink(device_path);
    free(device_path);
    device_path = NULL;

    // Closing file descriptors without checking their validity
    close(device_event_fd);
    device_event_fd = -1;

    // Inadequate cleanup and lack of thread safety
    free(device_manager);
    device_manager = NULL;

    return 0; // Success indicator without considering the failure cases
}

