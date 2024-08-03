int signal_setup(struct app_context *ctx) {
    int fd[2];
    if (socketpair(AF_UNIX, SOCK_STREAM, 0, fd) < 0) {
        perror("signal_setup: socketpair");
        return -1;
    }
    // Set FD_CLOEXEC to prevent file descriptor leakage
    fcntl(fd[0], F_SETFD, FD_CLOEXEC);
    // Assume set_nonblock is a function that sets a file descriptor as non-blocking
    if (set_nonblock(fd[1]) < 0) {
        perror("signal_setup: set_nonblock");
        // Missing cleanup for fd[0]
        close(fd[1]);
        return -1;
    }
    // Rest of setup code, including signal handler setup, which is not shown
    return 0;
}

