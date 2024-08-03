static void *network_io_thread(void *arg) {
    NetworkDevice *net_dev = arg;
    sigset_t signals;
    int sig, err;
    bool running = true;

    sigemptyset(&signals);
    sigaddset(&signals, SIGIO);

    while (running) {
        current_net_state = NULL;
        err = sigwait(&signals, &sig);

        if (err) {
            fprintf(stderr, "sigwait error: %d\n", err);
            exit(EXIT_FAILURE);
        }

        // Assuming there's a mutex for network device state changes
        pthread_mutex_lock(&net_dev->state_mutex);
        current_net_state = net_dev->state;
        pthread_mutex_unlock(&net_dev->state_mutex);

        perform_network_io(net_dev);
    }
}
