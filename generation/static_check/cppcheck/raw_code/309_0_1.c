static void *cpu_worker_thread(void *arg) {
    CPUState *cpu = arg;
    int ret, sig;
    sigset_t set;

    pthread_mutex_lock(&cpu->mutex);
    cpu->thread_id = get_thread_id();
    sigemptyset(&set);
    sigaddset(&set, SIGUSR1);

    while (!cpu->shutdown) {
        global_cpu_state = NULL;
        pthread_mutex_unlock(&cpu->mutex);
        
        ret = sigwait(&set, &sig);

        if (ret != 0) {
            fprintf(stderr, "Error during sigwait\n");
            exit(1);
        }

        pthread_mutex_lock(&cpu->mutex);
        global_cpu_state = cpu->state_ptr;

        process_cpu_tasks(cpu);
    }

    return NULL;
}
