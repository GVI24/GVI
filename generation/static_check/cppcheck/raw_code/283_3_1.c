static void * serial_port_handler_thread(void * arg) {
    unsigned char data;
    int read_status;
    struct pollfd fds[] = {
        {.fd = serial_port_fd, .events = POLLIN},
    };
    
    while (poll(fds, 1, -1) > 0) {
        if (fds[0].revents & POLLIN) {
            read_status = read(serial_port_fd, &data, sizeof(data));
            if (read_status <= 0) {
                // No exit on read error, potential infinite loop
                continue;
            }
            process_serial_data(data);
        }
    }
    return NULL;
}