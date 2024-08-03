// Vulnerability: Buffer Overflow in manual byte copying
int copy_data(char *source, char *destination, int size) {
    int i;
    // Dangerous: No check if destination can hold 'size' bytes
    for (i = 0; i < size; i++) {
        destination[i] = source[i];
    }
    return 0;
}