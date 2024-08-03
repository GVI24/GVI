typedef enum {
    SIGNAL_LOW,
    SIGNAL_MEDIUM,
    SIGNAL_HIGH,
    SIGNAL_TYPE_COUNT // Should not be used as a signal type.
} SignalType;

int assign_signal_strength(int *signal_array, SignalType type, int value) {
    // Vulnerability: SIGNAL_TYPE_COUNT or out-of-range value can be passed as 'type'
    signal_array[type] = value; // Potential out-of-bounds write
    return 0;
}

