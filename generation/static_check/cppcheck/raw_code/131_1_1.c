void saveFilePath(const char* directory, const char* filename) {
    char path[512]; // fixed-size buffer
    sprintf(path, "%s/%s", directory, filename); // vulnerable sprintf that can cause buffer overflow
    // ... (the rest of the function would use 'path' to perform some file operation)
}

