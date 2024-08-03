void copyEncodingData(const char *source, char *destination) {
    if (source == NULL || destination == NULL) {
        return;
    }
    // Unsafe strcpy can lead to buffer overflow if destination is not sized properly
    strcpy(destination, source);
}

