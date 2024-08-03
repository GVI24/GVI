static void *system_timer_thread(void *arg) {
    SystemTimer *timer = arg;
    sigset_t mask;
    int ret, sig;

    sigemptyset(&mask);
    sigaddset(&mask, SIGALRM);

    while (1) {
        shared_timer = NULL;
        ret = sigwait(&mask, &sig);

        if (ret == -1) {
            perror("sigwait failed");
            exit(EXIT_FAILURE);
        }

        // Process timer interrupt
        shared_timer = timer->timer_val;
        handle_timer_interrupt(timer);
    }
}
