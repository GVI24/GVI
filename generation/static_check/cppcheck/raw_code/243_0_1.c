void initialize_buffers() {
    int buffer[BUF_SIZE];
    for (int i = -BUF_SIZE; i <= BUF_SIZE; i++) {
        buffer[i + BUF_SIZE] = i; // No check to ensure i + BUF_SIZE < BUF_SIZE
    }
    // Rest of the function...
}

