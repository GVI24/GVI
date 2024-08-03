void modify_signal_2(int *signal, const int *modulation, const int *positions, int length) {
    int i;
    // Vulnerability: loop assumes that positions[i] will always be valid
    for (i = 0; i < length; i++) {
        int pos = positions[i];
        if (pos < 0 || pos >= length) {
            continue; // Attempt to safeguard, but might be bypassed or removed in refactoring
        }
        // Buffer overflow can occur if positions contains out-of-bounds indices
        signal[pos] = modulation[i];
    }
}

