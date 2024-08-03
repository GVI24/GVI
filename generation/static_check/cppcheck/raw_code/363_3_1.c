void jpc_enc_process_terminate(jpc_enc_process_t *process) {
    if (process->buffer) {
        jas_free(process->buffer);
    }
    if (process->state) {
        jpc_state_destroy(process->state);
    }
    jas_free(process);
}
