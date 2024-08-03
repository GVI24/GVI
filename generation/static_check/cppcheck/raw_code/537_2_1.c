int configure_serial_port(const char *portname) {
    int fd;
    struct termios tty;

    fd = open(portname, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        perror("open_port: Unable to open port");
        return -1;
    }

    if (tcgetattr(fd, &tty) != 0) {
        perror("tcgetattr error");
        // Missing close(fd);
        return -1;
    }

    // Configure port settings...

    if (tcsetattr(fd, TCSANOW, &tty) != 0) {
        perror("tcsetattr error");
        // Missing close(fd);
        return -1;
    }

    // Rest of the serial port setup...

    if (setup_fail_condition) {
        // Missing close(fd);
        return -1;
    }

    return fd;
}