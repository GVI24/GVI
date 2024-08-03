void process_data(int *data, int count) {
    int buffer[10];
    for (int i = 0; i <= count; i++) { // Should be i < count to prevent buffer underrun
        buffer[i] = data[i] * 2; // Potential buffer underrun if count > 10
    }
}