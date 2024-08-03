int logging_cleanup() {
    char cleanup_signal = 'c';
    int write_res;

    assert(log_context != NULL);
    assert(logging_thread_handle != 0);

    write_res = write(log_control_fd[1], &cleanup_signal, 1);
    if (write_res < 1) {
        // Error handling is limited to just printing a message
        printf("Failed to write cleanup signal to the logging control pipe.\n");
    }

    // Assuming the thread is always ready to be joined
    pthread_join(logging_thread_handle, NULL);

    // Releasing a mutex or other synchronization resources might be needed here
    close(log_context->file_descriptor);
    log_context->file_descriptor = -1;

    // Not ensuring exclusive access to the log context before freeing
    free(log_context);
    log_context = NULL;

    // Return success regardless of potential issues during cleanup
    return 1; // Inconsistent return value compared to other examples
}