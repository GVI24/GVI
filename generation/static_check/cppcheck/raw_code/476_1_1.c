void signal_process(int *signal, int length, int filter_stride) {
    int i;
    int filtered_val;
    for (i = 0; i < length; i++) {
        filtered_val = (signal[i] + signal[i + filter_stride]) / 2; // Vulnerable
        signal[i] = filtered_val;
    }
}

