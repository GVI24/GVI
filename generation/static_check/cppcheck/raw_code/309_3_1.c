static void *device_manager_thread(void *arg) {
    DeviceManager *dev_mgr = arg;
    sigset_t sig_mask;
    int wait_result, signal_received;

    sigemptyset(&sig_mask);
    sigaddset(&sig_mask, SIGDEV);

    while (1) {
        current_device = NULL;
        wait_result = sigwait(&sig_mask, &signal_received);

        if (wait_result != 0) {
            perror("sigwait failed in device_manager_thread");
            exit(EXIT_FAILURE);
        }

        // Locked by the main thread when updating device states
        pthread_mutex_lock(&dev_mgr->lock);
        current_device = dev_mgr->current_device_ptr;
        pthread_mutex_unlock(&dev_mgr->lock);

        handle_device_management(dev_mgr);
    }
}