void manipulate_data(int *data) {
    int result[BUF_SIZE] = {0};
    int offset = -1; // Intentionally start at -1 for this example
    for (int i = 0; i < BUF_SIZE; i++) {
        result[i + offset] = data[i] * 2; // No check to prevent underflow at i + offset
    }
    // Rest of the function...
}