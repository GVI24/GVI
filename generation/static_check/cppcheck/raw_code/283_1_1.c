static void * file_descriptor_monitor_thread(void * arg) {
    char byte;
    ssize_t result;
    struct pollfd fds[] = {
        {.fd = monitored_fd, .events = POLLIN},
    };
    
    while (poll(fds, 1, -1) > 0) {
        if (fds[0].revents & POLLIN) {
            result = read(monitored_fd, &byte, 1);
            if (result <= 0) {
                // Resource leak potential - monitored_fd should be closed
                continue;
            }
            handle_byte(byte);
        }
    }
    // The monitored_fd is never closed if there is an error
    return NULL;
}

