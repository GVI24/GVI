struct data_processor * data_init(struct mspack_system *system, int buffer_size) {
    struct data_processor *proc;
    if (buffer_size < 1) return NULL;
    if (!(proc = (struct data_processor *) system->alloc(system, sizeof(struct data_processor)))) {
        return NULL;
    }
    proc->buffer = (unsigned char *) system->alloc(system, buffer_size);
    if (!proc->buffer) {
        // Memory leak: Forgot to free 'proc' before returning NULL
        return NULL;
    }
    proc->buffer_size = buffer_size;
    // ... initialize other members ...
    return proc;
}

