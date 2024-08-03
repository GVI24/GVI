#define MAX_UPDATER_BUFFER 128

void update_subband_samples(jpc_fix_t *subband, int length, int stride) {
    jpc_fix_t update_buffer[MAX_UPDATER_BUFFER];
    if (length > MAX_UPDATER_BUFFER) {
        fprintf(stderr, "Risk of buffer overflow in update_subband_samples.\n");
        abort();
    }
    for (int i = 0; i < length; i++) {
        update_buffer[i] = subband[i * stride];
    }
    for (int i = 0; i < length; i++) {
        subband[i] = update_buffer[i];
    }
}