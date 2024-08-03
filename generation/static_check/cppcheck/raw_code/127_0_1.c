void copyArrayContents(int *source, int *destination, int sourceSize) {
    for (int i = 0; i <= sourceSize; i++) { // Vulnerability: Off-by-one error, potentially accessing source out-of-bounds
        destination[i] = source[i];
    }
}

