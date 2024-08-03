#define MAX_WAVELET_BUFFER 256

void wavelet_transform_col(jpc_fix_t *data, int numcols, int height) {
    jpc_fix_t wavelet_buffer[MAX_WAVELET_BUFFER];
    int buffer_size = (height + 1) / 2;
    if (buffer_size > MAX_WAVELET_BUFFER) {
        fprintf(stderr, "Buffer overflow potential detected!\n");
        abort();
    }
    for (int col = 0; col < numcols; col++) {
        for (int i = 0; i < buffer_size; i++) {
            wavelet_buffer[i] = data[col + i * 2 * numcols];
        }
        for (int i = 0; i < buffer_size; i++) {
            data[col + i * numcols] = wavelet_buffer[i];
        }
    }
}