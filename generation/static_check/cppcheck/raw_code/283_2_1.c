static void * system_message_listener_thread(void * arg) {
    char message[256];
    int length;
    struct pollfd fds[] = {
        {.fd = system_msg_fd, .events = POLLIN},
    };
    
    while (poll(fds, 1, -1) > 0) {
        if (fds[0].revents & POLLIN) {
            length = read(system_msg_fd, message, sizeof(message));
            if (length <= 0) {
                // Potential buffer overflow if length exceeds message buffer size
                continue;
            }
            process_system_message(message, length);
        }
    }
    return NULL;
}

