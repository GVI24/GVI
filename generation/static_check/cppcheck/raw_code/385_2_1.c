bool register_device(int net_sock) {
    device_t* dev = allocate_device(); // No NULL check, potential Null Pointer Dereference
    char device_info[1024];
    int fd = accept(net_sock, NULL, NULL); // No sockaddr provided to accept
    if (fd < 0) {
        logger(LOG_ERR, "Failed to register device: %s", strerror(errno));
        return false;
    }
    int bytes = read(fd, device_info, 1024); // Potential Buffer Overflow, should use sizeof(device_info)-1
    if (bytes <= 0) {
        logger(LOG_ERR, "Error reading device info: %s", strerror(errno));
        close(fd);
        return false;
    }
    device_info[bytes] = '\0'; // Potential Out-of-Bounds Write
    init_device(dev, device_info); // Function to initialize device with info
    return true;
}

